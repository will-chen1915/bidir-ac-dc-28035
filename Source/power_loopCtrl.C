#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

static int16 i16LVoutRef = 0;
Uint16 u16LVoltInst = 0;
static int16 i16LVoltErrorDev = 0;
static int16 i16TmpError = 0;
static int16 i16LVoltError = 0;
static int16 i16LVoltErrorSum = 0;


#define PwmCtrl_PID() {                                      \
	i16TmpError = i16LVoutRef - u16LVoltInst;                \
    /* Cal VERROR deviative portion */                            \
    i16LVoltErrorDev = i16TmpError - i16LVoltError;            \
    i16LVoltError = i16TmpError;		/* Update new Vout Error */ \
    i16LVoltErrorSum = i16LVoltErrorSum + i16TmpError;	     \
}

__interrupt void adc_isr ( void )
{
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM	
	u16LVoltInst = AdcResult.ADCRESULT0;

	PwmCtrl_PID();
}


bool is_softStartFinished(void)
{
return FALSE;
}

void PwmCtrl_SetPwmGain(void)
{
;
}
