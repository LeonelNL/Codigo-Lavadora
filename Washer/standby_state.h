#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;
uint8_t CicloIniciado;

void Standby_State(uint8_t BotonPulsadoStandby, uint8_t CicloSeleccionado)
{
    switch(BotonPulsadoStandby)
    {
        case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
            GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
            break;

        case 2:                                                 // BOTON START
            PhaseMachine = RunState;
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
    }

    CicloIniciado = CicloSeleccionado;
}
