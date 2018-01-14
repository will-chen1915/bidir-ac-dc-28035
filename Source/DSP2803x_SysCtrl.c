// TI File $Revision: /main/4 $
// Checkin $Date: September 8, 2005   17:32:45 $
//###########################################################################
//
// FILE:   DSP280x_SysCtrl.c
//
// TITLE:  DSP280x Device System Control Initialization & Support Functions.
//
// DESCRIPTION:
//
//         Example initialization of system resources.
//
//###########################################################################
// $TI Release: DSP280x V1.30 $
// $Release Date: February 10, 2006 $
//###########################################################################


#include "DSP28x_Project.h"     // Headerfile Include File
// a different section.  This section will then be mapped to a load and 
// run address using the linker cmd file.
#define ADC_MODCLK 0x0   // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*4) = 12.5 MHz
void IntOsc1Sel (void);
void DisableDog(void);
//---------------------------------------------------------------------------
// Example: DisableDog: 
//---------------------------------------------------------------------------
// This function disables the watchdog timer.

void DisableDog(void)
{
    EALLOW;
    SysCtrlRegs.WDCR = 0x006F;
    EDIS;
}
// Example: IntOsc1Sel:
//---------------------------------------------------------------------------
// This function switches to Internal Oscillator 1 and turns off all other clock
// sources to minimize power consumption

void IntOsc1Sel (void)
 {
    EALLOW;
	SysCtrlRegs.CLKCTL.bit.INTOSC1OFF = 0;
    SysCtrlRegs.CLKCTL.bit.OSCCLKSRCSEL=0;  // Clk Src = INTOSC1
	SysCtrlRegs.CLKCTL.bit.XCLKINOFF=1;     // Turn off XCLKIN
	SysCtrlRegs.CLKCTL.bit.XTALOSCOFF=1;    // Turn off XTALOSC
	SysCtrlRegs.CLKCTL.bit.INTOSC2OFF=1;    // Turn off INTOSC2
    EDIS;
}
//---------------------------------------------------------------------------
// Example: InitPll: v1.3
//---------------------------------------------------------------------------
// This function initializes the PLLCR register.
//#pragma CODE_SECTION(InitPll,"FlashBoot");
void InitPll(UINT16 val, UINT16 divsel)
{
   volatile UINT16 iVol;   
   
   // Make sure the PLL is not running in limp mode
   if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
   {
      // Missing external clock has been detected
      // Replace this line with a call to an appropriate
      // SystemShutdown(); function.

	  IntOsc1Sel();

       EALLOW;
      // OSCCLKSRC1 failure detected. PLL running in limp mode.
      // Re-enable missing clock logic.
      SysCtrlRegs.PLLSTS.bit.MCLKCLR = 1;
      EDIS; 
	 
      asm("        ESTOP0");
   }


     if (SysCtrlRegs.PLLSTS.bit.DIVSEL != 0)
   {
       EALLOW;
       SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
       EDIS;
   }

   // CLKINDIV MUST be 0 before PLLCR can be changed from
   // 0x0000. It is set to 0 by an external reset XRSn
   /*
   if (SysCtrlRegs.PLLSTS.bit.CLKINDIV != 0)
   {
       SysCtrlRegs.PLLSTS.bit.CLKINDIV = 0;
   }
   */
   
   // Change the PLLCR
   if (SysCtrlRegs.PLLCR.bit.DIV != val)
   {
       
      EALLOW;
      // Before setting PLLCR turn off missing clock detect logic
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
      SysCtrlRegs.PLLCR.bit.DIV = val;
      EDIS;
   
      // Optional: Wait for PLL to lock.
      // During this time the CPU will switch to OSCCLK/2 until
      // the PLL is stable.  Once the PLL is stable the CPU will 
      // switch to the new PLL value. 
      //
      // This time-to-lock is monitored by a PLL lock counter.   
      //   
      // Code is not required to sit and wait for the PLL to lock.   
      // However, if the code does anything that is timing critical, 
      // and requires the correct clock be locked, then it is best to 
      // wait until this switching has completed.  
  
      // Wait for the PLL lock bit to be set.  
      // Note this bit is not available on 281x devices.  For those devices
      // use a software loop to perform the required count. 

      // The watchdog should be disabled before this loop, or fed within 
      // the loop via ServiceDog().   
      
	  // Uncomment to disable the watchdog
      DisableDog();
   
      while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1) 
      {
	      // Uncomment to service the watchdog
          // KickDog();
      }
       
      EALLOW;
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
      EDIS;   
    }
	
   // If switching to 1/2
	if((divsel == 1)||(divsel == 2))
	{
		EALLOW;
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = divsel;
	    EDIS;
	}

   // * First go to 1/2 and let the power settle
	//   The time required will depend on the system, this is only an example
	// * Then switch to 1/1
	if(divsel == 3)
	{
		EALLOW;
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
	    DELAY_US(50L);
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = 3;
	    EDIS;
    }

}

//--------------------------------------------------------------------------
// Example: InitPeripheralClocks: 
//---------------------------------------------------------------------------
// This function initializes the clocks to the peripheral modules.
// First the high and low clock prescalers are set
// Second the clocks are enabled to each peripheral.
// To reduce power, leave clocks to unused peripherals disabled
//
// Note: If a peripherals clock is not enabled then you cannot 
// read or write to the registers for that peripheral 

void InitPeripheralClocks(void)
{
   EALLOW;


	// XCLKOUT OFF
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;		// 0:Stop all the TB clocks
	SysCtrlRegs.XCLK.bit.XCLKOUTDIV = 3;
     	
// Peripheral clock enables set for the selected peripherals.   
// If you are not using a peripheral leave the clock off
// to save on power. 
// 
// Note: not all peripherals are available on all 280x derivates.
// Refer to the datasheet for your particular device. 
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;		// ADC
	SysCtrlRegs.PCLKCR3.bit.COMP1ENCLK = 1; 	// COMP1
	SysCtrlRegs.PCLKCR3.bit.COMP2ENCLK = 1; 	// COMP2
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1; // CPU Timer-0
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1; // CPU Timer-1
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER2ENCLK = 1; // CPU Timer-2

	SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;		// I2C
	//SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 0;		// SPI-A
	//SysCtrlRegs.PCLKCR0.bit.SPIBENCLK = 0;		// SPI-B
	SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;		// SCI-A
	//SysCtrlRegs.PCLKCR0.bit.ECANAENCLK = 1;		// eCAN-A
	//SysCtrlRegs.PCLKCR0.bit.LINAENCLK = 1;		// LIN
    SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;		// eCAP1
   	SysCtrlRegs.PCLKCR2.bit.HRCAP1ENCLK = 0;
    SysCtrlRegs.PCLKCR2.bit.HRCAP2ENCLK = 0;
	
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;		// ePWM1
	SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;		// ePWM2
	SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;		// ePWM3
	SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;		// ePWM4
	SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;		// ePWM5
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;		// ePWM6
	SysCtrlRegs.PCLKCR1.bit.EPWM7ENCLK = 0;		// ePWM7
	SysCtrlRegs.PCLKCR0.bit.HRPWMENCLK = 1;		// HRPWM

	SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 0;		// eQEP1

	
	SysCtrlRegs.PCLKCR3.bit.COMP1ENCLK = 1; 
	SysCtrlRegs.PCLKCR3.bit.COMP2ENCLK = 1; 
	SysCtrlRegs.PCLKCR3.bit.COMP3ENCLK = 1;

	SysCtrlRegs.PCLKCR3.bit.CLA1ENCLK = 1;

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;		// 0:Stop all the TB clocks
												// 1:Enable TBCLK within the ePWM
	EDIS;
}


//---------------------------------------------------------------------------
// Example: IntOsc2Sel:
//---------------------------------------------------------------------------
// This function switches to Internal oscillator 2 from External Oscillator
// and turns off all other clock sources to minimize power consumption
// NOTE: If there is no external clock connection, when switching from
//       INTOSC1 to INTOSC2, EXTOSC and XLCKIN must be turned OFF prior
//       to switching to internal oscillator 1

void IntOsc2Sel (void) {
    EALLOW;
	SysCtrlRegs.CLKCTL.bit.INTOSC2OFF = 0;     // Turn on INTOSC2
    SysCtrlRegs.CLKCTL.bit.OSCCLKSRC2SEL = 1;  // Switch to INTOSC2
	SysCtrlRegs.CLKCTL.bit.XCLKINOFF = 1;      // Turn off XCLKIN
	SysCtrlRegs.CLKCTL.bit.XTALOSCOFF = 1;     // Turn off XTALOSC
	SysCtrlRegs.CLKCTL.bit.OSCCLKSRCSEL = 1;   // Switch to Internal Oscillator 2
    SysCtrlRegs.CLKCTL.bit.WDCLKSRCSEL = 1;    // Switch Watchdog Clk Src to INTOSC2
	SysCtrlRegs.CLKCTL.bit.INTOSC1OFF = 1;     // Turn off INTOSC1
    EDIS;
}

//---------------------------------------------------------------------------
// Example: XtalOscSel:
//---------------------------------------------------------------------------
// This function switches to External CRYSTAL oscillator and turns off all other clock
// sources to minimize power consumption. This option may not be available on all
// device packages

void XtalOscSel (void)  {
     EALLOW;
     SysCtrlRegs.CLKCTL.bit.XTALOSCOFF = 0;     // Turn on XTALOSC
     SysCtrlRegs.CLKCTL.bit.XCLKINOFF = 1;      // Turn off XCLKIN
     SysCtrlRegs.CLKCTL.bit.OSCCLKSRC2SEL = 0;  // Switch to external clock
     SysCtrlRegs.CLKCTL.bit.OSCCLKSRCSEL = 1;   // Switch from INTOSC1 to INTOSC2/ext clk
     SysCtrlRegs.CLKCTL.bit.WDCLKSRCSEL = 1;    // Switch Watchdog Clk Src to external clock
     SysCtrlRegs.CLKCTL.bit.INTOSC2OFF = 1;		// Turn off INTOSC2
     SysCtrlRegs.CLKCTL.bit.INTOSC1OFF = 1;		// Turn off INTOSC1
     EDIS;
}


//---------------------------------------------------------------------------
// Example: ExtOscSel:
//---------------------------------------------------------------------------
// This function switches to External oscillator and turns off all other clock
// sources to minimize power consumption.

void ExtOscSel (void)  {

	 EALLOW;
     SysCtrlRegs.XCLK.bit.XCLKINSEL = 1;       // 1-GPIO19 = XCLKIN, 0-GPIO38 = XCLKIN
     SysCtrlRegs.CLKCTL.bit.XTALOSCOFF = 1;	   // Turn off XTALOSC
     SysCtrlRegs.CLKCTL.bit.XCLKINOFF = 0; 	   // Turn on XCLKIN
     SysCtrlRegs.CLKCTL.bit.OSCCLKSRC2SEL = 0; // Switch to external clock
     SysCtrlRegs.CLKCTL.bit.OSCCLKSRCSEL = 1;  // Switch from INTOSC1 to INTOSC2/ext clk
     SysCtrlRegs.CLKCTL.bit.WDCLKSRCSEL = 1;   // Switch Watchdog Clk Src to external clock
     SysCtrlRegs.CLKCTL.bit.INTOSC2OFF = 1;	   // Turn off INTOSC2
     SysCtrlRegs.CLKCTL.bit.INTOSC1OFF = 1;	   // Turn off INTOSC1
	 EDIS;
}
//---------------------------------------------------------------------------
// InitSysCtrl: 
//---------------------------------------------------------------------------
// This function initializes the System Control registers to a known state.
// - Disables the watchdog
// - Set the PLLCR for proper SYSCLKOUT frequency 
// - Set the pre-scaler for the high and low frequency peripheral clocks
// - Enable the clocks to the peripherals

void InitSysCtrl(void)
{
	// Disable the watchdog        
//	Watch_Dog_Kick();
   
	//ExtOscSel();		// for external oscilator oscillator	 

	/*增加晶振判断，防止有源晶振的程序烧到无源晶振的扳子上*/
    if(SysCtrlRegs.PLLSTS.bit. OSCOFF != 0)
	{
		IntOsc1Sel();

	}
	// Initialize the PLLCR to 0x6
    InitPll(DSP28_PLLCR,DSP28_DIVSEL);
	
	// Initialize the peripheral clocks
	InitPeripheralClocks();
}

//---------------------------------------------------------------------------
// Example: InitFlash: 
//---------------------------------------------------------------------------
// This function initializes the Flash Control registers

//                   CAUTION 
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
#pragma CODE_SECTION(InitFlash, "AppRamfuncs");
//#pragma CODE_SECTION(InitFlash, "ramfuncs");
void InitFlash(void)
{
#if 0
   EALLOW;
   //Enable Flash Pipeline mode to improve performance
   //of code executed from Flash.
   FlashRegs.FOPT.bit.ENPIPE = 1;
   
   //                CAUTION
   //Minimum waitstates required for the flash operating
   //at a given CPU rate must be characterized by TI. 
   //Refer to the datasheet for the latest information.  

   //Set the Paged Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 3;

   //Set the Random Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.RANDWAIT = 3;
   
   //Set the Waitstate for the OTP
   FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;
   
   //                CAUTION
   //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;       
   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;   
   EDIS;

   //Force a pipeline flush to ensure that the write to 
   //the last register configured occurs before returning.  

   asm(" RPT #7 || NOP");
   #else
	 EALLOW;
	 //Enable Flash Pipeline mode to improve performance
	 //of code executed from Flash.
	 FlashRegs.FOPT.bit.ENPIPE = 1;
	
	 // 			   CAUTION
	 //Minimum waitstates required for the flash operating
	 //at a given CPU rate must be characterized by TI.
	 //Refer to the datasheet for the latest information.
	
	 //Set the Paged Waitstate for the Flash
	 FlashRegs.FBANKWAIT.bit.PAGEWAIT = 2;
	
	 //Set the Random Waitstate for the Flash
	 FlashRegs.FBANKWAIT.bit.RANDWAIT = 2;
	
	 //Set the Waitstate for the OTP
	 FlashRegs.FOTPWAIT.bit.OTPWAIT = 2;
	
// 			   CAUTION
	 //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
	 FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
	 FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
	 EDIS;
	
	 //Force a pipeline flush to ensure that the write to
	 //the last register configured occurs before returning.
	
	 asm(" RPT #7 || NOP");

   #endif
}	



//---------------------------------------------------------------------------
// Example: EnableDog: 
//---------------------------------------------------------------------------
// This function enables the watchdog timer.

void EnableDog(void)
{
    EALLOW;
    SysCtrlRegs.WDCR = 0x002F;
    EDIS;
}

//#pragma CODE_SECTION(Watch_Dog_Kick,"FlashBoot");
void Watch_Dog_Kick (void)
{
  	EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
    return;
}
	
//===========================================================================
// End of file.
//===========================================================================
