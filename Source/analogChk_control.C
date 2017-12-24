#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

#define K32_HV_INTERVAL               hptsc_UsToTicks(100)

// HV_OVP
#define K16_HVOVP_TH                  HV_VOLT(450)
#define K16_HVOVP_RECOVERY_TH         HV_VOLT(390)
#define K32_HVOVP_TIME                hptsc_MsToTicks(100)
#define K32_HVOVP_RCOVERY_TIME        hptsc_MsToTicks(100)

//HV_UVP
#define K16_HVUVP_TH                  HV_VOLT(370)
#define K16_HVUVP_RECOVERY_TH		  HV_VOLT(390)
#define K32_HVUVP_TIME                hptsc_MsToTicks(300)
#define K32_HVUVP_RCOVERY_TIME        hptsc_MsToTicks(300)

//LV_OVP
#define K16_LVOVP_TH                  LV_VOLT(16)
#define K16_LVOVP_RECOVERY_TH         LV_VOLT(12.5)
#define K32_LVOVP_TIME                hptsc_MsToTicks(20)
#define K32_LVOVP_RCOVERY_TIME        hptsc_MsToTicks(100)

//LV_UVP
#define K16_LVUVP_TH				  LV_VOLT(11)
#define K16_LVUVP_RECOVERY_TH         LV_VOLT(12.8)
#define K32_LVUVP_TIME                hptsc_MsToTicks(20)
#define K32_LVUVP_RCOVERY_TIME        hptsc_MsToTicks(100)

u16FaultRegType u16FaultReg = {0};

Uint16 u16HVoltInst;


void analog_HVmetering(void)
{
	static HptscTicks_t ts_HV = 0;
	static Uint16 u16HVoltTemp = 0;
	
	if (hptsc_IsElapsedRepetitive(&ts_HV, K32_HV_INTERVAL))
	{
		u16HVoltTemp = AdcResult.ADCRESULT2 << 3;//Q15
		u16HVoltInst = (u16HVoltInst + u16HVoltTemp)>>1;//Q15		
	}

}

void analog_ChkHVOVP(void)
{
	static HptscTicks_t ts_ticketHVOVPSum, ts_ticketHVOVPClrSum;
	static HptscTicks_t ts_HVOVP_ElapsedTicket = 0;
	static HptscTicks_t ts_HVOVP_CLR_ElapsedTicket = 0;
	
	if(u16FaultReg.bit.HVOVP== FALSE)
	{
		ts_HVOVP_CLR_ElapsedTicket = 0;
		ts_ticketHVOVPClrSum= 0;
		if(u16HVoltInst > K16_HVOVP_TH)
		{
			if(ts_ticketHVOVPSum > K32_HVOVP_TIME)
			{
				u16FaultReg.bit.HVOVP= TRUE;
				ts_HVOVP_ElapsedTicket = 0;
				ts_ticketHVOVPSum= 0;
			}
			else
			{
				ts_ticketHVOVPSum += hptsc_ElapsedTicket(&ts_HVOVP_ElapsedTicket);
			}
		}
		else
		{
        	ts_HVOVP_ElapsedTicket = 0;
			ts_ticketHVOVPSum= 0;    
		}
	}
	else
	{
		ts_HVOVP_ElapsedTicket = 0;
		ts_ticketHVOVPSum= 0;
		if(u16HVoltInst < K16_HVOVP_RECOVERY_TH)
		{
			if(ts_ticketHVOVPSum > K32_HVOVP_RCOVERY_TIME)
			{
				u16FaultReg.bit.HVOVP= FALSE;
				ts_HVOVP_CLR_ElapsedTicket = 0;
				ts_ticketHVOVPClrSum= 0;
			}
			else
			{
				ts_ticketHVOVPClrSum += hptsc_ElapsedTicket(&ts_HVOVP_CLR_ElapsedTicket);
			}
		}
		else
		{
			ts_HVOVP_CLR_ElapsedTicket = 0;
		    ts_ticketHVOVPClrSum= 0;
		}
	}

}

void analog_ChkHVUVP(void)
{
	static HptscTicks_t ts_ticketHVUVPSum, ts_ticketHVUVPClrSum;
	static HptscTicks_t ts_HVUVP_ElapsedTicket = 0;
	static HptscTicks_t ts_HVUVP_CLR_ElapsedTicket = 0;
	
	if(u16FaultReg.bit.HVUVP== FALSE)
		{
			ts_HVUVP_CLR_ElapsedTicket = 0;
			ts_ticketHVUVPClrSum= 0;
			if(u16HVoltInst < K16_HVUVP_TH)
			{
				if(ts_ticketHVUVPSum > K32_HVUVP_TIME)
				{
					u16FaultReg.bit.HVUVP= TRUE;
					ts_HVUVP_ElapsedTicket = 0;
					ts_ticketHVUVPSum= 0;
				}
				else
				{
					ts_ticketHVUVPSum += hptsc_ElapsedTicket(&ts_HVUVP_ElapsedTicket);
				}
			}
			else
			{
			    ts_HVUVP_ElapsedTicket = 0;
			    ts_ticketHVUVPSum= 0;
			}
		}
		else
		{
			ts_HVUVP_ElapsedTicket = 0;
			ts_ticketHVUVPSum= 0;
			if(u16HVoltInst < K16_HVUVP_RECOVERY_TH)
			{
				if(ts_ticketHVUVPSum > K32_HVUVP_RCOVERY_TIME)
				{
					u16FaultReg.bit.HVUVP= FALSE;
					ts_HVUVP_CLR_ElapsedTicket = 0;
					ts_ticketHVUVPClrSum= 0;
				}
				else
				{
					ts_ticketHVUVPClrSum += hptsc_ElapsedTicket(&ts_HVUVP_CLR_ElapsedTicket);
				}
			}
			else
			{
				ts_HVUVP_CLR_ElapsedTicket = 0;
				ts_ticketHVUVPClrSum= 0;
			}
		}
}


void analog_ChkLVOVP(void)
{
	static HptscTicks_t ts_ticketLVOVPSum, ts_ticketLVOVPClrSum;
	static HptscTicks_t ts_LVOVP_ElapsedTicket = 0;
	static HptscTicks_t ts_LVOVP_CLR_ElapsedTicket = 0;
	
	if(u16FaultReg.bit.LVOVP == FALSE)
    {
		ts_LVOVP_CLR_ElapsedTicket = 0;
		ts_ticketLVOVPClrSum= 0;
		if(u16LVoltInst > K16_LVOVP_TH)
		{
			if(ts_ticketLVOVPSum > K32_LVOVP_TIME)
			{
				u16FaultReg.bit.LVOVP = TRUE;
				ts_LVOVP_ElapsedTicket = 0;
				ts_ticketLVOVPSum= 0;
			}
			else
			{
				ts_ticketLVOVPSum += hptsc_ElapsedTicket(&ts_LVOVP_ElapsedTicket);
			}
		}
		else
		{
			ts_LVOVP_ElapsedTicket = 0;
			ts_ticketLVOVPSum= 0;
		}
	}
	else
	{
		ts_LVOVP_ElapsedTicket = 0;
		ts_ticketLVOVPSum= 0;
		if(u16LVoltInst < K16_LVOVP_RECOVERY_TH)
		{
			if(ts_ticketLVOVPClrSum > K32_LVOVP_RCOVERY_TIME)
			{
				u16FaultReg.bit.LVOVP = FALSE;
				ts_LVOVP_CLR_ElapsedTicket = 0;
				ts_ticketLVOVPClrSum= 0;
			}
			else
			{
				ts_ticketLVOVPClrSum += hptsc_ElapsedTicket(&ts_LVOVP_CLR_ElapsedTicket);
			}
		}
		else
		{
			ts_LVOVP_CLR_ElapsedTicket = 0;
			ts_ticketLVOVPClrSum= 0;
		}
	}
}

void analog_ChkLVUVP(void)
{
	static HptscTicks_t ts_ticketLVUVPSum, ts_ticketLVUVPClrSum;
	static HptscTicks_t ts_LVUVP_ElapsedTicket = 0;
	static HptscTicks_t ts_LVUVP_CLR_ElapsedTicket = 0;
	
	if(u16FaultReg.bit.LVUVP == FALSE)
    {
		ts_LVUVP_CLR_ElapsedTicket = 0;
		ts_ticketLVUVPClrSum= 0;
		if(u16LVoltInst < K16_LVUVP_TH)
		{
			if(ts_ticketLVUVPSum > K32_LVUVP_TIME)
			{
				u16FaultReg.bit.LVUVP = TRUE;
				ts_LVUVP_ElapsedTicket = 0;
				ts_ticketLVUVPSum= 0;
			}
			else
			{
				ts_ticketLVUVPSum += hptsc_ElapsedTicket(&ts_LVUVP_ElapsedTicket);
			}
		}
		else
		{
			ts_LVUVP_ElapsedTicket = 0;
			ts_ticketLVUVPSum= 0;
		}
	}
	else
	{
		if(u16LVoltInst > K16_LVUVP_RECOVERY_TH)
		{
			ts_LVUVP_ElapsedTicket = 0;
			ts_ticketLVUVPSum= 0;
			if(ts_ticketLVUVPClrSum > K32_LVUVP_RCOVERY_TIME)
			{
				u16FaultReg.bit.LVUVP = FALSE;
				ts_LVUVP_CLR_ElapsedTicket = 0;
				ts_ticketLVUVPClrSum= 0;
			}
			else
			{
				ts_ticketLVUVPClrSum += hptsc_ElapsedTicket(&ts_LVUVP_CLR_ElapsedTicket);
			}
		}
		else
		{
			ts_LVUVP_CLR_ElapsedTicket = 0;
			ts_ticketLVUVPClrSum= 0;
		}
	}

}


void analog_monitor(void)
{
	analog_HVmetering();
	analog_ChkHVOVP();
	analog_ChkHVUVP();
	analog_ChkLVOVP();
	analog_ChkLVUVP();
}

bool is_PFC_OK(void)
{
	if (PFCOK_State_e == True || PFCOK_State_e == TrueWait)
		return TRUE;
	else
		return FALSE;
}

bool is_fault(void)
{
    if(u16FaultReg.Word == 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }

}

bool is_OCP(void)
{
return 0;
}

bool is_LVOVP(void)
{
	if(u16FaultReg.bit.LVOVP == 1)
		return TRUE;
	else
		return FALSE;
}

bool isLV_UVP(void)
{
	if(u16FaultReg.bit.LVUVP == 1)
		return TRUE;
	else
		return FALSE;

}


bool isHV_OVP(void)
{
	if(u16FaultReg.bit.HVOVP == 1)
		return TRUE;
	else
		return FALSE;

}

bool isHV_UVP(void)
{
	if(u16FaultReg.bit.HVUVP == 1)
		return TRUE;
	else
		return FALSE;

}



