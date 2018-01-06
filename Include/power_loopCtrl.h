#ifndef _POWER_LOOPCTRL_H
#define _POWER_LOOPCTRL_H

#include "DSP28x_project.h"
#include "config.h"

#define DC_DC_FREQUENCY(x)      (CPU_SYSCLK / ((UINT32)x*2000)) 

#define DC_DC_FREQUENCY_75KHZ   DC_DC_FREQUENCY(75)

#define DUTY(x)                 (DC_DC_FREQUENCY_75KHZ*(UINT32)x/100)
#define INITIAL_DUTY            DUTY(25)   


#define	MAIN_DEAD_TIME				((INT16)24)							//400ns
#define SYC_DEAD_TIME           ((INT16)9)                          //150ns

typedef struct
{
	signed short int inter_A1;
	signed short int inter_A2;
	signed short int inter_A3;
	signed short int error_z1;
	signed short int error_z2;
	long Uout_z1;


}	CTRL2P2Z_coeff;


extern Uint16 u16LVoltInst;

extern bool Flag_Txd;


extern __interrupt void adc_isr(void);
extern void PwmCtrl_SetPwmGain(void);
extern bool is_softStartFinished(void);

#endif

