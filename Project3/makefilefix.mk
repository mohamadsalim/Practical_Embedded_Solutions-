#Makefile for Project 3.4
#Example for using Sufix rules 


#user defined variable 
Objects = main.o Lib.o App1.o	

#using automatic variable vpath to search for files on it's directory 
vpath %.c src 
vpath %.h headers
 
#automatic varaible to get included fiels path in compile time 
CCPFLAGS = -I headers -I scr 
CCPFLAGS11 = -I scr  

#defualt Target
#Base is always out of date 
Base : $(Objects)  	
#Make will checks the time of main.o and it's prerequites 	
main.o : main.c
#Make will checks the time of Lib.o and it's prerequites	
Lib.o : Lib.c Lib.h	   
#Make will checks the time of App1.o and it's prerequites	
App1.o : App1.c  App1.h 

#pattern implicit rule to generate execuatble file 
 %: 
	$(LINK.o) $^ -o SeventhExe
	
#sufix implicit rule to generate object files	
.c.o:
	$(COMPILE.c) $(CCPFLAGS) $(CCPFLAGS11) $(OUTPUT_OPTION) $<
	
#Phony target to delete all obj files	 
#Clean is it's phony prerequiets 
#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
.PHONY: Clean 
Clean:	
	rm *.o   

	
