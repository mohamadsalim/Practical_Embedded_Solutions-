
#Definition of Done Project (Final Project) 
#makefile for ARM Cortex_M4 embedded targets
#HW_PLATFORM = TM4C123GH6 
#GNU_MAKE VERSION = 
#Author = Mohamed salim
#Date = 15/3/2020 8:30Am

Source      =./SourceCode/main
Header      =./SourceCode/inc
OBJECTS     = main.o startup_ARMCM4.o
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

# Linker
LD=arm-none-eabi-gcc

# Path to linker script
LSCRIPT = TM4C123GH6.ld

# Linker flags
LFLAGS=-T $(LSCRIPT) --specs=nosys.specs

# Object copy (for converting formats)
OBJCOPY=arm-none-eabi-objcopy
OFLAGS=-O ihex
HEX2BIN  = $(HEX2BIN_TOOL)/hex2bin
#-{ Programming/Debugging Definitions }-----------------------------------------

# Debugger
DBG=arm-none-eabi-gdb

# OpenOCD
OCD=openocd

		
$(BIN_Release)/Program.bin : $(BIN_Release)/Program.hex
	@echo "Converting .hex to .bin target..."
	$(HEX2BIN) -b $< 

$(BIN_Release)/Program.hex : $(Bin_Debug)/Program.out
	@echo "Converting .out to .hex target..."
	$(OBJCOPY) $(OFLAGS) $(Bin_Debug)/Program.out $(BIN_Release)/Program.hex

$(Bin_Debug)/Program.out: $(OBJECTS) 
	@echo "Generate .out ..."
	$(LD) $(LFLAGS) $(OBJECTS) -o $(Bin_Debug)/Program.out 

main.o : $(Source)/main.c
	$(CC) $(CCPFLAGS) $(CFLAGS) $< -o $@
	
startup_ARMCM4.o : startup_ARMCM4.s 
	$(CC) $(CCPFLAGS) $(CFLAGS) $< -o $@
		

.PHONY : Clean
Clean : 
	rm *.o
	
.PHONY : clean_all
clean_all :
	@echo "Clean all in processing..."
	rm *.o
	rm $(BIN_Release)/*.bin
	rm $(BIN_Release)/*.hex
	rm $(Bin_Debug)/*.out
	
 