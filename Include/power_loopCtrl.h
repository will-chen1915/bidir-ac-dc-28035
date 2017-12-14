#ifndef _POWER_LOOPCTRL_H
#define _POWER_LOOPCTRL_H

#include "DSP28x_project.h"
#include "config.h"

#define DC_DC_FREQUENCY(x)      (CPU_SYSCLK / ((UINT32)x*1000)) 

#define DC_DC_FREQUENCY_70KHZ   DC_DC_FREQUENCY(70)

#define DUTY(x)                 (DC_DC_FREQUENCY_70KHZ*(UINT32)x/100)
#define INITIAL_DUTY            DUTY(25)   

#define	DEAD_TIME				((INT32)15)							//250ns

extern Uint16 u16LVoltInst;

extern __interrupt void adc_isr(void);
extern void PwmCtrl_SetPwmGain(void);
extern bool is_softStartFinished(void);

#endif

