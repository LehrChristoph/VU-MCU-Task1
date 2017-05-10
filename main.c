
#define F_CPU       (16000000UL)
#define BAUD 38400

/* includes */
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/setbaud.h>

#include <libglcd/glcd.h>
#include <libglcd/font.h>
#include <libglcd/Standard5x7.h>
#include <libmemstat/memstat.h>
#include <fftavr/ffft.h>
#include <libserialnet/serialnet.h>
#include <libserialnet/util.h>

#ifndef NULL
#define NULL    ((void *) 0)
#endif
#ifndef TRUE
#define TRUE    (0 == 0)
#endif
#ifndef FALSE
#define FALSE   (!TRUE)
#endif

//typedef int (*compfn)(const void*, const void*);

/* prototypes */
static void init(void);
static void drawFFT(void);
static void drawInfoScreen(void);
static void zigBeeCB(uint16_t src_addr, const char *data, uint8_t data_length, uint8_t broadcast);


/* constants */
#define ADC_MODE_RPM 1
#define ADC_MODE_SAMPLE 2
#define ADC_MODE_START_FFT 4

//#define TIMER1_COUNTER_TOP_PWM 640
#define TIMER1_COUNTER_TOP_PWM 2950
//#define TIMER1_COUNTER_TOP_PWM 1475
#define MAX_RPM 3400
#define MIN_RPM 650
#define TIMER3_COUNTER_TOP_A 250
#define TIMER3_COUNTER_TOP_B 40000
#define TIMER5_COUNTER_TOP 25000

#define ISR_ADC_FC 1 
#define ISR_ADC_SAMPLING 2
#define ISR_INPUT_CAPTURE 4
#define ISR_FFT 8
#define ISR_SWITCH_GLCD 16
#define ISR_NOISE_REDUCTION 32
#define ISR_REFRESH_ZIGBEE 64

#define GLCD_DISPLAY_RPM 1
#define GLCD_DISPLAY_FFT 2

#define MODE_USE_ADC 1
#define MODE_USE_ZIGBEE 2
#define MODE_NOISE_REDUCTION 4

#define PID_P_SHARE 100
#define PID_I_SHARE 5
#define PID_D_SHARE 0.0004

#define SERIALNET_ROLE 2
#define SERIALNET_ADDR 65535

/* variables */
static volatile uint8_t median=0;
static volatile uint8_t median_count =0;
static volatile uint8_t median_array[5] = {0,0,0,0,0};
static volatile uint8_t source_mode=0;
static volatile uint8_t adc_mode=0;
static volatile uint16_t set_rpm  =0;

static volatile uint16_t zigbee_address_master=0xFFFF;
static volatile uint16_t zigbee_rpm=0;

static volatile uint8_t isr_flags=0;
static volatile uint16_t measured_rpm=0;

static complex_t fft_buffter[FFT_N];		/* FFT buffer */
static uint16_t fft_spectrum[FFT_N/2];		/* Spectrum output buffer */
static int16_t fft_capture[FFT_N];
static volatile uint8_t fft_counter=0;
static char errorLast[30]="";

int main(void)
{
    uint8_t displayMode=GLCD_DISPLAY_RPM;
    int16_t error_priveous=0;
    uint16_t sum_up=0;
    
    /* init interrupts and ports */
    init();
    
    adc_mode = ADC_MODE_RPM;
    
    sei();   
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
   
    while(TRUE)
    {
        if(isr_flags ==0){
            sleep_cpu();
        }
        
        if((isr_flags & ISR_ADC_FC) == ISR_ADC_FC){
            isr_flags &= ~(ISR_ADC_FC);
            //get value from Potentiometer
            uint8_t median_temp[5] = { median_array[0], median_array[1], median_array[2], median_array[3], median_array[4]};
            
            uint8_t i, j;
            for(i=0; i<5; i++) {
                for(j=0; j<(5-i); j++) {
                    if(median_temp[j] > median_temp[j+1]) {
                        uint8_t temp = median_temp[j];
                        median_temp[j] = median_temp[j+1];
                        median_temp[j+1] = temp;
                    }
                }
            }
            if(median != median_temp[2]){
                
                if(source_mode == MODE_USE_ADC){
                    OCR1B = median_temp[2]*(TIMER1_COUNTER_TOP_PWM/255);
                    set_rpm = 10.7843*median_temp[2]+650;
                }
                median = median_temp[2];
            }
            
        }
        
        if((isr_flags & ISR_SWITCH_GLCD) == ISR_SWITCH_GLCD){
            if((displayMode & GLCD_DISPLAY_RPM) == GLCD_DISPLAY_RPM){
                displayMode &= ~(GLCD_DISPLAY_RPM);
                displayMode |= GLCD_DISPLAY_FFT;
            }else{
                displayMode &= ~(GLCD_DISPLAY_FFT);
                displayMode |= GLCD_DISPLAY_RPM;
            }
            glcdFillScreen(GLCD_CLEAR);
            
            isr_flags &= ~(ISR_SWITCH_GLCD);
        }
        
        if((isr_flags & ISR_NOISE_REDUCTION) == ISR_NOISE_REDUCTION){
            source_mode = MODE_USE_ADC;
            
            OCR1B = median*(TIMER1_COUNTER_TOP_PWM/255);
            set_rpm = 10.7843*median+650;
            
            isr_flags &= ~(ISR_NOISE_REDUCTION);
        }
        
        if((isr_flags & ISR_INPUT_CAPTURE) == ISR_INPUT_CAPTURE){
            
            isr_flags &= ~(ISR_INPUT_CAPTURE);
                        
            measured_rpm = 15 / (ICR4 *0.000008);
            
            if(sum_up > 300 && source_mode == MODE_NOISE_REDUCTION){
                
                set_rpm -= (set_rpm/10);
                if(set_rpm < MIN_RPM){
                    set_rpm =MIN_RPM;
                }
            }
            /*
            if(set_rpm > measured_rpm){
                
                uint16_t variance = set_rpm - measured_rpm;
                uint8_t compensation =0;
                
                if(variance > 100){
                    compensation =10;
                } else if(variance >50 ){
                    compensation =5;
                } else if(variance >20 ){
                    compensation =2;
                } else{
                    compensation =1;
                }
                
                if((OCR1B + compensation )< TIMER1_COUNTER_TOP_PWM){
                    OCR1B+=compensation;
                }else{
                    OCR1B = TIMER1_COUNTER_TOP_PWM;
                }
            }
            else if(set_rpm < measured_rpm) {

                uint16_t variance = measured_rpm-set_rpm;
                uint8_t compensation =0;
                
                if(variance > 100){
                    compensation =10;
                } else if(variance >50 ){
                    compensation =5;
                } else if(variance >20 ){
                    compensation =2;
                } else{
                    compensation =1;
                }
                
                if(OCR1B > compensation){
                    OCR1B-=compensation;
                }else{
                    OCR1B =0;
                }
            }*/
            
            
            int16_t error= (int16_t)set_rpm - (int16_t)measured_rpm;
            int16_t p_share=PID_P_SHARE * error;
            int16_t i_share=PID_I_SHARE * error_priveous;
            int16_t d_share=PID_D_SHARE * (error - error_priveous);
            error_priveous = error;
            //PID
            int16_t pid = p_share + i_share + d_share;
            
            OCR1B += pid *(TIMER1_COUNTER_TOP_PWM/MAX_RPM);
            
            
        }
        
        if((isr_flags & ISR_FFT) == ISR_FFT){

            isr_flags &= ~(ISR_FFT);
            
            //input for fft
            fft_input(fft_capture, fft_buffter);
            //start fft
            fft_execute(fft_buffter);
            //get result of fft
            fft_output(fft_buffter, fft_spectrum);
            
            adc_mode = ADC_MODE_RPM;
            TIMSK3|= 1<<OCIE3A;
            
            uint16_t max_specs[8] = {fft_spectrum[2],fft_spectrum[3],fft_spectrum[4],fft_spectrum[5],fft_spectrum[6],fft_spectrum[7],fft_spectrum[7],fft_spectrum[9]};
            //uint16_t sum_up=0;
            sum_up=0;
            for(uint8_t i=10; i<FFT_N/2; i++){
                uint16_t min =max_specs[0];
                uint8_t index_min=0;
                
                for(uint8_t j =1; j<8; j++){
                    if(max_specs[j]<min){
                        min=max_specs[j];
                        index_min =j;
                    }
                }
                if(fft_spectrum[i] > min){
                    max_specs[index_min] = fft_spectrum[i];
                }
            }
            
            for(uint8_t i=0; i<8;i++){
                sum_up += max_specs[i];
            }
            

            if((sum_up>>5)  > 400+0.048828125*measured_rpm && source_mode != MODE_NOISE_REDUCTION){
                
                PORTB |=0x08;
                
                set_rpm = set_rpm/2;
                
                if(set_rpm < MIN_RPM){
                    set_rpm = MIN_RPM;
                }
                
                if(source_mode == MODE_USE_ZIGBEE){
                    uint8_t i=0;
                    serialnet_broadcast_data("NOISEALERT");
                    serialnet_dispatch();
                    
                    while((serialnet_get_state() & SERIALNET_RESPONSE_ERR) == SERIALNET_RESPONSE_ERR && i < 5){
                        serialnet_broadcast_data("NOISEALERT");
                        serialnet_dispatch();
                        i++;
                    }
                    
                    if((serialnet_get_state() & SERIALNET_RESPONSE_ERR) == SERIALNET_RESPONSE_ERR ){
                        sprintf(errorLast, "ERROR SEND NOISEALERT");
                    }
                    
                    serialnet_clear_state(SERIALNET_RESPONSE_OK);
                    serialnet_clear_state(SERIALNET_RESPONSE_ERR);
                    
                    
                }
                
                source_mode = MODE_NOISE_REDUCTION;
                
            }

        }   
        
        if((isr_flags & ISR_REFRESH_ZIGBEE) == ISR_REFRESH_ZIGBEE){
            serialnet_dispatch();
            PORTC = serialnet_get_state();
            
            isr_flags &= ~(ISR_REFRESH_ZIGBEE);
            
            if((displayMode & GLCD_DISPLAY_FFT) == GLCD_DISPLAY_FFT){
                drawFFT();
            }
            
            if(displayMode == GLCD_DISPLAY_RPM){
                drawInfoScreen();
                
            }
        }
        
    }
    return 0;
}

static void init(void) {
    /* Initialize debug LEDs. */    
    DDRB = 0xFF;
    PORTB = 0x00;
    
    DDRC = 0xFF;
    PORTC = 0x00;
    
    /*PWM */
    DDRB |= 1<<PINB6;
    PORTB &= ~(1<<PINB6);
    
    /* external interrupt */
    DDRD &= ~(1 << PIND0 |1 << PIND0); 
    PORTD |= 1 << PIND0 | 1 << PIND0;
    
    /* ADC0 && ADC7 */
    DDRF &= ~(PINF0 | PINF7);
    PORTF |=  (PINF0 | PINF7);
    
    /* input capture */
    DDRL &= ~(PINL0);
    PORTL&= ~(PINL0);
    
    /* Set up PWM */
    TCCR1A |= 1<<WGM11 | 1<<COM1B1;
    TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
    OCR1B = 0;
    ICR1 = TIMER1_COUNTER_TOP_PWM;
    
    /* Set up ADC */
    ADMUX  |= 1<< ADLAR;
    ADCSRA |=  1<<ADEN | 1 << ADIE;

    /* Setup Timer 3 for Sampling and FFT*/
    TCCR3B |= 1<<WGM32 | 1<<CS31;// | 1<<CS30;
    OCR3A = TIMER3_COUNTER_TOP_A;
    TIMSK3|= 1<<OCIE3A;
    
    /* Set up Timer4 for Input capture */
    TCCR4B|= 1<<ICNC4 | 1<<CS42;// | 1<< ICES4;
    TIMSK4|= 1<<ICIE4;
    
    /* Setup Timer 3 for Sampling and FFT*/
    TCCR5B |= 1<<WGM52 | 1<<CS51 | 1<<CS50;
    OCR5A = TIMER5_COUNTER_TOP;
    TIMSK5|= 1<<OCIE5A;
    
    /* Set up GLCD */    
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);
    
    /* external interrupt */
    EICRA |= 1 << ISC01| 1 << ISC11;
    EIMSK |= 1 << INT0 | 1 << INT1;
    
    /* Configure Serialnet */
    uint8_t mac[8] = { 9, 8, 1, 5, 2, 5, 1 ,0};
    serialnet_init(zigBeeCB, 2, 0x1294, mac);
    serialnet_dispatch();
    PORTC = serialnet_get_state();
    
    /* set ADC Mode */
    adc_mode = ADC_MODE_RPM;
    source_mode = MODE_USE_ADC;
    
}

static void zigBeeCB(uint16_t src_addr, const char *data, uint8_t data_length, uint8_t broadcast){
    //do OP Shit
    zigbee_address_master = src_addr;
    
    if(strncmp("SETRPM:", data, 7)==0){
        PORTB |= 0x01;
        
        zigbee_rpm = atoi(&data[7]);
        if(zigbee_rpm < 650 || zigbee_rpm > 3400){
            zigbee_rpm =0;
        }else{
            set_rpm = zigbee_rpm;
        }
        
        if(source_mode != MODE_NOISE_REDUCTION){
            source_mode = MODE_USE_ZIGBEE;
        }
    }else if(strncmp("RESETALERT", data, 9)==0){
        PORTB |= 0x02;
        source_mode = MODE_USE_ZIGBEE;
        set_rpm = zigbee_rpm;
        
    }else if(strncmp("RESETRPM", data, 8)==0){
        PORTB |= 0x04;
        if(source_mode == MODE_USE_ZIGBEE){
            source_mode = MODE_USE_ADC;
            OCR1B = median*(TIMER1_COUNTER_TOP_PWM/255);
            set_rpm = 10.7843*median+650;
        }
        zigbee_rpm=0;
    }
    
    serialnet_clear_state(SERIALNET_GOT_DATA);
}

static void drawFFT(void){
    glcdFillScreen(GLCD_CLEAR);
                
    for(int i=0; i<FFT_N/2;i++){
        xy_point top, bottom;
        
        top.x=i*2;
        if((fft_spectrum[i]/2)>=63){
            top.y=0;
        }else{
            top.y=63-(fft_spectrum[i]/2);
        }
        
        bottom.x=i*2+1;
        bottom.y=63;
        
        glcdFillRect(top, bottom, &glcdSetPixel);
    }   
}

static void drawInfoScreen(void){
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
    
    line_xy.y=line_xy.y+10;
    
    rect_clear_left.x= 0;
    rect_clear_left.y = rect_clear_left.y + 10;
    
    rect_clear_right.y=rect_clear_right.y + 10;
    
    glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
    glcdDrawText(errorLast, line_xy, &Standard5x7, &glcdSetPixel);
    
    
}


/* interrupts */
ISR(ADC_vect)           
{   
    if(adc_mode == ADC_MODE_RPM){
        median_array[median_count] = ADCH;
        median_count = (median_count +1)%5;
        
        if(median_count ==0){
            adc_mode = ADC_MODE_SAMPLE;
            
        }
        isr_flags |= ISR_ADC_FC;
    }else if(adc_mode == ADC_MODE_SAMPLE){
        fft_capture[fft_counter] = ADCW- 32768;
        fft_counter = (fft_counter +1)%128;
        if(fft_counter ==0){
            adc_mode = ADC_MODE_START_FFT;
            isr_flags |= ISR_FFT;
            TIMSK3 &= ~(1<<OCIE3A);
            sleep_enable();
        }
    }
    
}


ISR(TIMER3_COMPA_vect)
{   
    
    if(adc_mode == ADC_MODE_RPM){
        if(median_count ==0){
            ADMUX &= ~(1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
        }
    }else if(adc_mode == ADC_MODE_SAMPLE){
        if(fft_counter ==0){
            ADMUX |= (1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
            sleep_disable();
        }
    }else{
        return;
    }
    
    ADCSRA |= 1 <<ADSC;

}

ISR(TIMER5_COMPA_vect)
{ 
    isr_flags |= ISR_REFRESH_ZIGBEE;
}
    
ISR(TIMER4_CAPT_vect)
{    
    isr_flags |= ISR_INPUT_CAPTURE;    
    TCNT4=0;
}

ISR(INT0_vect){
    isr_flags |= ISR_SWITCH_GLCD;
}

ISR(INT1_vect){
    if(zigbee_rpm ==0){
        isr_flags |= ISR_NOISE_REDUCTION;
    }
}

