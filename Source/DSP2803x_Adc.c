/*================================================================*
*           Copyright(c) 2015-2018, VMAX Power Co., Ltd.
*                      ALL RIGHTS RESERVED
*
* PRODUCT  : SAIC6600P220AC1U801
* FILENAME : VmaxPower_Adc.c
* PURPOSE  : Define base data type.
*
* HISTORY :
*    DATE           VERSION           AUTHOR         NOTE
* 2016-03-19          V1.0              VS         Created.
*=================================================================*/

//#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File
#include "DSP28x_Project.h"     // DSP28x Headerfile

#define ADC_usDELAY 	5000L

#define ADC_SHCLK		0xA		// S/H width in ADC module periods = 2 ADC cycle
#define ADC_TRIGER		0x01	// CPU Timer 0, TINT0n
#define EPWM2_TRIG      0x07    // ePWM2 ADCSOCA
#define ADC_SOCPrity	0x01	// SOC0 are high priority, rest of channels are in round robin mode.


#define DCVOLTFB		0x00
#define DCVOLTOVP		0x03
#define CSL_FB		    0x0B

#define TEMP            0x0E

#define VHS             0x09

#define VL_FB		    0x00
#define TEMPWATER		0x09
#define TEMPAIR		    0x0A

void InitAdcAio()
{

   EALLOW;

/* Configure ADC pins using AIO regs*/
// This specifies which of the possible AIO pins will be Analog input pins.
// NOTE: AIO1,3,5,7-9,11,13,15 are analog inputs in all AIOMUX1 configurations.
// Comment out other unwanted lines.

    GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;    // Configure AIO2 for A2 (analog input) operation CSH_FILT(IPK)
//    GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;    // Configure AIO4 for A4 (analog input) operation
//    GpioCtrlRegs.AIOMUX1.bit.AIO6 = 2;    // Configure AIO6 for A6 (analog input) operation
//    GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;   // Configure AIO10 for B2 (analog input) operation
//    GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;   // Configure AIO12 for B4 (analog input) operation
   GpioCtrlRegs.AIOMUX1.bit.AIO14 = 2;   // Configure AIO14 for B6 (analog input) operation (TEMP)

    EDIS;
}
//---------------------------------------------------------------------------
// InitAdc: 
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
// PLEASE NOTE, ADC INIT IS DIFFERENT ON 281x vs 280x DEVICES!!!
//
void InitAdc(void)

{	
	// To powerup the ADC the ADCENCLK bit should be set first to enable
	// clocks, followed by powering up the bandgap, reference circuitry, and ADC core.
	// Before the first conversion is performed a 5ms delay must be observed 
	// after power up to give all analog circuits time to power up and settle

	// Please note that for the delay function below to operate correctly the 
	// CPU_CLOCK_SPEED define statement in the DSP280x_Examples.h file must 
	// contain the correct CPU clock period in nanoseconds.

	InitAdcAio(); 

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
	(*Device_cal)();
	EDIS;

    EALLOW;

	AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;		//1: Internal reference on ADCREFIN

	AdcRegs.ADCCTL1.bit.ADCBGPWD  = 1;		// Power ADC BG
	AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;		// Power reference
	AdcRegs.ADCCTL1.bit.ADCPWDN   = 1;		// Power ADC
	AdcRegs.ADCCTL1.bit.ADCENABLE = 1;		// Enable ADC

    DELAY_US(ADC_usDELAY);

	AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;	// ADCINT trips before AdcResults latch
    AdcRegs.INTSEL1N2.bit.INT1E     = 1;	// Enable ADCINT1
    AdcRegs.INTSEL1N2.bit.INT1CONT  = 0;	// Disable ADCINT1 Continuous mode
//    AdcRegs.INTSEL1N2.bit.INT2CONT  = 1;	// Enable ADCINT1 Continuous mode
    AdcRegs.INTSEL1N2.bit.INT1SEL   = 0;	// setup EOC0 to trigger ADCINT1 to fire

  	AdcRegs.ADCSAMPLEMODE.all = 0;			// Single sample mode

	//ePWM2, ADCSOCA , smaple window 7 cycles ,output dc voltage sample
	AdcRegs.ADCSOC0CTL.bit.TRIGSEL = EPWM2_TRIG;
	AdcRegs.ADCSOC0CTL.bit.ACQPS = ADC_SHCLK;	
    AdcRegs.ADCSOC0CTL.bit.CHSEL = VL_FB;

	//ePWM2, ADCSOCA , smaple window 7 cycles ,VH voltage sample
	AdcRegs.ADCSOC2CTL.bit.TRIGSEL = EPWM2_TRIG;
	AdcRegs.ADCSOC2CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC2CTL.bit.CHSEL = VHS; 
	 
#if 0	
	AdcRegs.ADCSOC4CTL.bit.TRIGSEL = ADC_TRIGER;
	AdcRegs.ADCSOC4CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC4CTL.bit.CHSEL = CSL_FB;
#endif	
	//CPU Timer 0, TINT0n, smaple window 7 cycles, temperature
	AdcRegs.ADCSOC3CTL.bit.TRIGSEL = EPWM2_TRIG;
	AdcRegs.ADCSOC3CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC3CTL.bit.CHSEL = TEMP;

	 
	//round cycle, SOC15 is last, and SOC0 is highest round robin priority
	AdcRegs.SOCPRICTL.bit.RRPOINTER = 0x0f;
	
	//round ,prity same
    AdcRegs.SOCPRICTL.bit.SOCPRIORITY = ADC_SOCPrity;

    //Comparator Init
    /*//COMP1 LLC_OVP
	Comp1Regs.COMPCTL.bit.COMPDACEN = 1;
	Comp1Regs.COMPCTL.bit.CMPINV = 1;
	Comp1Regs.COMPCTL.bit.COMPSOURCE = 0;
	Comp1Regs.COMPCTL.bit.SYNCSEL = 1;
	Comp1Regs.COMPCTL.bit.QUALSEL = 4;// 5 CLKS filter
	Comp1Regs.DACVAL.bit.DACVAL = LLC_OVP_POINT;
    */
  
	EDIS;
}

//===========================================================================
// End of file.
//===========================================================================

