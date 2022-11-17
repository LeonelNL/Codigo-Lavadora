#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "definiciones.h"

#define CycleLeds GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t CurrentState;
//uint8_t EstadoMaquina;

void HighCycleLedDefault(CurrentState)
{
//    if(EstadoMaquina == 0)
//    {
//        switch(CurrentState)
//        {
//            case 0:                                                 // Recien Endencido ciclo HIGH
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);
//                break;
//            case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
//                EstadoMaquina = StandbyState;
//                break;
//            case 2:                                                 // BOTON START
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
//                EstadoMaquina = StandbyState;
//                break;
//            case 3:                                                 // Bonton MEDIUM
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 8);
//                EstadoMaquina = StandbyState;
//                break;
//            case 4:                                                 // Boton LOW
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 4);
//                EstadoMaquina = StandbyState;
//                break;
//            case 5:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
//                EstadoMaquina = StandbyState;
//                break;
//        }
//    }
//    else if(EstadoMaquina == 1)
//    {
//        switch(CurrentState)
//        {
//            case 0:                                                 // Recien Endencido ciclo HIGH
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 0);
//                break;
//            case 1:                                                 //  High (Ciclo 1) LED CICLO 1 ON
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 16);
//                break;
//            case 2:                                                 // BOTON START
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
//                break;
//            case 3:                                                 // Bonton MEDIUM
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 8);
//                break;
//            case 4:                                                 // Boton LOW
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 4);
//                break;
//            case 5:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 2);
//                break;
//            case 6:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 17);
//                EstadoMaquina = RunState;
//                break;
//            case 7:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 9);
//                EstadoMaquina = RunState;
//                break;
//            case 8:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 5);
//                EstadoMaquina = RunState;
//                break;
//            case 9:                                                 // Boton AU
//                GPIOPinWrite(GPIO_PORTF_BASE, CycleLeds, 3);
//                EstadoMaquina = RunState;
//                break;
//        }
//    }
//    else if(EstadoMaquina == 2)
//    {
//
//    }
}

