#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"
#include "idle_state.h"
#include "standby_state.h"

uint8_t PhaseMachine, BotonPresionado;

void MachineState(BotonPresionado)
{
    switch(PhaseMachine)
    {
        case IdleState:
            Idle_State(BotonPresionado);
            break;

        case StandbyState:
            Standby_State(BotonPresionado);
            break;

        case RunState:

            break;
    }
}

