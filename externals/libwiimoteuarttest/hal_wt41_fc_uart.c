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
#include "Timer1.h"

// Functions declarations
void halWT41FcUart_Receive(uint8_t byte);
void halWT41FcUart_call_receive_callback(void);
uint8_t halWT41FcUart_get_free_buffer_space(void);
void halWT41FcUart_timer_callback(void);

// define functions pointers
static void (*halWT41_receive_callback)(uint8_t);
static void (*halWT41_send_callback)(void);

// define variables
volatile uint8_t wt41_read_index;
volatile uint8_t wt41_write_index;
volatile uint8_t wt41_receive_buffer[HAL_WT41_BUFFER_SIZE];
volatile uint8_t wt41_buffer_space;
volatile uint8_t recv_counter=0;
volatile uint8_t recv_flag ;

error_t halWT41FcUartInit(void (*sndCallback)(), void (*rcvCallback)(uint8_t))
{
    DDRJ |= (1 << PORTJ5);
    PORTJ &= ~(1 << PORTJ5);

    timer1_set_prescaler(TIMER1_PRESCALER_64);
    timer1_set_waveform_generation_mode(TIMER1_CTC_MODE_TOP_OCR1A);
    timer1_activate_output_A(TIMER1_CTC_NO_PORT_OPERATION);
    timer1_set_output_compare_A(1250);
    timer1_enable_output_compare_interrupt_A(halWT41FcUart_timer_callback);

    USART3_inits(USART3_BAUDRATE_1_M,
                 USART3_STOP_BITS_1,
                 USART3_PARITY_DISABLED,
                 USART3_CHAR_SIZE_8_BIT);

    USART3_set_flow_control();

    wt41_read_index=0;
    wt41_write_index = 0;
    wt41_buffer_space = HAL_WT41_BUFFER_SIZE;
    halWT41_receive_callback = rcvCallback;
    halWT41_send_callback = sndCallback;
    USART3_enable_receiver(halWT41FcUart_Receive);

    recv_flag= 0x00;
    return SUCCESS;
}

void halWT41FcUart_timer_callback(void)
{
    USART3_enable_transmitter(halWT41_send_callback);
    USART3_clear_flow_control();
    PORTJ |= (1 << PORTJ5);
    timer1_disable_output_compare_interrupt_A();
}

error_t halWT41FcUartSend(uint8_t byte)
{
    static uint8_t send_counter=0;

    if(USART3_write_byte(byte) > 0 )
    {
        return ERROR;
    }
    return SUCCESS;
}

void halWT41FcUart_Receive(uint8_t byte)
{
    uint8_t buffer_space;
    wt41_receive_buffer[wt41_write_index] = byte;
    if(wt41_write_index +1 >=HAL_WT41_BUFFER_SIZE)
    {
        wt41_write_index=0;
    }
    else
    {
        wt41_write_index++;
    }

    buffer_space = halWT41FcUart_get_free_buffer_space();
    if (buffer_space <= HAL_WT41_FLOW_CONTROL_SET)
    {
        USART3_set_flow_control();
    }

    sei();

    if(recv_flag)
    {
        return;
    }

    recv_flag = 0xFF;

    while(wt41_read_index != wt41_write_index)
    {

        if (wt41_buffer_space <= HAL_WT41_FLOW_CONTROL_SET)
        {
            USART3_set_flow_control();
        }
        else if (wt41_buffer_space > HAL_WT41_FLOW_CONTROL_CLEAR)
        {
            USART3_clear_flow_control();
        }

        uint8_t temp = wt41_receive_buffer[wt41_read_index];
        (*halWT41_receive_callback)(temp);

        if(wt41_read_index +1 >=HAL_WT41_BUFFER_SIZE)
        {
            wt41_read_index=0;
        }
        else
        {
            wt41_read_index++;
        }

        wt41_buffer_space = halWT41FcUart_get_free_buffer_space();
    }

    recv_flag = 0x00;
}

uint8_t halWT41FcUart_get_free_buffer_space(void)
{
    // ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        uint8_t free_buffer_space = 0;

        // empty space from write index until end of buffer
        // and from 0 t0 read index
        if (wt41_write_index < wt41_read_index )
        {
            free_buffer_space = wt41_read_index - wt41_write_index;
        }
        // empty space between write and read index
        else
        {
            free_buffer_space =HAL_WT41_BUFFER_SIZE - (wt41_write_index - wt41_read_index);
        }

        return free_buffer_space;
    }
}
