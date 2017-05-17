#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_SerialNet(void);
 
void send_noisealert(void);

void dispatch(void);

uint16_t get_rpm(void);

uint8_t get_isr_flags_serialnet(void);

uint8_t get_serialnet_flags(void);
