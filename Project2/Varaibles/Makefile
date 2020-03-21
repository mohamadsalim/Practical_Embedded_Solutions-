#Makefile for Project 2.3
#using Automatic variables(user define , make define)
	
#using user define variable 
Objects = main.o Lib.o App1.o	

#defualt Target
#Base is always out of date 
Base : $(Objects)  
	gcc $^ -o ThirdExe 

#Make will checks the time of main.o and it's prerequites 	
main.o : main.c
	gcc -c $< 
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.c Lib.h	 
	gcc -c $<  
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.c  App1.h
	gcc -c $< 
 

	