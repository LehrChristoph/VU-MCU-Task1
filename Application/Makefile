#
# Makefile for the C interrupt demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
CLOCK		= 1600000

SRC_DIR		= ./src		# directory where source code is stored
OBJ_DIR		= ./obj		# directory where object files will be created
LIB_DIR		= ./libs	# directory where the libraries are stored
INC_DIR		= ./inc		# includes from external files, e.g. libraries

SRCS		= $(wildcard $(SRC_DIR)/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/avr_libs/basics/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/avr_libs/modules/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/provided_code/*.c)
SRCS	   += $(wildcard $(SRC_DIR)/provided_code/wiimote/*.c)
OBJECTS     = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBOBJECTS  =

INCLUDES	= $(INC_DIR) $(SRC_DIR) $(SRC_DIR)/avr_libs $(SRC_DIR)/provided_code
LIBS		= $(OBJ_DIR)/avr_libs $(OBJ_DIR)/provided_code
LIBS 	   += $(wildcard $(LIB_DIR)/*.a)

DEFINES		= F_CPU=$(CLOCK)

MCU         = atmega1280

CCLD        = avr-gcc
ASFLAGS     = -mmcu=$(MCU) -I. -x assembler-with-cpp -Wa,-adhlns=$(<:.S=.lst),-gstabs
CCFLAGS     = -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -fshort-enums -fpack-struct -funsigned-char -funsigned-bitfields
CCFLAGS    += $(DEFINES:%=-D%) $(INCLUDES:%=-I%)
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf,-lprintf_min -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
LDFLGAS    += $(LIBS:%=-L%)

PROG        = avrprog2
PRFLAGS     = -m$(MCU) -d

all: $(OBJ_DIR) $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(LIBOBJECTS)
	$(CCLD) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBOBJECTS)

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
