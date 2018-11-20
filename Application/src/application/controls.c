/*
 * controls.c
 *
 *  Created on: 9 Nov 2018
 *      Author: christoph
 */

#include "controls.h"

#include <stdlib.h>

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>

#include "util.h"
#include "wiimote/wii_user.h"
#include "field.h"
#include "wiimote/mac.h"

//function definitions
void controls_rcvButton(uint8_t wii, uint16_t button);
void controls_rcvAccel(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
void controls_conCallback(uint8_t wii, connection_status_t status);
void controls_setLeds(uint8_t wii, error_t status);

// callback when controls are setupb
static void (*controls_connect_callback)(void);
// button callback definitions
static void (*button_a_callback)(void);
static void (*button_b_callback)(void);
static void (*button_d_up_callback)(void);
static void (*button_d_down_callback)(void);
static void (*button_d_left_callback)(void);
static void (*button_d_right_callback)(void);

// iterator for mac address of wiimote
static uint8_t wiimote_iterator;
// deviation which shall be applied to ball
static int8_t deviation;
// current button states
static uint16_t button_states;


void controls_init(void)
{
    error_t error = wiiUserInit(controls_rcvButton, controls_rcvAccel);
    wiimote_iterator = 0;
    button_states = 0;

    if(error != SUCCESS)
    {
        // TODO Display Error
        field_display_error(ERROR_WII_INIT);
    }
}

void controls_connect(void (*connect_callback)(void))
{
    controls_connect_callback = connect_callback;
    uint8_t current_mac[1][8];
    memcpy_P(current_mac, macs[wiimote_iterator], 6);
    field_display_connect(*current_mac);
    error_t error = wiiUserConnect(0, *current_mac, controls_conCallback);

    if(error != SUCCESS)
    {
        // TODO Display Error
        field_display_error(ERROR_WII_CONNECT);
    }
}
void controls_set_button_press_callback(uint16_t button, void (*button_press_callback)(void))
{
    switch(button)
    {
        case CONTROLS_BUTTON_A:
            button_a_callback = button_press_callback;
            break;
        case CONTROLS_BUTTON_B:
            button_b_callback = button_press_callback;
            break;
        case CONTROLS_BUTTON_D_UP:
            button_d_up_callback = button_press_callback;
            break;
        case CONTROLS_BUTTON_D_DOWN:
            button_d_down_callback = button_press_callback;
            break;
        case CONTROLS_BUTTON_D_LEFT:
            button_d_left_callback = button_press_callback;
            break;
        case CONTROLS_BUTTON_D_RIGHT:
            button_d_right_callback = button_press_callback;
            break;
    }
}

void controls_clear_button_press_callback(uint16_t button)
{
    switch(button)
    {
        case CONTROLS_BUTTON_A:
            button_a_callback = NULL;
            break;
        case CONTROLS_BUTTON_B:
            button_b_callback = NULL;
            break;
        case CONTROLS_BUTTON_D_UP:
            button_d_up_callback = NULL;
            break;
        case CONTROLS_BUTTON_D_DOWN:
            button_d_down_callback = NULL;
            break;
        case CONTROLS_BUTTON_D_LEFT:
            button_d_left_callback = NULL;
            break;
        case CONTROLS_BUTTON_D_RIGHT:
            button_d_right_callback = NULL;
            break;
    }
}

void controls_rcvButton(uint8_t wii, uint16_t button)
{
    // high byte == first byte
    // low byte == second byte

    // get which buttons changed
    uint16_t bit_changes = button_states ^ (button | button_states);

    if((bit_changes & CONTROLS_BUTTON_A) >0 && (button & CONTROLS_BUTTON_A) > 0 && button_a_callback != NULL)
    {
        (*button_a_callback)();
    }

    if((bit_changes & CONTROLS_BUTTON_B) >0 && (button & CONTROLS_BUTTON_B) > 0 && button_b_callback != NULL)
    {
        (*button_b_callback)();
    }

    if((bit_changes & CONTROLS_BUTTON_D_UP) >0 && (button & CONTROLS_BUTTON_D_UP) > 0 && button_d_up_callback != NULL)
    {
        (*button_d_up_callback)();
    }

    if((bit_changes & CONTROLS_BUTTON_D_DOWN) >0 && (button & CONTROLS_BUTTON_D_DOWN) > 0 && button_d_down_callback != NULL)
    {
        (*button_d_down_callback)();
    }

    if((bit_changes & CONTROLS_BUTTON_D_LEFT) >0 && (button & CONTROLS_BUTTON_D_LEFT) > 0 && button_d_left_callback != NULL)
    {
        (*button_d_left_callback)();
    }

    if((bit_changes & CONTROLS_BUTTON_D_RIGHT) >0 && (button & CONTROLS_BUTTON_D_RIGHT) > 0 && button_d_right_callback != NULL)
    {
        (*button_d_right_callback)();
    }

    button_states = button;
}

void controls_rcvAccel(uint8_t wii, uint16_t x, uint16_t y, uint16_t z)
{

    static int8_t last_z = 0;
    // ignore lsb
    int8_t temp_y = (y >> 1);
    int8_t temp_z = (z >> 1);

    // invert msb -> correct format of signed integer
    temp_y ^= 0x80;

    if( last_z < 0 && temp_z < 0 )
    {
        uint8_t deviation_temp = 0;
        uint8_t abs_y = abs(temp_y);

        // discard lsb
        abs_y >>= 1;
        // calculate deviation
        for(uint8_t i=1; i<8; i++)
        {
            if((abs_y & 0x01 )>0)
            {
                deviation_temp = i;
            }
            abs_y >>= 1;
        }

        if(temp_y > 0)
        {
            deviation = 0-deviation_temp;
        }
        else
        {
            deviation = deviation_temp;
        }
    }

    last_z = temp_z;

}

void controls_conCallback(uint8_t wii, connection_status_t status)
{

    if(status == DISCONNECTED)
    {

        if(wiimote_iterator+1 >= mac_cnt)
        {
            wiimote_iterator=0;
        }
        else
        {
            wiimote_iterator++;
        }

        uint8_t current_mac[1][6];
        memcpy_P(current_mac, macs[wiimote_iterator], 6);

        field_display_connect(*current_mac);
        error_t error = wiiUserConnect(wii, *current_mac, controls_conCallback);

        if(error != SUCCESS)
        {
            // TODO Display Error
            field_display_error(ERROR_WII_CONNECT);
        }
    }
    else
    {
        error_t error = wiiUserSetLeds(wii, 0x0F, controls_setLeds);

        if(error != SUCCESS)
        {
            // TODO Display Error
            field_display_error(ERROR_WII_SET_LEDS);
        }
    }
}

void controls_setLeds(uint8_t wii, error_t status)
{
    if(status != SUCCESS)
    {
        // TODO Display Error
        field_display_error(ERROR_WII_SET_LEDS);
    }
    else
    {

        (*controls_connect_callback)();
    }
}

void controls_EnableAccl(void)
{
    error_t error = wiiUserSetAccel(0, 0xfF, NULL);
    if(error != SUCCESS)
    {
        // TODO Display Error
        field_display_error(ERROR_WII_SET_ACCL);
    }
}

int8_t controls_get_deviation(void)
{
    return deviation;
}
