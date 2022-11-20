#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;

void Standby_State(uint8_t BotonPulsadoStandby)
{

    switch(BotonPulsadoStandby)
    {
        case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
            break;
        case 2:                                                 // BOTON START
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
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
            PhaseMachine = RunState;
            break;
        case 7:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 9);
            PhaseMachine = RunState;
            break;
        case 8:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 5);
            PhaseMachine = RunState;
            break;
        case 9:                                                 // Boton AU
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 3);
            PhaseMachine = RunState;
            break;
    }

    CicloIniciado = CicloSeleccionado;

}
