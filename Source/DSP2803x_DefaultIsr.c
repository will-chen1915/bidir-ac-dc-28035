//#########################################################
//
// FILE:	DSP280x_DefaultIsr.c
//
// TITLE:	DSP280x Device Default Interrupt Service Routines.
//
// This file contains shell ISR routines for the 280x PIE vector table.
// Typically these shell ISR routines can be used to populate the entire PIE 
// vector table during device debug.  In this manner if an interrupt is taken
// during firmware development, there will always be an ISR to catch it.  
//
// As develpment progresses, these ISR rotuines can be eliminated and replaced
// with the user's own ISR routines for each interrupt.  Since these shell ISRs
// include infinite loops they will typically not be included as-is in the final
// production firmware. 
//
//#########################################################
// Running on TMS320LF280xA   DCDC part   h741au1(1.00)               
// External clock is 20MHz, PLL * 10/2 , CPU-Clock 100 MHz	      
// Date: from May 23, 2005 to Oct 30, 2006  , (C) www & mhp & mj & lyg
// Version:1.00     Change Date: May 24, 2005 , 
//#########################################################

#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File

/*interrupt void rsvd_ISR(void)      // For test
{
	EPwm1Regs.AQCSFRC.all = 0x5;		//PWM1A,PWM1B force low
	EPwm2Regs.AQCSFRC.all = 0x5;		//PWM2A,PWM2B force low
	
	for(;;);
}*/

interrupt void USER_ISR(void)       // Non-maskable interrupt
{
//	mOffDcdcPwm();		// close and PWM disable
//	mOffPfcPwm();
	
	for(;;);		// wait for watchdog
}
//===========================================================================
// End of file.
//===========================================================================

