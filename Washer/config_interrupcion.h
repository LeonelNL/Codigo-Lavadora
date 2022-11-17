#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "definiciones.h"


#define CycleButtons GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
uint8_t state = 0;
uint8_t BotonPulsado1 = 0 , BotonHigh1 = 0, BotonMedium1 = 0, BotonLow1 = 0, BotonAU1 = 0;

void GPIOIntHandler()
{
    GPIOIntClear(GPIO_PORTB_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_1|GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4);
    state = GPIOIntStatus(GPIO_PORTB_BASE, true);

    switch(state)
    {
            case 1:                                                                 //BotonStart
                BotonPulsado1 = 2;
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
                break;
            case 2:                                                                //Boton HIGH
                BotonPulsado1 = 1;
                BotonHigh1 = 1;
                BotonMedium1 = 0, BotonLow1 = 0, BotonAU1 = 0;
                break;
            case 4:                                                               //Boton MEDIUM
                BotonPulsado1 = 3;
                BotonMedium1 = 1;
                BotonHigh1 = 0, BotonLow1 = 0, BotonAU1 = 0;
                break;
            case 8:                                                              //Boton LOW
                BotonPulsado1 = 4;
                BotonLow1 = 1;
                BotonHigh1 = 0, BotonMedium1 = 0, BotonAU1 = 0;
                break;
            case 16:                                                             //Boton CICLO AU
                BotonPulsado1 = 5;
                BotonAU1 = 1;
                BotonHigh1 = 0, BotonLow1 = 0, BotonMedium1 = 0;
                break;
    }
//    switch (state){
//        case 1:                                                                 //BotonStart
//            BotonPulsado = 2;
//            if(BotonHigh == 1)
//            {
//                BotonPulsado = 6;
//            }
//            else if(BotonMedium == 1)
//            {
//                BotonPulsado = 7;
//            }
//            else if(BotonLow == 1)
//            {
//                BotonPulsado = 8;
//            }
//            else if(BotonAU == 1)
//            {
//                BotonPulsado = 9;
//            }
//            break;
//        case 2:                                                                //Boton HIGH
//            BotonPulsado = 1;
//            BotonHigh = 1;
//            BotonMedium = 0, BotonLow = 0, BotonAU = 0;
//            break;
//        case 4:                                                               //Boton MEDIUM
//            BotonPulsado = 3;
//            BotonMedium = 1;
//            BotonHigh = 0, BotonLow = 0, BotonAU = 0;
//            break;
//        case 8:                                                              //Boton LOW
//            BotonPulsado = 4;
//            BotonLow = 1;
//            BotonHigh = 0, BotonMedium = 0, BotonAU = 0;
//            break;
//        case 16:                                                             //Boton CICLO AU
//            BotonPulsado = 5;
//            BotonAU = 1;
//            BotonHigh = 0, BotonLow = 0, BotonMedium = 0;
//            break;
//    }
}

