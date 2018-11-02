/*
 * PinChangeInterrupts.h
 *
 *  Created on: 29 Nov 2017
 *      Author: christoph
 */

#include <avr/io.h>

#ifndef AVR_LIBS_PINCHANGEINTERRUPTS_C_
#define AVR_LIBS_PINCHANGEINTERRUPTS_C_

#define PIN_CHANGE_WHOLE_BANK 0

#define PIN_CHANGE_INTERRUPTS_PCINT0 1
#define PIN_CHANGE_INTERRUPTS_PCINT1 2
#define PIN_CHANGE_INTERRUPTS_PCINT2 4
#define PIN_CHANGE_INTERRUPTS_PCINT3 8
#define PIN_CHANGE_INTERRUPTS_PCINT4 16
#define PIN_CHANGE_INTERRUPTS_PCINT5 32
#define PIN_CHANGE_INTERRUPTS_PCINT6 64
#define PIN_CHANGE_INTERRUPTS_PCINT7 128

#define PIN_CHANGE_INTERRUPTS_PCINT8 1
#define PIN_CHANGE_INTERRUPTS_PCINT9 2
#define PIN_CHANGE_INTERRUPTS_PCINT10 4
#define PIN_CHANGE_INTERRUPTS_PCINT11 8
#define PIN_CHANGE_INTERRUPTS_PCINT12 16
#define PIN_CHANGE_INTERRUPTS_PCINT13 32
#define PIN_CHANGE_INTERRUPTS_PCINT14 64
#define PIN_CHANGE_INTERRUPTS_PCINT15 128

#define PIN_CHANGE_INTERRUPTS_PCINT16 1
#define PIN_CHANGE_INTERRUPTS_PCINT17 2
#define PIN_CHANGE_INTERRUPTS_PCINT18 4
#define PIN_CHANGE_INTERRUPTS_PCINT19 8
#define PIN_CHANGE_INTERRUPTS_PCINT20 16
#define PIN_CHANGE_INTERRUPTS_PCINT21 32
#define PIN_CHANGE_INTERRUPTS_PCINT22 64
#define PIN_CHANGE_INTERRUPTS_PCINT23 128

#define EXTERNAL_INTERRUPT_0 1
#define EXTERNAL_INTERRUPT_1 2
#define EXTERNAL_INTERRUPT_2 4
#define EXTERNAL_INTERRUPT_3 8
#define EXTERNAL_INTERRUPT_4 16
#define EXTERNAL_INTERRUPT_5 32
#define EXTERNAL_INTERRUPT_6 64
#define EXTERNAL_INTERRUPT_7 128

#define EXTERNAL_INTERRUPT_ON_LOW_LEVEL 0
#define EXTERNAL_INTERRUPT_ON_LEVEL_CHANGE 1
#define EXTERNAL_INTERRUPT_ON_FALLING_EDGE 2
#define EXTERNAL_INTERRUPT_ON_RISING_EDGE 3

void PinChangeInterrupts_bank0_enable_interrupt(void);

void PinChangeInterrupts_bank0_disable_interrupt(void);

void PinChangeInterrupts_bank1_enable_interrupt(void);

void PinChangeInterrupts_bank1_disable_interrupt(void);

void PinChangeInterrupts_bank2_enable_interrupt(void);

void PinChangeInterrupts_bank2_disable_interrupt(void);

void PinChangeInterrupts_bank0_enable(uint8_t pin);

void PinChangeInterrupts_bank0_disable(uint8_t pin);

void PinChangeInterrupts_bank1_enable(uint8_t pin);

void PinChangeInterrupts_bank1_disable(uint8_t pin);

void PinChangeInterrupts_bank2_enable(uint8_t pin);

void PinChangeInterrupts_bank2_disable(uint8_t pin);

void PinChangInterrupts_bank0_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void));

void PinChangInterrupts_bank1_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void));

void PinChangInterrupts_bank2_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void));

void PinCahngeInterrupts_enable_external_interupt(uint8_t pin, uint8_t mode, void (*external_interrupt_callback)(void));

void PinCahngeInterrupts_disable_external_interupt(uint8_t pin);

#endif /* AVR_LIBS_PINCHANGEINTERRUPTS_C_ */
