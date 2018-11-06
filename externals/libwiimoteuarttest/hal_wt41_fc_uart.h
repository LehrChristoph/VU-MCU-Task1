#ifndef HAL_WT41_FC_UART
#define HAL_WT41_FC_UART

#include <avr/io.h>
#include <stdint.h>
#include "util.h"

#ifndef HAL_WT41_BUFFER_SIZE
    #define HAL_WT41_BUFFER_SIZE 48
#endif

// Flow control will be set if free space is lower or equla then that value
#ifndef HAL_WT41_FLOW_CONTROL_SET
    #define HAL_WT41_FLOW_CONTROL_SET 5
#endif

// Flow control will be cleared if free space is creater then that value
#ifndef HAL_WT41_FLOW_CONTROL_CLEAR
    #define HAL_WT41_FLOW_CONTROL_CLEAR HAL_WT41_BUFFER_SIZE/2
#endif

error_t halWT41FcUartInit(void (*sndCallback)(), void (*rcvCallback)(uint8_t));
error_t halWT41FcUartSend(uint8_t byte);

#endif
