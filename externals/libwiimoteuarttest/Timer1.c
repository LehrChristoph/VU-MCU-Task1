/*
 * Timer1.c
 *
 *  Created on: 5 Oct 2018
 *      Author: christoph
 */

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "Timer1.h"

void (*timer1_overflow_callback)(void);
void (*timer1_output_compare_match_A_callback)(void);
void (*timer1_output_compare_match_B_callback)(void);
void (*timer1_output_compare_match_C_callback)(void);
void (*timer1_input_capture_callback)(uint16_t);

void timer1_set_prescaler(uint8_t prescaler)
{
    TCCR1B |= prescaler;
    TCCR1B &= (0xF8 | prescaler);
}

void timer1_set_waveform_generation_mode(uint8_t mode){

    uint8_t top = mode & 0x08;
    top = top << 1;
    uint8_t bottom = mode & 0x03;

    TCCR1A |= bottom;
    TCCR1A &= (0xFB | bottom);

    TCCR1B |= top;
    TCCR1B &= (0xF7 | top);
}

void timer1_activate_output_A(uint8_t mode)
{
    uint8_t tmp = (mode & 0x03) << 6;
    TCCR1A |= tmp;
    TCCR1A &= (0x3F | tmp);
}

void timer1_activate_output_B(uint8_t mode){
    uint8_t tmp = (mode & 0x03) << 4;
    TCCR1A |= tmp;
    TCCR1A &= (0xBF | tmp);
}

void timer1_activate_output_C(uint8_t mode){
    uint8_t tmp = (mode & 0x03) << 2;
    TCCR1A |= tmp;
    TCCR1A &= (0xF3 | tmp);
}

void timer1_enable_overflow_interrupt(void (*callback)(void)){
	timer1_overflow_callback = callback;
	TIMSK1 |= (1 << TOIE1);
}

void timer1_enable_output_compare_interrupt_A(void (*callback)(void)){
	timer1_output_compare_match_A_callback = callback;
	TIMSK1 |= (1 << OCIE1A);
}

void timer1_disable_output_compare_interrupt_A(void){
	TIMSK1 &= ~(1 << OCIE1A);
}

void timer1_enable_output_compare_interrupt_B(void (*callback)(void)){
	timer1_output_compare_match_B_callback = callback;
	TIMSK1 |= (1 << OCIE1B);
}

void timer1_enable_output_compare_interrupt_C(void (*callback)(void)){
	timer1_output_compare_match_C_callback = callback;
	TIMSK1 |= (1 << OCIE1C);
}

void timer1_set_output_compare_A(uint16_t value){
	OCR1A = value;
}

void timer1_increase_output_compare_A(uint16_t value){
	uint16_t temp = OCR1A;
	if(temp + value > temp){
		OCR1A = value + temp;
	}else{
		OCR1A = 0xFFFF;
	}
}

void timer1_decrease_output_compare_A(uint16_t value){
	uint16_t temp = OCR1A;
	if(temp - value  > OCR1A){
		OCR1A = 0x0000;
	}else{
		OCR1A = temp - value;
	}
}

uint16_t timer1_get_output_compare_A(void){
	return OCR1A;
}

void timer1_set_output_compare_B(uint16_t value){
	OCR1B = value;
}

void timer1_increase_output_compare_B(uint16_t value){
	uint16_t temp = OCR1B;
	if(temp + value > temp){
		OCR1B = value + temp;
	}else{
		OCR1B = 0xFFFF;
	}
}

void timer1_decrease_output_compare_B(uint16_t value){
	uint16_t temp = OCR1B ;
	if(temp - value  > temp){
		OCR1B = 0x0000;
	}else{
		OCR1B = temp - value;
	}
}

uint16_t timer1_get_output_compare_B(void){
	return OCR1B;
}

void timer1_set_output_compare_C(uint16_t value){
	OCR1C = value;
}

void timer1_increase_output_compare_C(uint16_t value){
	uint16_t temp = OCR1C;
	if(temp + value > temp){
		OCR1C = value + temp;
	}else{
		OCR1C = 0xFFFF;
	}
}

void timer1_decrease_output_compare_C(uint16_t value){
	uint16_t temp = OCR1C ;
	if(temp - value  > temp){
		OCR1C = 0x0000;
	}else{
		OCR1C = temp - value;
	}
}

uint16_t timer1_get_output_compare_C(void){
	return OCR1C;
}

void timer1_reset_counter(void)
{
    TCNT1 = 0x0000;
}

void timer1_enable_input_capture_interrupt(void)
{
    TIMSK1 |= (1<<ICIE1);
}

void timer1_disable_input_capture_interrupt(void)
{
    TIMSK1 &= ~(1<<ICIE1);
}

ISR(TIMER1_OVF_vect){
	(*timer1_overflow_callback)();
}

ISR(TIMER1_COMPA_vect){
	(*timer1_output_compare_match_A_callback)();
}

ISR(TIMER1_COMPB_vect){
	(*timer1_output_compare_match_B_callback)();
}

ISR(TIMER1_COMPC_vect){
	(*timer1_output_compare_match_C_callback)();
}

ISR(TIMER1_CAPT_vect){
    uint16_t input_capture = ICR1;
    TCNT1=0;
	(*timer1_input_capture_callback)(input_capture);
}
