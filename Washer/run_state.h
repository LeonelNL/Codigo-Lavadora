#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;
uint8_t BotonHigh1, BotonMedium1, BotonLow1, BotonAU1;

void Run_State(uint8_t BotonPulsadoRun)
{
    BotonHigh1 = 0, BotonMedium1 = 0, BotonLow1 = 0, BotonAU1 = 0;
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 1);
    switch(BotonPulsadoRun)
    {
        case 2:
            PhaseMachine = PauseState;
            break;
    }
}
