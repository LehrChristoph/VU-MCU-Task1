/*
 * sound.h
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include <avr/io.h>


#ifndef APPLICATION_SOUND_H_
#define APPLICATION_SOUND_H_

// sets how big the ADC ring buffer shall be
#ifndef SOUND_VOLUME_BUFFER_SIZE
    #define SOUND_VOLUME_BUFFER_SIZE 5
#endif

void sound_init(void);

void sound_send_data(void);

void sound_add_volume_val(uint8_t sound_input);

void sound_set_volume(void);

void sound_read_data(void);

void sound_start_playing_startup(void);

void sound_start_playing_theme(void);

void sound_play_game_over(void);

#endif
