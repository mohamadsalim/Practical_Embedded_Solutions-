
#if 0
/* p2_1.c Toggling LEDs in C using registers by addresses */
/* This program toggles all three LEDs for 0.5 second ON and 0.5 second OFF.*/
/*PF1 - red LED
PF2 - blue LED
PF3 - green LED
They are high active (a '1' turns ON the LED).*/
/* PORTF data register */
#define PORTFDAT (*((volatile unsigned int*)0x400253FC))
/* PORTF data direction register */
#define PORTFDIR (*((volatile unsigned int*)0x40025400))
/* PORTF digital enable register */
#define PORTFDEN (*((volatile unsigned int*)0x4002551C))
/* run mode clock gating register */
#define RCGCGPIO (*((volatile unsigned int*)0x400FE608))
/* coprocessor access control register */
#define SCB_CPAC (*((volatile unsigned int*)0xE000ED88))
void delayMs(int n); /* function prototype for delay */
int main(void)
{
/* enable clock to GPIOF at clock gating register */
RCGCGPIO |= 0x20;
/* set PORTF pin3-1 as output pins */
PORTFDIR = 0x0E;
/* set PORTF pin3-1 as digital pins */
PORTFDEN = 0x0E;
while(1)
{
/* write PORTF to turn on all LEDs */
PORTFDAT = 0x0E;
delayMs(500);
/* write PORTF to turn off all LEDs */
PORTFDAT = 0;
delayMs(500);
}
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access*/
/* This is required since TM4C123G has a floating point coprocessor */
SCB_CPAC |= 0x00F00000;
}

#endif

#if 1
/* p2_3b.c: Toggling LEDs using special function registers by their names defined in
the TivaWare header file */
#include <stdint.h>
#include "tm4c123gh6pm.h"
void delayMs(int n);
int main(void)
{
/* enable clock to GPIOF at clock gating control register */
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
/* enable the GPIO pins for the LED (PF3, 2 1) as output */
GPIO_PORTF_DIR_R = 0x0E;
/* enable the GPIO pins for digital function */
GPIO_PORTF_DEN_R = 0x0E;
while(1)
{
GPIO_PORTF_DATA_R = 0x0E; /* turn on all LEDs */
delayMs(500);
GPIO_PORTF_DATA_R = 0; /* turn off all LEDs */
delayMs(500);
}
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor. */
NVIC_CPAC_R |= 0x00F00000;
}

#endif

#if 0
/* p2.4.c: Toggling a single LED
 This program turns on the red LED and toggles the blue LED 0.5 sec on and 0.5 sec off. */
#include <stdint.h>
#include "C:\ti\TivaWare_C_Series-1.1\inc\tm4c123gh6pm.h"
void delayMs(int n);
int main(void)
{
/* enable clock to GPIOF at clock gating control register */
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
/* enable the GPIO pins for the LED (PF3, 2 1) as output */
GPIO_PORTF_DIR_R = 0x0E;
/* enable the GPIO pins for digital function */
GPIO_PORTF_DEN_R = 0x0E;
/* turn on red LED only and leave it on */
GPIO_PORTF_DATA_R = 0x02;
while(1)
{
GPIO_PORTF_DATA_R |= 4; /* turn on blue LED */
delayMs(500);
GPIO_PORTF_DATA_R &= ~4; /* turn off blue LED */
delayMs(500);
}
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor. */
NVIC_CPAC_R |= 0x00F00000;
}
#endif

#if 0
/* p4_1.c: Sending "YES" to UART0 on TI ARM Launchpad (TM4C123GH6PM) */
/* UART0 is on USB/Debug */
/* Use TeraTerm to see the message "YES" on a PC */
#include <stdint.h>
#include "tm4c123gh6pm.h"

void UART0Tx(char c);
void delayMs(int n);
int main(void)
{
SYSCTL_RCGCUART_R |= SYSCTL_PPUART_P0; /* provide clock to UART0 */
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; /* enable clock to PORTA */
/* UART0 initialization */
UART0_CTL_R = 0; /* disable UART0 */
UART0_IBRD_R = 104; /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
UART0_FBRD_R = 11; /* fraction part, see Example 4-4 */
UART0_CC_R = 0; /* use system clock */
UART0_LCRH_R = 0x60; /* 8-bit, no parity, 1-stop bit, no FIFO */
UART0_CTL_R = 0x301; /* enable UART0, TXE, RXE */
/* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
GPIO_PORTA_DEN_R = 0x03; /* Make PA0 and PA1 as digital */
GPIO_PORTA_AFSEL_R = 0x03; /* Use PA0,PA1 alternate function */
GPIO_PORTA_PCTL_R = 0x11; /* configure PA0 and PA1 for UART */
delayMs(10); /* wait for output line to stabilize */
for(;;)
{
UART0Tx('Y');
UART0Tx('E');
UART0Tx('S');
UART0Tx(' ');
}
}
/* UART0 Transmit */
/* This function waits until the transmit buffer is available then */
/* writes the character in the transmit buffer. It does not wait */
/* for transmission to complete. */
void UART0Tx(char c)
{
while((UART0_FR_R & UART_FR_TXFF) != 0); /* wait until Tx buffer not full */
UART0_DR_R = c; /* before giving it another byte */
}
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor. */
NVIC_CPAC_R |= 0x00F00000;
}
#endif