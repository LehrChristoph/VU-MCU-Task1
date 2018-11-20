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
#include <stdlib.h>

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
void field_display_end(void);
void field_update_positions(void);
void field_update_ball_position(uint8_t y_shift);
void field_draw_barrier(field_barrier barrier, uint8_t y_shift);
void field_update_glcd(void);
void field_display_new_game(void);
void field_display_SB(void);
uint8_t field_check_bottom_collision(uint8_t colision_left, uint8_t collision_right, field_barrier barrier);
uint8_t field_check_side_collision(uint8_t collision_left, uint8_t collision_right, field_barrier barrier);
void filed_add_deviation(int8_t deviation);

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
const char new_score[] PROGMEM = "NEW SCORE ENTRY";

static uint16_t current_score;
static uint8_t score_position;

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

    field_cyclic_task_id =  Tasker_add_task(0x01, field_cyclic_task, 5);
}

void field_reset_field(void)
{
    field_ball_center_current.x = FIELD_BALL_INIT_POSITION;
    field_ball_center_current.y = FIELD_GLCD_HEIGTH - FIELD_BALL_RADIUS -2;
    field_ball_bottom_current.x = FIELD_BALL_INIT_POSITION;
    field_ball_bottom_current.y = FIELD_GLCD_HEIGTH -2;

    current_score = 0;
    score_position = 0;

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
            field_update_positions();
            already_displayed = 0x00;
            break;
        case GAME_OVER:
            field_display_end();
            break;
        case GAME_GET_PLAYER:
            break;
        case GAME_DISPLAY_SB:
            field_display_SB();
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

void field_display_end(void)
{

    glcdSetYShift(0);
    glcdFillScreen(GLCD_CLEAR);

    score_position = ScoreBoard_new_score(current_score);
    if(score_position >0 )
    {
        xy_point message_point ;
        message_point.x = FIELD_NEW_CORE_POSITION_X;
        message_point.y = FIELD_STRING_POSITION_Y;

        glcdDrawTextPgm(new_score, message_point, &Standard5x7, glcdSetPixel);
        game_set_state(GAME_GET_PLAYER);
    }
    else
    {
        xy_point message_point ;
        message_point.x = FIELD_GAME_OVER_STRING_POSITION_X;
        message_point.y = FIELD_STRING_POSITION_Y;
        glcdDrawTextPgm(game_over_message, message_point, &Standard5x7, glcdSetPixel);
        game_set_state(GAME_DISPLAY_SB);
    }

    current_score = 0x00;

}

void field_display_SB(void)
{
    if(! already_displayed)
    {
        ScoreBoard_display(score_position);

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

}

void field_update_positions(void)
{
    static uint16_t game_counter = 0;
    static uint8_t line_counter =0;
    static uint8_t speed_counter =0;
    if(game_counter == 0)
    {
        current_score++;
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

            if( speed_counter >= FIELD_SPEED_INCREASE_INTERVAL && game_speed > FIELD_MIN_SPEED)
            {
                game_speed--;
            }
            speed_counter++;
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
    uint8_t y_blocked = 0x00, x_blocked = 0x00;

    xy_point draw_point = field_ball_center_current;
    draw_point.y += y_shift;

    glcdDrawCircle(draw_point, FIELD_BALL_RADIUS, glcdClearPixel);
    int8_t deviation = controls_get_deviation();

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

    if(collision_right + FIELD_BALL_RADIUS >= FIELD_GLCD_WIDTH)
    {
        collision_right = FIELD_GLCD_WIDTH-1;
    }
    else
    {
        collision_right += FIELD_BALL_RADIUS;
    }

    if(deviation > 0)
    {

        if(collision_right + abs(deviation) >= FIELD_GLCD_WIDTH-1)
        {
            collision_right=FIELD_GLCD_WIDTH-1;
            collision_left =FIELD_GLCD_WIDTH-(2*FIELD_BALL_RADIUS + 1) -1;
        }
        else
        {
            collision_left+=deviation;
            collision_right+=deviation;
        }
    }
    else if(deviation < 0)
    {
        if(collision_left < abs(deviation))
        {
            collision_left = 0;
            collision_right =2*FIELD_BALL_RADIUS + 1;
        }
        else
        {
            collision_left+=deviation;
            collision_right+=deviation;
        }
    }


    for(uint8_t i=0; i<FIELD_BARRIER_ARRAY_SIZE; i++)
    {

        // check if ball drops on barrier
        if(field_barriers_current[i].glcd_position-1 == field_ball_bottom_current.y ||
           field_barriers_current[i].glcd_position   == field_ball_bottom_current.y)
        {
            y_blocked = field_check_bottom_collision(collision_left, collision_right, field_barriers_current[i]);

        }
        // check if colision is left or right
        if(field_ball_center_current.y - FIELD_BALL_RADIUS <= field_barriers_current[i].glcd_position &&
           field_ball_center_current.y + FIELD_BALL_RADIUS >= field_barriers_current[i].glcd_position)
        {
            x_blocked = field_check_side_collision(collision_left, collision_right, field_barriers_current[i]);
        }
        if (x_blocked || y_blocked)
        {
            break;
        }
    }

    if(! x_blocked)
    {
        filed_add_deviation(deviation);
    }

    if(!y_blocked && field_ball_bottom_current.y < FIELD_GLCD_HEIGTH -2 )
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

uint8_t field_check_bottom_collision(uint8_t collision_left, uint8_t collision_right, field_barrier barrier)
{
    uint8_t start_x=0, end_x=FIELD_BARRIER_BLOCK_WIDTH-1;
    uint16_t seed = barrier.seed;

    for(uint8_t j=0; j<16; j++)
    {

        // check if something left or right of center is coliding
        if((collision_left <= end_x && field_ball_bottom_current.x >= end_x) ||
            (collision_right >= start_x && field_ball_bottom_current.x <= start_x))
        {
            // only break loop if coliding
            if((seed & 0x1) > 0)
            {
                field_ball_bottom_current.y=barrier.glcd_position-1;
                field_ball_center_current.y=barrier.glcd_position-FIELD_BALL_RADIUS-1;
                return 0xFF;
            }
        }
        //check if center is coliding
        else if(field_ball_bottom_current.x >= start_x && field_ball_bottom_current.x <= end_x)
        {
            if((seed & 0x1) > 0)
            {
                field_ball_bottom_current.y=barrier.glcd_position-1;
                field_ball_center_current.y=barrier.glcd_position-FIELD_BALL_RADIUS-1;
                return 0xFF;
            }
        }

        start_x += FIELD_BARRIER_BLOCK_WIDTH;
        end_x += FIELD_BARRIER_BLOCK_WIDTH;
        seed = (seed >> 1);
    }
    return 0x00;
}

uint8_t field_check_side_collision(uint8_t collision_left, uint8_t collision_right, field_barrier barrier)
{
    uint16_t seed = barrier.seed;
    uint8_t start_x=0, end_x=FIELD_BARRIER_BLOCK_WIDTH-1;

    for(uint8_t j=0; j<16; j++)
    {
        // check if something is on the left side of the ball
        if(collision_right > end_x && collision_right < end_x + FIELD_BARRIER_BLOCK_WIDTH
           // check if current block is a hole and if the right block is a barrier
           && ((seed >> j) & 0x1) == 0 && ((seed >> (j+1) )& 0x1) == 1) //
        {
            field_ball_bottom_current.x = end_x - FIELD_BALL_RADIUS;
            field_ball_center_current.x = end_x - FIELD_BALL_RADIUS;
            return 0xFF;
        }
        else if(collision_left < start_x && collision_left > start_x - FIELD_BARRIER_BLOCK_WIDTH
                // check if current block is a hole and if the left block is a barrier
                && ((seed >> j) & 0x1) == 0 && ((seed >> (j-1)) & 0x1) == 1) //
        {
            field_ball_bottom_current.x = start_x + FIELD_BALL_RADIUS;
            field_ball_center_current.x = start_x + FIELD_BALL_RADIUS;
            return 0xFF;
        }

        start_x += FIELD_BARRIER_BLOCK_WIDTH;
        end_x += FIELD_BARRIER_BLOCK_WIDTH;
    }

    return 0x00;
}

void filed_add_deviation(int8_t deviation)
{
    if(deviation >0)
    {

        uint8_t new_pos = field_ball_bottom_current.x + abs(deviation);

        if(new_pos >= FIELD_GLCD_WIDTH)
        {
            field_ball_bottom_current.x = FIELD_GLCD_WIDTH-FIELD_BALL_RADIUS-2;
            field_ball_center_current.x = FIELD_GLCD_WIDTH-FIELD_BALL_RADIUS-2;
        }
        else
        {
            field_ball_bottom_current.x += deviation;
            field_ball_center_current.x += deviation;
        }
    }
    else if(deviation < 0)
    {
        int8_t new_pos = field_ball_bottom_current.x + deviation;

        if(new_pos <= FIELD_BALL_RADIUS)
        {
            field_ball_bottom_current.x = FIELD_BALL_RADIUS+1;
            field_ball_center_current.x = FIELD_BALL_RADIUS+1;
        }
        else
        {
            field_ball_bottom_current.x += deviation;
            field_ball_center_current.x += deviation;
        }
    }
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
