/*
 * game.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */


#include <avr/io.h>
#include "application/game.h"
#include "application/sound.h"

void game_init(void)
{
    sound_init();
}
