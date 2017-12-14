/*=============================================================================*
 *         Copyright(c) 2008-2012, Emerson Network Power Co., Ltd.
 *                          ALL RIGHTS RESERVED
 *
 *  PRODUCT  : 
 *
 *  FILENAME : DSP2803x_ECan.c
 *  PURPOSE  : DSP280x Enhanced CAN Initialization & Support Functions	      
 *  
 *  HISTORY  :
 *    DATE            VERSION        AUTHOR            NOTE
 *    2009-02-10      A00           zoulx             Created.   Pre-research 
 *	  2010-03-09	  A01			Chenhm			 change for 2803x
 *============================================================================*/
//############################################################################
// Running on TMS320LF2803xA   DCDC part   h741au1(1.00)               
// External clock is 20MHz, PLL * 10/2 , CPU-Clock 60 MHz	      
// Version:1.00     Change Date: May 24, 2005 , 
//############################################################################

#include "DSP2803x_Device.h"     // DSP28 Headerfile Include File

/*******************************************************************************
*Function name:	InitECana()
*Parameters:  ECanaShadow:Create a shadow register structure for the CAN control
*             registers. This is needed, since, only 32-bit access is allowed to
*             these registers. 16-bit access to these registers could potentially
*             corrupt the register contents. This is especially true while writing
*             to a bit (or group of bits) among bits 16 - 31.
*Description:   This function initializes the eCAN module                            
*******************************************************************************/
void InitECana(void)	
{
	struct ECAN_REGS ECanaShadow;
	
	// EALLOW enables access to protected bits
	EALLOW;		

	//disable all mailbox
	ECanaRegs.CANME.all = 0x00000000;
	
	// Configure eCAN RX and TX pins for eCAN transmissions using eCAN register  
	ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
	ECanaShadow.CANTIOC.bit.TXFUNC = 1;
	ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

	ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
	ECanaShadow.CANRIOC.bit.RXFUNC = 1;
	ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

	// Configure eCAN for HECC mode - (reqd to access mailboxes 16 thru 31) 
	// HECC mode also enables time-stamping feature
	ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
	ECanaShadow.CANMC.bit.SUSP = 1;	
	ECanaShadow.CANMC.bit.SCB = 1;	
	ECanaShadow.CANMC.bit.ABO = 1;	
	ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;
	
/* Initialize all bits of 'Message Control Register' to zero */
// Some bits of MSGCTRL register come up in an unknown state. For proper operation,
// all bits (including reserved bits) of MSGCTRL must be initialized to zero

    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

// TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
//	as a matter of precaution.

	ECanaRegs.CANTA.all	= 0xFFFFFFFF;	/* Clear all TAn bits */

	ECanaRegs.CANRMP.all = 0xFFFFFFFF;	/* Clear all RMPn bits */

	ECanaRegs.CANGIF0.all = 0xFFFFFFFF;	/* Clear all interrupt flag bits */
	ECanaRegs.CANGIF1.all = 0xFFFFFFFF;
	
	// Configure bit timing parameters for eCANA
	ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
	ECanaShadow.CANMC.bit.CCR = 1 ;            // Set CCR = 1
	ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	ECanaShadow.CANES.all = ECanaRegs.CANES.all;

	while(ECanaShadow.CANES.bit.CCE != 1 ) 	   // Wait for CCE bit to be set..
	{ECanaShadow.CANES.all = ECanaRegs.CANES.all;}   
    
	ECanaShadow.CANBTC.all = 0;

	ECanaShadow.CANBTC.bit.BRPREG = 3;		// TQ=(BRPREG+1)/SYSCLK/2=533ns, NTQ = 8us/533ns = 15
	ECanaShadow.CANBTC.bit.TSEG2REG = 2;	//500k
	ECanaShadow.CANBTC.bit.TSEG1REG =10;	////Bit rate = SYSCLKOUT/(BRPREG+1)*[(TSEG2REG+1)+(TSEG1REG+1)+1]) 

 	ECanaShadow.CANBTC.bit.SAM = 1;			// 0:采样三次
 	ECanaShadow.CANBTC.bit.SJWREG = 1;		// 0: synchronization jump width is 1
 	ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;
    
	ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
	ECanaShadow.CANMC.bit.CCR = 0;         // Set CCR = 0
	ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    
	while(ECanaShadow.CANES.bit.CCE != 0 ) 	// Wait for CCE bit to be  cleared..
	{ECanaShadow.CANES.all = ECanaRegs.CANES.all;}   

	ECanaMboxes.MBOX0.MSGID.all = 0x40000000; 
						/* bit 31: Use standard identifier. AMI bit must be equal to 0 for the IDE to be used in this fashion.
						     bit30: Acceptance Mask Enabled.
						     bit19: Normal transmit mode.
						     bit28~bit0: Message identifier*/
   ECanaMboxes.MBOX1.MSGID.all = 0x40000000; 
						/* bit 31: Use standard identifier. AMI bit must be equal to 0 for the IDE to be used in this fashion.
						     bit30: Acceptance Mask Enabled.
						     bit19: Normal transmit mode.
						     bit28~bit0: Message identifier*/

	ECanaMboxes.MBOX4.MSGID.all = 0x40000000; 
						/* bit 31: Use standard identifier. AMI bit must be equal to 0 for the IDE to be used in this fashion.
						     bit30: Acceptance Mask Enabled.
						     bit19: Normal transmit mode.
						     bit28~bit0: Message identifier*/
    ECanaMboxes.MBOX5.MSGID.all = 0x40000000; 
						/* bit 31: Use standard identifier. AMI bit must be equal to 0 for the IDE to be used in this fashion.
						     bit30: Acceptance Mask Enabled.
						     bit19: Normal transmit mode.
						     bit28~bit0: Message identifier*/
	
	//Setup Acceptance mask
    ECanaLAMRegs.LAM0.all = 0xF7FFFFFF;   //don't care
    ECanaLAMRegs.LAM1.all = 0xF7FFFFFF;   //don't care
    ECanaLAMRegs.LAM4.all = 0xFFFFFFFF;   //don't care
    ECanaLAMRegs.LAM5.all = 0xFFFFFFFF;   //don't care

	//Configure Mailbox direction registers
    ECanaRegs.CANMD.all = 0x00000030; // mailboxs 4~5 is configure receive mailboxs, others are transmit mailboxs
   
   //Configure mailbox overwrite protection
    ECanaRegs.CANOPC.all = 0x00000030;
   
   //Enable Mailbox(es)
    ECanaRegs.CANME.all = 0x00000033; //Enable transmit mailbox1，mailbox0; and receive box 4,5

	EDIS;
}	

void InitECanaID(void)
{
   	EALLOW;	
	ECanaRegs.CANME.all = 0x00000000;

	ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000008;
	ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000008;
	ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000008;

	ECanaMboxes.MBOX1.MSGID.all = 0xc6000003;

	ECanaRegs.CANME.all = 0x00000032;		// Required before writing the MSGIDs
	ECanaRegs.CANMD.all = 0x00000002; 	

	EDIS;
	ECanaLAMRegs.LAM1.all = 0x810FFFFC;
	ECanaLAMRegs.LAM4.all = 0x800FFFFC;
	ECanaLAMRegs.LAM5.all = 0x800FFFFC;



}


/*******************************************************************************
*Function name:	InitECanaGpio()
*Description:   This function initializes GPIO pins to function as eCAN pins                            
*******************************************************************************/
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
// Caution: 
// Only one GPIO pin should be enabled for CANTXA/B operation.
// Only one GPIO pin shoudl be enabled for CANRXA/B operation. 
// Comment out other unwanted lines.
void InitECanaGpio(void)
{
   EALLOW;

	// Enable internal pull-up for the selected CAN pins 
	// Pull-ups can be enabled or disabled by the user. 
	// This will enable the pullups for the specified pins.
	// Comment out other unwanted lines.
	GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;	    // Enable pull-up for GPIO30 (CANRXA)
	GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;	    // Enable pull-up for GPIO31 (CANTXA)

	// Set qualification for selected CAN pins to asynch only
	// Inputs are synchronized to SYSCLKOUT by default.  
	// This will select asynch (no qualification) for the selected pins.
    GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 3;   // Asynch qual for GPIO30 (CANRXA)   

	// Configure eCAN-A pins using GPIO regs
	// This specifies which of the possible GPIO pins will be eCAN functional pins.
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 1;	// Configure GPIO30 for  CANRXA operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 1;	// Configure GPIO31 for CANTXA operation

    EDIS;
}

/******************************************************************************/
/* Bit configuration parameters for 100 MHz SYSCLKOUT*/ 
/******************************************************************************/
/*
The table below shows how BRP field must be changed to achieve different bit
rates with a BT of 10, for a 80% SP:
--------------------------------------------------------------------------------
BT = 10, TSEG1 = 6, TSEG2 = 1, Sampling Point = 80% 
--------------------------------------------------------------------------------
1   Mbps : BRP+1 = 10 	: CAN clock = 10 MHz
500 kbps : BRP+1 = 20 	: CAN clock = 5 MHz 
250 kbps : BRP+1 = 40 	: CAN clock = 2.5 MHz 
125 kbps : BRP+1 = 80 	: CAN clock = 1.25 MHz 
100 kbps : BRP+1 = 100 	: CAN clock = 1 MHz
50  kbps : BRP+1 = 200 	: CAN clock = 0.5 MHz

The table below shows how to achieve different sampling points with a BT of 25:
--------------------------------------------------------------------------------
Achieving desired SP by changing TSEG1 & TSEG2 with BT = 25  
--------------------------------------------------------------------------------

TSEG1 = 18, TSEG2 = 4, SP = 80% 
TSEG1 = 17, TSEG2 = 5, SP = 76% 
TSEG1 = 16, TSEG2 = 6, SP = 72% 
TSEG1 = 15, TSEG2 = 7, SP = 68% 
TSEG1 = 14, TSEG2 = 8, SP = 64% 

The table below shows how BRP field must be changed to achieve different bit
rates with a BT of 25, for the sampling points shown above: 

1   Mbps : BRP+1 = 4 
500 kbps : BRP+1 = 8 
250 kbps : BRP+1 = 16 
125 kbps : BRP+1 = 32 
100 kbps : BRP+1 = 40
50  kbps : BRP+1 = 80

*/
/*******************************************************************************
*Function name:	InitECan()
*Description:   This function initializes the eCAN module  to a known state                            
*******************************************************************************/
void InitECan(void)
{
	InitECanaGpio();

 	InitECana();
}
//===========================================================================
// End of file.
//===========================================================================

