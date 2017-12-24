// TI File $Revision: /main/2 $
// Checkin $Date: December 2, 2004   11:50:58 $
//###########################################################################
//
// FILE:	DSP280x_Gpio.c
//
// TITLE:	DSP280x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP280x V1.30 $
// $Release Date: February 10, 2006 $
//###########################################################################

#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File


//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
	EALLOW;
   
	// Each GPIO pin can be: 
	// a) a GPIO input/output
	// b) peripheral function 1
	// c) peripheral function 2
	// d) peripheral function 3
	// By default, all are GPIO Inputs 
	GpioCtrlRegs.GPAMUX1.all = 0x1000;     // GPIO functionality GPIO0-GPIO15
	GpioCtrlRegs.GPAMUX2.all = 0x0000;     // GPIO functionality GPIO16-GPIO31
	GpioCtrlRegs.GPBMUX1.all = 0x0000;     // GPIO functionality GPIO32-GPIO44

	// Pin:								44		43		42		41		40
	// role:							/		TESTP2	SR_SD	/		YELLOW
	// dft:   							-		-		0		-		0

	// Pin:		39		38		37		36		35		34		33		32
	// role:	WDLED	TCK		TDO		TMS		TDI		/		SCL		SDA
	// dft:   	-		-		-		-		-		1		-		-

	// Pin:		31		30		29(I)	28(I)	27(I)	26		25		24
	// role:	CANTx	CANRx	DCOVP	DCOCP	DISCHARGE	/		/DSP_CTRL_12V	FanPwm
	// dft:   	-		-		-		-		-		-		-		0

	// Pin:		23		22		21(I)	20(I)	19		18		17		16
	// role:	/		-WP		ACP+	ACP-	/		/		/		/
	// dft:		-		1		-		-		-		-		-		-

	// Pin:		15(I)	14		13		12		11		10		9		8
	// role:	PFCOCP	DCDCSHORT	mainRe	/		GREEN	RED		/		DC2B
	// dft:		-		0		0		-		0		0		1		-

	// Pin:		7		6		5		4		3		2		1		0
	// role:	/		DC2A	/		DC1B	PFCB	PFCA	/		DC1A
	// dft:		-		-		-		-		-		-		-		-


	// Pull-ups can be enabled or disabled. 
	//0 Enable the internal pullup on the specified pin.
	//1 Disable the internal pullup on the specified pin.
	GpioCtrlRegs.GPAPUD.all = 0xFDFFBFFF;	// 1:Pullup's disabled 0:enable
	GpioCtrlRegs.GPBPUD.all = 0x1FF;		// 1:Pullup's disabled 0:enable

	//Specifies the qualification sampling period for GPIO
	GpioCtrlRegs.GPACTRL.all = 0x00000000;		//QUALPRD = SYSCLKOUT
	GpioCtrlRegs.GPBCTRL.bit.QUALPRD0 = 0x00;	//QUALPRD = SYSCLKOUT

    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0x12;	//QUALPRD = 2*18*SYSCLKOUT
   
	// Each input can have different qualification
	// a) input synchronized to SYSCLKOUT
	// b) input qualified by a sampling window
	// c) input sent asynchronously (valid for peripheral inputs only)
	GpioCtrlRegs.GPAQSEL1.all = 0x00000000;    // GPIO0-GPIO15 Synch to SYSCLKOUT. 
	GpioCtrlRegs.GPAQSEL2.all = 0x00000000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
	GpioCtrlRegs.GPBQSEL1.all = 0x00000000;    // GPIO32-GPIO34 Synch to SYSCLKOUT 

    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 2;    // GPIO12 Synch to 6*Samples = 5*2*18*SYSCLKOUT
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 2;    // GPIO16 Synch to 6*Samples = 5*2*18*SYSCLKOUT
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 2;    // GPIO17 Synch to 6*Samples = 5*2*18*SYSCLKOUT

   	//0 Configures the GPIO pin as an input.
	//1 Configures the GPIO pin as an output


//	GpioCtrlRegs.GPADIR.all = 0x0EE08000;
//	GpioCtrlRegs.GPBDIR.all = 0x0000;

	// GPIO12---PFC_OK
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;	// GPIO12 as gpio 
	GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;	    // GPIO12 as input
	GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;	    // Pullup's enabled

	// GPIO17---LED1
	GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;	// GPIO12 as gpio 
	GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;	    // GPIO12 as output
	GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;	    // Pullup's enabled

	// GPIO18---LED2
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;	// GPIO18 as gpio 
	GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;	    // GPIO18 as output
	GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;	    // Pullup's enabled

	// GPIO25---LED3
	GpioCtrlRegs.GPAMUX2.bit.GPIO16= 0;	// GPIO25 as gpio 
	GpioCtrlRegs.GPADIR.bit.GPIO25 = 1;	    // GPIO25 as Output
	GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;	    // Pullup's enabled

	#if 0
	// GPIO44---LE3
	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 0;	// GPIO44 as gpio 
	GpioCtrlRegs.GPBDIR.bit.GPIO44 = 1;	    // GPIO44 as Output
	GpioCtrlRegs.GPBPUD.bit.GPIO44 = 0;	    // Pullup's enabled
    #endif
	

    // GPIO23---24Wpd
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0;    // GPIO23 as gpio
	GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;	    // GPIO23 as output
	GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;	    // Pullup's Disabled
	
	EDIS;	
}	
	
//===========================================================================
// End of file.
//===========================================================================
