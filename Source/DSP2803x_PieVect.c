//#########################################################
//
// FILE:	DSP280x_PieVect.c
//
// TITLE:	DSP280x Devices PIE Vector Table Initialization Functions.
//
//#########################################################
// Running on TMS320LF280xA   DCDC part   h741au1(1.00)               
// External clock is 20MHz, PLL * 10/2 , CPU-Clock 100 MHz	      
// Date: from May 23, 2005 to Oct 30, 2006  , (C) www & mhp & mj & lyg
// Version:1.00     Change Date: May 24, 2005 , 
//#########################################################

#include "DSP2803x_Device.h"     // DSP280x Headerfile Include File
#include "config.h"


/*const struct PIE_VECT_TABLE PieVectTableInit = {

      rsvd_ISR,  // 0  Reserved space
      rsvd_ISR,  // 1  Reserved space 
      rsvd_ISR,  // 2  Reserved space 
      rsvd_ISR,  // 3  Reserved space 
      rsvd_ISR,  // 4  Reserved space 
      rsvd_ISR,  // 5  Reserved space 
      rsvd_ISR,  // 6  Reserved space 
      rsvd_ISR,  // 7  Reserved space 
      rsvd_ISR,  // 8  Reserved space 
      rsvd_ISR,  // 9  Reserved space 
      rsvd_ISR,  // 10 Reserved space 
      rsvd_ISR,  // 11 Reserved space 
      rsvd_ISR,  // 12 Reserved space 


// Non-Peripheral Interrupts
      rsvd_ISR,		//INT13_ISR,     // XINT13 or CPU-Timer 1
      rsvd_ISR,		//INT14_ISR,     // CPU-Timer2
      rsvd_ISR,		//DATALOG_ISR,   // Datalogging interrupt
      rsvd_ISR,		//RTOSINT_ISR,   // RTOS interrupt
      rsvd_ISR,		//EMUINT_ISR,    // Emulation interrupt
      rsvd_ISR,       // Non-maskable interrupt
      rsvd_ISR,   // Illegal operation TRAP
      rsvd_ISR,	//USER1_ISR,     // User Defined trap 1
      rsvd_ISR,	//USER2_ISR,     // User Defined trap 2
      rsvd_ISR,	//USER3_ISR,     // User Defined trap 3
      rsvd_ISR,	//USER4_ISR,     // User Defined trap 4
      rsvd_ISR,	//USER5_ISR,     // User Defined trap 5
      rsvd_ISR,	//USER6_ISR,     // User Defined trap 6
      rsvd_ISR,	//USER7_ISR,     // User Defined trap 7
      rsvd_ISR,	//USER8_ISR,     // User Defined trap 8
      rsvd_ISR,	//USER9_ISR,     // User Defined trap 9
      rsvd_ISR,	//USER10_ISR,    // User Defined trap 10
      rsvd_ISR,	//USER11_ISR,    // User Defined trap 11
      rsvd_ISR,	//USER12_ISR,    // User Defined trap 12

// Group 1 PIE Vectors
      rsvd_ISR,		//SEQ1INT_ISR,     // 1.1 ADC  
      rsvd_ISR,		//SEQ2INT_ISR,     // 1.2 ADC  
      rsvd_ISR,        // 1.3
      rsvd_ISR,		//XINT1_ISR,       // 1.4     
      rsvd_ISR,		//XINT2_ISR,       // 1.5
      rsvd_ISR,		//ADCINT_ISR,      // 1.6 ADC
      TINT0_ISR,       // 1.7 Timer 0
      rsvd_ISR,		//WAKEINT_ISR,     // 1.8 WD, Low Power

// Group 2 PIE Vectors
      rsvd_ISR,		//EPWM1_TZINT_ISR, // 2.1 EPWM-1 Trip Zone
      rsvd_ISR,		//EPWM2_TZINT_ISR, // 2.2 EPWM-2 Trip Zone
      rsvd_ISR,		//EPWM3_TZINT_ISR, // 2.3 EPWM-3 Trip Zone
      rsvd_ISR,		//EPWM4_TZINT_ISR, // 2.4 EPWM-4 Trip Zone
      rsvd_ISR,		//EPWM5_TZINT_ISR, // 2.5 EPWM-5 Trip Zone
      rsvd_ISR,		//EPWM6_TZINT_ISR, // 2.6 EPWM-6 Trip Zone                        
      rsvd_ISR,        // 2.7
      rsvd_ISR,        // 2.8
      
// Group 3 PIE Vectors
      rsvd_ISR,		//EPWM1_INT_ISR,   // 3.1 EPWM-1 Interrupt
      rsvd_ISR,		//EPWM2_INT_ISR,   // 3.2 EPWM-2 Interrupt
      rsvd_ISR,		//EPWM3_INT_ISR,   // 3.3 EPWM-3 Interrupt
      rsvd_ISR,		//EPWM4_INT_ISR,   // 3.4 EPWM-4 Interrupt
      rsvd_ISR,		//EPWM5_INT_ISR,   // 3.5 EPWM-5 Interrupt
      rsvd_ISR,		//EPWM6_INT_ISR,   // 3.6 EPWM-6 Interrupt                        
      rsvd_ISR,        // 3.7
      rsvd_ISR,        // 3.8
      
// Group 4 PIE Vectors
      rsvd_ISR,		//ECAP1_INT_ISR,   // 4.1 ECAP-1
      rsvd_ISR,		//ECAP2_INT_ISR,   // 4.2 ECAP-2
      rsvd_ISR,		//ECAP3_INT_ISR,   // 4.3 ECAP-3
      rsvd_ISR,		//ECAP4_INT_ISR,   // 4.4 ECAP-4            
      rsvd_ISR,        // 4.5      
      rsvd_ISR,        // 4.6           
      rsvd_ISR,        // 4.7      
      rsvd_ISR,        // 4.8      
      
// Group 5 PIE Vectors
      rsvd_ISR,		//EQEP1_INT_ISR,   // 5.1 EQEP-1
      rsvd_ISR,		//EQEP2_INT_ISR,   // 5.2 EQEP-2
      rsvd_ISR,        // 5.3      
      rsvd_ISR,        // 5.4           
      rsvd_ISR,        // 5.5      
      rsvd_ISR,        // 5.6      
      rsvd_ISR,        // 5.7      
      rsvd_ISR,        // 5.8   


// Group 6 PIE Vectors
      rsvd_ISR,		//SPIRXINTA_ISR,   // 6.1 SPI-A
      rsvd_ISR,		//SPITXINTA_ISR,   // 6.2 SPI-A
      rsvd_ISR,		//SPIRXINTB_ISR,   // 6.3 SPI-B
      rsvd_ISR,		//SPITXINTB_ISR,   // 6.4 SPI-B
      rsvd_ISR,		//SPIRXINTC_ISR,   // 6.5 SPI-C
      rsvd_ISR,		//SPITXINTC_ISR,   // 6.6 SPI-C
      rsvd_ISR,		//SPIRXINTD_ISR,   // 6.7 SPI-D
      rsvd_ISR,		//SPITXINTD_ISR,   // 6.8 SPI-D                  

      
// Group 7 PIE Vectors
      rsvd_ISR,        // 7.1      
      rsvd_ISR,        // 7.2
      rsvd_ISR,        // 7.3      
      rsvd_ISR,        // 7.4           
      rsvd_ISR,        // 7.5      
      rsvd_ISR,        // 7.6      
      rsvd_ISR,        // 7.7      
      rsvd_ISR,        // 7.8   

// Group 8 PIE Vectors
      rsvd_ISR,		//I2CINT1A_ISR,    // 8.1      
      rsvd_ISR,		//I2CINT2A_ISR,    // 8.2
      rsvd_ISR,        // 8.3      
      rsvd_ISR,        // 8.4           
      rsvd_ISR,        // 8.5      
      rsvd_ISR,        // 8.6      
      rsvd_ISR,        // 8.7      
      rsvd_ISR,        // 8.8    
      
// Group 9 PIE Vectors     
      rsvd_ISR,		//SCIRXINTA_ISR,   // 9.1 SCI-A
      rsvd_ISR,		//SCITXINTA_ISR,   // 9.2 SCI-A
      rsvd_ISR,		//SCIRXINTB_ISR,   // 9.3 SCI-B
      rsvd_ISR,		//SCITXINTB_ISR,   // 9.4 SCI-B
      rsvd_ISR,		//ECAN0INTA_ISR,   // 9.5 eCAN-A
      rsvd_ISR,		//ECAN1INTA_ISR,   // 9.6 eCAN-A
      rsvd_ISR,		//ECAN0INTB_ISR,   // 9.7 eCAN-B
      rsvd_ISR,		//ECAN1INTB_ISR,   // 9.8 eCAN-B
      
// Group 10 PIE Vectors
      rsvd_ISR,        // 10.1      
      rsvd_ISR,        // 10.2
      rsvd_ISR,        // 10.3      
      rsvd_ISR,        // 10.4           
      rsvd_ISR,        // 10.5      
      rsvd_ISR,        // 10.6      
      rsvd_ISR,        // 10.7      
      rsvd_ISR,        // 10.8    
            
// Group 11 PIE Vectors
      rsvd_ISR,        // 11.1      
      rsvd_ISR,        // 11.2
      rsvd_ISR,        // 11.3      
      rsvd_ISR,        // 11.4           
      rsvd_ISR,        // 11.5      
      rsvd_ISR,        // 11.6      
      rsvd_ISR,        // 11.7      
      rsvd_ISR,        // 11.8
        
// Group 12 PIE Vectors
      rsvd_ISR,        // 12.1      
      rsvd_ISR,        // 12.2
      rsvd_ISR,        // 12.3      
      rsvd_ISR,        // 12.4           
      rsvd_ISR,        // 12.5      
      rsvd_ISR,        // 12.6      
      rsvd_ISR,        // 12.7      
      rsvd_ISR,        // 12.8   
};
*/

//---------------------------------------------------------------------------
// InitPieVectTable: 
//---------------------------------------------------------------------------
// This function initializes the PIE vector table to a known state.
// This function must be executed after boot time.
//

void InitPieVectTable(void)
{
	/*int16	i;
	Uint32 *Source = (void *) &PieVectTableInit;
	Uint32 *Dest = (void *) &PieVectTable;
		
	EALLOW;	
	for(i=0; i < 128; i++)
		*Dest++ = *Source++;	
	EDIS;*/

	int16	i;
	Uint32 *Source = (void *) &USER_ISR;//USER_ISR;	 
	Uint32 *Dest = (void *) &PieVectTable;
		
	EALLOW;	
	for(i=0; i < 128; i++)
		*Dest++ = (Uint32)Source;
	EDIS;
	// Enable the PIE Vector Table
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
			
}

//===========================================================================
// End of file.
//===========================================================================
