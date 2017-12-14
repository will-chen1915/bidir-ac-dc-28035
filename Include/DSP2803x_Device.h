//###########################################################################
//
// FILE:   DSP2803x_Device.h
//
// TITLE:  DSP2803x Device Definitions.
//
//###########################################################################
// $TI Release: F2803x C/C++ Header Files and Peripheral Examples V126 $
// $Release Date: November 30, 2011 $
//###########################################################################

#ifndef DSP2803x_DEVICE_H
#define DSP2803x_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#define   TARGET   1
//---------------------------------------------------------------------------
// User To Select Target Device:


#define   DSP28_28030PAG   0
#define   DSP28_28030PN    0

#define   DSP28_28031PAG   0
#define   DSP28_28031PN    0

#define   DSP28_28032PAG   0
#define   DSP28_28032PN    0

#define   DSP28_28033PAG   0
#define   DSP28_28033PN    0

#define   DSP28_28034PAG   0
#define   DSP28_28034PN    0

#define   DSP28_28035PAG   0
#define   DSP28_28035PN    TARGET


//---------------------------------------------------------------------------
// Common CPU Definitions:
//

extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int IER;

#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define  EALLOW asm(" EALLOW")
#define  EDIS   asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x0001
#define BIT1    0x0002
#define BIT2    0x0004
#define BIT3    0x0008
#define BIT4    0x0010
#define BIT5    0x0020
#define BIT6    0x0040
#define BIT7    0x0080
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000

//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             int16;
typedef long            int32;
typedef unsigned char   Uint8;
typedef unsigned int    Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif

#ifndef UINT16
#define	UINT16	Uint16
#define	UINT32	Uint32
#define	INT16	int16
#define	INT32	int32
#define	FLOAT	float
#endif

typedef union
	{
		INT32		dword;
		struct
		{
			UINT16 	lword;
			INT16 	hword;
		}			half;
	}UNLONG;											//变量名加前缀un_

typedef	union {
   Uint16               all;
//   struct EPROM_BITS   bit;
}ubitintd;


struct intData
{
	int iLD;
	int iHD;
};
typedef struct intData intStructData;

typedef	union 
{
	int32 lData;
	intStructData iData;
}longunion;


typedef	union 
{
	unsigned int id ;
	struct   packed_data
	{
		 unsigned highchar : 8;
		 unsigned lowchar  : 8;
	}bitdata;                                                                                                    
}ubitint ;


typedef	union 
{
	float fd ;
	ubitint intdata[2];   
	long	lData;	
	intStructData iData;
}ubitfloat ;


typedef union
{
	unsigned int msgaddid[3];
	struct
	{
		unsigned ADDIDL	:16;		/* reserved */
		unsigned ADDIDH	:16;		/* reserved */
		unsigned ADDADD	:8;		/* com attribute */
		unsigned ADDOK	:8;		/* 1:continuous frame */
	}msgaddbit;
}frameaddid;

//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//
#include "DSP2803x_Adc.h"                // ADC Registers
#include "DSP2803x_BootVars.h"           // Boot ROM Variables
#include "DSP2803x_DevEmu.h"             // Device Emulation Registers
#include "DSP2803x_Cla.h"                // Control Law Accelerator Registers
#include "DSP2803x_Cla_defines.h"
#include "DSP2803x_Comp.h"               // Comparator Registers

#include "DSP2803x_CpuTimers.h"          // 32-bit CPU Timers
#include "DSP2803x_DefaultISR.h"          // 32-bit CPU Timers
#include "DSP2803x_ECan.h"               // Enhanced eCAN Registers
#include "DSP2803x_ECap.h"               // Enhanced Capture
#include "DSP2803x_EPwm.h"               // Enhanced PWM
#include "DSP2803x_EQep.h"               // Enhanced QEP
#include "DSP2803x_Gpio.h"               // General Purpose I/O Registers
#include "DSP2803x_HRCap.h"              // High Resolution Capture
#include "DSP2803x_I2c.h"                // I2C Registers
#include "DSP2803x_Lin.h"                // LIN Registers
#include "DSP2803x_NmiIntrupt.h"         // NMI Interrupt Registers
#include "DSP2803x_PieCtrl.h"            // PIE Control Registers
#include "DSP2803x_PieVect.h"            // PIE Vector Table
#include "DSP2803x_Spi.h"                // SPI Registers
#include "DSP2803x_Sci.h"                // SCI Registers
#include "DSP2803x_SysCtrl.h"            // System Control/Power Modes
#include "DSP2803x_XIntrupt.h"           // External Interrupts
#include "DSP2803x_ePwm_defines.h"           // pwm define
#include "SFO_V6.h"
#include "IQmathLib.h"
#include "Flash2803x_API.h"
#include "Flash2803x_API_Config.h"
#include "Flash2803x_API_Library.h"
//#include "VmaxPower_isr.h"
//#include "VmaxPower_RS485.h"
#include "PubFunc.h"
//#include "VmaxPower_constant.h"
#include "FlashUpdate.h"
//#include "VmaxPower_main.h"
#include "DSP2803x_GlobalPrototypes.h"             // Device Emulation Registers
#include "CLAShared.h"
//#include "VmaxPower_eeprom.h"
#include "App_stateCtrl.h"
#include "hptsc.h"
#include "power_loopCtrl.h"
#include "analogChk_control.h"
#include "App_stateCtrl.h"
#include "power_loopCtrl.h"
#include "Signal_IOCtrl.h"
#include "main.h"
#include <stdbool.h>
#include <stdint.h>

#include "Cla.h"
//#include "Cla_shared.h" 

#if (DSP28_28035PN||DSP28_28034PN||DSP28_28033PN||DSP28_28032PN||DSP28_28031PN||DSP28_28030PN)
#define DSP28_COMP1 1
#define DSP28_COMP2 1
#define DSP28_COMP3 1
#define DSP28_EPWM1 1
#define DSP28_EPWM2 1
#define DSP28_EPWM3 1
#define DSP28_EPWM4 1
#define DSP28_EPWM5 1
#define DSP28_EPWM6 1
#define DSP28_EPWM7 1
#define DSP28_ECAP1 1
#define DSP28_EQEP1 1
#define DSP28_ECANA 1
#define DSP28_HRCAP1 1
#define DSP28_HRCAP2 1
#define DSP28_SPIA  1
#define DSP28_SPIB  1
#define DSP28_SCIA  1
#define DSP28_I2CA  1
#define DSP28_LINA  1
#endif

#if (DSP28_28035PAG||DSP28_28034PAG||DSP28_28033PAG||DSP28_28032PAG||DSP28_28031PAG||DSP28_28030PAG)
#define DSP28_COMP1 1
#define DSP28_COMP2 1
#define DSP28_COMP3 1
#define DSP28_EPWM1 1
#define DSP28_EPWM2 1
#define DSP28_EPWM3 1
#define DSP28_EPWM4 1
#define DSP28_EPWM5 1
#define DSP28_EPWM6 1
#define DSP28_EPWM7 0
#define DSP28_ECAP1 1
#define DSP28_EQEP1 1
#define DSP28_ECANA 1
#define DSP28_HRCAP1 1
#define DSP28_HRCAP2 1
#define DSP28_SPIA  1
#define DSP28_SPIB  0
#define DSP28_SCIA  1
#define DSP28_I2CA  1
#define DSP28_LINA  1
#endif

// Timer definitions based on System Clock
// 60 MHz devices 
	#define      mSec0_5          30000           // 0.5 mS
	#define      mSec0_75         45000           // 0.75 mS
	#define      mSec1            60000           // 1.0 mS
	#define      mSec2            120000          // 2.0 mS
	#define      mSec5            300000          // 5.0 mS
	#define      mSec7_5          450000          // 7.5 mS
	#define      mSec10           600000          // 10 mS
	#define      mSec20           1200000         // 20 mS
	#define      mSec50           3000000         // 50 mS
	#define      mSec75           4500000         // 75 mS
	#define      mSec100          6000000         // 100 mS
	#define      mSec200          12000000        // 200 mS
	#define      mSec500          30000000        // 500 mS
	#define      mSec750          45000000        // 750 mS
	#define      mSec1000         60000000        // 1000 mS
	#define      mSec2000         120000000       // 2000 mS
	#define      mSec5000         300000000       // 5000 mS



/*-----------------------------------------------------------------------------
      Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
-----------------------------------------------------------------------------*/

//#define DSP28_DIVSEL   0 // Enable /4 for SYSCLKOUT
//#define DSP28_DIVSEL   1 // Disable /4 for SYSCKOUT
#define DSP28_DIVSEL   2 // Enable /2 for SYSCLKOUT
//#define DSP28_DIVSEL   3 // Enable /1 for SYSCLKOUT


#define DSP28_PLLCR   6    // Uncomment for 60 MHz devices [60 MHz = (20MHz * 12)/2]
//#define DSP28_PLLCR   11
//#define DSP28_PLLCR   10
//#define DSP28_PLLCR    9
//#define DSP28_PLLCR    8      // Uncomment for 40 MHz devices [40 MHz = (10MHz * 8)/2]
//#define DSP28_PLLCR    7
//#define DSP28_PLLCR    6
//#define DSP28_PLLCR    5
//#define DSP28_PLLCR    4
//#define DSP28_PLLCR    3
//#define DSP28_PLLCR    2
//#define DSP28_PLLCR    1
//#define DSP28_PLLCR    0  // PLL is bypassed in this mode
//----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.

      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat
      the number as a 64-bit value.

      Only one statement should be uncommented.

      Example:   60 MHz devices:
                 CLKIN is a 10 MHz crystal or internal 10 MHz oscillator

                 In step 1 the user specified PLLCR = 0xC for a
                 60 MHz CPU clock (SYSCLKOUT = 60 MHz).

                 In this case, the CPU_RATE will be 16.667L
                 Uncomment the line: #define CPU_RATE 16.667L

-----------------------------------------------------------------------------*/

#define CPU_RATE   16.667L   // for a 60MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   25.000L   // for a 40MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//----------------------------------------------------------------------------

// The following pointer to a function call calibrates the ADC and internal oscillators
#define Device_cal (void   (*)(void))0x3D7C80


// DO NOT MODIFY THIS LINE.
//#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)
#define DELAY_US(A)  AppDSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2803x_DEVICE_H definition

//===========================================================================
// End of file.
//===========================================================================
