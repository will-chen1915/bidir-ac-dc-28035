
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
	InitialInterrupts();

	memcpy(&RamfuncsRunStart,&RamfuncsLoadStart,&RamfuncsLoadEnd - &RamfuncsLoadStart);	
	InitFlash();

	// Initialize other periphereral:detail info in DSP280x_InitPeripherals.c
	InitPeripherals();

	StartCpuTimer0();
	StartCpuTimer1();
	App_initStateCtrl();
	Set_PID_Coff();
	EnableINT();
	
    //EnableDog();
//	Enable_MainPWMCtrl();
//	Enable_SYNCPWMCtrl();
	for(;;)
    {
		//LEDCtrl_LED3On();
		//LEDCtrl_LED3Off();
		IO_UpdSignal();
		analog_monitor();
		SCICommu_Control();
		App_StateCtrl();
		ParametersCtrl();
		
		//Thermal_Main();// Temperature Monitor
		//Fan_CtrlMain();
		//App_CANCommu();				// CAN Communication	
    }
}

