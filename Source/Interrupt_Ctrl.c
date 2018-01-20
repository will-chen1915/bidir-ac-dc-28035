#include "DSP2803x_Device.h"		// DSP280x Headerfile Include File


/******************************************************************************
 *Function name: InitialInterrupts()
 *Description :  enables the  the PIE  interrupts                                                     
 *input:         void                                 
 *global vars:   void                
 *output:        void  
 *CALLED BY:     main()
 ******************************************************************************/
void InitialInterrupts(void)
{

	EALLOW;
	//PieVectTable.EPWM1_INT = &Epwm1_Isr;
	//PieVectTable.EPWM1_TZINT = &epwm1_tzint_isr;	
   	//PieVectTable.CLA1_INT2 = &cla1_task2_isr;    
    //PieVectTable.ECAP1_INT = &ecap1_isr;
    PieVectTable.ADCINT1 = &adc_isr;
	PieVectTable.TINT0 = &cpu_timer0_isr;
	EDIS;

	//PieCtrlRegs.PIEIER2.bit.INTx1 = 1;  // Enable PIE Group 2, INT 1(ePWM1 TZINT)
	//PieCtrlRegs.PIEIER3.bit.INTx1 = 1;  // Enable PIE Group 3, INT 1(ePWM1 INT)
	//PieCtrlRegs.PIEIER11.bit.INTx2 = 1;	// Enable INT 11.2 in the PIE (CLA Task2)
	//PieCtrlRegs.PIEIER4.bit.INTx1 = 1;  // Enable PIE Group 4, INT 1(eCAP1 INT)
	PieCtrlRegs.PIEIER1.bit.INTx1 = 1;    //Enable PIE Group 1, INT 1(ADCIN1)
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1; //Enable INT 7(CPU TImer0)
	// Enable the PIE Vector Table
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
}

/*=================================================================
* FUNCTION: EnableInterrupts
* PURPOSE : ÖÐ¶ÏÊ¹ÄÜ
* INPUT:    void
*
* RETURN:   void
*
* CALLS:    void
*
* CALLED BY:main()
*
*=================================================================*/
void EnableINT(void)
{
	//EPwm1Regs.ETSEL.bit.INTEN = 1;	// Enable ePWM1 INT
	//CpuTimer0Regs.TCR.bit.TIE = 0;		//Enable CPUTIMER0
	EALLOW;
	//Cla1Regs.MIER.all = M_INT2;			// Enable Task 8,2,1
	
    EDIS;
	
	IER |= M_INT1; 						// Enable CPU Interrupt 1
	//IER |= M_INT2;						// Enable ePWM1 TZINT
	//IER |= M_INT3;						// Enable ePWM1 INT	
    //IER |= M_INT11;						// Enable cla1 INT
	//IER |= M_INT4;						// Enable eCAP1 INT	
	// Enable global Interrupts and higher priority real-time debug events:
	EINT;								// Enable Global interrupt INTM
	ERTM;								// Enable Global realtime interrupt DBGM
}



