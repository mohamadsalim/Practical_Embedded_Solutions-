# 1 "App1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "App1.c"



# 1 "App1.h" 1





unsigned char SumFunc(unsigned char x , unsigned char y) ;
# 5 "App1.c" 2


unsigned char SumFunc(unsigned char x , unsigned char y)
{
 unsigned char Sum = x+y ;
 return ((Sum == 0 || Sum < x || Sum < y) ? 0:Sum);
}
