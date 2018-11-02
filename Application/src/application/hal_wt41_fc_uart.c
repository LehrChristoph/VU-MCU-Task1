/*
 * hal_wt41_fc_uart.c
 *
 *  Created on: 25 Oct 2018
 *      Author: christoph
 */

#include "hal_wt41_fc_uart.h"

#include <avr/io.h>
#include <stdint.h>

#include "basics/USART3.h"

// Functions declarations
void halWT41FcUart_Receive(uint8_t byte);
void halWT41FcUart_call_receive_callback(void);
uint8_t halWT41FcUart_get_free_buffer_space(void);

// define functions pointers
void (*halWT41_receive_callback)(uint8_t);

// define variables
uint8_t wt41_read_index=0;
volatile uint8_t wt41_write_index = 0;
uint8_t wt41_receive_buffer[HAL_WT41_BUFFER_SIZE];

error_t halWT41FcUartInit(void (*sndCallback)(void), void (*rcvCallback)(uint8_t))
{
    USART3_inits(USART3_BAUDRATE_1_M, USART3_STOP_BITS_1, USART3_PARITY_DISABLED ,USART3_CHAR_SIZE_8_BIT);
    halWT41_receive_callback = rcvCallback;
    USART3_enable_receiver(&halWT41FcUart_Receive);
    USART3_enable_transmitter(sndCallback);
    return SUCCESS;
}

error_t halWT41FcUartSend(uint8_t byte)
{
    USART3_write_byte(byte);
    return SUCCESS;
}

void halWT41FcUart_Receive(uint8_t byte)
{

    wt41_receive_buffer[wt41_write_index] = byte;

    wt41_write_index = (1+wt41_write_index) % HAL_WT41_BUFFER_SIZE;


    if (halWT41FcUart_get_free_buffer_space() <= HAL_WT41_FLOW_CONTROL_SET)
    {
        USART3_set_flow_control();
    }
    // call of callback to QueuedExecuter for short ISR
    // QueuedExecuter_add_function_call(&halWT41FcUart_call_receive_callback);
}


void halWT41FcUart_call_receive_callback(void)
{
    halWT41_receive_callback(wt41_receive_buffer[wt41_read_index]);

    wt41_read_index = (1+wt41_read_index) % HAL_WT41_BUFFER_SIZE;

    if (halWT41FcUart_get_free_buffer_space() > HAL_WT41_FLOW_CONTROL_CLEAR)
    {
        USART3_clear_flow_control();
    }
}

uint8_t halWT41FcUart_get_free_buffer_space(void)
{
    uint8_t free_buffer_space = 0;

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

    return free_buffer_space;
}
