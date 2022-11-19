#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "definiciones.h"


#define CycleButtons GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t state = 0;
uint8_t CicloSeleccionado = 0;
uint8_t BotonPulsado1;

void GPIOIntHandler(uint8_t *PhaseState)
{
    GPIOIntClear(GPIO_PORTB_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_1|GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4);
    state = GPIOIntStatus(GPIO_PORTB_BASE, true);

    switch(state)
    {
            case 1:                                                                 //BotonStart
                BotonPulsado1 = 2;
                break;

            case 2:                                                                //Boton HIGH
                BotonPulsado1 = 1;
                CicloSeleccionado = CicloHigh;
                break;

            case 4:                                                               //Boton MEDIUM
                BotonPulsado1 = 3;
                CicloSeleccionado = CicloMedium;
                break;

            case 8:                                                              //Boton LOW
                BotonPulsado1 = 4;
                CicloSeleccionado = CicloLow;
                break;

            case 16:                                                             //Boton CICLO AU
                BotonPulsado1 = 5;
                CicloSeleccionado = CicloAU;
                break;
    }
}

