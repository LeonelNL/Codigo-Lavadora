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

char dato[0];
uint32_t i = 0;


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
        dato[i] = UARTCharGetNonBlocking(UART0_BASE);
        switch(dato[i])
        {
            case NivelBajoSerial:

                break;

            case NivelMedioSerial:

                break;

            case NivelAltoSerial:

                break;

            case BombaDrenadoOnSerial:

                break;

            case BombaDrenadoOffSerial:

                break;

            case BombaLlenadoOnSerial:

                break;

            case BombaLlenadoOffSerial:

                break;

            case CicloHighSerial:
                BotonPulsado = 1;
                break;

            case CicloMediumSerial:
                BotonPulsado = 3;
                break;

            case CicloLowSerial:
                BotonPulsado = 4;
                break;

            case CicloAuSerial:
                BotonPulsado = 5;
                break;

            case StartCicloSerial:
                BotonPulsado = 2;
                break;
        }
    }
}
