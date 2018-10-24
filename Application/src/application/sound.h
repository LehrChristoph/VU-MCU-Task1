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

inline void sound_add_volume_val(uint8_t) __attribute__((always_inline)); // optimize function

#endif
