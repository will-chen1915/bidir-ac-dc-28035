
#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

#define POWER_UP_TIME               hptsc_MsToTicks(12)
#define SHUTDOWN_TIME               hptsc_MsToTicks(10)
#define SOFT_START_TIME             hptsc_MsToTicks(130)
#define STABILIZITING_TIME          hptsc_MsToTicks(30)




PSUCharge_StateType PSUCharge_state;
static hptsc_DefineTimer(HptscTicks_t, ts_SmTimer) //General purpose


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
void App_initStateCtrl(void)
{
	PSUCharge_state = POWER_UP;
	
	//#define DEVICE_POWER_UP_TIME     hptsc_MsToTicks(12)
	hptsc_LoadTimer(&ts_SmTimer, POWER_UP_TIME);
	//Load Timer here
}

void Disable_MainPWMCtrl(void)
{
	EALLOW;
	EPwm1Regs.TZFRC.bit.OST = TZ_ENABLE;//	
	EPwm2Regs.TZFRC.bit.OST = TZ_ENABLE;//
	EDIS;
}

void Enable_MainPWMCtrl(void)
{
	EALLOW;
	EPwm1Regs.TZCLR.bit.OST = TZ_ENABLE;//	
	EPwm2Regs.TZCLR.bit.OST = TZ_ENABLE;//
	EDIS;
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
	hptsc_UpdateTimer(&ts_SmTimer);
	switch(PSUCharge_state)
    {
        case POWER_UP:
		{
			if (hptsc_IsTimerExpired(&ts_SmTimer))
			{
				PSUCharge_state = SHUT_DOWN;
				hptsc_LoadTimer(&ts_SmTimer, SHUTDOWN_TIME);
			}
			break;
		}
		case SHUT_DOWN:
		{
			Disable_MainPWMCtrl();
			if((is_PFC_OK() == TRUE)&&(is_fault() == FALSE))
			{
				if (hptsc_IsTimerExpired(&ts_SmTimer))
				{
                    Enable_MainPWMCtrl();
					PSUCharge_state = SOFT_START;
					hptsc_LoadTimer(&ts_SmTimer, SOFT_START_TIME);
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
			else if(is_softStartFinished() == TRUE)
			{
				if (hptsc_IsTimerExpired(&ts_SmTimer))
				{
					PSUCharge_state = STABILIZITING;
					hptsc_LoadTimer(&ts_SmTimer, STABILIZITING_TIME);
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
			if (hptsc_IsTimerExpired(&ts_SmTimer))
			{
				PSUCharge_state = NORMAL_OPERATION;
				//hptsc_LoadTimer(&ts_SmTimer, NORMAL_OPERATION_TIME);
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
			
    }
}


