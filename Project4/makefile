#Project 4.4 for GENERAT Automatically Depndencies 

VPATH = src headers

PATHS    = src -I headers 

OBJECTS  = main.o App.o Lib.o
 
SRC      = main.c App.c Lib.c 

CC       = gcc 

CPPFLAGS = -I $(PATHS)
  
#defualt Target
#Base is always out of date 
Depndencies : $(OBJECTS)  	
#Make will checks the time of main.o and it's prerequites 	
main.o: main.c App.h Lib.h
#Make will checks the time of Lib.o and it's prerequites	
Lib.o: Lib.c Lib.h	   
#Make will checks the time of App1.o and it's prerequites	
App.o: App.c App.h 

include $(subst .c,.d,$(SRC))

%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
	
	