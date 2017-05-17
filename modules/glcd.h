#include <avr/io.h>

#define GLCD_DISPLAY_RPM 1
#define GLCD_DISPLAY_FFT 2

void init_GLCD(void);

uint8_t switchScreen(void);

void drawFFT(uint16_t *fft_spectrum, uint8_t counter);

void drawInfoScreen(uint16_t set_rpm, uint16_t measured_rpm, uint8_t source_mode, uint16_t zigbee_rpm);
