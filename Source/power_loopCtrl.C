#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

#define K32_PARAMETER_CTRL_INTERVAL        hptsc_MsToTicks(20)

#define K32_MAX_RGE_LIMIT                  (65536<<16)

CTRL2P2Z_coeff  CTRL2P2Z_COEFF_VOLTAGE_LOOP;


Uint16 u16Vol_K_P = 0;
Uint16 u16Vol_K_I = 0;
Uint16 u16Vol_K_D = 0;

Uint16 u16LVoutRefNormal = 0;


Uint16 u16LVoutRef = 0;
Uint16 u16LVoltInst = 0;

Uint16 Flag_Txd_cnt = 0;
bool Flag_Txd = FALSE;

Uint8 u8RampLVoltRef_Cnt = 0;

bool bsoftStart = FALSE;


//static int16 i16LVoltErrorDev = 0;
//static int16 i16TmpError = 0;
static int16 i16LVoltError = 0;
//static int16 i16LVoltErrorSum = 0;
//static int16 u16PwmDutyBuf = 0;

void Set_LVoltRef(Uint16 u16SetValue)
{
	Uint16 u16set_temp;
	u16set_temp = u16SetValue;
	if(u16set_temp > u16LVoutRefNormal)
		u16set_temp = u16LVoutRefNormal;
	u16LVoutRef = u16set_temp;
}

Uint16 Get_LVoltRef(void)
{
    return u16LVoutRef;
}

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

#define Ctrl_RampLVoltRef(){                                      \
	if(bsoftStart == TRUE)                                        \
	{                                                             \
    	u8RampLVoltRef_Cnt++;                                     \
    	if(u8RampLVoltRef_Cnt >= INT_CNT)                         \
    	{                                                         \
    	    if(u16LVoutRef < u16LVoutRefNormal)                   \
    	    {                                                     \
                u16LVoutRef = u16LVoutRef + K16_LV_CHARGE_STEP_SIZE;     \
                if(u16LVoutRef > u16LVoutRefNormal)               \
                {                                                 \
                    u16LVoutRef = u16LVoutRefNormal;              \
    			}                                                 \
    		}                                                     \
    	}                                                         \
    	u8RampLVoltRef_Cnt = 0;                                   \
    	bsoftStart = FALSE;                                      \
    }                                                              \
}                                                                                     


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


interrupt void adc_isr ( void )
{
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM	
	short temp_duty_V;
	u16LVoltInst = AdcResult.ADCRESULT0 << 3;
	Ctrl_RampLVoltRef();
	i16LVoltError = u16LVoutRef - u16LVoltInst;
	temp_duty_V = PI_LVolt ( i16LVoltError, ( K32_MAX_RGE_LIMIT ), &CTRL2P2Z_COEFF_VOLTAGE_LOOP, 0 );	//0x4E1FB1E0 = 20000*2^16
	
    //EPwm1Regs.CMPA.half.CMPA = temp_duty_V;
	//EPwm4Regs.CMPA.half.CMPA = DC_DC_FREQUENCY - temp_duty_V;
	if ( !Flag_Txd )
	{
#if 1
		Txd_buf[Flag_Txd_cnt]= 0x55;
		Flag_Txd_cnt++;


		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16LVoltInst>>8 );
		Flag_Txd_cnt++;
		Txd_buf[Flag_Txd_cnt]= ( char ) ( u16LVoltInst&0x00ff );
		Flag_Txd_cnt++;

#endif

		if ( Flag_Txd_cnt>=790 )
		{
			Flag_Txd=1;
			Flag_Txd_cnt=0;
		}
	}
	AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;		//Clear ADCINT1 flag reinitialize for next SOC
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
}


bool is_softStartFinished(void)
{
    Uint16 LV_ref = 0;
	LV_ref = u16LVoutRef + K16_LV_CHARGE_STEP_SIZE;
	if(LV_ref > u16LVoutRefNormal)
        return TRUE;
	else
		return FALSE;
}

void ParametersCtrl(void)
{
//    static HptscTicks_t ts_ParaCtrl = 0;
//    if (hptsc_IsElapsedRepetitive(&ts_ParaCtrl, K32_PARAMETER_CTRL_INTERVAL))
//   {;}

     PSUModeType PSUMode_temp = 0;
	 PSU_StateType PUSChargeState_temp = 0;
	 PSU_StateType PUSDischargeState_temp = 0;
	  
     PSUMode_temp = PSUMode_ChkMode();
     if(PSUMode_temp == CHARGE_MODE)
	 {
         PUSChargeState_temp = PSUChargeState_ChkState();
			  switch(PUSChargeState_temp)
			  {
			      case SOFT_START:

                      bsoftStart = TRUE;
                      break;


				  case STABILIZITING:

				      bsoftStart = FALSE;
					  break;


				  default:

                      break;
			  }

	 }
     else if(PSUMode_temp == DISCHARGE_MODE)
     {
    	 ;
     }
     else
     {;}
}
