/*
 * field.h
 *
 *  Created on: 24 Oct 2018
 *      Author: christoph
 */

#ifndef APPLICATION_FIELD_H_
#define APPLICATION_FIELD_H_

#include <avr/io.h>
#include "game.h"

#ifndef FIELD_BARRIER_INTERVAL
    #define FIELD_BARRIER_INTERVAL 10
#endif

#ifndef FIELD_DEFAULT_SPEED
    #define FIELD_DEFAULT_SPEED 25
#endif

#ifndef FIELD_BALL_RADIUS
    #define FIELD_BALL_RADIUS 3
#endif

#ifndef FIELD_GLCD_HEIGTH
    #define FIELD_GLCD_HEIGTH 64
#endif

#ifndef FIELD_STRING_POSITION_Y
    #define FIELD_STRING_POSITION_Y 32
#endif

#ifndef FIELD_TITLE_STRING_POSITION_X
    #define FIELD_TITLE_STRING_POSITION_X 10
#endif

#ifndef FIELD_GAME_OVER_STRING_POSITION_X
    #define FIELD_GAME_OVER_STRING_POSITION_X 13
#endif

#ifndef FIELD_BARRIER_ARRAY_SIZE
    #define FIELD_BARRIER_ARRAY_SIZE 8
#endif

#ifndef FIELD_BARRIER_BLOCK_WIDTH
    #define FIELD_BARRIER_BLOCK_WIDTH 8
#endif

#ifndef FIELD_BALL_INIT_POSITION
    #define FIELD_BALL_INIT_POSITION 64
#endif

typedef struct __field_barrier
{
    uint16_t seed;
    uint8_t glcd_position;
} field_barrier;

typedef enum {
	FIELD_DISPLAY_READY,
    FIELD_ALREADY_DISPLAYED,
} display_state_t;


void field_init(void);

void field_updated_local_game_state(game_state_t new_game_state);

#endif
