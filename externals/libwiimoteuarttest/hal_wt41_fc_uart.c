/*
 * hal_wt41_fc_uart.c
 *
 *  Created on: 25 Oct 2018
 *      Author: christoph
 */

#include "hal_wt41_fc_uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/atomic.h>
#include <util/delay.h>

#include "USART3.h"

// Functions declarations
void halWT41FcUart_Receive(uint8_t byte);
void halWT41FcUart_call_receive_callback(void);
uint8_t halWT41FcUart_get_free_buffer_space(void);

// define functions pointers
void (*halWT41_receive_callback)(uint8_t);

// define variables
uint8_t wt41_read_index=0;
uint8_t wt41_write_index = 0;
uint8_t wt41_receive_buffer[HAL_WT41_BUFFER_SIZE];


error_t halWT41FcUartInit(void (*sndCallback)(), void (*rcvCallback)(uint8_t))
{

    PORTH = 0x00;
    DDRH = 0xFF;

    PORTK = 0x00;
    DDRK = 0xFF;

    PORTL = 0x00;
    DDRL = 0xFF;

    // TODO: replace busy waiting
    DDRJ |= (1 << PORTJ5);
    PORTJ &= ~(1 << PORTJ5);

    USART3_inits(USART3_BAUDRATE_1_M,
                 USART3_STOP_BITS_1,
                 USART3_PARITY_DISABLED,
                 USART3_CHAR_SIZE_8_BIT);

    USART3_set_flow_control();

    halWT41_receive_callback = rcvCallback;
    USART3_enable_receiver(halWT41FcUart_Receive);
    USART3_enable_transmitter(sndCallback);

    _delay_ms(5);
    USART3_clear_flow_control();
    PORTJ |= (1 << PORTJ5);

    PORTK ^= (1 << PORTK0);

    return SUCCESS;
}

error_t halWT41FcUartSend(uint8_t byte)
{
    static uint8_t send_counter=0;
    PORTK |= (1 << PORTK1);

    PORTH = send_counter++;

    if(USART3_write_byte(byte) > 0 )
    {
        PORTK ^= (1 << PORTK2);
        return ERROR;
    }
    PORTK ^= (1 << PORTK3);
    return SUCCESS;
}

void halWT41FcUart_Receive(uint8_t byte)
{
    static uint8_t recv_counter=0;

    wt41_receive_buffer[wt41_write_index] = byte;

    wt41_write_index = (1+wt41_write_index) % HAL_WT41_BUFFER_SIZE;

    uint8_t current_buffer_space = halWT41FcUart_get_free_buffer_space();

    if (current_buffer_space <= HAL_WT41_FLOW_CONTROL_SET)
    {
        USART3_set_flow_control();
    }


    if(current_buffer_space < HAL_WT41_BUFFER_SIZE-1)
    {
        PORTK ^= (1 << PORTK4);
        return;
    }

    sei();

    PORTK ^= (1 << PORTK5);

    while(current_buffer_space <= HAL_WT41_BUFFER_SIZE)
    {
        recv_counter++;
        PORTL = recv_counter;

        uint8_t temp = wt41_receive_buffer[wt41_read_index];
        (*halWT41_receive_callback)(temp);

        PORTH = recv_counter;
        wt41_read_index = (1+wt41_read_index) % HAL_WT41_BUFFER_SIZE;

        current_buffer_space = halWT41FcUart_get_free_buffer_space();

        if (current_buffer_space > HAL_WT41_FLOW_CONTROL_CLEAR)
        {
            USART3_clear_flow_control();
        }

    }

    PORTK ^= (1 << PORTK6);
}

uint8_t halWT41FcUart_get_free_buffer_space(void)
{
    uint8_t free_buffer_space = 0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        // empty space from write index until end of buffer
        // and from 0 t0 read index
        if (wt41_read_index < wt41_write_index)
        {
            free_buffer_space =HAL_WT41_BUFFER_SIZE - wt41_write_index + wt41_read_index;
        }
        // empty space between write and read index
        else if (wt41_read_index > wt41_write_index)
        {
            free_buffer_space = wt41_read_index - wt41_write_index;
        }
        else
        {
            free_buffer_space = HAL_WT41_BUFFER_SIZE;
        }
    }
    return free_buffer_space;
}
