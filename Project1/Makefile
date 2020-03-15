#Makefile for Project 1.1 


#defualt Target
Base : main.o  Lib.o  App1.o 
	gcc main.c Lib.c App1.c -o FirstProject 

main.o : main.c
	gcc -c main.c -o main.o
	
Lib.o : Lib.c Lib.h	 
	gcc -c Lib.c -o Lib.o 
	
App1.o : App1.c  App1.h
	gcc -c App1.c -o App1.o
	