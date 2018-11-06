/*
 * PinChangeInterrupts.c
 *
 *  Created on: 29 Nov 2017
 *      Author: christoph
 */

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "PinChangeInterrupts.h"

void (*bank0_callback)(void);
void (*bank1_callback)(void);
void (*bank2_callback)(void);

#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
void (*pin0_callback)(void);
void (*pin1_callback)(void);
void (*pin2_callback)(void);
void (*pin3_callback)(void);
void (*pin4_callback)(void);
void (*pin5_callback)(void);
void (*pin6_callback)(void);
void (*pin7_callback)(void);

void (*pin8_callback)(void);
void (*pin9_callback)(void);
void (*pin10_callback)(void);
void (*pin11_callback)(void);
void (*pin12_callback)(void);
void (*pin13_callback)(void);
void (*pin14_callback)(void);
void (*pin15_callback)(void);

void (*pin16_callback)(void);
void (*pin17_callback)(void);
void (*pin18_callback)(void);
void (*pin19_callback)(void);
void (*pin20_callback)(void);
void (*pin21_callback)(void);
void (*pin22_callback)(void);
void (*pin23_callback)(void);

volatile uint8_t bank0_pin_states = 0x00;
volatile uint8_t bank1_pin_states = 0x00;
volatile uint8_t bank2_pin_states = 0x00;

#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN

void (*external_interrupt_0_callback)(void);
void (*external_interrupt_1_callback)(void);
void (*external_interrupt_2_callback)(void);
void (*external_interrupt_3_callback)(void);
void (*external_interrupt_4_callback)(void);
void (*external_interrupt_5_callback)(void);
void (*external_interrupt_6_callback)(void);
void (*external_interrupt_7_callback)(void);

void PinChangeInterrupts_bank0_enable_interrupt(void){
    PCICR |= (1 << PCIE0);
}

void PinChangeInterrupts_bank0_disable_interrupt(void){
	PCICR &= ~(1 << PCIE0);
}

void PinChangeInterrupts_bank1_enable_interrupt(void){
	PCICR |= (1 << PCIE1);
}

void PinChangeInterrupts_bank1_disable_interrupt(void){
	PCICR &= ~(1 << PCIE1);
}

void PinChangeInterrupts_bank2_enable_interrupt(void){
	PCICR |= (1 << PCIE2);
}

void PinChangeInterrupts_bank2_disable_interrupt(void){
	PCICR &= ~(1 << PCIE2);
}

void PinChangeInterrupts_bank0_enable(uint8_t pin){
	PCMSK0 |= pin;
}

void PinChangeInterrupts_bank0_disable(uint8_t pin){
	PCMSK0 &= ~pin;
}

void PinChangeInterrupts_bank1_enable(uint8_t pin){
	PCMSK1 |= pin;
}

void PinChangeInterrupts_bank1_disable(uint8_t pin){
	PCMSK1 &= ~pin;
}

void PinChangeInterrupts_bank2_enable(uint8_t pin){
	PCMSK2 |= pin;
}

void PinChangeInterrupts_bank2_disable(uint8_t pin){
	PCMSK2 &= ~pin;
}

void PinChangInterrupts_bank0_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void)){
	switch(pin){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
		case PIN_CHANGE_INTERRUPTS_PCINT0:
			pin0_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT1:
			pin1_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT2:
			pin2_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT3:
			pin3_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT4:
			pin4_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
        case PIN_CHANGE_INTERRUPTS_PCINT5:
			pin5_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT6:
			pin6_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT7:
			pin7_callback = pin_change_interrupt_callback;
            bank0_callback = null;
			break;
#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        default:
            bank0_callback = pin_change_interrupt_callback;
            break;
	}
}

void PinChangInterrupts_bank1_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void)){
	switch(pin){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
		case PIN_CHANGE_INTERRUPTS_PCINT8:
			pin8_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT9:
			pin9_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT10:
			pin10_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT11:
			pin11_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT12:
			pin12_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
        case PIN_CHANGE_INTERRUPTS_PCINT13:
			pin13_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT14:
			pin14_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT15:
			pin15_callback = pin_change_interrupt_callback;
            bank1_callback = null;
			break;
#endif //PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        default:
            bank1_callback = pin_change_interrupt_callback;
            break;
	}
}

void PinChangInterrupts_bank2_set_callback(uint8_t pin, void (*pin_change_interrupt_callback)(void)){
	switch(pin){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
		case PIN_CHANGE_INTERRUPTS_PCINT16:
			pin0_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT17:
			pin17_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT18:
			pin18_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT19:
			pin19_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT20:
			pin20_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
        case PIN_CHANGE_INTERRUPTS_PCINT21:
			pin21_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCINT22:
			pin22_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
		case PIN_CHANGE_INTERRUPTS_PCIN23:
			pin23_callback = pin_change_interrupt_callback;
            bank2_callback = null;
			break;
#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        default:
            bank2_callback = pin_change_interrupt_callback;
            break;
	}
}

void PinCahngeInterrupts_enable_external_interupt(uint8_t pin, uint8_t mode, void (*external_interrupt_callback)(void)){
	EIMSK |= pin;

	switch(mode){
		case EXTERNAL_INTERRUPT_0:
            EICRA |= mode;
            EICRA &= ~(0xFB | mode);
            external_interrupt_0_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_1:
            EICRA |= (mode << 2);
            EICRA &= ~(0xF3 | (mode << 2));
            external_interrupt_1_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_2:
            EICRA |= (mode << 4);
            EICRA &= ~(0xBF | (mode << 4));
            external_interrupt_2_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_3:
            EICRA |= (mode << 6);
            EICRA &= ~(0x3F | (mode << 6));
            external_interrupt_3_callback = external_interrupt_callback;
            break;
		case EXTERNAL_INTERRUPT_4:
            EICRB |= mode;
            EICRB &= ~(0xFB | mode);
            external_interrupt_4_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_5:
            EICRB |= (mode << 2);
            EICRB &= ~(0xF3 | (mode << 2));
            external_interrupt_5_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_6:
            EICRB |= (mode << 4);
            EICRB &= ~(0xBF | (mode << 4));
            external_interrupt_6_callback = external_interrupt_callback;
            break;
        case EXTERNAL_INTERRUPT_7:
            EICRB |= (mode << 6);
            EICRB &= ~(0x3F | (mode << 6));
            external_interrupt_7_callback = external_interrupt_callback;
            break;
	}

}

void PinCahngeInterrupts_disable_external_interupt(uint8_t pin){
	EIMSK &= ~(pin);
}

ISR(INT0_vect){
	(*external_interrupt_0_callback)();
}

ISR(INT1_vect){
	(*external_interrupt_1_callback)();
}

ISR(INT2_vect){
	(*external_interrupt_2_callback)();
}

ISR(INT3_vect){
	(*external_interrupt_3_callback)();
}

ISR(INT4_vect){
	(*external_interrupt_4_callback)();
}

ISR(INT5_vect){
	(*external_interrupt_5_callback)();
}

ISR(INT6_vect){
	(*external_interrupt_6_callback)();
}

ISR(INT7_vect){
	(*external_interrupt_7_callback)();
}

ISR(PCINT0_vect){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
	uint8_t new_pin_states = PINB;
	uint8_t diffs = (bank0_pin_states ^ new_pin_states) & PCMSK0;
	bank0_pin_states = new_pin_states;

    if(bank0_callback != null)
    {
#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        (*bank0_callback)();
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
    }

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT0) > 0){
		(*pin0_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT1) > 0){
		(*pin1_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT2) > 0){
		(*pin2_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT3) > 0){
		(*pin3_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT4) > 0){
		(*pin4_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT5) > 0){
		(*pin5_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT6) > 0){
		(*pin6_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT7) > 0){
		(*pin7_callback)();
	}
#endif //PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
}

ISR(PCINT1_vect){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
	uint8_t new_pin_states = (PINJ << 1) | (PINE & 0x01);
	uint8_t diffs = (bank1_pin_states ^ new_pin_states) & PCMSK1;
	bank1_pin_states = new_pin_states;

    if(bank1_callback != null)
    {
#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        (*bank1_callback)();
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
    }

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT8) > 0){
		(*pin8_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT9) > 0){
		(*pin9_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT10) > 0){
		(*pin10_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT11) > 0){
		(*pin11_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT12) > 0){
		(*pin12_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT13) > 0){
		(*pin13_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT14) > 0){
		(*pin14_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT14) > 0){
		(*pin14_callback)();
	}
#endif //PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
}

ISR(PCINT2_vect){
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
	uint8_t new_pin_states = PINK;
	uint8_t diffs = (bank2_pin_states ^ new_pin_states) & PCMSK2;
	bank2_pin_states = new_pin_states;

    if(bank2_callback != null)
    {
#endif // PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
        (*bank2_callback)();
#ifdef PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
    }

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT16) > 0){
		(*pin16_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT17) > 0){
		(*pin17_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT18) > 0){
		(*pin18_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT19) > 0){
		(*pin19_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT20) > 0){
		(*pin20_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT21) > 0){
		(*pin21_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT22) > 0){
		(*pin22_callback)();
	}

	if((diffs & PIN_CHANGE_INTERRUPTS_PCINT22) > 0){
		(*pin22_dcallback)();
	}
#endif //PIN_CHANGE_INTERRUPTS_ENABLE_SINGLE_PIN
}
