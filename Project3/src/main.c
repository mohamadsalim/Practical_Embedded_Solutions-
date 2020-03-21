

/********************************************************************
************The First Project of GNU make****************************
********************************************************************/

#include "Lib.h"
#include "App1.h"




int main(void)
{
	unsigned char result ;
	unsigned char a = 20 , b = 25 ;
	result = SumFunc(a,b);
	Printd(&result);
	
 return 0 ;	
}
