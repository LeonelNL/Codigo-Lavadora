#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define CycleLeds GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t CurrentState;

void HighCycleLedDefault(CurrentState){
    switch(CurrentState){
        case 1:                                                 // IDLE LEDS OFF
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);
            break;
        case 2:                                                 // Boton Start, High (Ciclo 1) LED CICLO 1 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
            break;
        case 3:                                                 // Boton ciclo 2 LED CICLO 2 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 4);
            break;
        case 4:                                                 // Boton ciclo 3 LED CICLO 3 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 8);
            break;
        case 5:                                                 // Boton ciclo 4 LED CICLO 4 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
            break;
        case 6:                                                 // Cycle run, LED START ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 1);
            break;
    }
}

