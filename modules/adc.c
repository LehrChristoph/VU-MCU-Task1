#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <fftavr/ffft.h>

#define ADC_MODE_RPM 1
#define ADC_MODE_SAMPLE 2
#define ADC_MODE_START_FFT 4

#define ISR_ADC_FC 1 
#define ISR_ADC_SAMPLING 2
#define ISR_INPUT_CAPTURE 4
#define ISR_FFT 8
#define ISR_SWITCH_GLCD 16
#define ISR_NOISE_REDUCTION 32
#define ISR_REFRESH 64

#define TIMER3_COUNTER_TOP_A 250

static uint8_t fft_counter =0;
static complex_t fft_buffter[FFT_N];		/* FFT buffer */
static uint16_t fft_spectrum[FFT_N/2];		/* Spectrum output buffer */
static int16_t fft_capture[FFT_N];

static uint8_t median=0;
static volatile uint8_t median_count =0;
static uint8_t median_array[5] = {0,0,0,0,0};

static uint8_t adc_mode = ADC_MODE_RPM;
static uint8_t isr_flags=0;

void init_ADC(void){

    /* ADC0 && ADC7 */
    DDRF &= ~(PINF0 | PINF7);
    PORTF |=  (PINF0 | PINF7);
    
    /* Set up ADC */
    ADMUX  |= 1<< ADLAR;
    ADCSRA |= 1 << ADIE;

    /* Setup Timer 3 for Sampling and FFT*/
    TCCR3B |= 1<<WGM32 | 1<<CS31;
    OCR3A = TIMER3_COUNTER_TOP_A;
    TIMSK3|= 1<<OCIE3A;

}

uint8_t get_median(void){
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
        median = median_temp[2];
    }
    return median;
}

void enable_ADC(void){
    adc_mode = ADC_MODE_RPM;
    TIMSK3|= 1<<OCIE3A;
    
}

uint8_t get_isr_flags(void){
    return isr_flags;
}

uint16_t get_sum_up(void){
    //input for fft
    fft_input(fft_capture, fft_buffter);
    //start fft
    fft_execute(fft_buffter);
    //get result of fft
    fft_output(fft_buffter, fft_spectrum);
    
    uint16_t max_specs[8] = {fft_spectrum[2],fft_spectrum[3],fft_spectrum[4],fft_spectrum[5],fft_spectrum[6],fft_spectrum[7],fft_spectrum[7],fft_spectrum[9]};
    //uint16_t sum_up=0;
    uint16_t sum_up=0;
    uint8_t i=0;
    uint8_t j=0;
    
    for(i=10; i<FFT_N/2; i++){
        uint16_t min =max_specs[0];
        uint8_t index_min=0;
        
        for(j =1; j<8; j++){
            if(max_specs[j]<min){
                min=max_specs[j];
                index_min =j;
            }
        }
        if(fft_spectrum[i] > min){
            max_specs[index_min] = fft_spectrum[i];
        }
    }
    
    for(i=0; i<8;i++){
        sum_up += max_specs[i];
    }
    
    return sum_up;
}

uint16_t* get_fft_spectrum(void){
    return fft_spectrum;
}

ISR(ADC_vect)           
{   
    if(adc_mode == ADC_MODE_RPM){
        median_array[median_count] = ADCH;
        median_count = (median_count +1)%5;
        
        if(median_count ==0){
            adc_mode = ADC_MODE_SAMPLE;
            isr_flags |= ISR_ADC_FC;
        }
        ADCSRA &= ~(1<<ADEN);
    }else if(adc_mode == ADC_MODE_SAMPLE){
        fft_capture[fft_counter] = ADCW- 32768;
        fft_counter = (fft_counter +1)%128;
        if(fft_counter ==0){
            adc_mode = ADC_MODE_START_FFT;
            isr_flags |= ISR_FFT;
            TIMSK3 &= ~(1<<OCIE3A);
            ADCSRA &= ~(1<<ADEN);
            sleep_enable();
        }
    }
}


ISR(TIMER3_COMPA_vect)
{   
    
    if(adc_mode == ADC_MODE_RPM){
        ADCSRA |=  1<<ADEN;
        if(median_count ==0){
            ADMUX &= ~(1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
        }
    }else if(adc_mode == ADC_MODE_SAMPLE){
        ADCSRA |=  1<<ADEN;
        if(fft_counter ==0){
            ADMUX |= (1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
            sleep_disable();
        }
    }else{
        return;
    }
    
    ADCSRA |= 1 <<ADSC;

}
