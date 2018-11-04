/*
 * ScoreBoard.c
 *
 *  Created on: 3 Nov 2018
 *      Author: christoph
 */

#include "ScoreBoard.h"

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "glcd.h"
#include "Standard5x7.h"

static score_t score_board[SCORE_BOARD_SIZE];
static uint16_t score_board_min;
static uint16_t score_board_max;

const char default_acronym[] PROGMEM = "-----";
const char score_format[] PROGMEM = "%d %s %5d";

void ScoreBoard_init(void)
{
    for(uint8_t i=0; i< SCORE_BOARD_SIZE; i++)
    {
        score_board[i].score = 0;
        strcpy_P(score_board[i].player, default_acronym);
    }
    score_board_min = 0;
    score_board_max = 0;
}


uint8_t ScoreBoard_new_score(score_t score)
{
    if(score.score > score_board_min)
    {
        //find position where
        for(uint8_t i=SCORE_BOARD_SIZE-2; (i >=1 && i < SCORE_BOARD_SIZE); i--)
        {
            score_board[i+1] = score_board[i];

            if(score_board[i-1].score > score.score)
            {
                score_board[i] = score;
                return i+1;
            }
        }
        score_board[0] = score;
        return 1;
    }

    return SCORE_BOARD_SIZE;
}


void ScoreBoard_display(uint8_t highlight_entry)
{
    xy_point score_position;
    score_position.x = 10;
    score_position.y = SCORE_BOARD_BOTOM;

    for(uint8_t i=SCORE_BOARD_SIZE; i>0; i--)
    {
        char score_output[14];
        char format[10];

        strcpy_P(format, score_format);
        sprintf(score_output, format, i, score_board[i-1].player, score_board[i-1].score);

        if(i == highlight_entry)
        {
            xy_point left_bottom, right_top;

            left_bottom.y = score_position.y -1;
            left_bottom.x = 0;

            right_top.y = left_bottom.y + SCORE_BOARD_ENTRY_IVERVAL;
            right_top.x = 127;

            glcdFillRect(left_bottom, right_top, glcdSetPixel);
            glcdDrawText(score_output, score_position, &Standard5x7, glcdClearPixel);
        }
        else
        {
            glcdDrawText(score_output, score_position, &Standard5x7, glcdSetPixel);
        }

        score_position.y += SCORE_BOARD_ENTRY_IVERVAL;
    }
}
