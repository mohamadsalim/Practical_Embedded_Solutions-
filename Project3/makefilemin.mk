#Makefile for Project 3.3
#Example for using pattern rules 


#using user define variable 
Objects = main.o Lib.o App1.o	

#using automatic variable vpath to search for files on it's directory 
#vpath %.c src 
#vpath %.h headers

VPATH = src headers 
#automatic varaible to get included fiels path in compile time 
CCPFLAGS = -I headers 
CCPFLAGS11 = -I scr  
bin = ./bin


#defualt Target
#Base is always out of date 
Base: $(Objects)  	
#Make will checks the time of main.o and it's prerequites 	
main.o : 
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.h	   
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.h 

%.o: %.c
	$(COMPILE.c) $(CCPFLAGS) $(CCPFLAGS11) $(OUTPUT_OPTION) $<

%: 
	$(LINK.o) $^ -o $(bin)/$@ 
	rm *.o
#Phony target to delete all obj files	 
#Clean is it's phony prerequiets 
#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
.PHONY: Clean 
Clean:	
	rm *.o   

	
