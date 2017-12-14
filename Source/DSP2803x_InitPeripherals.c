//#########################################################
//
// FILE:	DSP28_InitPeripherals.c
//
// TITLE:	DSP28 Device Initialization To Default State.
//
//#########################################################
// Running on TMS320LF280xA   DCDC part   h741au1(1.00)               
// External clock is 20MHz, PLL * 10/2 , CPU-Clock 100 MHz	      
// Date: from May 23, 2005 to Oct 30, 2006  , (C) www & mhp & mj & lyg
// Version:1.00     Change Date: May 24, 2005 , 
//#########################################################


#include "DSP2803x_Device.h"
//-------------------------------------------------------------------------
// InitPeripherals:
//-------------------------------------------------------------------------
// The following function initializes the peripherals to a default state.
// It calls each of the peripherals default initialization functions.
// This function should be executed at boot time or on a soft reset.
//
void InitPeripherals(void)
{
	InitEPwm();
	InitAdc();
	InitCpuTimers();
//	InitECan();
//	InitSci();
//    InitI2C();
}

//=========================================================
// No more.
//=========================================================
