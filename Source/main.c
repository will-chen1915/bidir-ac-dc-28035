
/*
 * Removed the
 * InitRAM()
 * MemCopy(&IsrRamfuncsLoadStart, &IsrRamfuncsLoadEnd, &IsrRamfuncsRunStart);
 * MemCopy(&AppRamfuncsLoadStart, &AppRamfuncsLoadEnd, &AppRamfuncsRunStart);
 *
 * DSP2803x_MemCopy.c since there is a function(void MemCopy(UNIT16 *SourceAddr, UINT16 *SourceEndAddr, UINT16* DestAddr)) cannot pass the compiling
 * Uint16 EmuBMode, Uint16  EmuKey;
 */


//#include "main.h"

#include "DSP28x_Project.h"     // DSP28x Headerfile

//#include "DSP2803x_Cla_defines.h"  
//#include "Cla_shared.h" 
//#include "DSP2803x_Device.h"		// DSP280x Headerfile Include File


//  Main Function
void main(void)

{
    //Clear all interrupt, initialize PIE vector table:Disable CPU interrupt 
	DINT;
	DisableDog();
	InitSysCtrl();
	InitGpio();
	IER = 0x00000000;
	IFR = 0x00000000;
    //Initialize PIE control registers:detail info in DSP280x_PieCtrl.c file
	InitPieCtrl();
	InitPieVectTable();
    // This function Initial and  enables the PIE  interrupts
	vInitialInterrupts();
    //ram initialize
	//InitRAM(); //TODO

	//MemCopy(&IsrRamfuncsLoadStart, &IsrRamfuncsLoadEnd, &IsrRamfuncsRunStart);

    //MemCopy(&AppRamfuncsLoadStart, &AppRamfuncsLoadEnd, &AppRamfuncsRunStart);

	InitFlash();

    // Initialize other periphereral:detail info in DSP280x_InitPeripherals.c
	InitPeripherals();

	StartCpuTimer0();

	EALLOW;
	EPwm1Regs.HRMSTEP = 113;
	EDIS;

 	//App_DataInit();
	//App_CputoClaVar_init();//cla
	App_initStateCtrl();
	EnableInterrupts();
    EnableDog();

	for(;;)
    {
        //App_CheckChrgDisChrg();
		//App_WarnCtrl();
		IO_UpdSignal();
		analog_monitor();
		App_StateCtrl();
		PwmCtrl_SetPwmGain();
		
		//Thermal_Main();// Temperature Monitor
		//Fan_CtrlMain();
		/*
		App_MtimerTreat();			// main timer treatment		
		App_SoftStartCtrl();		// soft start control
		App_LINSCICommu();			// Lin_SCI Communication(1938)
		App_SCICommu();				// SCI Communication(46K80)
		App_CircuitCal();			// volt,curr,power calculation		
		App_WarnCtrl();				// IO samp and control
		App_CANCommu();				// CAN Communication
		FlashUpdate();				// Flash Update
		*/
    }
}

