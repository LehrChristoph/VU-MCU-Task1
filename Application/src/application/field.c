/*
 * field.c
 *
 *  Created on: 24 Oct 2018
 *      Author: christoph
 */

#include "application/field.h"

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/atomic.h>
#include <stdio.h>

#include "glcd.h"
#include "Standard5x7.h"
#include "game.h"
#include "modules/Tasker.h"
#include "modules/rand.h"
#include "ScoreBoard.h"
#include "controls.h"

// functions definitions
void field_cyclic_task(void);
void field_display_start_screen(void);
void field_display_game(void);
void field_display_end(void);
void field_update_positions(void);
void field_update_ball_position(uint8_t y_shift);
void field_draw_barrier(field_barrier barrier, uint8_t y_shift);
void field_update_glcd(void);
void field_display_new_game(void);

static uint8_t field_cyclic_task_id = 0xFF;

static game_state_t field_current_game_state = GAME_STARTUP;

static field_barrier field_barriers_current[8];
static uint8_t field_barrier_index;

static xy_point field_ball_center_current;
static xy_point field_ball_bottom_current;

static uint16_t game_speed = FIELD_DEFAULT_SPEED;

static uint8_t already_displayed = 0x00;
static uint8_t connect_infor_already_displayed = 0x00;

const char startup_message[] PROGMEM = "FALLING DOWN BALL";
const char game_over_message[] PROGMEM = "GAME OVER";
const char connect_message[] PROGMEM = "CONNECTING TO:";
const char mac_address_format[] PROGMEM = "%02X:%02X:%02X:%02X:%02X:%02X";
const char ready_to_start_message[] PROGMEM = "Ready to Start";
const char press_a_message[] PROGMEM = "New Game: Press A";

static uint16_t current_score;
static uint8_t score_postion;

const char wiimote_init_error[] PROGMEM = "WiiUserInit Error";
const char wiimote_connect_error[] PROGMEM = "WiiUserConnect Error";
const char wiimote_setLeds_error[] PROGMEM = "WiiUserSetLeds Error";
const char wiimote_setAccl_error[] PROGMEM = "WiiUserSetAccl Error";

// const PGM_P error_table[4] PROGMEM =
// {
//     wiimote_init_error,
//     wiimote_connect_error,
//     wiimote_setLeds_error,
//     wiimote_setAccl_error
// };

void field_init(void)
{
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);

    field_current_game_state = GAME_IDLE;

    field_reset_field();

    field_cyclic_task_id =  Tasker_add_task(0x01, field_cyclic_task, 10);
}

void field_reset_field(void)
{
    field_ball_center_current.x = FIELD_BALL_INIT_POSITION;
    field_ball_center_current.y = FIELD_GLCD_HEIGTH - FIELD_BALL_RADIUS -2;
    field_ball_bottom_current.x = FIELD_BALL_INIT_POSITION;
    field_ball_bottom_current.y = FIELD_GLCD_HEIGTH -2;

    current_score =0;
    score_postion =0;
    already_displayed = 0x00;
    game_speed = FIELD_DEFAULT_SPEED;
    field_current_game_state = GAME_IDLE;
    connect_infor_already_displayed = 0x00;

    field_barrier_index=0;
    for(uint8_t i=0; i<FIELD_BARRIER_ARRAY_SIZE; i++)
    {
        field_barriers_current[field_barrier_index].glcd_position = FIELD_GLCD_HEIGTH-1;
        field_barriers_current[field_barrier_index].seed = 0xFF;
    }
}

void field_updated_local_game_state(game_state_t new_game_state)
{
    field_current_game_state = new_game_state;
}

void field_cyclic_task(void)
{
    game_state_t game_state;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        game_state = field_current_game_state;
    }

    switch(game_state)
    {
        case GAME_IDLE :
            already_displayed = 0x00;
            break;
        case GAME_STARTUP :
            field_display_start_screen();
            break;
    	case GAME_PLAYING:
            field_display_game();
            already_displayed = 0x00;
            break;
        case GAME_OVER:
            field_display_end();
            break;
    }
}

void field_display_start_screen(void)
{
    if(! already_displayed)
    {
        current_score = 0;

        xy_point message_point ;
        message_point.x = FIELD_TITLE_STRING_POSITION_X;
        message_point.y = FIELD_STRING_POSITION_Y;
        glcdDrawTextPgm(startup_message, message_point, &Standard5x7, glcdSetPixel);

        already_displayed = 0xFF;
    }
}

void field_display_game(void)
{
    field_update_positions();
}

void field_display_end(void)
{
    if(! already_displayed)
    {
        glcdSetYShift(0);
        glcdFillScreen(GLCD_CLEAR);

        xy_point message_point ;
        message_point.x = FIELD_GAME_OVER_STRING_POSITION_X;
        message_point.y = FIELD_STRING_POSITION_Y;
        glcdDrawTextPgm(game_over_message, message_point, &Standard5x7, glcdSetPixel);

        score_t new_score;
        new_score.score = current_score;
        score_postion = ScoreBoard_new_score(new_score);
        ScoreBoard_display(score_postion);

        field_display_new_game();

        already_displayed = 0xFF;
    }
}

void field_display_connect(uint8_t *mac_address)
{
    xy_point message_clear_point_1 ;
    message_clear_point_1.x = 0;
    message_clear_point_1.y = 10;

    xy_point message_clear_point_2 ;
    message_clear_point_2.x = 127;
    message_clear_point_2.y = 40;

    glcdFillRect(message_clear_point_1, message_clear_point_2, glcdClearPixel);

    xy_point message_point ;
    message_point.x = 5;
    message_point.y = 20;
    glcdDrawTextPgm(connect_message, message_point, &Standard5x7, glcdSetPixel);
    connect_infor_already_displayed = 0xFF;

    char mac_output[18];
    char format[30];

    strcpy_P(format, mac_address_format);
    sprintf(mac_output, format,
            (&mac_address)[0][0],
            (&mac_address)[0][1],
            (&mac_address)[0][2],
            (&mac_address)[0][3],
            (&mac_address)[0][4],
            (&mac_address)[0][5]);

    xy_point mac_address_point ;
    mac_address_point.x = 5;
    mac_address_point.y = 28;
    glcdDrawText(mac_output, mac_address_point, &Standard5x7, glcdSetPixel);
}

void field_display_ready_to_start(void)
{

    xy_point message_point ;
    message_point.x = 20;
    message_point.y = 50;
    glcdDrawTextPgm(ready_to_start_message, message_point, &Standard5x7, glcdSetPixel);
    field_display_new_game();
}

void field_display_new_game(void)
{
    xy_point message_point ;
    message_point.x = 12;
    message_point.y = 63;
    glcdDrawTextPgm(press_a_message, message_point, &Standard5x7, glcdSetPixel);
}

void field_display_error(uint8_t error_code)
{
    PORTK = error_code;
}

void field_update_positions(void)
{
    static uint16_t game_counter = 0;
    static uint8_t line_counter =0;

    if(game_counter == 0)
    {
        uint8_t y_shift = glcdGetYShift();
        glcdSetYShift(y_shift +1);
        glcdDrawHorizontal(y_shift, glcdClearPixel);

        //apply y_shift
        for(uint8_t i=0; i<FIELD_BARRIER_ARRAY_SIZE; i++)
        {
            field_barriers_current[i].glcd_position--;
        }

        if(line_counter == 0)
        {
            field_barriers_current[field_barrier_index].seed = rand16();
            field_barriers_current[field_barrier_index].glcd_position = FIELD_GLCD_HEIGTH-1;
            field_draw_barrier(field_barriers_current[field_barrier_index], y_shift);

            field_barrier_index = (field_barrier_index+1)%8;
        }

        field_update_ball_position(y_shift);

        line_counter = (line_counter +1) % FIELD_BARRIER_INTERVAL;
    }

    if(game_counter == (game_speed>1))
    {
        uint8_t y_shift = glcdGetYShift();
        field_update_ball_position(y_shift);
    }

    game_counter = (game_counter +1) % game_speed;
}

void field_update_ball_position(uint8_t y_shift)
{
    uint8_t blocked = 0x00;

    xy_point draw_point = field_ball_center_current;
    draw_point.y += y_shift-1;

    glcdDrawCircle(draw_point, FIELD_BALL_RADIUS, glcdClearPixel);
    uint8_t ball_position_top = field_ball_center_current.y - FIELD_BALL_RADIUS;
    uint8_t deviation = controls_get_deviation();

    for(uint8_t i=0; i<FIELD_BARRIER_ARRAY_SIZE; i++)
    {

        // check if ball drops on barrier
        if(field_barriers_current[i].glcd_position-1 == field_ball_bottom_current.y ||
           field_barriers_current[i].glcd_position   == field_ball_bottom_current.y)
        {
            uint8_t start_x=0, end_x=FIELD_BARRIER_BLOCK_WIDTH-1;
            uint16_t seed = field_barriers_current[i].seed;

            uint8_t collision_left = field_ball_bottom_current.x;
            uint8_t collision_right = field_ball_bottom_current.x;

            if(collision_left < FIELD_BALL_RADIUS)
            {
                collision_left = 0;
            }
            else
            {
                collision_left -= FIELD_BALL_RADIUS;
            }

            if(collision_right + FIELD_BALL_RADIUS > 127)
            {
                collision_left = 127;
            }
            else
            {
                collision_right += FIELD_BALL_RADIUS;
            }

            for(uint8_t j=0; j<16; j++)
            {

                // check if something left or right of center is coliding
                if((collision_left <= end_x && field_ball_bottom_current.x >= end_x) ||
                    (collision_right >= start_x && field_ball_bottom_current.x <= start_x))
                {
                    // only break loop if coliding
                    if((seed & 0x1) > 0)
                    {
                        blocked = 0xFF;
                        field_ball_bottom_current.y=field_barriers_current[i].glcd_position-1;
                        field_ball_center_current.y=field_barriers_current[i].glcd_position-FIELD_BALL_RADIUS-1;
                        break;
                    }
                }
                //check if center is coliding
                else if(field_ball_bottom_current.x >= start_x && field_ball_bottom_current.x <= end_x)
                {
                    if((seed & 0x1) > 0)
                    {
                        blocked = 0xFF;
                        field_ball_bottom_current.y=field_barriers_current[i].glcd_position-1;
                        field_ball_center_current.y=field_barriers_current[i].glcd_position-FIELD_BALL_RADIUS-1;
                    }
                    break;
                }

                start_x += FIELD_BARRIER_BLOCK_WIDTH;
                end_x += FIELD_BARRIER_BLOCK_WIDTH;
                seed = (seed >> 1);
            }

            break;
        }
        //check if colision is left or right
        else if(field_barriers_current[i].glcd_position-1 >= ball_position_top ||
           field_barriers_current[i].glcd_position <= field_ball_bottom_current.y)
        {
            // TODO: check if colision is left or right
        }
    }

    if(!blocked && field_ball_bottom_current.y < FIELD_GLCD_HEIGTH -2 )
    {
        field_ball_bottom_current.y+=1;
        field_ball_center_current.y+=1;
    }

    if(field_ball_center_current.y <= FIELD_BALL_RADIUS )
    {
        game_set_state(GAME_OVER);
    }

    draw_point = field_ball_center_current;
    draw_point.y += y_shift;

    glcdDrawCircle(draw_point, FIELD_BALL_RADIUS, glcdSetPixel);
}


void field_draw_barrier(field_barrier barrier, uint8_t y_shift)
{
    uint16_t seed = barrier.seed;

    xy_point start_p, end_p;
    start_p.x = 0;
    end_p.x = FIELD_BARRIER_BLOCK_WIDTH-1;
    start_p.y = end_p.y = y_shift;

    for(uint8_t i=0; i<16; i++)
    {
        if( (seed & 0x1) > 0)
        {
            glcdDrawLine(start_p, end_p, glcdSetPixel);
        }

        seed = (seed >> 1);
        start_p.x += FIELD_BARRIER_BLOCK_WIDTH;
        end_p.x += FIELD_BARRIER_BLOCK_WIDTH;
    }
}
