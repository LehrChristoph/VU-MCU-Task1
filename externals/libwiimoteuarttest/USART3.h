/*
 * USART3.h
 *
 *  Created on: 30 Sep 2018
 *      Author: christoph
 */

#ifndef AVR_LIBS_UART3_H_
#define AVR_LIBS_UART3_H_

#include <avr/io.h>
#include "PinChangeInterrupts.h"

#ifndef USART3_BUFFER_SIZE
    #define USART3_BUFFER_SIZE 256
#endif

#if USART3_BUFFER_SIZE > 0xFFFF
    #error USART3: only buffer sizes up to 65k are supported
#endif

#if USART3_BUFFER_SIZE < 2
    #error USART3: buffer has to be at leas of size 2
#endif

#if defined(USART3_DOUBLE_SPEED)
    #define USART3_CLOCK (F_CPU/8)
#elif defined(USART3_SYNCHRONUS)
    #define USART3_CLOCK (F_CPU/2)
#else
    #define USART3_CLOCK (F_CPU/16)
#endif

#define USART3_PORT_FC PORTJ
#define USART3_DDR_FC DDRJ
#define USART3_PIN_FC PINJ
#define USART3_CTS_FC PORTJ3
#define USART3_RTS_FC PORTJ2
#define USART3_PCINT_PIN PIN_CHANGE_INTERRUPTS_PCINT11

typedef enum {
	USART3_SEND_ENABLED,
	USART3_DISABLE_SEND,
	USART3_SEND_DISABLED,
} usart3_flow_control_t;

// calculation for baudrate based on input clock
#define USART3_BAUDRATE_2400    (USART3_CLOCK/2400)-1
#define USART3_BAUDRATE_4800    (USART3_CLOCK/4800)-1
#define USART3_BAUDRATE_9600    (USART3_CLOCK/9600)-1
#define USART3_BAUDRATE_14_4_k  (USART3_CLOCK/14400)-1
#define USART3_BAUDRATE_19_2_k  (USART3_CLOCK/19200)-1
#define USART3_BAUDRATE_28_8_k  (USART3_CLOCK/28800)-1
#define USART3_BAUDRATE_38_4_k  (USART3_CLOCK/38400)-1
#define USART3_BAUDRATE_57_6_k  (USART3_CLOCK/57600)-1
#define USART3_BAUDRATE_76_8_k  (USART3_CLOCK/78600)-1
#define USART3_BAUDRATE_115_2_k (USART3_CLOCK/115200)-1
#define USART3_BAUDRATE_230_4_k (USART3_CLOCK/230400)-1
#define USART3_BAUDRATE_250_k   (USART3_CLOCK/250000)-1
#define USART3_BAUDRATE_500_k   (USART3_CLOCK/500000)-1
#define USART3_BAUDRATE_1_M     (USART3_CLOCK/1000000)-1

#define USART3_PARITY_DISABLED 0
#define USART3_PARITY_EVEN 2
#define USART3_PARITY_ODD 3

#define USART3_STOP_BITS_1 0
#define USART3_STOP_BITS_2 1

#define USART3_CHAR_SIZE_5_BIT 0
#define USART3_CHAR_SIZE_6_BIT 1
#define USART3_CHAR_SIZE_7_BIT 2
#define USART3_CHAR_SIZE_8_BIT 3
// is currently not implemented
// #define USART3_CHAR_SIZE_9_BIT 7

void USART3_inits(uint8_t baudrate, uint8_t stop_bits, uint8_t parity, uint8_t char_size);

void USART3_set_clock_polarity_rising_edge(void);

void USART3_set_clock_polarity_falling_edge(void);

void USART3_enable_receiver(void (*callback)(uint8_t));

void USART3_disable_receiver(void);

void USART3_enable_transmitter(void (*callback)(void));

void USART3_disable_transmitter(void);

uint8_t USART3_write_byte(uint8_t data_byte);

uint8_t USART3_write_string(char *data_string, uint16_t length);

uint16_t USART3_get_free_buffer_space(void);

void USART3_set_flow_control(void);

void USART3_clear_flow_control(void);

#endif
