//#########################################################
//
// FILE:   DSP280x_EPwm.c
//
// TITLE:  DSP280x ePWM Initialization & Support Functions.
//
//#########################################################
// Running on TMS320LF280xA               
// External clock is 20MHz, PLL * 10/2 , CPU-Clock 100 MHz	      
// Date: from 2005/12/28      , jurgen lv
// Version:1.00     Change Date: 
//#########################################################

#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File
#include "config.h"

void InitEPWM1(void);
void InitEPWM2(void);
void InitEPWM3(void);
void InitEPWM4(void);
void InitEPWM5(void);
void InitEPWM6(void);
void InitEPWM7(void);
//---------------------------------------------------------------------------
// Example: InitEPwmGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM pins

void InitEPwm1Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)   
   
/* Configure ePWM-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM1 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
//    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
   
    EDIS;
}

void InitEPwm2Gpio(void)
{
   EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM3B)

/* Configure ePWM-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM2 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
//    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
   
    EDIS;
}

void InitEPwm3Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // disable pull-up on GPIO5 (EPWM3B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM3 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
	
    EDIS;
}

void InitEPwm4Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;    // disable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;    // disable pull-up on GPIO7 (EPWM4B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM4 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
	
    EDIS;
}

void InitEPwm5Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;    // disable pull-up on GPIO8 (EPWM5A)
    //GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;    // disable pull-up on GPIO9 (EPWM5B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
   // GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
	
    EDIS;
}

void InitEPwm6Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // disable pull-up on GPIO10 (EPWM6A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // disable pull-up on GPIO11 (EPWM6B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
//    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B
	
    EDIS;
}

void InitEPwm7Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBPUD.bit.GPIO40 = 1;    // disable pull-up on GPIO8 (EPWM7A)
    GpioCtrlRegs.GPBPUD.bit.GPIO41 = 1;    // disable pull-up on GPIO9 (EPWM7B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 1;   // Configure GPIO40 as EPWM7A
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 1;   // Configure GPIO41 as EPWM7B
	
    EDIS;
}

void InitTzGpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up on GPIO12 (TZ1)
   GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;    // Enable pull-up on GPIO16 (TZ2)
   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;    // Enable pull-up on GPIO17 (TZ3)
//  GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up on GPIO28 (TZ2)
 
/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 2;  // Asynch input GPIO12 (TZ1)
   GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 2;  // Asynch input GPIO16 (TZ2)
   GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 2;  // Asynch input GPIO17 (TZ3)
//   GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (TZ2)
 
/* Configure TZ pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be TZ functional pins.
// Comment out other unwanted lines.   
   //GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as TZ1
   //GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;  // Configure GPIO16 as TZ2
   //GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;  // Configure GPIO17 as TZ3
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;  // Configure GPIO12 as gpio
   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;  // Configure GPIO16 as gpio
   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;  // Configure GPIO17 as gpio
//   GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // Configure GPIO28 as TZ2
//   GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;
   EDIS;
}
//---------------------------------------------------------------------------
// InitEPwm: 
//---------------------------------------------------------------------------
// This function initializes the ePWM(s) to a known state.
//
void InitEPwm(void)
{
	// Initialize ePWM1/2/5/6
	// for HV
	InitEPwm1Gpio();
	InitEPwm2Gpio();
	InitEPwm5Gpio();
	InitEPwm6Gpio();
	InitEPwm3Gpio();
	InitEPwm4Gpio();
	//InitTzGpio();
	//DISABLE_TZ;

	EALLOW;	
	
#if 0
    EPwm1Regs.AQSFRC.bit.RLDCSF = 0;	//load on event counter equals zero
    EPwm2Regs.AQSFRC.bit.RLDCSF = 1;	//load on event counter equals period
    EPwm5Regs.AQSFRC.bit.RLDCSF = 0;	//load on event counter equals zero
    EPwm6Regs.AQSFRC.bit.RLDCSF = 1;	//load on event counter equals period

	EPwm1Regs.AQCSFRC.bit.CSFA = 1;
	EPwm2Regs.AQCSFRC.bit.CSFA = 1;  
	EPwm5Regs.AQCSFRC.bit.CSFA = 1;  
	EPwm6Regs.AQCSFRC.bit.CSFA = 1;
#endif

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
	
	InitEPWM1();//---DVH1----
	InitEPWM2();//---DVL2----
	InitEPWM3();//---DVL3----
	InitEPWM4();//---DVH4----
	InitEPWM5();//DVA  SYCH_A---
	InitEPWM6();//DVB SYCH_B---
	
	 
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;      // Start all the timers synced
	EPwm1Regs.TBCTL.bit.SWFSYNC = 1;
	EDIS;
}

//PWMC---DV3H
void InitEPWM1(void)
{
	#if 0
    // Define an event (DCAEVT1) based on COMP2
	EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL = DC_COMP2OUT;        // DCAH = Comparator 2 output
	EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL = DC_COMP2OUT;        // DCAL = Comparator 2 output
	EPwm1Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_LOW;              // DCAEVT1 =  DCAH low(will become active as Comparator output goes low)  
	EPwm1Regs.DCACTL.bit.EVT1SRCSEL = DC_EVT1;                // DCAEVT1 = DCAEVT1 (not filtered)
	EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL = DC_EVT_ASYNC;       // Take async path
         
	// Enable DCAEVT1 and DCBEVT1 are one shot trip sources
	// Note: DCxEVT1 events can be defined as one-shot.  
	//       DCxEVT2 events can be defined as cycle-by-cycle.
	EPwm1Regs.TZSEL.bit.DCAEVT1 = 1;
	EPwm1Regs.TZSEL.bit.DCBEVT1 = 0;

	// What do we want the DCAEVT1 and DCBEVT1 events to do?
	// DCAEVTx events can force EPWMxA 
	// DCBEVTx events can force EPWMxB  
	EPwm1Regs.TZCTL.bit.DCAEVT1 = TZ_FORCE_LO;           // EPWM1A will go low
	#endif

	#if 1
//	EPwm1Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;			//Enable TZ1 as a OST trip source
//	EPwm1Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;			//Enable TZ2 as a OST trip source
//	EPwm1Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm1Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm1Regs.TZCTL.bit.TZB = TZ_NO_CHANGE;
	EPwm1Regs.TZCLR.all = 0x0007;					//clear all TZFLAG
	EPwm1Regs.TZEINT.bit.OST = 0;					//disable interrupt
    #endif
	
	EPwm1Regs.TBCTR = 0;                            // Clear counter
	EPwm1Regs.TBPHS.half.TBPHS = 0;	                // Set as master, phase =0
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
	EPwm1Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down 
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;		//Pass through 
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  // Count up
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm1Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
//	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;		//Select INT on PRD event
	EPwm1Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
//	EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm1Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG

	//Setup CC
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPA.half.CMPA = INITIAL_DUTY;

    //Set pwm edge adjusting mode
	EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;              // ClearvPWM1A on Zero
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;
	EPwm1Regs.AQCTLA.bit.PRD = AQ_CLEAR;				  //Set PWM1A on Zero

   	EPwm1Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm1Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    EPwm1Regs.DBRED = DEAD_TIME;
    //EPwm1Regs.DBFED = DEAD_TIME;		

	#if 0
	EPwm1Regs.HRCNFG.all = 0x0;	
    EPwm1Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm1Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm1Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm1Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion

    EPwm1Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm1Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
    #endif
	
	//ADC trigger source
	EPwm1Regs.ETSEL.bit.SOCAEN	= 1;				// Enable SOC on A group
	EPwm1Regs.ETSEL.bit.SOCASEL	= ET_CTRU_CMPB;		// Select SOC from CPMB on upcount
	EPwm1Regs.ETPS.bit.SOCAPRD 	= 1;				// Generate pulse on 1st event
}

//PWMA---DV1H
void InitEPWM2(void)
{
    #if 0
    // Define an event (DCAEVT1) based on COMP2
	EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL = DC_COMP2OUT;        // DCAH = Comparator 2 output
	EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL = DC_COMP2OUT;        // DCAL = Comparator 2 output
	EPwm2Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_LOW;              // DCAEVT1 =  DCAH low(will become active as Comparator output goes low)  
	EPwm2Regs.DCACTL.bit.EVT1SRCSEL = DC_EVT1;                // DCAEVT1 = DCAEVT1 (not filtered)
	EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL = DC_EVT_ASYNC;       // Take async path
         
	// Enable DCAEVT1 and DCBEVT1 are one shot trip sources
	// Note: DCxEVT1 events can be defined as one-shot.  
	//       DCxEVT2 events can be defined as cycle-by-cycle.
	EPwm2Regs.TZSEL.bit.DCAEVT1 = 1;
	EPwm2Regs.TZSEL.bit.DCBEVT1 = 0;

	// What do we want the DCAEVT1 and DCBEVT1 events to do?
	// DCAEVTx events can force EPWMxA 
	// DCBEVTx events can force EPWMxB  
	EPwm2Regs.TZCTL.bit.DCAEVT1 = TZ_FORCE_LO;           // EPWM2A will go low
	#endif

	#if 1
	//EPwm2Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;			//Enable TZ1 as a OST trip source
	//EPwm2Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;			//Enable TZ2 as a OST trip source
	//EPwm2Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm2Regs.TZCTL.bit.TZB = TZ_NO_CHANGE;			//not used
	EPwm2Regs.TZCLR.all = 0x0007;					//clear all TZFLAG
	EPwm2Regs.TZEINT.bit.OST = TZ_DISABLE;			//disable interrupt
	#endif
	
	EPwm2Regs.TBCTR = 0;
	EPwm2Regs.TBPHS.half.TBPHS = 0;	 
	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm2Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  // Count up
	EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm2Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
//	EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;		//Select INT on PRD event
	EPwm2Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
//	EPwm2Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm2Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG
	
	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm2Regs.CMPA.half.CMPA = INITIAL_DUTY;

	EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
//	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
//	EPwm2Regs.AQCTLA.bit.CBU = AQ_CLEAR;
	EPwm2Regs.AQCTLA.bit.PRD = AQ_SET;

   	EPwm2Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm2Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    EPwm2Regs.DBRED = DEAD_TIME;
    //EPwm2Regs.DBFED = DC_DB_TIME;		

	//ADC trigger source
	EPwm2Regs.ETSEL.bit.SOCAEN	= 1;				// Enable SOC on A group
	//EPwm2Regs.ETSEL.bit.SOCASEL	= ET_CTRU_CMPB;		// Select SOC from CPMB on upcount
	EPwm2Regs.ETPS.bit.SOCAPRD 	= 1;				// Generate pulse on 1st event


	#if 0
	EPwm2Regs.HRCNFG.all = 0x0;	
    EPwm2Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm2Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm2Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm2Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion

    EPwm2Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm2Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
	#endif
}

//DVA
void InitEPWM3(void)
{
	#if 0
	EPwm3Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;	
	EPwm3Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm3Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm3Regs.TZCTL.bit.TZB = TZ_FORCE_LO;
	EPwm3Regs.TZEINT.bit.OST = 0;					//disable interrupt
	#endif
	
	EPwm3Regs.TBCTR = 0;
	EPwm3Regs.TBPHS.half.TBPHS = 0;	 
	EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm3Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down 
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm3Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
//	EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;		//Select INT on PRD event
	EPwm3Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
//	EPwm3Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm3Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG
	
	EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm3Regs.CMPA.half.CMPA = DC_DUTY_MIN;

	EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;
//	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm3Regs.AQCTLA.bit.PRD = AQ_CLEAR;				

   	EPwm3Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm3Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    EPwm3Regs.DBRED = DEAD_TIME;
  //  EPwm3Regs.DBFED = DEAD_TIME;		

	#if 0
	EPwm3Regs.HRCNFG.all = 0x0;	
    EPwm3Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm3Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm3Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm3Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion

    EPwm3Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm3Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
	#endif
}

//DVB
void InitEPWM4(void)
{
	#if 0
	EPwm4Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;	
	EPwm4Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm4Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm4Regs.TZCTL.bit.TZB = TZ_FORCE_LO;
	EPwm4Regs.TZEINT.bit.OST = 0;					//disable interrupt
	#endif

	EPwm4Regs.TBCTR = 0;
	EPwm4Regs.TBPHS.half.TBPHS = 0;	 
	EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE;
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm4Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down		 
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm4Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
	EPwm4Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;		//Select INT on PRD event
	EPwm4Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
	EPwm4Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm4Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG
	
	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm4Regs.CMPA.half.CMPA = DC_DC_FREQUENCY_70KHZ - INITIAL_DUTY;

	EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
	EPwm4Regs.AQCTLA.bit.PRD = AQ_SET;
	EPwm4Regs.AQCTLA.bit.CAD= AQ_CLEAR;

   	EPwm4Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm4Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    EPwm4Regs.DBRED = DEAD_TIME;
 //   EPwm4Regs.DBFED = DC_DB_TIME;		
	#if 0
	EPwm4Regs.HRCNFG.all = 0x0;	
    EPwm4Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm4Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm4Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm4Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion

    EPwm4Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm4Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
	#endif
}


//PWMD---DV4L
void InitEPWM5(void)
{
    #if 0
    // Define an event (DCAEVT1) based on COMP2
	EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL = DC_COMP2OUT;        // DCAH = Comparator 2 output
	EPwm5Regs.DCTRIPSEL.bit.DCALCOMPSEL = DC_COMP2OUT;        // DCAL = Comparator 2 output
	EPwm5Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_LOW;              // DCAEVT1 =  DCAH low(will become active as Comparator output goes low)  
	EPwm5Regs.DCACTL.bit.EVT1SRCSEL = DC_EVT1;                // DCAEVT1 = DCAEVT1 (not filtered)
	EPwm5Regs.DCACTL.bit.EVT1FRCSYNCSEL = DC_EVT_ASYNC;       // Take async path
         
	// Enable DCAEVT1 and DCBEVT1 are one shot trip sources
	// Note: DCxEVT1 events can be defined as one-shot.  
	//       DCxEVT2 events can be defined as cycle-by-cycle.
	EPwm5Regs.TZSEL.bit.DCAEVT1 = 1;
	EPwm5Regs.TZSEL.bit.DCBEVT1 = 0;

	// What do we want the DCAEVT1 and DCBEVT1 events to do?
	// DCAEVTx events can force EPWMxA 
	// DCBEVTx events can force EPWMxB  
	EPwm5Regs.TZCTL.bit.DCAEVT1 = TZ_FORCE_LO;           // EPWM5A will go low
	#endif

	#if 1
//	EPwm5Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;			//Enable TZ1 as a OST trip source	
//	EPwm5Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;			//Enable TZ2 as a OST trip source	
//	EPwm5Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm5Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm5Regs.TZCTL.bit.TZB = TZ_NO_CHANGE;
	EPwm5Regs.TZEINT.bit.OST = 0;					//disable interrupt
	#endif

	EPwm5Regs.TBCTR = 0;
	EPwm5Regs.TBPHS.half.TBPHS = 0;	 
	EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm5Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down 
	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm5Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm5Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
//	EPwm5Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;		//Select INT on PRD event
	EPwm5Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
//	EPwm5Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm5Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG
	
	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm5Regs.CMPA.half.CMPA = DC_DUTY_MIN;
	EPwm5Regs.CMPB = 0;

	EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
//	EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm5Regs.AQCTLA.bit.PRD = AQ_SET;	

//	EPwm5Regs.AQCTLB.bit.CBU = AQ_CLEAR;
//	EPwm5Regs.AQCTLB.bit.CBD = AQ_SET;

   	EPwm5Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm5Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    //EPwm5Regs.DBRED = DEAD_TIME;
    EPwm5Regs.DBFED = DEAD_TIME;	

	#if 0
	EPwm5Regs.HRCNFG.all = 0x0;	
    EPwm5Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm5Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm5Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm5Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion
	
    EPwm5Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm5Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
	#endif
}

//PWMB---DV2L
void InitEPWM6(void)
{
    #if 0
    // Define an event (DCAEVT1) based on COMP2
	EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL = DC_COMP2OUT;        // DCAH = Comparator 2 output
	EPwm6Regs.DCTRIPSEL.bit.DCALCOMPSEL = DC_COMP2OUT;        // DCAL = Comparator 2 output
	EPwm6Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_LOW;              // DCAEVT1 =  DCAH low(will become active as Comparator output goes low)  
	EPwm6Regs.DCACTL.bit.EVT1SRCSEL = DC_EVT1;                // DCAEVT1 = DCAEVT1 (not filtered)
	EPwm6Regs.DCACTL.bit.EVT1FRCSYNCSEL = DC_EVT_ASYNC;       // Take async path
         
	// Enable DCAEVT1 and DCBEVT1 are one shot trip sources
	// Note: DCxEVT1 events can be defined as one-shot.  
	//       DCxEVT2 events can be defined as cycle-by-cycle.
	EPwm6Regs.TZSEL.bit.DCAEVT1 = 1;
	EPwm6Regs.TZSEL.bit.DCBEVT1 = 0;

	// What do we want the DCAEVT1 and DCBEVT1 events to do?
	// DCAEVTx events can force EPWMxA 
	// DCBEVTx events can force EPWMxB  
	EPwm6Regs.TZCTL.bit.DCAEVT1 = TZ_FORCE_LO;           // EPWM6A will go low
	#endif

	#if 1
//	EPwm6Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;			//Enable TZ1 as a OST trip source	
//	EPwm6Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;			//Enable TZ2 as a OST trip source	
//	EPwm6Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;			//Enable TZ3 as a OST trip source
	EPwm6Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm6Regs.TZCTL.bit.TZB = TZ_NO_CHANGE;
	EPwm6Regs.TZEINT.bit.OST = 0;					//disable interrupt
    #endif
	
	EPwm6Regs.TBCTR = 0;
	EPwm6Regs.TBPHS.half.TBPHS = 0;	 
	EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm6Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down
		 
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 
	EPwm6Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm6Regs.TBPRD = DC_DC_FREQUENCY_70KHZ;

	EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;			//Timebase clock pre-scale
	EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
//	EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;		//Select INT on PRD event
	EPwm6Regs.ETSEL.bit.INTEN = 0;					//Disnable INT
//	EPwm6Regs.ETPS.bit.INTPRD = ET_1ST;				//Generate INT on 1st event
	EPwm6Regs.ETCLR.all = 0x000F;			 		//Clear all ETFLAG
	
	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm6Regs.CMPA.half.CMPA = DC_PRD_Ts - DC_DUTY_MIN;

	EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;
//	EPwm6Regs.AQCTLA.bit.CAD = AQ_CLEAR;
	EPwm6Regs.AQCTLA.bit.PRD = AQ_CLEAR;
				
	#ifdef DT_REG
   	EPwm6Regs.DBCTL.bit.OUT_MODE = DBB_ENABLE;
    EPwm6Regs.DBCTL.bit.POLSEL = DBA_ALL;			//Neither inverted
    EPwm6Regs.DBRED = DEAD_TIME;
    //EPwm6Regs.DBFED = DC_DB_TIME;		
	#endif

	#if 0
	EPwm6Regs.HRCNFG.all = 0x0;	
    EPwm6Regs.HRCNFG.bit.HRLOAD = HR_CTR_ZERO;
	EPwm6Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm6Regs.HRCNFG.bit.EDGMODE = HR_BEP;			//rising and falling edge
	EPwm6Regs.HRCNFG.bit.AUTOCONV = HR_CONV_AUTO;	//Enable autoconversion

    EPwm6Regs.HRPCTL.bit.HRPE = 0x01;				//Turn on high-resolution period control.
    EPwm6Regs.HRPCTL.bit.TBPHSHRLOADE = 1;
	#endif
}
#if 0
void InitEPWM7(void)
{
	EPwm7Regs.TZSEL.bit.OSHT3 = TZ_DISABLE;	
	EPwm7Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
	EPwm7Regs.TZCTL.bit.TZB = TZ_FORCE_LO;
	EPwm7Regs.TZCLR.all = 0x0007;					//clear all TZFLAG
	EPwm7Regs.TZEINT.bit.OST = 0;					//disable interrupt

	EPwm7Regs.TBCTR = 0;
	EPwm7Regs.TBCTL.bit.PHSDIR = TB_UP;				//Phase Direction Down		 
	EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; 
	EPwm7Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm7Regs.TBPRD = PFC_Ts;

	EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV4;			//Timebase clock pre-scale
	EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		//High speed time pre-scale
	
	EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;

	EPwm7Regs.CMPA.half.CMPA = 0;		//PFC_DUTY_MAX
	EPwm7Regs.CMPB = 0;

	EPwm7Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR;

	EPwm7Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm7Regs.AQCTLB.bit.CBU = AQ_CLEAR;
}
#endif
//===========================================================================
// End of file.
//===========================================================================
