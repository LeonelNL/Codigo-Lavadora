#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

uint8_t PhaseMachine;

void Pause_State(uint8_t BotonPulsadoPause)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); //blink LED
    switch(BotonPulsadoPause)
    {
        case 2:
            PhaseMachine = RunState;
            break;
    }
}
