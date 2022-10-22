#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "config_interrupcion.h"

#define CycleLeds GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
#define CycleButtons GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4


void ConfiguracionPines()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    /*-------------------- Configuracion de los LEDS de ciclos -------------------*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, CycleLeds);

/*-------------------- Configuracion de los pines de BOTONES de ciclos -------------------*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, CycleButtons);
    GPIOPadConfigSet(GPIO_PORTB_BASE, CycleButtons, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntEnable(GPIO_PORTB_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_1|GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4);
    GPIOIntTypeSet(GPIO_PORTB_BASE, CycleButtons, GPIO_LOW_LEVEL);
    IntPrioritySet(INT_GPIOB, 0);
    IntRegister(INT_GPIOB, GPIOIntHandler);
    IntEnable(INT_GPIOB);
    IntMasterEnable();
}
