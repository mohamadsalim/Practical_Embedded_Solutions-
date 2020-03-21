#Makefile for Project 3.1
#using VPATH Automatic Variable

#using user define variable 
Objects = main.o Lib.o App1.o	
#using automatic variable VPATH to search for files on listed directory
VPATH = src headers 
#using ccpflags user variable to define including files to compiler when it compiles c files 
CCPFLAGS = -I headers -I src

#defualt Target
#Base is always out of date 
Base : $(Objects)  
	gcc $^ -o FourthdExe 

#Make will checks the time of main.o and it's prerequites 	
main.o : main.c
	gcc $(CCPFLAGS) -c $< 
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.c Lib.h	 
	gcc $(CCPFLAGS) -c $<  
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.c App1.h
	gcc $(CCPFLAGS) -c $< 
#Phony target to delete all obj files	 
#Clean is it's phony prerequiets 
#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
.PHONY: Clean 
Clean:	
	rm *.o   

	