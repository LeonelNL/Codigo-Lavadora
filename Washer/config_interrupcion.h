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

#define CycleButtons GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t state = 0;
uint8_t BotonPulsado;

void GPIOIntHandler()
{
    GPIOIntClear(GPIO_PORTB_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_1|GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4);
    state = GPIOIntStatus(GPIO_PORTB_BASE, true);
    switch (state){
        case 1:
            BotonPulsado = 1;
            break;
        case 2:
            BotonPulsado = 2;
            break;
        case 4:
            BotonPulsado = 3;
            break;
    }
}
