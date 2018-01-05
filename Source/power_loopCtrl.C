#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

CTRL2P2Z_coeff  CTRL2P2Z_COEFF_VOLTAGE_LOOP;


Uint16 u16Vol_K_P = 0;
Uint16 u16Vol_K_I = 0;
Uint16 u16Vol_K_D = 0;

static Uint16 u16LVoutRef = 0;
Uint16 u16LVoltInst = 0;

Uint16 Flag_Txd_cnt = 0;
bool Flag_Txd = FALSE;



//static int16 i16LVoltErrorDev = 0;
//static int16 i16TmpError = 0;
static int16 i16LVoltError = 0;
//static int16 i16LVoltErrorSum = 0;
//static int16 u16PwmDutyBuf = 0;
#if 0


#define PwmCtrl_PID() {                                      \
	Uint16 u16PidTmpVar;                                   \ 
	i16TmpError = u16LVoutRef - u16LVoltInst;                \
    /* Cal VERROR deviative portion */                            \
    i16LVoltErrorDev = i16TmpError - i16LVoltError;            \
    i16LVoltError = i16TmpError;		/* Update new Vout Error */ \
    i16LVoltErrorSum = i16LVoltErrorSum + i16TmpError;	     \
    u16PidTmpVar3 = i16LVoltError*u16Vol_K_P + i16LVoltErrorSum*u16Vol_K_I + i16LVoltErrorDev*u16Vol_K_D;\
    /*if(u16PidTmpVar3) */    \
}
#endif

short PI_LVolt ( int16 error, int32 Max_out,CTRL2P2Z_coeff* CTRL2p2z,int32 U32Min_out )
{
	/* Compute PI for Boost Mode */
	/* Every time the PI order sets extreme values then CTMax or CTMin are managed */
	unsigned short  pid_out;
	int32 temp1,temp2,temp3;

//	error =  Voutref- VoutT ;

	temp1 = CTRL2p2z->inter_A1 * ( int32 ) error ;
	temp2= ( CTRL2p2z->inter_A2 * ( int32 ) CTRL2p2z->error_z1 );
	temp2= ( temp1+temp2 ) <<1; //it is fraid

	temp3= ( CTRL2p2z->inter_A3 * ( int32 ) CTRL2p2z->error_z2 ) <<1;
	temp2=temp2+temp3;
	temp2=temp2+CTRL2p2z->Uout_z1;

	if ( temp2>Max_out )
	{
		temp2=Max_out;
	}
	else if ( temp2<U32Min_out )
	{
		temp2=U32Min_out;
	}
	CTRL2p2z->Uout_z1=temp2;
	CTRL2p2z->error_z2= ( int16 ) CTRL2p2z->error_z1;
	CTRL2p2z->error_z1= ( int16 ) error;

	pid_out= ( int16 ) ( CTRL2p2z->Uout_z1>>16 );

	return  pid_out;
}


__interrupt void adc_isr ( void )
{
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM	
	short temp_duty_V;
	u16LVoltInst = AdcResult.ADCRESULT0 << 3;
	temp_duty_V = PI_LVolt ( i16LVoltError, ( 0x7FEE0000 ), &CTRL2P2Z_COEFF_VOLTAGE_LOOP, 0 );	//0x4E1FB1E0 = 20000*2^16

	
    EPwm1Regs.CMPA.half.CMPA = temp_duty_V;
	EPwm4Regs.CMPA.half.CMPA = DC_DC_FREQUENCY_75KHZ - temp_duty_V;
	if ( !Flag_Txd )
	{
#if 0
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xiin>>8 );
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xiin&0x00ff );
		Flag_Txd_cnt++;


		Txd_buf[Flag_Txd_cnt]=0x55;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xvin>>8 );
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xvin&0x00ff );
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( temp_I_ref>>8 );;
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( temp_I_ref&0x00ff );;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( temp_duty_I>>8 );;
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( temp_duty_I&0x00ff );;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( uVbus_Area>>8 );;
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( uVbus_Area&0x00ff );;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16AvgVbus>>8 );;
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16AvgVbus&0x00ff );;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xiin>>8 );;
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16Xiin&0x00ff );;
		Flag_Txd_cnt++;

		Txd_buf[Flag_Txd_cnt]= ( char ) ( uPowerState&0x00ff );;
		Flag_Txd_cnt++;

#endif

		if ( Flag_Txd_cnt>798 )
		{
			Flag_Txd=1;
			Flag_Txd_cnt=0;
		}
	}
}


bool is_softStartFinished(void)
{
return FALSE;
}

void PwmCtrl_SetPwmGain(void)
{
;
}
