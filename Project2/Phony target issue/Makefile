#Makefile for Project 2.2
#solving PHONY naming issue


#defualt Target
Base : main.o  Lib.o  App1.o  
	gcc main.o Lib.o App1.o -o SecondExe 

main.o : main.c
	gcc -c main.c 
	
Lib.o : Lib.c Lib.h	 
	gcc -c Lib.c  
	
App1.o : App1.c  App1.h
	gcc -c App1.c 

#Phony target to delete all obj files	 
#Clean is it's phony prerequiets 
#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
#.PHONY: Clean 
Clean:	
	rm *.o  