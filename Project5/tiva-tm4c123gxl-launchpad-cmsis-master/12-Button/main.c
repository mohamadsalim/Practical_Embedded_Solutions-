/**
 * @file     main.c
 * @brief    Blink LEDs using SysTick generated delays and GPIO interrupts
 * @version  V1.0
 * @date     23/01/2016
 *
 * @note     Uses interrupt to monitor input.
 * @note     Uses systick to count time.
 * @note     The GPIO interface is implemented using callback routine.
 * @note     The blinking frequency does not depends on core frequency.
 * @note     Button press reverses blinking cycle. Not always due to bouncing.
 * @note     CMSIS library used.
 *
 **/

#include "TM4C123GH6PM.h"

/**
 * BIT Macro
 *
 * To avoid magic numbers
 */
#define BIT(N) (1U<<(N))

/**
 * PORTA..G configured by using bit 0..6
 */
//@{
#define BITPORTA        BIT(0)
#define BITPORTB        BIT(1)
#define BITPORTC        BIT(2)
#define BITPORTD        BIT(3)
#define BITPORTE        BIT(4)
#define BITPORTF        BIT(5)
#define BITPORTG        BIT(6)
//@}



/**
 * LEDs are in PortF(3:1)
 */
//@{
#define LED_RED         BIT(1)
#define LED_BLUE        BIT(2)
#define LED_GREEN       BIT(3)
#define LED_ALL         (LED_RED|LED_BLUE|LED_GREEN)
#define LED_NONE        0
//@}

/**
 * Switches are in PortF(4) and PortF(0)
 */
//@{
#define SW1             BIT(4)
#define SW2             BIT(0)
#define SW_ALL          (SW1|SW2)
//@}


/**
 * @brief Bus to be used to access GPIO
 *
 * @note AHB: Uses base address 0x4005D000
 *            1 clock access
 *            Corresponding bit in HBCTL must be set
 * @note APB: Uses base address 0x40025000
 *            Slow (2 clock access)
 *            Legacy
 *
 * @note Comment out the following to use APB
 */
#define USE_AHB


/*
 * Forward definition of GPIO routines
 */
void GPIO_Init(uint32_t outputs, uint32_t inputs);
static inline void GPIO_WritePins(uint32_t zeroes, uint32_t ones);
static inline uint32_t GPIO_ReadPins(void);


/***************************************************************************
 *                                                                         *
 *              SysTick Routines                                           *
 *                                                                         *
 ***************************************************************************/

/**
 * @brief SysTick Handler
 *
 * @note  Called every 1 ms
 */

//@{
volatile uint32_t tick = 0;
volatile uint32_t sentido = 0;

void SysTick_Handler(void) {
uint32_t bits;

    tick++;
    bits = GPIO_ReadPins();
    if( (bits&SW1) != 0 ) { // No debounce yet
        sentido = !sentido;
    }

}
//@}
/**
 * @brief Delay
 *
 * @note  It gives a delay milliseconds delay
 *
 */
void Delay(uint32_t delay) {
uint32_t tbegin = tick;

    while( (tick-tbegin)<delay ) {}
}

/**
 * @brief udelay
 *
 * @note  It gives a precise delay
 * @note  Units are given by the period of SysTick clock
 */
void udelay(uint32_t delay) {
uint32_t tbegin = SysTick->VAL;

    while( ((SysTick->VAL-tbegin)&0xFFFFFF)<delay ) {}

}

/**
 * @brief xdelay
 *
 * @note  It gives a very small delay
 */
void xdelay(volatile uint32_t delay) {

    while( delay-- ) {}

}

/***************************************************************************
 *                                                                         *
 *              GPIO control routines                                      *
 *                                                                         *
 ***************************************************************************/

/**
 * @brief Initialization of GPIO Port F
 *
 * @note LED pins set to output
 */
void
GPIO_Init(uint32_t outputs, uint32_t inputs) {
GPIOA_Type *gpio;

#ifdef USE_AHB
    gpio = GPIOF_AHB;
    /* Enable AHB access for Port F  */
    SYSCTL->GPIOHBCTL |= BIT(5);
#else
    gpio = GPIOF;
#endif

    /* Enable clock for Port F         */
    SYSCTL->RCGCGPIO  |= BIT(5);
    xdelay(10);


    /*
     * To modify PF0, it is necessary to unlock it because it can be used as NMI
     * See Datasheet: Observation at 10.1 and Commit control in 10.2.4
     */

    if( (inputs|outputs)&1 ) {
        gpio->LOCK = 0x4C4F434B;                // Unlock to set PF0 = ASCII('LOCB')
        *(uint32_t * )(&(gpio->CR)) = 1;        // CR is marked read-only
    }

    /* Pins for led are digital output */
    gpio->DIR    = outputs;                     // Only specified bits are outputs
    gpio->DEN    = inputs|outputs;              // All pins are digital I/O
    gpio->PUR    = inputs;                      // Set pull up for inputs



    xdelay(10);
    if( (inputs|outputs)&1 ) {
        gpio->LOCK = 0x0;                       // Lock again
        *(uint32_t * )(&(gpio->CR))   = 0x0;    // CR is marked read-only
    }

}


/**
 * @brief Write to GPIO Port F
 *
 * @note First, pins specified by zero are zeroed. Then the pins
 *       specified by ones, area set
 *
 * @note Use bit-banding
 *
 * @note GPIOA_Type defined as:
 * typedef struct {
 *   __I  uint32_t  RESERVED0[255];  // Deveria ser BITBAND[255]
 *   __IO uint32_t  DATA;
 *   __IO uint32_t  DIR;
 *    ....
 *    } GPIOA_Type;
 *
 */
static inline void
GPIO_WritePins(uint32_t zeroes, uint32_t ones) {
uint32_t *base;

#ifdef USE_AHB
    base = (uint32_t *) GPIOF_AHB_BASE;
#else
    base = (uint32_t *) GPIOF_BASE;
#endif

    *(base+(zeroes|ones)) = ones;
}


/**
 * @brief Reads pins in GPIO Port F
 */
inline uint32_t
GPIO_ReadPins(void) {
GPIOA_Type *gpio;

#ifdef USE_AHB
    gpio = GPIOF_AHB;
#else
    gpio = GPIOF;
#endif
    return gpio->DATA;
}


/***************************************************************************
 *                                                                         *
 *              Main procedure                                             *
 *                                                                         *
 ***************************************************************************/

/**
 * @brief Main routine
 *
 * Initializes GPIO
 * Blink LEDs
 */

int main(void) {
int state;

    SysTick_Config(SystemCoreClock/1000);

    GPIO_Init(LED_ALL,SW_ALL);

    // Enable Interrupt from SysTick
    NVIC_EnableIRQ (SysTick_IRQn);


    __enable_irq();

    state = 0;
    while(1) {

        switch(state) {
        case 0:
            GPIO_WritePins(LED_ALL, LED_RED);
            Delay(1000);
            if( sentido )
                state = 1;
            else
                state = 2;
            break;
        case 1:
            GPIO_WritePins(LED_ALL, LED_GREEN);
            Delay(1000);
            if( sentido )
                state = 2;
            else
                state = 0;
            break;
        case 2:
            GPIO_WritePins(LED_ALL, LED_BLUE);
            Delay(1000);
            if( sentido )
                state = 0;
            else
                state = 1;
            break;
        }

    }
    return 0;
}
