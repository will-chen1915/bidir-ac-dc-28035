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

//#define ADC_SHCLK		0xA		// S/H width in ADC module periods = 2 ADC cycle
#define ADC_SHCLK		0x6		// S/H width in ADC module periods = 2 ADC cycle
#define ADC_TRIGER		0x01	// CPU Timer 0, TINT0n
#define	ADC_TRIGSEL_EPWM1_ADCSOCA			0x05	//ADCTRIG5-��ePWM1,ADCSOCA
#define EPWM2_TRIG      0x07    // ePWM2 ADCSOCA
#define ADC_SOCPrity	0x01	// SOC0 are high priority, rest of channels are in round robin mode.


#define CSL_FB		    0x0F
#define TEMP            0x0C
#define VHS             0x07
#define VL_FB		    0x0B


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

/*  AdcChanSelect-
    This function selects the ADC channel to convert by setting all SOC channel selects to a single channel.

     * IMPORTANT * This function will overwrite previous SOC channel select settings. Recommend saving
           the previous settings.
 */
void AdcChanSelect(Uint16 ch_no)
{
    AdcRegs.ADCSOC0CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC1CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC2CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC3CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC4CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC5CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC6CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC7CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC8CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC9CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC10CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC11CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC12CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC13CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC14CTL.bit.CHSEL= ch_no;
    AdcRegs.ADCSOC15CTL.bit.CHSEL= ch_no;
} //end AdcChanSelect

void AdcOffsetSelfCal()
{
    Uint16 AdcConvMean;
    EALLOW;
    AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;                  //Select internal reference mode
    AdcRegs.ADCCTL1.bit.VREFLOCONV = 1;                 //Select VREFLO internal connection on B5
    AdcChanSelect(13);                                  //Select channel B5 for all SOC
    AdcRegs.ADCOFFTRIM.bit.OFFTRIM = 80;                //Apply artificial offset (+80) to account for a negative offset that may reside in the ADC core
    AdcConvMean = AdcConversion();                      //Capture ADC conversion on VREFLO
    AdcRegs.ADCOFFTRIM.bit.OFFTRIM = 80 - AdcConvMean;  //Set offtrim register with new value (i.e remove artical offset (+80) and create a two's compliment of the offset error)
    AdcRegs.ADCCTL1.bit.VREFLOCONV = 0;                 //Select external ADCIN5 input pin on B5
    EDIS;
}

/* AdcConversion -
   This function initiates several ADC conversions and returns the average. It uses ADCINT1 and ADCINT2
   to "ping-pong" between SOC0-7 and SOC8-15 and is referred to as "ping-pong" sampling.

     * IMPORTANT * This function will overwrite previous ADC settings. Recommend saving previous settings.
*/
Uint16 AdcConversion(void)
{
    Uint16 index, SampleSize, Mean, ACQPS_Value;
    Uint32 Sum;

    index       = 0;            //initialize index to 0
    SampleSize  = 256;          //set sample size to 256 (**NOTE: Sample size must be multiples of 2^x where is an integer >= 4)
    Sum         = 0;            //set sum to 0
    Mean        = 999;          //initialize mean to known value

    //Set the ADC sample window to the desired value (Sample window = ACQPS + 1)
    ACQPS_Value = 6;
    AdcRegs.ADCSOC0CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC1CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC2CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC3CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC4CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC5CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC6CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC7CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC8CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC9CTL.bit.ACQPS  = ACQPS_Value;
    AdcRegs.ADCSOC10CTL.bit.ACQPS = ACQPS_Value;
    AdcRegs.ADCSOC11CTL.bit.ACQPS = ACQPS_Value;
    AdcRegs.ADCSOC12CTL.bit.ACQPS = ACQPS_Value;
    AdcRegs.ADCSOC13CTL.bit.ACQPS = ACQPS_Value;
    AdcRegs.ADCSOC14CTL.bit.ACQPS = ACQPS_Value;
    AdcRegs.ADCSOC15CTL.bit.ACQPS = ACQPS_Value;


    //Enable ping-pong sampling

    // Enabled ADCINT1 and ADCINT2
    AdcRegs.INTSEL1N2.bit.INT1E = 1;
    AdcRegs.INTSEL1N2.bit.INT2E = 1;

    // Disable continuous sampling for ADCINT1 and ADCINT2
    AdcRegs.INTSEL1N2.bit.INT1CONT = 0;
    AdcRegs.INTSEL1N2.bit.INT2CONT = 0;

    AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;    //ADCINTs trigger at end of conversion

    // Setup ADCINT1 and ADCINT2 trigger source
    AdcRegs.INTSEL1N2.bit.INT1SEL = 6;      //EOC6 triggers ADCINT1
    AdcRegs.INTSEL1N2.bit.INT2SEL = 14;     //EOC14 triggers ADCINT2

    // Setup each SOC's ADCINT trigger source
    AdcRegs.ADCINTSOCSEL1.bit.SOC0  = 2;    //ADCINT2 starts SOC0-7
    AdcRegs.ADCINTSOCSEL1.bit.SOC1  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC2  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC3  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC4  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC5  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC6  = 2;
    AdcRegs.ADCINTSOCSEL1.bit.SOC7  = 2;
    AdcRegs.ADCINTSOCSEL2.bit.SOC8  = 1;    //ADCINT1 starts SOC8-15
    AdcRegs.ADCINTSOCSEL2.bit.SOC9  = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC10 = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC11 = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC12 = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC13 = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC14 = 1;
    AdcRegs.ADCINTSOCSEL2.bit.SOC15 = 1;

    DELAY_US(ADC_usDELAY);                  // Delay before converting ADC channels


    //ADC Conversion

    AdcRegs.ADCSOCFRC1.all = 0x00FF;  // Force Start SOC0-7 to begin ping-pong sampling

    while( index < SampleSize ){

        //Wait for ADCINT1 to trigger, then add ADCRESULT0-7 registers to sum
        while (AdcRegs.ADCINTFLG.bit.ADCINT1 == 0){}
        AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;   //Must clear ADCINT1 flag since INT1CONT = 0
        Sum += AdcResult.ADCRESULT0;
        Sum += AdcResult.ADCRESULT1;
        Sum += AdcResult.ADCRESULT2;
        Sum += AdcResult.ADCRESULT3;
        Sum += AdcResult.ADCRESULT4;
        Sum += AdcResult.ADCRESULT5;
        Sum += AdcResult.ADCRESULT6;
        Sum += AdcResult.ADCRESULT7;

        //Wait for ADCINT2 to trigger, then add ADCRESULT8-15 registers to sum
        while (AdcRegs.ADCINTFLG.bit.ADCINT2 == 0){}
        AdcRegs.ADCINTFLGCLR.bit.ADCINT2 = 1;   //Must clear ADCINT2 flag since INT2CONT = 0
        Sum += AdcResult.ADCRESULT8;
        Sum += AdcResult.ADCRESULT9;
        Sum += AdcResult.ADCRESULT10;
        Sum += AdcResult.ADCRESULT11;
        Sum += AdcResult.ADCRESULT12;
        Sum += AdcResult.ADCRESULT13;
        Sum += AdcResult.ADCRESULT14;
        Sum += AdcResult.ADCRESULT15;

        index+=16;

    } // end data collection

    //Disable ADCINT1 and ADCINT2 to STOP the ping-pong sampling
    AdcRegs.INTSEL1N2.bit.INT1E = 0;
    AdcRegs.INTSEL1N2.bit.INT2E = 0;

    Mean = Sum / SampleSize;    //Calculate average ADC sample value

    return Mean;                //return the average
}//end AdcConversion

void ConfigAdc(void)
{
#if 0
	EALLOW;
	AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;	// ADCINT trips after AdcResults latch
	AdcRegs.INTSEL1N2.bit.INT1E 	= 1;	// Enable ADCINT1
	AdcRegs.INTSEL1N2.bit.INT1CONT	= 0;	// Disable ADCINT1 Continuous mode
	//AdcRegs.INTSEL1N2.bit.INT2CONT  = 0;	// Disable ADCINT1 Continuous mode
	AdcRegs.INTSEL1N2.bit.INT1SEL	= 0;	// setup EOC0 to trigger ADCINT1 to fire

	AdcRegs.ADCSAMPLEMODE.all = 0;			// Single sample mode

	//ePWM2, ADCSOCA , smaple window 7 cycles ,output dc voltage sample
	AdcRegs.ADCSOC0CTL.bit.TRIGSEL = ADC_TRIGSEL_EPWM1_ADCSOCA;
	AdcRegs.ADCSOC0CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC0CTL.bit.CHSEL = VL_FB;

	//ePWM2, ADCSOCA , smaple window 7 cycles ,VH voltage sample
	AdcRegs.ADCSOC1CTL.bit.TRIGSEL = ADC_TRIGSEL_EPWM1_ADCSOCA;
	AdcRegs.ADCSOC1CTL.bit.ACQPS = ADC_SHCLK;
	AdcRegs.ADCSOC1CTL.bit.CHSEL = VHS;

	//ePWM2, ADCSOCA, smaple window 7 cycles, temperature
	AdcRegs.ADCSOC2CTL.bit.TRIGSEL = ADC_TRIGSEL_EPWM1_ADCSOCA;
	AdcRegs.ADCSOC2CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC2CTL.bit.CHSEL = TEMP;

	//ePWM2, ADCSOCA , smaple window 7 cycles ,VH voltage sample
	AdcRegs.ADCSOC3CTL.bit.TRIGSEL = ADC_TRIGSEL_EPWM1_ADCSOCA;
	AdcRegs.ADCSOC3CTL.bit.ACQPS = ADC_SHCLK;	
	AdcRegs.ADCSOC3CTL.bit.CHSEL = CSL_FB;
	 
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
#else
	EALLOW;
	//Disable ADCINT1 trigger firstly, or the TRIGSEL field is ignored.
	AdcRegs.ADCINTSOCSEL1.all = 0;
//	AdcRegs.ADCINTSOCSEL2.all = ADC_TRIGSEL_ENABLE;

	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN0	= 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN2	= 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN4	= 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN6	= 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN8	= 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN10 = 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN12 = 0;	//Single sample mode
	AdcRegs.ADCSAMPLEMODE.bit.SIMULEN14 = 0;	//Single sample mode

	AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0x0;		//SOC priority is handled in round robin mode for all channels.
	AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0; // Enable non-overlap mode
	AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;	// ADCINT1 trips after AdcResults latch
	AdcRegs.INTSEL1N2.bit.INT1E 	= 1;	// Enabled ADCINT1
	AdcRegs.INTSEL1N2.bit.INT1CONT	= 0;	// Disable ADCINT1 Continuous mode
	AdcRegs.INTSEL1N2.bit.INT1SEL	= 0;	// setup EOC0 to trigger ADCINT1 to fire

	/*******************************************************
	*
	********************************************************/

	AdcRegs.ADCSOC0CTL.bit.CHSEL	= 0;	// CSac-FB
	AdcRegs.ADCSOC1CTL.bit.CHSEL	= 0;	//ACL-FB
	AdcRegs.ADCSOC2CTL.bit.CHSEL	= 0;	//ACN-FB
	AdcRegs.ADCSOC3CTL.bit.CHSEL	= 0;	//H-FB ĸ�ߵ�ѹ����
	AdcRegs.ADCSOC4CTL.bit.CHSEL	= 0;	//REF3Vp
//	AdcRegs.ADCSOC5CTL.bit.CHSEL	= ADC_IN_B2;	//
//	AdcRegs.ADCSOC6CTL.bit.CHSEL	= ADC_IN_B4;	//
//	AdcRegs.ADCSOC7CTL.bit.CHSEL	= ADC_IN_B0;	//
//	AdcRegs.ADCSOC8CTL.bit.CHSEL	= ADC_IN_A5;	//

	AdcRegs.ADCSOC0CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	// set SOC0 start trigger on EPWM5ADCSOCA, due to round-robin SOC0 converts first then SOC1
	AdcRegs.ADCSOC1CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	//
	AdcRegs.ADCSOC2CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	//
	AdcRegs.ADCSOC3CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	//
	AdcRegs.ADCSOC4CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	//
//	AdcRegs.ADCSOC5CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM5_ADCSOCA;	//
//	AdcRegs.ADCSOC6CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM6_ADCSOCA;	//
//	AdcRegs.ADCSOC7CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM6_ADCSOCA;	//
//	AdcRegs.ADCSOC8CTL.bit.TRIGSEL	= ADC_TRIGSEL_EPWM1_ADCSOCA;	//

	AdcRegs.ADCSOC0CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
	AdcRegs.ADCSOC1CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
	AdcRegs.ADCSOC2CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
	AdcRegs.ADCSOC3CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
	AdcRegs.ADCSOC4CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
//	AdcRegs.ADCSOC5CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
//	AdcRegs.ADCSOC6CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
//	AdcRegs.ADCSOC7CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
//	AdcRegs.ADCSOC8CTL.bit.ACQPS	= 6;	//Sample windowis 7 cycles long (6+1 clock cycles)
	EDIS;
#endif

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

//	InitAdcAio(); 

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
	(*Device_cal)();
	EDIS;

    EALLOW;

	AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;		//0: Internal reference on ADCREFIN

	AdcRegs.ADCCTL1.bit.ADCBGPWD  = 1;		// Power ADC BG
	AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;		// Power reference
	AdcRegs.ADCCTL1.bit.ADCPWDN   = 1;		// Power ADC
	AdcRegs.ADCCTL1.bit.ADCENABLE = 1;		// Enable ADC
	EDIS;

    DELAY_US(ADC_usDELAY);

//	AdcOffsetSelfCal();
	
	ConfigAdc();
}

//===========================================================================
// End of file.
//===========================================================================

