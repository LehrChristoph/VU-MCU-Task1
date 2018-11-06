
all: wiimoteuarttest.elf

wiimoteuarttest.elf: PinChangeInterrupts.o USART3.o mac.o hal_wt41_fc_uart.o Timer1.o libwiimoteuarttest.a
	avr-gcc -mmcu=atmega1280 -o wiimoteuarttest.elf -L. -lwiimoteuarttest mac.o hal_wt41_fc_uart.o PinChangeInterrupts.o USART3.o Timer1.o

mac.o: mac.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -c -o mac.o mac.c

hal_wt41_fc_uart.o: hal_wt41_fc_uart.c
	avr-gcc -mmcu=atmega1280 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -I. -std=c99 -DF_CPU=16000000UL -DUSART3_ENABLE_FLOW_CONTROL -c -o hal_wt41_fc_uart.o hal_wt41_fc_uart.c

USART3.o: USART3.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -I. -DUSART3_ENABLE_FLOW_CONTROL -std=c99 -DF_CPU=16000000UL -c -o USART3.o USART3.c

Timer1.o: Timer1.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -I.   -std=c99 -DF_CPU=16000000UL -c -o Timer1.o Timer1.c

PinChangeInterrupts.o: PinChangeInterrupts.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -I. -std=c99 -DF_CPU=16000000UL -c -o PinChangeInterrupts.o PinChangeInterrupts.c

install: all
	avrprog2 --flash w:wiimoteuarttest.elf -v

clean:
	rm -f *.elf *.o
