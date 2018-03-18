// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   11:11:34 $
//###########################################################################
//
// FILE:	DSP280x_CpuTimers.c
//
// TITLE:	CPU 32-bit Timers Initialization & Support Functions.
//
// NOTES:   CpuTimer1 and CpuTimer2 are reserved for use with DSP BIOS and
//          other realtime operating systems.  
//
//          Do not use these two timers in your application if you ever plan
//          on integrating DSP-BIOS or another realtime OS. 
//
//          For this reason, the code to manipulate these two timers is
//          commented out and not used in these examples.
//           
//###########################################################################
// $TI Release: DSP280x V1.30 $
// $Release Date: February 10, 2006 $
//###########################################################################

#include "DSP2803x_Device.h"     // Headerfile Include File

#include "config.h"


struct CPUTIMER_VARS CpuTimer0;
struct CPUTIMER_VARS CpuTimer1;



// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
//struct CPUTIMER_VARS CpuTimer1;
//struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// InitCpuTimers: 
//---------------------------------------------------------------------------
// This function initializes all three CPU timers to a known state.
//
void InitCpuTimers(void)
{
    // CPU Timer 0
    // Initialize address pointers to respective timer registers:
    CpuTimer0.RegsAddr = &CpuTimer0Regs;
    // Initialize timer period to maximum:
    CpuTimer0Regs.PRD.all  = CPU_TIME0_PERIOD_REGISTER_VALUE;

    CpuTimer0Regs.TPR.bit.TDDR= CPU_TIMER0_DIVIDER;
	CpuTimer0Regs.TPR.bit.PSC = 0;
    CpuTimer0Regs.TPRH.all = 0;
	//Timer0 Free Run
	CpuTimer0Regs.TCR.bit.FREE = 1;
    // Make sure timer is stopped:
    CpuTimer0Regs.TCR.bit.TSS = 1;
    // Reload all counter register with period value:
    CpuTimer0Regs.TCR.bit.TRB = 1;
	//Enable interrupt
	CpuTimer0Regs.TCR.bit.TIE = 1;
	//Clear interrupt flag
	CpuTimer0Regs.TCR.bit.TIF = 1;
    // Reset interrupt counters:
    CpuTimer0.InterruptCount = 0;            	
	
	
// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
// Do not use these two timers if you ever plan on integrating 
// DSP-BIOS or another realtime OS. 
//
// For this reason, the code to manipulate these two timers is
// commented out and not used in these examples.

    // Initialize address pointers to respective timer registers:
	CpuTimer1.RegsAddr = &CpuTimer1Regs;
//	CpuTimer2.RegsAddr = &CpuTimer2Regs;
	// Initialize timer period to maximum:
	CpuTimer1Regs.PRD.all  = HPTSC_COUNTER_MSK;
//	CpuTimer2Regs.PRD.all  = 0xFFFFFFFF;
	// Initialize pre-scale counter to divide by 200 (SYSCLKOUT):60000000/200=300KHz(input clock)
	CpuTimer1Regs.TPR.bit.TDDR= CPU_TIMER1_DIVIDER;
	CpuTimer1Regs.TPR.bit.PSC = 0;
	CpuTimer1Regs.TPRH.all = 0;

		//Timer1 Free Run
	CpuTimer1Regs.TCR.bit.FREE = 1;
	// Make sure timers are stopped:
	CpuTimer1Regs.TCR.bit.TSS = 1;             
//	CpuTimer2Regs.TCR.bit.TSS = 1;             
	// Reload all counter register with period value:
	CpuTimer1Regs.TCR.bit.TRB = 1;             
//	CpuTimer2Regs.TCR.bit.TRB = 1;             
	// Reset interrupt counters:
	CpuTimer1.InterruptCount = 0;
//	CpuTimer2.InterruptCount = 0;

}	
	
//---------------------------------------------------------------------------
// ConfigCpuTimer: 
//---------------------------------------------------------------------------
// This function initializes the selected timer to the period specified
// by the "Freq" and "Period" parameters. The "Freq" is entered as "MHz"
// and the period in "uSeconds". The timer is held in the stopped state
// after configuration.
//

//===========================================================================
// End of file.
//===========================================================================
