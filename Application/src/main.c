/*
 * main.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include <avr/io.h>

#include "application/game.h"

void init_application(void);

int main(int argc, char const *argv[])
{
    init_application();
}


void init_application(void)
{
    game_init();
}
