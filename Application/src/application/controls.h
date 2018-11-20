/*
 * controls.h
 *
 *  Created on: 9 Nov 2018
 *      Author: christoph
 */

#ifndef APPLICATION_CONTROLS_H
#define APPLICATION_CONTROLS_H

#include <avr/io.h>

#define CONTROLS_BUTTON_B       0x0004
#define CONTROLS_BUTTON_A       0x0008
#define CONTROLS_BUTTON_D_UP    0x0800
#define CONTROLS_BUTTON_D_DOWN  0x0400
#define CONTROLS_BUTTON_D_LEFT  0x0100
#define CONTROLS_BUTTON_D_RIGHT 0x0200

void controls_init(void);

void controls_connect(void (*connect_callback)(void));

void controls_set_button_press_callback(uint16_t button, void (*button_press_callback)(void));

void controls_clear_button_press_callback(uint16_t button);

int8_t controls_get_deviation(void);

void controls_EnableAccl(void);

#endif
