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
#include "highdefault.h"
#include "config_pines.h"
#include "definiciones.h"
#include "driverlib/uart.h"
#include "configuracionUART.h"


int main(void)
{
   ConfiguracionPines();
   ConfigUART();
   while(1)
    {
        HighCycleLedDefault(BotonPulsado);
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
        SysCtlDelay(133333);
    }
}

