
#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

#define POWER_UP_TIME               hptsc_MsToTicks(12)
#define SHUTDOWN_TIME               hptsc_MsToTicks(50)
#define SOFT_START_TIME             hptsc_MsToTicks(130)
#define STABILIZITING_TIME          hptsc_MsToTicks(30)

#define MAX_STATE_SIZE              3

#define INIT_CHARGE_LV_REF          2//K16_LV_CHARGE_STEP_SIZE



PSUModeType         PSUMode;

PSU_StateType PSUCharge_state;
PSU_StateType PSUDischarge_state;

static hptsc_DefineTimer(HptscTicks_t, ts_ChgTimer)//; //General purpose
static hptsc_DefineTimer(HptscTicks_t, ts_DischgTimer)//; //General purpose

void test1(void)
{;}


//void *PSU_state_Machine[MAX_STATE_SIZE] = {&PSUChargeStateCtrl,&}; 

/*******************************************************************************
* void app_initStateCtrl(void);
*			
* Input  :  N/A
*
* Output :  N/A
*
* Description: 
*  
*  
* Notes:This subroutine should be run in main loop
******************************************************************************/
void initPSUChargeStateCtrl(void)
{
	PSUCharge_state = POWER_UP;
	u16LVoutRefNormal = K16_LVOLT_CHARGE_NORMAL;	

	hptsc_LoadTimer(&ts_ChgTimer, POWER_UP_TIME);
	//Load Timer here
}

void initPSUDischargeStateCtrl(void)
{
	PSUDischarge_state = POWER_UP;
	u16LVoutRefNormal = K16_LVOLT_DISCHARGE_NORMAL;

	hptsc_LoadTimer(&ts_DischgTimer, POWER_UP_TIME);
	//Load Timer here
}

void Disable_MainPWMCtrl(void)
{
	EALLOW;
	EPwm1Regs.TZFRC.bit.OST = TZ_ENABLE;//	
	EPwm4Regs.TZFRC.bit.OST = TZ_ENABLE;//
	EDIS;
}

void Enable_MainPWMCtrl(void)
{
	EALLOW;
	EPwm1Regs.TZCLR.bit.OST = TZ_ENABLE;//	
	EPwm4Regs.TZCLR.bit.OST = TZ_ENABLE;//
	EDIS;
}

void Disable_SYNCPWMCtrl(void)
{
	EALLOW;
	EPwm5Regs.TZFRC.bit.OST = TZ_ENABLE;//	
	EPwm6Regs.TZFRC.bit.OST = TZ_ENABLE;//
	EDIS;
	bSetSROn = FALSE;
}

void Enable_SYNCPWMCtrl(void)
{
	EALLOW;
	EPwm5Regs.TZCLR.bit.OST = TZ_ENABLE;//	
	EPwm6Regs.TZCLR.bit.OST = TZ_ENABLE;//
	EDIS;
	bSetSROn = TRUE;
}

#if 0
void Volt_InitOpVolt(void)
{
    static Uint16 u16InitVoutRef = 0;
	u16InitVoutRef = Get_LVolt();//softstart from current voltage
    Set_LVoltRef(LV_VOLT(13));
}
#endif

void PSUChargeStateCtrl(void)
{
	hptsc_UpdateTimer(&ts_ChgTimer);
	switch(PSUCharge_state)
    {
        case POWER_UP:
		{
			if (hptsc_IsTimerExpired(&ts_ChgTimer))
			{
				PSUCharge_state = SHUT_DOWN;
				hptsc_LoadTimer(&ts_ChgTimer, SHUTDOWN_TIME);
			}
			//LEDCtrl_LED3On();
			break;
		}
		case SHUT_DOWN:
		{
			Disable_MainPWMCtrl();
			Disable_SYNCPWMCtrl();
			//LEDCtrl_LED3Off();
//			if(1/*(is_PFC_OK() == TRUE)&&(is_fault() == FALSE)*/)
			if((is_PFC_OK() == TRUE))
			{
				if (hptsc_IsTimerExpired(&ts_ChgTimer))
				{
					Set_LVoltRef(INIT_CHARGE_LV_REF);
					set_MaxDuty(0);
					Enable_MainPWMCtrl();
					//Volt_InitOpVolt()
					PSUCharge_state = SOFT_START;
					hptsc_LoadTimer(&ts_ChgTimer, SOFT_START_TIME);
				}
			}
			break;
		}
		case SOFT_START:
		{
			if(0/*is_OCP() == TRUE*/)
			{
				;
			}
			else if(0/*is_LVOVP() == TRUE*/)
			{
				;
			}
			else if(0/*isHV_OVP() == TRUE*/)
			{
				;
			}
						
			else if((is_PFC_OK() == FALSE))
			{
					Disable_MainPWMCtrl();
					Disable_SYNCPWMCtrl();
					PSUCharge_state = SHUT_DOWN;
					hptsc_LoadTimer(&ts_ChgTimer, SHUTDOWN_TIME);		
			}
			else if(is_softStartFinished() == TRUE)
			{
				if (hptsc_IsTimerExpired(&ts_ChgTimer))
				{
					PSUCharge_state = STABILIZITING;
					hptsc_LoadTimer(&ts_ChgTimer, STABILIZITING_TIME);
				}
			}

			break;
		}
		case STABILIZITING:
		{
			if(0/*is_OCP() == TRUE*/)
			{
				;
			}
			else if(0/*is_LVOVP() == TRUE*/)
			{
				;
			}
			else if(0/*isHV_OVP() == TRUE*/)
			{
				;
			}
			else if(0/*isLV_UVP() == TRUE*/)
			if (hptsc_IsTimerExpired(&ts_ChgTimer))
			{
				PSUCharge_state = NORMAL_OPERATION;
				//hptsc_LoadTimer(&ts_ChgTimer, NORMAL_OPERATION_TIME);
			}
			if((is_PFC_OK() == FALSE))
			{
					Disable_MainPWMCtrl();
					Disable_SYNCPWMCtrl();
					PSUCharge_state = SHUT_DOWN;
					hptsc_LoadTimer(&ts_ChgTimer, SHUTDOWN_TIME);		
			}
			break;
		}	
		case NORMAL_OPERATION:
		{
			if(0/*is_OCP() == TRUE*/)
			{
				;
			}
			else if(0/*is_LVOVP() == TRUE*/)
			{
				;			
			}
			else if(0/*isHV_OVP() == TRUE*/)
			{
				;			
			}
			if((is_PFC_OK() == FALSE))
			{
					Disable_MainPWMCtrl();
					Disable_SYNCPWMCtrl();
					PSUCharge_state = SHUT_DOWN;
					hptsc_LoadTimer(&ts_ChgTimer, SHUTDOWN_TIME);		
			}
			break;
		}
		default:
		{
		    PSUCharge_state = SHUT_DOWN;
			hptsc_LoadTimer(&ts_ChgTimer, SHUTDOWN_TIME);	    
		}	
    }

}


void PSUDischargeStateCtrl(void)
{
	hptsc_UpdateTimer(&ts_DischgTimer);
	switch(PSUDischarge_state)
    {
        case POWER_UP:
		{
			if (hptsc_IsTimerExpired(&ts_DischgTimer))
			{
				PSUDischarge_state = SHUT_DOWN;
				hptsc_LoadTimer(&ts_DischgTimer, SHUTDOWN_TIME);
			}
			break;
		}
		case SHUT_DOWN:
		{
			Disable_MainPWMCtrl();
			if((is_PFC_OK() == TRUE)&&(is_fault() == FALSE))
			{
				if (hptsc_IsTimerExpired(&ts_DischgTimer))
				{
                    //Enable_MainPWMCtrl();
					PSUDischarge_state = SOFT_START;
					hptsc_LoadTimer(&ts_DischgTimer, SOFT_START_TIME);
				}
			}
			break;
		}
		case SOFT_START:
		{
			if(is_OCP() == TRUE)
			{
				;
			}
			else if(is_LVOVP() == TRUE)
			{
				;
			}
			else if(isHV_OVP() == TRUE)
			{
				;
			}
			//else if(is_softStartFinished() == TRUE)
			{
				if (hptsc_IsTimerExpired(&ts_DischgTimer))
				{
					PSUDischarge_state = STABILIZITING;
					hptsc_LoadTimer(&ts_DischgTimer, STABILIZITING_TIME);
				}
			}
			break;
		}
		case STABILIZITING:
		{
			if(is_OCP() == TRUE)
			{
				;
			}
			else if(is_LVOVP() == TRUE)
			{
				;
			}
			else if(isHV_OVP() == TRUE)
			{
				;
			}
			if (hptsc_IsTimerExpired(&ts_DischgTimer))
			{
				PSUDischarge_state = NORMAL_OPERATION;
				//hptsc_LoadTimer(&ts_ChgTimer, NORMAL_OPERATION_TIME);
			}
			break;
		}	
		case NORMAL_OPERATION:
		{
			if(is_OCP() == TRUE)
			{
				;
			}
			else if(is_LVOVP() == TRUE)
			{
				;			
			}
			else if(isHV_OVP() == TRUE)
			{
				;			
			}
			break;
		}
		default:
		{
		    PSUDischarge_state = SHUT_DOWN;
			hptsc_LoadTimer(&ts_DischgTimer, SHUTDOWN_TIME);	    
		}	
			
    }

}

void App_initStateCtrl(void)
{
	PSUMode = STANDBY_MODE;
}

/*******************************************************************************
 *Function name: App_StateCtrl()  
 *Description :  PSU state control                                                    
 *input:         void                                 
 *global vars:   g_u16RunFlag.bit.WARN: run flag, 10ms once               
 *output:        void 
 *CALLED BY:     main()
 ******************************************************************************/
void App_StateCtrl(void)
{
	switch(PSUMode)
	{
        case STANDBY_MODE:
		{
            if(1)
            {
                initPSUChargeStateCtrl();
			    PSUMode = CHARGE_MODE;
			}
			else if(0)
			{
			    initPSUDischargeStateCtrl();
			    PSUMode = DISCHARGE_MODE;
			}
			else
				Disable_MainPWMCtrl();
			break;
		}

		case CHARGE_MODE:
		{
            if(0)
            {
			    PSUMode = STANDBY_MODE;
            }
			else
				PSUChargeStateCtrl();
			break;	
		}
		
		case DISCHARGE_MODE:
		{
            if(0)
            {
			    PSUMode = STANDBY_MODE;
            }
			else
				PSUDischargeStateCtrl();
			break;	
		}
		
		default:PSUMode = STANDBY_MODE;
	}
}

PSUModeType PSUMode_ChkMode(void)
{
    return PSUMode;
}

PSU_StateType PSUChargeState_ChkState(void)
{
    return PSUCharge_state;
}

PSU_StateType PSUDischargeState_ChkState(void)
{
    return PSUDischarge_state;
}

