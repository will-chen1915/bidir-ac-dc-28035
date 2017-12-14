// TI File $Revision: /main/2 $
// Checkin $Date: December 2, 2004   11:55:13 $
//###########################################################################
//
// FILE:	DSP280x_I2C.c
//
// TITLE:	DSP280x SCI Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP280x V1.30 $
// $Release Date: February 10, 2006 $
//###########################################################################

#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File

//---------------------------------------------------------------------------
// Example: InitI2CGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as I2C pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
// Caution: 
// Only one GPIO pin should be enabled for SDAA operation.
// Only one GPIO pin shoudl be enabled for SCLA operation. 
// Comment out other unwanted lines.

void InitI2CGpio()
{

   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;    // Enable pull-up for GPIO32 (SDAA)
	GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;	   // Enable pull-up for GPIO33 (SCLA)

/* Set qualification for selected pins to asynch only */
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;  // Asynch input GPIO32 (SDAA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;  // Asynch input GPIO33 (SCLA)

/* Configure SCI pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be I2C functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;   // Configure GPIO32 for SDAA operation
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;   // Configure GPIO33 for SCLA operation
	
    EDIS;
	//GpioDataRegs.GPASET.bit.GPIO23 = 1;	//WP=1,disable write
}
//---------------------------------------------------------------------------
// InitI2C: 
//---------------------------------------------------------------------------
// This function initializes the I2C to a known state.
//
void InitI2C(void)
{
	/*InitI2CGpio();

	// Initialize I2C
	I2caRegs.I2CMDR.bit.IRS = 0;
	I2caRegs.I2CSAR = 0x0050;	// 7Fh,the 7-bit slave addr that  I2C transmits
								// when it is in the master-transmitter mode
	I2caRegs.I2CPSC.all = 5;	// 10M,Prescaler - need 7-12 Mhz on module clk
	I2caRegs.I2CCLKL = 40;		// ICCL,NOTE: must be non zero
	I2caRegs.I2CCLKH = 35;		// ICCH,NOTE: must be non zero
	I2caRegs.I2CIER.all = 0x00;	// Disable SCD & ARDY interrupts
	 */ 
	 /* 
		                           60MHz      60M
	  module clock frequency = ----------- = ------=10MHz
		                         (IPSC+1)       6

	                                   60MHz               		 60MHz
	  master clock frequency = ---------------------------	 = -------- = 80K
		                         (IPSC+1)[(ICCL+5)+(ICCH+5)]     6*125
	*/
	/*
	I2caRegs.I2CMDR.bit.IRS = 1;	// Take I2C out of reset
   									// Stop I2C when suspended
	I2caRegs.I2CFFTX.all = 0x6000;	// Enable FIFO mode and TXFIFO
	I2caRegs.I2CFFRX.all = 0x2040;	// Enable RXFIFO, clear RXFFINT,

	I2caRegs.I2CCNT = 0x0000;
	I2caRegs.I2CSTR.all = 0xFFFF;
*/
    INT16 i16Temp; 
	InitI2CGpio();
	
	I2caRegs.I2CMDR.bit.IRS = 0;								//I2C模块不使能
//	I2caRegs.I2CSAR = 0x50;									// 配置EEPROM 片地址
	
	// I2C时钟分频，当前时钟为60000000/7/125=68.6kHz
	//when I2CPSC >=1 时钟=系统时钟/(I2CPSC+1)/((I2CCLKL+5) +(I2CCLKH+5)) 
	//when I2CPSC =1   时钟=系统时钟/(I2CPSC+1)/((I2CCLKL+6) +(I2CCLKH+6)) 
	//when I2CPSC =0   时钟=系统时钟/(I2CPSC+1)/((I2CCLKL+7) +(I2CCLKH+7)) 
	I2caRegs.I2CPSC.all = 6;								
	I2caRegs.I2CCLKL = 45;			
	I2caRegs.I2CCLKH = 70;			
	
	I2caRegs.I2CIER.all = 0x0000;								// 关中断
	I2caRegs.I2CMDR.bit.IRS = 1;								// 使能I2C模块
	I2caRegs.I2CMDR.all = 0x0020;								//使能I2C 模块(同上一语句有相同功能)
	I2caRegs.I2CFFTX.all = 0x6000;								// 使能 FIFO 和 TXFIFO
	I2caRegs.I2CFFRX.all = 0x2000;								// 使能 RXFIFO,清 RXFFINT, 
  
	I2caRegs.I2CCNT=0x0000;
	I2caRegs.I2CSTR.all=0xFFFF;								//清除所有标志位
//I2C时钟使能，也可以把该语句调整至系统时钟初始化
//	SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;   					// I2C

	for (i16Temp = 0;i16Temp < 10000;i16Temp++)				//等待10ms以正确判断总线状态
  	{
		asm( " rpt #99||nop");
  	}
}	


	
//===========================================================================
// End of file.
//===========================================================================
