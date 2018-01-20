#ifndef _CONFIG_H
#define _CONFIG_H


#include "DSP2803x_Device.h"


#define CPU_SYSCLK (uint32_t)60000000

#define DIVIDER_TIMER(x)  (x-1)

/*CPU timer0 clock frequency config*/
#define CPU_TIMER0_DIVIDER               DIVIDER_TIMER(1)//means no divide for SYSCLK
#define CPU_TIMER0_PERIOD_USec           (40.0)//us
#define CPU_TIME0_PERIOD_REGISTER_VALUE  ((Uint32)(CPU_TIMER0_PERIOD_USec*CPU_SYSCLK/(CPU_TIMER0_DIVIDER+1)/1000000))
#define T0_ms(x)                         (Uint32)((float)x*1000/CPU_TIMER0_PERIOD_USec)


/*CPU timer1 clock frequency config*/
#define CPU_TIMER1_DIVIDER              DIVIDER_TIMER(200)
#define CPU_TIME1_FREQUENCY            (Uint32)(CPU_SYSCLK/(CPU_TIMER1_DIVIDER+1))



#define TRUE     1
#define FALSE    0
#define LOW      0
#define HIGH     1
#define true     1
#define false    0
#define SUCCESS  1
#define ERROR    0


#endif
