#
# Makefile for the C interrupt demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
CLOCK		= 16000000

SRC_DIR		= ./src
OBJ_DIR		= ./obj
INC_DIR		= ./inc
LIB_DIR		= ./libs

SRCS		= $(wildcard $(SRC_DIR)/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/basics/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/drivers/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/modules/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/application/*.c)

OBJECTS     = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBOBJECTS  =

INCLUDES	= $(SRC_DIR) $(SRC_DIR)/avr_libs $(INC_DIR)
LIB_DIRS	= $(OBJ_DIR)/avr_libs $(LIB_DIR)
LIBS 		= glcd

DEFINES		= F_CPU=$(CLOCK)

MCU         = atmega1280

CCLD        = avr-gcc
ASFLAGS     = -mmcu=$(MCU) -I. -x assembler-with-cpp -Wa,-adhlns=$(<:.S=.lst),-gstabs
CCFLAGS     = -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -fshort-enums -fpack-struct -funsigned-char -funsigned-bitfields -finline-functions
CCFLAGS    += $(DEFINES:%=-D%) $(INCLUDES:%=-I%)
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf,-lprintf_min -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums

PROG        = avrprog2
PRFLAGS     = -m$(MCU) -d

all: $(OBJ_DIR) $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(LIBOBJECTS)
	$(CCLD) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBOBJECTS) $(LIB_DIRS:%=-L%) $(LIBS:%=-l%)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.S
	$(CCLD) -c $(ASFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(dir $(OBJECTS))

install: $(FILENAME).elf
	make all
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf
	rm -rf $(OBJ_DIR)
