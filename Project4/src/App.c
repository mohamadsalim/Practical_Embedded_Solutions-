


#include "App.h"


unsigned char SumFunc(unsigned char x , unsigned char y)
{
	unsigned char Sum = x+y ; 
	return ((Sum == 0 || Sum < x || Sum < y) ? 0:Sum);	
}