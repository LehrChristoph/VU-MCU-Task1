#
# Makefile for the C interrupt demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
OBJECTS     = main.o drivers/fftavr/ffft.o modules/controller/pid.o
LIBOBJECTS  = drivers/libglcd/libglcd.a drivers/libserialnet/libserialnet.a
MCU         = atmega1280

CCLD        = avr-gcc
ASFLAGS     = -mmcu=$(MCU) -I. -x assembler-with-cpp -Wa,-adhlns=$(<:.S=.lst),-gstabs 
CCFLAGS     = -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -fshort-enums -fpack-struct -funsigned-char -funsigned-bitfields 
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf,-lprintf_min -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(LIBOBJECTS)
	$(CCLD) $(LDFLAGS) -Ldrivers -Ldrivers/libglcd -lglcd  -Ldrivers/avrfft -Ldrivers/libserialnet -lserialnet -Lmodules/controller -o $@ $(OBJECTS) $(LIBOBJECTS)

%.o: %.c
	$(CCLD) $(CCFLAGS) -S -Idrivers -Imodules -c -o $@ $<

%.o : %.S
	$(CCLD) -c $(ASFLAGS) $< -o $@
	
install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS)

