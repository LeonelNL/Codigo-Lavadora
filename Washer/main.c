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
#include "highdefault.h"
#include "config_pines.h"

int main(void)
{
   ConfiguracionPines();

   while(1)
    {
        HighCycleLedDefault(BotonPulsado);
    }
}
