== Serialnet Library ==

This driver abstracts the access to the ATZB-24-module over serialnet.

= Pin Configuration =

At the moment the module defaults to UART3 on PORTJ (on an atmega 1280) with switches 3 and 7 of the EasyBee-module enabled.

== How to use it ==

Include 'serialnet.h' wherever you want to use the serialnet functions. Link your own object files together with the library (add '-lserialnet' to the linker command). E.g. call the linker in the following way:

avr-gcc main.o -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -lserialnet -L. -o application.elf

Make sure that the header and library files are in the compilers and linkers search path. E.g. in the same directory as your other source files ('-L.' adds the current directory to the linkers library search path).
