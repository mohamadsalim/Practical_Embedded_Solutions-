#Makefile for Project 2.1
#using PHONY Target
#using Empty Target
	
#defualt Target
#Base is always out of date 
Base : main.o  Lib.o  App1.o MainTimeStamp 
	gcc main.o Lib.o App1.o -o FirstExe 

#Make will checks the time of main.o and it's prerequites 	
main.o : main.c
	gcc -c main.c 
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.c Lib.h	 
	gcc -c Lib.c  
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.c  App1.h
	gcc -c App1.c 
#this is an empty target to take a timestamp for main.o changing 
#so Make every time will checks on dendency of MainTimeStamp (i.e main.o) and if it's updated it will create MainTimeStamp again  
MainTimeStamp : main.o 
	touch MainTimeStamp 
#Clean is a PHONY Target to delete all obj files
Clean:	
	rm *.o  

	