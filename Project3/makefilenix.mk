#Makefile for Project 3.2
#using VPATH , vpath Automatic Variable

#using user define variable 
Objects = main.o Lib.o App1.o	
#using automatic variable vpath to search for files on it's directory 
vpath %.c src 
vpath %.h headers
 
CCPFLAGS = -I headers -I src

#defualt Target
#Base is always out of date 
Base : $(Objects)  
	gcc $^ -o FifthExe 

#Make will checks the time of main.o and it's prerequites 	
main.o : main.c
	gcc $(CCPFLAGS) -c $< 
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.c Lib.h	 
	gcc $(CCPFLAGS) -c $<  
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.c  App1.h
	gcc $(CCPFLAGS) -c $< 
#Phony target to delete all obj files	 
#Clean is it's phony prerequiets 
#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
.PHONY: Clean 
Clean:	
	rm *.o   

	
