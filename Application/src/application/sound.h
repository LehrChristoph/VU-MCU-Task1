/*
 * sound.h
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include <avr/io.h>


#ifndef APPLICATION_SOUND_H_
#define APPLICATION_SOUND_H_

// set how many block shall be stored in the buffer
#ifndef SOUND_BLOCK_BUFFER_SIZE
    #define SOUND_BLOCK_BUFFER_SIZE 2
#endif

#define SOUND_BUFFER_SIZE SOUND_BLOCK_BUFFER_SIZE*4

void sound_init(void);

#endif
