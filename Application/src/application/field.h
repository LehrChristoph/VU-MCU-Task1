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


#ifndef FIELD_DEFAULT_SPEED
    #define FIELD_DEFAULT_SPEED 30
#endif

#ifndef FIELD_SPEED_INCREASE_INTERVAL
    #define FIELD_SPEED_INCREASE_INTERVAL 10
#endif

#ifndef FIELD_MIN_SPEED
    #define FIELD_MIN_SPEED 5
#endif

#ifndef FIELD_BALL_RADIUS
    #define FIELD_BALL_RADIUS 2
#endif

#ifndef FIELD_GLCD_HEIGTH
    #define FIELD_GLCD_HEIGTH 64
#endif

#ifndef FIELD_GLCD_WIDTH
    #define FIELD_GLCD_WIDTH 128
#endif

#ifndef FIELD_STRING_POSITION_Y
    #define FIELD_STRING_POSITION_Y 9
#endif

#ifndef FIELD_TITLE_STRING_POSITION_X
    #define FIELD_TITLE_STRING_POSITION_X 10
#endif

#ifndef FIELD_GAME_OVER_STRING_POSITION_X
    #define FIELD_GAME_OVER_STRING_POSITION_X 13
#endif

#ifndef FIELD_NEW_CORE_POSITION_X
    #define FIELD_NEW_CORE_POSITION_X 5
#endif

#ifndef FIELD_BARRIER_INTERVAL
    #define FIELD_BARRIER_INTERVAL 10
#endif

#ifndef FIELD_BARRIER_ARRAY_SIZE
    #define FIELD_BARRIER_ARRAY_SIZE 8
#endif

#ifndef FIELD_BARRIER_BLOCK_WIDTH
    #define FIELD_BARRIER_BLOCK_WIDTH 8
#endif

#ifndef FIELD_BALL_INIT_POSITION
    #define FIELD_BALL_INIT_POSITION FIELD_GLCD_WIDTH/2
#endif

#define ERROR_WII_INIT      1
#define ERROR_WII_CONNECT   2
#define ERROR_WII_SET_LEDS  3
#define ERROR_WII_SET_ACCL  4

typedef struct __field_barrier
{
    uint16_t seed;
    uint8_t glcd_position;
} field_barrier;


void field_init(void);

void field_updated_local_game_state(game_state_t new_game_state);

void field_display_connect(uint8_t *mac_address);

void field_display_error(uint8_t error_code);

void field_display_ready_to_start(void);

void field_reset_field(void);

#endif
