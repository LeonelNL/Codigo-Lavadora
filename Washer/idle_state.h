#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;

void Idle_State(uint8_t BotonPulsadoIdle)
{

        switch(BotonPulsadoIdle)
        {
            case 0:                                                 // Recien Endencido ciclo HIGH
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);
                break;
            case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
                PhaseMachine = StandbyState;
                break;
            case 2:                                                 // BOTON START
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
                PhaseMachine = StandbyState;
                break;
            case 3:                                                 // Bonton MEDIUM
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 8);
                PhaseMachine = StandbyState;
                break;
            case 4:                                                 // Boton LOW
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 4);
                PhaseMachine = StandbyState;
                break;
            case 5:                                                 // Boton AU
                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
                PhaseMachine = StandbyState;
                break;
        }
}
