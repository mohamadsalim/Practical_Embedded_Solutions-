

/********************************************************************
************The First Project of GNU make****************************
********************************************************************/

#include "App1.h"
#include "Lib.h"



int main(void)
{
	unsigned char result ;
	unsigned char a = 25 , b = 6 ;
	result = SumFunc(a,b);
	Printd(&result);
	
 return 0 ;	
}
