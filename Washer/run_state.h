#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;

void Run_State(uint8_t BotonPulsadoRun, uint8_t CicloIniciado)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 1);

    switch(BotonPulsadoRun)
    {
        case 2:
            PhaseMachine = PauseState;
            break;
    }
    switch(CicloIniciado)
    {
        case CicloHigh:

            break;

        case CicloMedium:

            break;

        case CicloLow:

            break;

        case CicloAU:

            break;
    }
}
