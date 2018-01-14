#ifndef _POWER_LOOPCTRL_H
#define _POWER_LOOPCTRL_H

#include "DSP28x_project.h"
#include "config.h"

#define DC_DC_FREQUENCY_Khz(x)  (CPU_SYSCLK / ((UINT32)x*2000)) 

#define DC_DC_FREQUENCY         DC_DC_FREQUENCY_Khz(75)



#define DUTY(x)                 (DC_DC_FREQUENCY*(UINT32)x/50)
#define INITIAL_DUTY            DUTY(44)


#define	MAIN_DEAD_TIME			((INT16)24)							//400ns
#define SYC_DEAD_TIME           ((INT16)9)                          //150ns

#define INT_CNT                 10
#define DC_DC_PERIOD            (DC_DC_FREQUENCY*16.667/1000)//us
#define T_INTERUPT_ms(x)        ((Uint16)((float)x*1000/(DC_DC_PERIOD*INT_CNT)))//
#define K16_LVOLT_RISETIME      T_INTERUPT_ms(26.0)//
#define K16_LV_CHARGE_STEP_SIZE ((Uint16)(LV_VOLT(13)/K16_LVOLT_RISETIME))

#define K16_LVOLT_CHARGE_NORMAL            LV_VOLT(13)
#define K16_LVOLT_DISCHARGE_NORMAL         LV_VOLT(14)

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
extern Uint16 u16LVoutRefNormal;


extern interrupt void adc_isr(void);
extern void ParametersCtrl(void);
extern bool is_softStartFinished(void);
extern void Set_LVoltRef(Uint16 u16SetValue);
extern Uint16 Get_LVoltRef(void);

#endif

