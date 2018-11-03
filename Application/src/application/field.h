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


typedef struct __field_barrier
{
    uint16_t seed;
    uint8_t glcd_position;
} field_barrier;


void field_init(void);

void field_updated_local_game_state(game_state_t new_game_state);

#endif
