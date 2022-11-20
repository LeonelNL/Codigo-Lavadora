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
#include "driverlib/pin_map.h"
#include "config_pines.h"
#include "definiciones.h"
#include "driverlib/uart.h"
#include "configuracionUART.h"
#include "machine_state.h"

int main(void)
{
    ConfiguracionPines();
    ConfigUART();
    GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);

    while(1)
    {
        MachineState(BotonPulsado1);
        UARTCharPut(UART0_BASE, '#');
        UARTCharPut(UART0_BASE, 'E');
        UARTCharPut(UART0_BASE, 'n');
        UARTCharPut(UART0_BASE, 't');
        UARTCharPut(UART0_BASE, 'e');
        UARTCharPut(UART0_BASE, 'r');
        UARTCharPut(UART0_BASE, ' ');
        UARTCharPut(UART0_BASE, 'T');
        UARTCharPut(UART0_BASE, 'e');
        UARTCharPut(UART0_BASE, 'x');
        UARTCharPut(UART0_BASE, 't');
        UARTCharPut(UART0_BASE, '&');
        SysCtlDelay(1333333);
    }
}

