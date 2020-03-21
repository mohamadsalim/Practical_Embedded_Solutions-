#Project 5.1 for GENERAT Automatically Depndencies 


vpath %.c src
vpath %.h headers

PATHS    = src -I headers 

OBJECTS  = main.o App.o Lib.o
 
SRC      = ./src/main.c ./src/App.c ./src/Lib.c 

CC       = gcc 

CPPFLAGS = -I $(PATHS)

Dependancy : ./src/main.d ./src/App.d ./src/Lib.d		
main.d : main.c
App.d   : App.c
Lib.d   : Lib.c 

%.d : %.c
	$(CC) -M $(CPPFLAGS) $^ > $@
	
include $(SRC:.c=.d)	

:%.d %.o
	$(LINK.O) $(OBJECTS) -o $@
	
main.o : main.c
App.o : App.c 
Lib.o : Lib.c	
  	
%.o : %.c
	$(CC) $(CCPFLAGS) -c $<
	