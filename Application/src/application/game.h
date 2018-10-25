/*
 * game.h
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include <avr/io.h>

#ifndef APPLICATION_GAME_H_
#define APPLICATION_GAME_H_

typedef enum {
	ADC_MODE_VOLUME	= 0,
	ADC_MODE_LFSR	= 1,
} adc_mode_t;

void game_init(void);

void game_timer_callback(void);

void game_ADC_callback(uint16_t adc_val);

void game_start(void);

#endif
