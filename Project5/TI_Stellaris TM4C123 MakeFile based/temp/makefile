

Source      =./SourceCode
Header      =./SourceCode/inc
OBJECTS     = main.o startup_ARMCM4
Obj_Debug   =./Debug 
Bin_Debug   =./Debug/Bin
obj_Release =./Release/Obj 
BIN_Release =./Release/Bin
CMSIS       =./SourceCode/cmsis
INC_C       =./SourceCode/inc_c
HEX2BIN_TOOL=./Tools/Hex2bin-2.5/bin/Release


VPATH = $(Source) $(Header) $(CMSIS) $(INC_C)


#-{ Compiler Definitions }------------------------------------------------------

# Compiler
CC=arm-none-eabi-gcc

# Device specific flags [1]
DFLAGS=-mcpu=cortex-m4 -mthumb -msoft-float
# Compiler flags
CFLAGS=$(DFLAGS) -g -c -Wall -Wextra

CCPFLAGS = -I $(Header) -I $(INC_C) -I $(CMSIS)

HEX2BIN  = "$(HEX2BIN_TOOL)/hex2bin"

# Linker
LD=arm-none-eabi-gcc

# Path to linker script
LSCRIPT = TM4C123GH6.ld

# Linker flags
LFLAGS=-T $(LSCRIPT) --specs=nosys.specs

# Object copy (for converting formats)
OBJCOPY=arm-none-eabi-objcopy
OFLAGS=-O ihex

#-{ Programming/Debugging Definitions }-----------------------------------------

# Debugger
DBG=arm-none-eabi-gdb

# OpenOCD
OCD=openocd


$(BIN_Release)/Program.bin : $(BIN_Release)/Program.hex
	$(HEX2BIN) -b $< 

$(BIN_Release)/Program.hex : $(Bin_Debug)/Program.out
	$(OBJCOPY) $(OFLAGS) $(Bin_Debug)/Program.out $(BIN_Release)/Program.hex

$(Bin_Debug)/Program.out: $(OBJECTS) 
	$(LD) $(LFLAGS) $(OBJECTS) -o $(Bin_Debug)/Program.out 

main.o : $(Source)/main.c
	$(CC) $(CCPFLAGS) $(CFLAGS) $< -o $@
	
startup_ARMCM4.o : startup_ARMCM4.s 
	$(CC) $(CCPFLAGS) $(CFLAGS) $< -o $@
		

.PHONY:clean
clean:
	rm *.o
	
 