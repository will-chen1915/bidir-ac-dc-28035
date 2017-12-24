#ifndef _CONFIG_H
#define _CONFIG_H


#include "DSP2803x_Device.h"


#define CPU_SYSCLK (uint32_t)60000000


/*CPU timer0 clock frequency config*/
#define CPU_TIMER0_DIVIDER              DIVIDER_TIMER0(200)
#define CPU_TIME0_FREQUENCY            (Uint32)(CPU_SYSCLK/(CPU_TIMER0_DIVIDER+1))


#define TRUE     1
#define FALSE    0
#define LOW      0
#define HIGH     1
#define true     1
#define false    0
#define SUCCESS  1
#define ERROR    0


#endif
