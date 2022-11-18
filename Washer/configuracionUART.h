#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

char dato[1];
uint8_t PhaseMachine;


void ConfigUART()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    IntMasterEnable(); //enable processor interrupts
    IntEnable(INT_UART0); //enable the UART interrupt
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT); //only enable RX and TX interrupts
}


void UARTIntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(UART0_BASE, true); //get interrupt status
    UARTIntClear(UART0_BASE, ui32Status); //clear the asserted interrupts

    while(UARTCharsAvail(UART0_BASE)) //loop while there are chars
    {
        dato[0] = UARTCharGetNonBlocking(UART0_BASE);
        switch(dato[0])
        {
            case NivelBajoSerial:

                break;

            case NivelMedioSerial:

                break;

            case NivelAltoSerial:

                break;

            case CicloHighSerial:
                BotonPulsado1 = 1;
                BotonHigh1 = 1;
                BotonMedium1 = 0, BotonLow1 = 0, BotonAU1 = 0;
                break;

            case CicloMediumSerial:
                BotonPulsado1 = 3;
                BotonMedium1 = 1;
                BotonHigh1 = 0, BotonLow1 = 0, BotonAU1 = 0;
                break;

            case CicloLowSerial:
                BotonPulsado1 = 4;
                BotonLow1 = 1;
                BotonHigh1 = 0, BotonMedium1 = 0, BotonAU1 = 0;
                break;

            case CicloAuSerial:
                BotonPulsado1 = 5;
                BotonAU1 = 1;
                BotonHigh1 = 0, BotonLow1 = 0, BotonMedium1 = 0;
                break;

            case StartCicloSerial:
                BotonPulsado1 = 2;
                if(PhaseMachine == 0 || 1 || 2)
                {
                    if(BotonHigh1 == 1)
                    {
                        BotonPulsado1 = 6;
                    }
                    else if(BotonMedium1 == 1)
                    {
                        BotonPulsado1 = 7;
                    }
                    else if(BotonLow1 == 1)
                    {
                        BotonPulsado1 = 8;
                    }
                    else if(BotonAU1 == 1)
                    {
                        BotonPulsado1 = 9;
                    }
                }
                break;
        }
    }
}
