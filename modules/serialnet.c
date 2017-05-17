#include "serialnet.h"
#include <libserialnet/serialnet.h>

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void serialnet_callback(uint16_t src_addr, const char *data, uint8_t data_length, uint8_t broadcast);

#define SERIALNET_ROLE 2
#define SERIALNET_ADDR 0xB00B

#define SERIALNET_SET_RPM 1 
#define SERIALNET_RESET_RPM 2
#define SERIALNET_RESET_ALERT 4

#define ISR_ADC_FC 1 
#define ISR_SERIALNET 2
#define ISR_INPUT_CAPTURE 4
#define ISR_FFT 8
#define ISR_SWITCH_GLCD 16
#define ISR_CLEAR_NOISE_REDUCTION 32
#define ISR_REFRESH 64

static uint16_t zigbee_rpm=0;
static uint8_t isr_flags=0;
static uint8_t internal_flags=0;

void init_SerialNet(void){
    
    /* Configure Serialnet */
    uint8_t mac[8] = { 9, 8, 1, 5, 2, 5, 1 ,0};
    serialnet_init(serialnet_callback, SERIALNET_ROLE, SERIALNET_ADDR, mac);
    serialnet_dispatch();

}

void dispatch(void){
    serialnet_dispatch();
}

uint16_t get_rpm(void){
    return zigbee_rpm;
}

uint8_t get_isr_flags_serialnet(void){
    uint8_t flags = isr_flags;
    isr_flags =0;
    return flags;
}

uint8_t get_serialnet_flags(void){
    uint8_t flags = internal_flags;
    internal_flags =0;
    return flags;
}

void send_noisealert(void){
    
    uint8_t i=0;
    serialnet_broadcast_data("NOISEALERT");
    serialnet_dispatch();
    
    while((serialnet_get_state() & SERIALNET_RESPONSE_ERR) == SERIALNET_RESPONSE_ERR && i < 5){
        serialnet_broadcast_data("NOISEALERT");
        serialnet_dispatch();
        i++;
    }
    
    serialnet_clear_state(SERIALNET_RESPONSE_OK);
    serialnet_clear_state(SERIALNET_RESPONSE_ERR);
}

static void serialnet_callback(uint16_t src_addr, const char *data, uint8_t data_length, uint8_t broadcast){
    //do OP Shit    
    if(strncmp("SETRPM:", data, 7)==0){
        
        zigbee_rpm = atoi(&data[7]);
        if(zigbee_rpm < 650 || zigbee_rpm > 3400){
            zigbee_rpm =0;
        }else{
            internal_flags |= SERIALNET_SET_RPM;
            isr_flags |= ISR_SERIALNET;
        }
    }else if(strncmp("RESETALERT", data, 9)==0){
        internal_flags |= SERIALNET_RESET_ALERT;
        isr_flags |= ISR_SERIALNET;
        
    }else if(strncmp("RESETRPM", data, 8)==0){
        internal_flags |= SERIALNET_RESET_RPM;
        isr_flags |= ISR_SERIALNET;
        zigbee_rpm=0;
    }
    
    serialnet_clear_state(SERIALNET_GOT_DATA);
}
