#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define CycleLeds GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t CurrentState;

void HighCycleLedDefault(CurrentState)
{
    switch(CurrentState)
    {
        case 0:                                                 // Recien Endencido ciclo HIGH
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);
            break;
        case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
            break;
        case 2:                                                 // BOTON START
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 1);
            break;
        case 3:                                                 // Bonton MEDIUM
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 8);
            break;
        case 4:                                                 // Boton LOW
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 4);
            break;
        case 5:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
            break;
        case 6:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 17);
            break;
        case 7:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 9);
            break;
        case 8:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 5);
            break;
        case 9:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 3);
            break;
    }
}

