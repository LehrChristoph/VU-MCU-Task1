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
#include <string.h>

#include "glcd.h"
#include "Standard5x7.h"

static score_t score_board[SCORE_BOARD_SIZE];
static uint16_t score_board_min;

const char score_format[] PROGMEM = "%d %3s %5d";
const char continue_str[] PROGMEM = "Press A to continue";

static uint8_t current_char_from_table = 32;
static char player_name[3];
static uint8_t current_char_position;
static xy_point char_point;
static uint8_t current_hs_postion;


void ScoreBoard_init(void)
{
    for(uint8_t i=0; i< SCORE_BOARD_SIZE; i++)
    {
        score_board[i].score = 0;
    }
    score_board_min = 0;
}


uint8_t ScoreBoard_new_score(uint16_t score)
{
    if(score > score_board_min)
    {
        ScoreBoard_init_new_player();

        //find position where
        for(int8_t i=SCORE_BOARD_SIZE-1; i >0 ; i--)
        {
            if(i < SCORE_BOARD_SIZE-1 )
            {
                score_board[i+1].score = score_board[i].score;
                strncpy(score_board[i+1].player, score_board[i].player,SCORE_BOARD_PLAYER_LENGTH);
            }

            if(score_board[i-1].score >= score)
            {
                score_board[i].score = score;
                current_hs_postion=i;

                score_board_min = score_board[SCORE_BOARD_SIZE-1].score;

                return i+1;
            }

        }
        score_board[1].score = score_board[0].score;
        strncpy(score_board[1].player, score_board[0].player,SCORE_BOARD_PLAYER_LENGTH);
        score_board[0].score = score;
        current_hs_postion = 0;

        score_board_min = score_board[SCORE_BOARD_SIZE-1].score;

        return 1;
    }
    current_hs_postion = SCORE_BOARD_SIZE;
    return 0;
}


void ScoreBoard_display(uint8_t highlight_entry)
{
    xy_point score_position;
    score_position.x = SCORE_BOARD_LEFT_INTENT;
    score_position.y = SCORE_BOARD_BOTOM;

    xy_point message_clear_point_1 ;
    message_clear_point_1.x = 0;
    message_clear_point_1.y = SCORE_BOARD_BOTOM;

    xy_point message_clear_point_2 ;
    message_clear_point_2.x = 127;
    message_clear_point_2.y = SCORE_BOARD_BOTOM - SCORE_BOARD_SIZE * SCORE_BOARD_ENTRY_INTERVAL;

    glcdFillRect(message_clear_point_1, message_clear_point_2, glcdClearPixel);

    for(uint8_t i=SCORE_BOARD_SIZE; i>0; i--)
    {
        if(score_board[i-1].score > 0)
        {
            char score_output[14];
            char format[12];

            strcpy_P(format, score_format);
            sprintf(score_output, format, i, score_board[i-1].player, score_board[i-1].score);


            if(i == highlight_entry)
            {
                xy_point left_bottom, right_top;

                left_bottom.y = score_position.y ;
                left_bottom.x = 0;

                right_top.y = left_bottom.y - SCORE_BOARD_ENTRY_INTERVAL +1;
                right_top.x = 127;

                glcdFillRect(left_bottom, right_top, glcdSetPixel);
                glcdDrawText(score_output, score_position, &Standard5x7, glcdClearPixel);
            }
            else
            {
                glcdDrawText(score_output, score_position, &Standard5x7, glcdSetPixel);
            }
        }
        score_position.y -= SCORE_BOARD_ENTRY_INTERVAL;
    }
}

void ScoreBoard_init_new_player(void)
{
    char_point.x = SCORE_BOARD_CHAR_POS_X;
    char_point.y = SCORE_BOARD_CHAR_POS_Y;

    for(uint8_t i=0; i<SCORE_BOARD_PLAYER_LENGTH; i++)
    {
        glcdDrawChar('A', char_point, &Standard5x7, glcdSetPixel);
        player_name[i]='A';

        char_point.x += SCORE_BOARD_CHAR_INTERVAL;
    }
    current_char_from_table = 'A';
    char_point.x = SCORE_BOARD_CHAR_POS_X;

    xy_point cursor_point_1 ;
    cursor_point_1.x = char_point.x;
    cursor_point_1.y = char_point.y+2;

    xy_point cursor_point_2 ;
    cursor_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;
    cursor_point_2.y = char_point.y+2;

    glcdFillRect(cursor_point_1, cursor_point_2, glcdSetPixel);


    xy_point message_point ;
    message_point.x = 5;
    message_point.y = 50;
    glcdDrawTextPgm(continue_str, message_point, &Standard5x7, glcdSetPixel);

}

void ScoreBoard_next_char_in_list(void)
{
    current_char_from_table++;
    if (current_char_from_table > SCORE_BOARD_END_CHAR)
    {
        current_char_from_table = SCORE_BOARD_START_CHAR;
    }

    xy_point message_clear_point_2 ;
    message_clear_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;
    message_clear_point_2.y = char_point.y-8;

    glcdFillRect(char_point, message_clear_point_2, glcdClearPixel);

    char output = current_char_from_table;
    player_name[current_char_position] = output;
    glcdDrawChar(output, char_point, &Standard5x7, glcdSetPixel);

}

void ScoreBoard_priv_char_in_list(void)
{
    current_char_from_table--;
    if (current_char_from_table < SCORE_BOARD_START_CHAR)
    {
        current_char_from_table = SCORE_BOARD_END_CHAR;
    }

    xy_point message_clear_point_2 ;
    message_clear_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;
    message_clear_point_2.y = char_point.y-8;

    glcdFillRect(char_point, message_clear_point_2, glcdClearPixel);

    char output = current_char_from_table;
    player_name[current_char_position] = output;
    glcdDrawChar(output, char_point, &Standard5x7, glcdSetPixel);
}

void ScoreBoard_next_char_for_name(void)
{
    xy_point cursor_point_1 ;
    cursor_point_1.x = char_point.x;
    cursor_point_1.y = char_point.y+2;

    xy_point cursor_point_2 ;
    cursor_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;
    cursor_point_2.y = char_point.y+2;

    glcdFillRect(cursor_point_1, cursor_point_2, glcdClearPixel);

    current_char_position++;

    if(current_char_position >= SCORE_BOARD_PLAYER_LENGTH)
    {
        current_char_position=0;
        char_point.x = SCORE_BOARD_CHAR_POS_X;
    }
    else
    {
        char_point.x += SCORE_BOARD_CHAR_INTERVAL;
    }

    current_char_from_table = player_name[current_char_position];

    cursor_point_1.x = char_point.x;
    cursor_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;

    glcdFillRect(cursor_point_1, cursor_point_2, glcdSetPixel);
}

void ScoreBoard_priv_char_for_name(void)
{
    xy_point cursor_point_1 ;
    cursor_point_1.x = char_point.x;
    cursor_point_1.y = char_point.y+2;

    xy_point cursor_point_2 ;
    cursor_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;
    cursor_point_2.y = char_point.y+2;

    glcdFillRect(cursor_point_1, cursor_point_2, glcdClearPixel);

    current_char_position--;

    if(current_char_position >= SCORE_BOARD_PLAYER_LENGTH)
    {
        current_char_position=SCORE_BOARD_PLAYER_LENGTH-1;
        char_point.x = SCORE_BOARD_CHAR_POS_X * (SCORE_BOARD_PLAYER_LENGTH-1);
    }
    else
    {
        char_point.x -= SCORE_BOARD_CHAR_INTERVAL;
    }

    current_char_from_table = player_name[current_char_position];

    cursor_point_1.x = char_point.x;
    cursor_point_2.x = char_point.x+SCORE_BOARD_CHAR_INTERVAL-1;

    glcdFillRect(cursor_point_1, cursor_point_2, glcdSetPixel);
}

void ScoreBoard_store_player_name(void)
{
    if(current_hs_postion < SCORE_BOARD_SIZE)
    {
        strncpy(score_board[current_hs_postion].player, player_name,SCORE_BOARD_PLAYER_LENGTH);
    }
}
