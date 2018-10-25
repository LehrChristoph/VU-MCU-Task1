/*
 * field.c
 *
 *  Created on: 24 Oct 2018
 *      Author: christoph
 */

#include "application/field.h"

#include <avr/io.h>

#include "glcd.h"

void field_init(void)
{
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);

    xy_point p1, p2;

    p1.x = 10;
    p1.y = 10;

    p2.x = 50;
    p2.y = 50;

    glcdFillRect(p1, p2, &glcdSetPixel);
}
