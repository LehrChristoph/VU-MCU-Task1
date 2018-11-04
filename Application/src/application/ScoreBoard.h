/*
 * ScoreBoard.h
 *
 *  Created on: 3 Nov 2018
 *      Author: christoph
 */

#ifndef APPLICATION_SCORE_BOARD_H
#define APPLICATION_SCORE_BOARD_H

#include <avr/io.h>

#ifndef SCORE_BOARD_SIZE
    #define SCORE_BOARD_SIZE 5
#endif

#ifndef SCORE_BOARD_BOTOM
    #define SCORE_BOARD_BOTOM 60
#endif

#ifndef SCORE_BOARD_ENTRY_IVERVAL
    #define SCORE_BOARD_ENTRY_IVERVAL 9
#endif

typedef struct __core_entry
{
    uint16_t score;
    char player[6];
} score_t;

void ScoreBoard_init(void);

uint8_t ScoreBoard_new_score(score_t score);

void ScoreBoard_display(uint8_t highlight_entry);

#endif
