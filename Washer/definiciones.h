#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

#define NivelBajoSerial 'A'
#define NivelMedioSerial 'B'
#define NivelAltoSerial 'C'
#define BombaDrenadoOnSerial 'D'
#define BombaDrenadoOffSerial 'E'
#define BombaLlenadoOnSerial 'F'
#define BombaLlenadoOffSerial 'G'
#define CicloHighSerial 'H'
#define CicloMediumSerial 'I'
#define CicloLowSerial 'J'
#define CicloAuSerial 'K'
#define StartCicloSerial 'L'

#define IdleState 0
#define StandbyState 1
#define RunState 2
#define PauseState 3
#define EndOfCycle 4

//#define BotonHigh 16
//#define BotonLow 8
//#define BotonMedium 4
//#define BotonAU 2
//#define BotonStart_Pausa 1


