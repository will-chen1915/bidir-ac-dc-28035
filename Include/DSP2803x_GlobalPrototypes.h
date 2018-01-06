// TI File $Revision: /main/5 $
// Checkin $Date: November 19, 2009   10:29:27 $
//###########################################################################
//
// FILE:   DSP2803x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for DSP2803x Examples
//
//###########################################################################
// $TI Release: 2803x C/C++ Header Files V1.21 $
// $Release Date: December 1, 2009 $
//###########################################################################

#ifndef DSP2803x_GLOBALPROTOTYPES_H
#define DSP2803x_GLOBALPROTOTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*---- shared global function prototypes -----------------------------------*/
extern void InitAdc(void);
extern void InitAdcAio(void);
extern void AdcOffsetSelfCal(void);
//extern void AdcChanSelect();
extern Uint16 AdcConversion (void);
#if DSP28_ECANA
extern void InitECan(void);
extern void InitECana(void);
extern void InitECanaID(void);
extern void InitECanGpio(void);
extern void InitECanaGpio(void);
#endif // endif DSP28_ECANA
extern void InitECap(void);
extern void InitECapGpio(void);
extern void InitECap1Gpio(void);
extern void InitCompGpio(void);
extern void InitComp1Gpio(void);
#if DSP28_COMP2
extern void InitComp2Gpio(void);
#endif // endif DSP28_COMP2
#if DSP28_COMP2
extern void InitComp3Gpio(void);
#endif // endif DSP28_COMP3
extern void InitEPwm(void);
extern void InitEPwmGpio(void);
extern void InitEPwm1Gpio(void);
extern void InitEPwm2Gpio(void);
extern void InitEPwm3Gpio(void);
#if DSP28_EPWM4
extern void InitEPwm4Gpio(void);
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5
extern void InitEPwm5Gpio(void);
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
extern void InitEPwm6Gpio(void);
#endif // endif DSP28_EPWM6
#if DSP28_EPWM7
extern void InitEPwm7Gpio(void);
#endif // endif DSP28_EPWM7
#if DSP28_EQEP1
extern void InitEQep(void);
extern void InitEQepGpio(void);
extern void InitEQep1Gpio(void);
#endif // endif DSP28_EQEP1
extern void InitGpio(void);
extern void InitI2C(void);
extern void InitI2CGpio(void);

extern void InitLin(void);
extern void InitLina(void);
extern void InitLinGpio(void);
extern void InitLinaGpio(void);

extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitSci(void);
extern void InitSciGpio(void);
extern void InitSciaGpio(void);
extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
#if DSP28_SPIB
extern void InitSpibGpio(void);
#endif // endif DSP28_SPIB
extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void InitPll(Uint16 pllcr, Uint16 clkindiv);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void AppDSP28x_usDelay(Uint32 Count);
#define KickDog ServiceDog     // For compatiblity with previous versions
extern void ServiceDog(void);
extern void DisableDog(void);
extern Uint16 CsmUnlock(void);
extern void IntOsc1Sel (void);
extern void IntOsc2Sel (void);
extern void XtalOscSel (void);
extern void ExtOscSel (void);

extern void vInitialInterrupts(void);
extern void InitECapAPWM(void);
extern void InitHRCap1Gpio(void);
extern void InitHRCapGpio(void);
extern void InitHRCap(void);

// DSP28_DBGIER.asm
extern void SetDBGIER(Uint16 dbgier);

//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);

//extern void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);

//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in Flash to a different RUN location in internal
// RAM
extern Uint16 IsrRamfuncsLoadStart;
extern Uint16 IsrRamfuncsLoadEnd;
extern Uint16 IsrRamfuncsRunStart;

extern Uint16 BootRamfuncsLoadStart;
extern Uint16 BootRamfuncsLoadEnd;
extern Uint16 BootRamfuncsRunStart;

extern Uint16 AppRamfuncsLoadStart;
extern Uint16 AppRamfuncsLoadEnd;
extern Uint16 AppRamfuncsRunStart;

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2803x_GLOBALPROTOTYPES_H

//===========================================================================
// End of file.
//===========================================================================
