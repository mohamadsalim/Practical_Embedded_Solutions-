
#General Makefile to run sub makefiles 

win:
	make -f makefilewin.mk	

nix: 
	make -f makefilenix.mk

min:
	make -f makefilemin.mk

fix:
	make -f makefilefix.mk 
	

#.PHONY also is always out of date so it should be execute when we request excplicity "make clean" 	
.PHONY: Clean 
Clean:	
	rm *.o  	 