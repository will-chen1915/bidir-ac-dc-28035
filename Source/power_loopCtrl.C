#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

Uint16 u16Vol_K_P = 0;
Uint16 u16Vol_K_I = 0;
Uint16 u16Vol_K_D = 0;

static Uint16 u16LVoutRef = 0;
Uint16 u16LVoltInst = 0;

#if 0
static int16 i16LVoltErrorDev = 0;
static int16 i16TmpError = 0;
static int16 i16LVoltError = 0;
static int16 i16LVoltErrorSum = 0;
static int16 u16PwmDutyBuf = 0;


#define PwmCtrl_PID() {                                      \
	Uint16 u16PidTmpVar;                                   \ 
	i16TmpError = u16LVoutRef - u16LVoltInst;                \
    /* Cal VERROR deviative portion */                            \
    i16LVoltErrorDev = i16TmpError - i16LVoltError;            \
    i16LVoltError = i16TmpError;		/* Update new Vout Error */ \
    i16LVoltErrorSum = i16LVoltErrorSum + i16TmpError;	     \
    u16PidTmpVar3 = i16LVoltError*u16Vol_K_P + i16LVoltErrorSum*u16Vol_K_I + i16LVoltErrorDev*u16Vol_K_D;\
    /*if(u16PidTmpVar3) */    \
}
#endif

__interrupt void adc_isr ( void )
{
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM	
	u16LVoltInst = AdcResult.ADCRESULT0 << 3;
}


bool is_softStartFinished(void)
{
return FALSE;
}

void PwmCtrl_SetPwmGain(void)
{
;
}
