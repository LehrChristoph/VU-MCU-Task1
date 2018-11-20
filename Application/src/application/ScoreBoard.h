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

#ifndef SCORE_BOARD_TOP
    #define SCORE_BOARD_TOP 9
#endif

#ifndef SCORE_BOARD_BOTOM
    #define SCORE_BOARD_BOTOM 54
#endif

#ifndef SCORE_BOARD_ENTRY_INTERVAL
    #define SCORE_BOARD_ENTRY_INTERVAL 9
#endif

#ifndef SCORE_BOARD_LEFT_INTENT
    #define SCORE_BOARD_LEFT_INTENT 10
#endif

#ifndef SCORE_BOARD_CHAR_POS_Y
    #define SCORE_BOARD_CHAR_POS_Y 25
#endif

#ifndef SCORE_BOARD_CHAR_POS_X
    #define SCORE_BOARD_CHAR_POS_X 10
#endif

#ifndef SCORE_BOARD_CHAR_INTERVAL
    #define SCORE_BOARD_CHAR_INTERVAL 6
#endif

#ifndef SCORE_BOARD_PLAYER_LENGTH
    #define SCORE_BOARD_PLAYER_LENGTH 3
#endif

#ifndef SCORE_BOARD_START_CHAR
    #define SCORE_BOARD_START_CHAR 32
#endif

#ifndef SCORE_BOARD_END_CHAR
    #define SCORE_BOARD_END_CHAR 126
#endif

typedef struct __core_entry
{
    uint16_t score;
    char player[SCORE_BOARD_PLAYER_LENGTH+1];
} score_t;

void ScoreBoard_init(void);

uint8_t ScoreBoard_new_score(uint16_t score);

void ScoreBoard_display(uint8_t highlight_entry);

void ScoreBoard_init_new_player(void);

void ScoreBoard_next_char_in_list(void);

void ScoreBoard_priv_char_in_list(void);

void ScoreBoard_next_char_for_name(void);

void ScoreBoard_priv_char_for_name(void);

void ScoreBoard_store_player_name(void);

#endif
