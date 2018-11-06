/*
 * USART3.c
 *
 *  Created on: 30 SEP 2018
 *      Author: christoph
 */

#include "USART3.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/atomic.h>

#ifdef USART3_ENABLE_FLOW_CONTROL

#include "PinChangeInterrupts.h"

void USART3_pin_change_callback(void);

#endif

void (*usart3_transmitter_callback)(void);
void (*usart3_receiver_callback)(uint8_t);

// define ring buffer and correspoding indexes
uint8_t *usart3_send_buffer[USART3_BUFFER_SIZE];
volatile uint16_t usart3_read_index = 0;
uint16_t usart3_write_index = 0;

usart3_flow_control_t usart3_mode = USART3_SEND_ENABLED;

volatile uint8_t uart_counter = 0;

void USART3_inits(uint8_t baudrate, uint8_t stop_bits, uint8_t parity, uint8_t char_size)
{
    UBRR3L = baudrate& 0xFF;
    UBRR3H = (baudrate >> 8)& 0x0F;

    uint8_t temp = 0x00;
    temp |= (parity << 4);
    temp |= (stop_bits << 3);
    temp |= (char_size << 1);

    UCSR3C = temp;

    #if defined(USART3_DOUBLE_SPEED)
        UCSR3A |= (1<< U2X3);
        UCSR3C &= ~(1 << UMSEL31 | 1 << UMSEL30);
    #elif defined(USART3_SYNCHRONUS)
        UCSR3C &= ~(1 << UMSEL31);
        UCSR3C |=  (1 << UMSEL30);
    #else
        UCSR3A &= ~(1<< U2X3);
        UCSR3C &= ~(1 << UMSEL31 | 1 << UMSEL30);
    #endif

    #ifdef USART3_ENABLE_FLOW_CONTROL
    USART3_PORT_FC &= ~(1 << USART3_CTS_FC | 1 << USART3_RTS_FC );
    USART3_DDR_FC |= (1 << USART3_CTS_FC );
    USART3_DDR_FC &= ~(1 << USART3_RTS_FC );

    PinChangInterrupts_bank1_set_callback(USART3_PCINT_PIN, &USART3_pin_change_callback);
    PinChangeInterrupts_bank1_enable(USART3_PCINT_PIN);
    PinChangeInterrupts_bank1_enable_interrupt();

    #endif
}

#ifdef USART3_SYNCHRONUS

void USART3_set_clock_polarity_rising_edge(void)
{
    UCSR3C &= ~(1 << UCPOL3);
}

void USART3_set_clock_polarity_falling_edge(void)
{
    UCSR3C |= (1 << UCPOL3);
}

#endif

void USART3_enable_receiver(void (*callback)(uint8_t))
{
    usart3_receiver_callback = callback;
    UCSR3B |= (1 << RXEN3 | 1 << RXCIE3);
}

void USART3_disable_receiver(void)
{
    UCSR3B &= ~(1 << RXEN3 | 1 << RXCIE3);
    usart3_receiver_callback=NULL;
}

void USART3_enable_transmitter(void (*callback)(void))
{
    UCSR3B |= (1 << TXEN3);
    usart3_transmitter_callback = callback;
}

void USART3_disable_transmitter(void)
{
    UCSR3B &= ~(1 << TXEN3);
    usart3_transmitter_callback=NULL;
}

uint8_t USART3_write_byte(uint8_t data_byte)
{
    if(USART3_get_free_buffer_space() > 0)
    {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            if (usart3_read_index == usart3_write_index && usart3_mode == USART3_SEND_ENABLED)
            {
                usart3_write_index = (1+usart3_write_index) % USART3_BUFFER_SIZE;
                UDR3 = data_byte;
                UCSR3B |= (1 << UDRIE3);
            }
            else
            {
                *usart3_send_buffer[usart3_write_index] = data_byte;
                usart3_write_index = (1+usart3_write_index) % USART3_BUFFER_SIZE;
            }
        }
        return 0;
    }
    return 1;
}

uint8_t USART3_write_string(char *data_string, uint16_t length)
{
    if(USART3_get_free_buffer_space() > length)
    {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            uint16_t usart3_write_index_old = usart3_write_index;

            // check if string has to be split up
            if (usart3_write_index + length >= USART3_BUFFER_SIZE ||
                usart3_write_index + length <= usart3_write_index)
            {
                //copy first part of string
                uint16_t copy_length = USART3_BUFFER_SIZE - usart3_write_index;
                memcpy(usart3_send_buffer[usart3_read_index], data_string, copy_length);

                //copy second part of string
                uint16_t send_index = copy_length;
                copy_length = length - copy_length;
                memcpy(usart3_send_buffer, &(data_string[send_index]), copy_length);

                // set write index to the correct id
                usart3_write_index = copy_length;
            }
            else
            {
                memcpy(usart3_send_buffer[usart3_read_index], data_string, length);
                usart3_write_index += length;
            }

            if (usart3_read_index == usart3_write_index_old &&  usart3_mode == USART3_SEND_ENABLED)
            {
                UCSR3B |= (1 << UDRIE3);
            }
        }
        return 0;
    }
    return 1;
}

uint16_t USART3_get_free_buffer_space(void)
{
    uint16_t free_buffer_space = 0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        // empty space from write index until end of buffer
        // and from 0 t0 read index
        if (usart3_read_index < usart3_write_index)
        {
            free_buffer_space =USART3_BUFFER_SIZE - usart3_write_index + usart3_read_index;
        }
        // empty space between write and read index
        else if (usart3_read_index > usart3_write_index)
        {
            free_buffer_space = usart3_read_index - usart3_write_index;
        }
        // Buffer is empty
        else
        {
            free_buffer_space= USART3_BUFFER_SIZE;
        }
    }
    return free_buffer_space;
}

#ifdef USART3_ENABLE_FLOW_CONTROL

void USART3_set_flow_control(void)
{
    USART3_PORT_FC |= (1 << USART3_CTS_FC );
}

void USART3_clear_flow_control(void)
{
    USART3_PORT_FC &= ~(1 << USART3_CTS_FC );
}

void USART3_pin_change_callback(void)
{
    uint8_t temp = USART3_PIN_FC & ( 1 << USART3_RTS_FC);

    if(temp > 0)
    {
        usart3_mode = USART3_DISABLE_SEND;
    }
    else
    {
        usart3_mode = USART3_SEND_ENABLED;

        if (usart3_read_index != usart3_write_index)
        {
            UDR3 = *usart3_send_buffer[usart3_read_index];
            usart3_read_index = (1+usart3_read_index) % USART3_BUFFER_SIZE;

            // enable interrupt again
            UCSR3B |= (1 << UDRIE3);
        }
    }
}

#endif

ISR(USART3_RX_vect)
{
    uint8_t data = UDR3;
    (*usart3_receiver_callback)(data);
}

ISR(USART3_UDRE_vect)
{

    uint16_t usart3_read_index_temp = usart3_read_index;

    usart3_read_index = (1+usart3_read_index) % USART3_BUFFER_SIZE;

    if (usart3_read_index == usart3_write_index || usart3_mode == USART3_DISABLE_SEND)
    {
        // nothing to send left
        UCSR3B &= ~(1 << UDRIE3);

        if (usart3_mode == USART3_DISABLE_SEND)
        {
            usart3_mode = USART3_SEND_DISABLED;
        }
    }
    else
    {
        PORTK = *usart3_send_buffer[usart3_read_index_temp];
        UDR3 = *usart3_send_buffer[usart3_read_index_temp];
    }

    if (usart3_transmitter_callback != NULL)
    {
        (*usart3_transmitter_callback)();
    }
}
