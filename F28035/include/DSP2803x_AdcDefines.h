//###########################################################################
//
// 文件名: DSP2803x_AdcDefines.h
//
// 标题:   DSP28035 ADC寄存器宏定义  
//
// 描述:   为了便于ADC初始化程序的修改及阅读，对寄存器变量进行了重新宏定义。
// 
// 开发环境：CCS3.3
//
// 作者:   Haypin Tse
//
// 邮箱：  tinghai899220@gmail.com
//   
//###########################################################################
// $Haypin Tse Debug: DSP2803x C/C++ Header Files $
// $Release Date: 2013年09月16 $
//###########################################################################

#ifndef DSP2803x_AdcDefines_H
#define DSP2803x_AdcDefines_H


#ifdef __cplusplus
extern "C" {
#endif

// ADC Control Register 1 (ADCTRL1) Field Descriptions
//==========================
//RESET bits
#define	ADC_RESET					0x1	//Resets entire ADC module (bit is then set back to 0 by ADC logic)

//ADCPWDN
#define	ADC_POWER_DOWN				0x0	//All analog circuitry inside the core except the bandgap and referencce circuitryis powered down
#define	ADC_POWER_UP				0x1	//Theanalogcircuitryinside the coreis poweredup					

//ADCBGPWD
#define	ADC_BANDGAP_POWER_DOWN      0x0	//Bandgap　circuitry　is powered　down
#define	ADC_BANDGAP_POWER_UP		0x1	//Bandgap buffer'scurcuitryinside coreis poweredup

//ADCREFSEL
#define	ADC_REF_POWER_DOWN          0x0	//Reference buffers circuitry is powered down
#define	ADC_REF_POWER_UP			0x1	//Reference buffers circuitry inside the core is powered up

//ADCREFSEL
#define	ADC_REF_INTERNAL			0x0	//Internal Bandgap used for reference generation
#define	ADC_REF_EXTERNAL			0x1	//External VREFHI/VREFLO pins used for reference generation


// ADC Control Register2(ADCCTL2)Field Descriptions
//==========================
//ADCNONOVERLAP
#define	ADC_OVERLAP_ENABLE				0x0	//Overlap of sample and conversionis allowed					
#define	ADC_OVERLAP_DISABLE				0x1	//Overlap of sample is not allowed

//CLKDIV2EN
#define	ADC_CPUCLK_DIV1					0x0	//ADC clock = CPU clock					
#define	ADC_CPUCLK_DIV2					0x1	//ADC clock= CPU clock/2


//ADC Interrupt Flag Clear Register(ADCINTFLGCLR) Field Descriptions
//==========================
//ADCINT9 ADCINT8 ADCINT7 ADCINT6 ADCINT5 ADCINT4 ADCINT3 ADCINT2 ADCINT1
#define	ADC_INT_FLAG_CLEAR		0x1	//ADCinterrupt FlagClearBit


//Interrupt Select (1,3,5,7,9) And (2,4,6,8,10) Register(INTSEL1,3,5,7,9N2,4,6,8,10)
//==========================
//INTxSEL
#define	ADC_INT_TRIG_EOC0 				0x00	//EOC0 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC1 				0x01	//EOC1 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC2 				0x02	//EOC2 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC3 				0x03	//EOC3 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC4 				0x04	//EOC4 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC5 				0x05	//EOC5 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC6 				0x06	//EOC6 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC7 				0x07	//EOC7 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC8 				0x08	//EOC8 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC9 				0x09	//EOC9 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC10 				0x0A	//EOC10 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC11 				0x0B	//EOC11 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC12 				0x0C	//EOC12 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC13 				0x0D	//EOC13 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC14 				0x0E	//EOC14 is trigger for ADCINTx
#define	ADC_INT_TRIG_EOC15 				0x0F	//EOC15 is trigger for ADCINTx

//INTxE
#define	ADC_INT_DISABLE			0x0		//ADCINTx is disabled
#define	ADC_INT_ENABLE			0x1		//ADCINTx is enabled

//INTxCONT
#define	ADC_INT_CONTINUOUS_DISABLE 				0x0	//No further ADCINTx pulses are generated until ADCINTx flag (in ADCINTFLG register)is cleared by user.
#define	ADC_INT_CONTINUOUS_ENABLE 				0x1	//ADCINTx pulses are generated whenever an EOC pulse is generated irrespective if the flag bit is cleared or not.


//ADC　Sample　Mode　Register(ADCSAMPLEMODE) (AddressOffset12h)
//==========================
//SIMULEN14 SIMULEN12 SIMULEN10 SIMULEN8 SIMULEN6 SIMULEN4 SIMULEN2 SIMULEN0
//NOTE: Thefollowing ADCSampleModeRegisteris EALLOWprotected.
 
#define	ADC_SINGLE_SAMP  0	//Single sample mode
#define	ADC_SIMUL_SAMP    0x1	//Simultaneous sample


//ADCSOC0-SOC15 Control Registers(ADCSOCxCTL) Register Field Descriptions (continued)
//==========================
//CHSEL
#define	ADC_IN_A0		0x0	//ADCINA0
#define	ADC_IN_A1		0x1	//ADCINA1
#define	ADC_IN_A2		0x2	//ADCINA2
#define	ADC_IN_A3		0x3	//ADCINA3
#define	ADC_IN_A4		0x4	//ADCINA4
#define	ADC_IN_A5		0x5	//ADCINA5
#define	ADC_IN_A6		0x6	//ADCINA6
#define	ADC_IN_A7		0x7	//ADCINA7

#define	ADC_IN_B0		0x8	//ADCINB0
#define	ADC_IN_B1		0x9	//ADCINB1
#define	ADC_IN_B2		0xA	//ADCINB2
#define	ADC_IN_B3		0xB	//ADCINB3
#define	ADC_IN_B4		0xC	//ADCINB4
#define	ADC_IN_B5		0xD	//ADCINB5
#define	ADC_IN_B6		0xE	//ADCINB6
#define	ADC_IN_B7		0xF	//ADCINB7


//ADC Interrupt Trigger SOC Select 1 Register (ADCINTSOCSEL1) (Address Offset 14h)
//==========================
//SOC7 SOC6 SOC5 SOC4 SOC3 SOC2 SOC1 SOC0
//NOTE: The following ADC Sample Mode Register is EALLOW protected.
#define	ADC_TRIGSEL_ENABLE 					0x0	//No ADCINT will trigger SOCx. TRIGSEL field determines SOCx trigger
#define	ADC_TRIGSEL_ADCINT1 				0x1	//ADCINT1 will trigger SOCx. TRIGSEL field is ignored.
#define	ADC_TRIGSEL_ADCINT2 				0x2	//ADCINT1 will trigger SOCx. TRIGSEL field is ignored.


//ADC　SOC0-SOC15　Control　Registers(ADCSOCxCTL) Register　Field　Descriptions
//==========================
//TRIGSEL
#define	ADC_TRIGSEL_SOFTWARE				0x00	//ADCTRIG0- Software only.

#define	ADC_TRIGSEL_TINT0n					0x01	//ADCTRIG1- CPUTimer0,TINT0n
#define	ADC_TRIGSEL_TINT1n					0x02	//ADCTRIG2- CPUTimer1,TINT1n
#define	ADC_TRIGSEL_TINT2n					0x03	//ADCTRIG3- CPUTimer2,TINT2n

#define	ADC_TRIGSEL_XINT2SOC				0x04	//ADCTRIG4-　XINT2,XINT2SOC

#define	ADC_TRIGSEL_EPWM1_ADCSOCA			0x05	//ADCTRIG5-　ePWM1,ADCSOCA
#define	ADC_TRIGSEL_EPWM1_ADCSOCB			0x06	//ADCTRIG6-　ePWM1,ADCSOCB

#define	ADC_TRIGSEL_EPWM2_ADCSOCA			0x07	//ADCTRIG7-　ePWM2,ADCSOCA
#define	ADC_TRIGSEL_EPWM2_ADCSOCB			0x08	//ADCTRIG8-　ePWM2,ADCSOCB

#define	ADC_TRIGSEL_EPWM3_ADCSOCA			0x09	//ADCTRIG9-　ePWM3,ADCSOCA
#define	ADC_TRIGSEL_EPWM3_ADCSOCB			0x0A	//ADCTRIG10-　ePWM3,ADCSOCB

#define	ADC_TRIGSEL_EPWM4_ADCSOCA			0x0B	//ADCTRIG11-　ePWM4,ADCSOCA
#define	ADC_TRIGSEL_EPWM4_ADCSOCB			0x0C	//ADCTRIG12-　ePWM4,ADCSOCB

#define	ADC_TRIGSEL_EPWM5_ADCSOCA			0x0D	//ADCTRIG13-　ePWM5,ADCSOCA
#define	ADC_TRIGSEL_EPWM5_ADCSOCB			0x0E	//ADCTRIG414-　ePWM5,ADCSOCB

#define	ADC_TRIGSEL_EPWM6_ADCSOCA			0x0F	//ADCTRIG15-　ePWM6,ADCSOCA
#define	ADC_TRIGSEL_EPWM6_ADCSOCB			0x10	//ADCTRIG16-　ePWM6,ADCSOCB

#define	ADC_TRIGSEL_EPWM7_ADCSOCA			0x11	//ADCTRIG17-　ePWM7,ADCSOCA
#define	ADC_TRIGSEL_EPWM7_ADCSOCB			0x12	//ADCTRIG18-　ePWM7,ADCSOCB

//ADCSOC0-SOC15ControlRegisters(ADCSOCxCTL) RegisterFieldDescriptions(continued)
//==========================
//ACQPS[5:0]
#define	ADC_ACQUISITION_7ADCCLK		0x6	//Sample　windowis 7　cycles　long (6+1　clock　cycles)					
#define	ADC_ACQUISITION_8ADCCLK		0x7	//Sample　windowis 8　cycles　long (6+1　clock　cycles)	
#define	ADC_ACQUISITION_9ADCCLK		0x8	//Sample　windowis 9　cycles　long (6+1　clock　cycles)						
#define	ADC_ACQUISITION_10ADCCLK	0x9	//Sample　windowis 10　cycles　long (6+1　clock　cycles)	
#define	ADC_ACQUISITION_11ADCCLK	0xA	//Sample　windowis 11　cycles　long (6+1　clock　cycles)						
#define	ADC_ACQUISITION_12ADCCLK	0xB	//Sample　windowis 12　cycles　long (6+1　clock　cycles)	
#define	ADC_ACQUISITION_13ADCCLK	0xC	//Sample　windowis 13　cycles　long (6+1　clock　cycles)						
#define	ADC_ACQUISITION_14ADCCLK	0xD	//Sample　windowis 14　cycles　long (6+1　clock　cycles)	
#define	ADC_ACQUISITION_15ADCCLK	0xE	//Sample　windowis 15　cycles　long (6+1　clock　cycles)						
#define	ADC_ACQUISITION_16ADCCLK	0xF	//Sample　windowis 16　cycles　long (6+1　clock　cycles)

//ADC SOC Force 1 Register(ADCSOCFRC1) Field Descriptions	
//==========================
//SOCx(x = 15 to 0)
#define	ADC_FORCE_START		0x1	//Force SOCx flag bit to 1.This will cause a conversion to start once priority is given to SOCx.	


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2803x_AdcDefines

//===========================================================================
// End of file.
//===========================================================================
