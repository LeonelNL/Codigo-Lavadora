#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"
#include "idle_state.h"
#include "standby_state.h"
#include "run_state.h"
#include "pause_state.h"

uint8_t PhaseMachine, BotonPresionado;
uint8_t BotonPulsado1;
uint8_t PhaseState;

void MachineState(BotonPresionado)
{

    switch(PhaseMachine)
    {
        case IdleState:
            Idle_State(BotonPresionado, CicloSeleccionado);
            PhaseState = IdleState;
            break;

        case StandbyState:
            Standby_State(BotonPresionado, CicloSeleccionado);
            PhaseState = StandbyState;
            break;

        case RunState:
            Run_State(BotonPresionado, CicloIniciado);
            PhaseState = RunState;
            break;

        case PauseState:
            Pause_State(BotonPresionado);
            PhaseState = PauseState;
            break;
    }
    BotonPulsado1 = 0;
}

