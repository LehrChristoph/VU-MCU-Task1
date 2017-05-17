#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <libglcd/glcd.h>
#include <libglcd/font.h>
#include <libglcd/Standard5x7.h>

#include "glcd.h"

#define MODE_USE_ADC 1
#define MODE_USE_ZIGBEE 2
#define MODE_NOISE_REDUCTION 4

uint8_t displayMode=GLCD_DISPLAY_RPM;

void init_GLCD(void){

    /* Set up GLCD */    
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);
    
    displayMode = GLCD_DISPLAY_RPM;
}

uint8_t switchScreen(void){
    if((displayMode & GLCD_DISPLAY_RPM) == GLCD_DISPLAY_RPM){
        displayMode &= ~(GLCD_DISPLAY_RPM);
        displayMode |= GLCD_DISPLAY_FFT;
    }else{
        displayMode &= ~(GLCD_DISPLAY_FFT);
        displayMode |= GLCD_DISPLAY_RPM;
    }
    glcdFillScreen(GLCD_CLEAR);
    
    return displayMode;
}

void drawFFT(uint16_t *fft_spectrum, uint8_t counter){
    glcdFillScreen(GLCD_CLEAR);
    uint8_t i=0;
    
    for(i=0; i<counter;i++){
        xy_point top, bottom;
        
        top.x=i*2;
        if((fft_spectrum[i]/32)>=16){
            top.y=0;
        }else{
            top.y=63-(fft_spectrum[i]/16);
        }
        
        bottom.x=i*2+1;
        bottom.y=63;
        
        glcdFillRect(top, bottom, &glcdSetPixel);
    }   
}

void drawInfoScreen(uint16_t set_rpm, uint16_t measured_rpm, uint8_t source_mode, uint16_t zigbee_rpm){
    char drawLine[30]="";
    xy_point line_xy, rect_clear_left, rect_clear_right;


    line_xy.x = 3;
    line_xy.y = 8;
    
    rect_clear_left.x = 90;
    rect_clear_left.y = 0;
    
    rect_clear_right.x=128;
    rect_clear_right.y=10;
    
    if(set_rpm < 1000){
        sprintf(drawLine, "Set RPM:         %d", set_rpm);
    }else{
        sprintf(drawLine, "Set RPM:        %d", set_rpm);
    }
    

    
    glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
    glcdDrawText(drawLine, line_xy, &Standard5x7, &glcdSetPixel);
    
    line_xy.y=line_xy.y+10;
    
    rect_clear_left.y = rect_clear_left.y + 10;
    
    rect_clear_right.y=rect_clear_right.y + 10;
    
    if(measured_rpm < 1000){
        sprintf(drawLine, "Measured RPM:    %d", measured_rpm);
    }else{
        sprintf(drawLine, "Measured RPM:   %d", measured_rpm);
    }
    
    glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
    glcdDrawText(drawLine, line_xy, &Standard5x7, &glcdSetPixel);
    
    line_xy.y=line_xy.y+10;
    
    rect_clear_left.y = rect_clear_left.y + 10;
    
    rect_clear_right.y=rect_clear_right.y + 10;
    
    if(source_mode == MODE_NOISE_REDUCTION){
        sprintf(drawLine, "Noise reduction:  ON");
    }else{
        sprintf(drawLine, "Noise reduction: OFF");
    }                     
    
    glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
    glcdDrawText(drawLine, line_xy, &Standard5x7, &glcdSetPixel);
    
    line_xy.y=line_xy.y+10;
    
    rect_clear_left.x= 64;
    rect_clear_left.y = rect_clear_left.y + 10;
    
    rect_clear_right.y=rect_clear_right.y + 10;
    
    if(zigbee_rpm != 0){
        sprintf(drawLine, "Source:    SerialNet");
    }else{
        sprintf(drawLine, "Source:         ADC0");
    }
    
    glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
    glcdDrawText(drawLine, line_xy, &Standard5x7, &glcdSetPixel);
    
} 
