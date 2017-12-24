

#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File

#define   K16_PFCOK_OFF_T     hptsc_MsToTicks(10)
#define   K16_PFC_ON_T     hptsc_MsToTicks(10)

LogicStateType PFCOK_State_e = False;

T_LedState LED1State = LED_OFF;
T_LedState LED2State = LED_OFF;
T_LedState LED3State = LED_OFF;




void IO_UpdState(LogicStateType* StateName, Uint16* StateCnt, bool (*const ChkFunc)(), const Uint16 T2Ftime, const Uint16 F2Ttime, const Uint16 DefState)
{
    switch (*StateName)
    {
        case True:
        {
            if (ChkFunc() == FALSE)
            {
                *StateCnt = 0;
                *StateName = TrueWait;
            }
            break;
        }
        case TrueWait:
        {
            (*StateCnt)++;
            if (ChkFunc() == TRUE)
            {
                *StateName = True;
            }
            else if (*StateCnt > T2Ftime)
            {
                *StateName = False;
            }
            break;
        }
        case False:
        {
            if (ChkFunc() == TRUE)
            {
                *StateCnt = 0;
                *StateName = FalseWait;
            }
            break;
        }
        case FalseWait:
        {
            (*StateCnt)++;
            if (ChkFunc() == FALSE)
            {
                *StateName = False;
            }
            else if (*StateCnt > F2Ttime)
            {
                *StateName = True;
            }
            break;
       }
        default:
        {
            *StateName = DefState;
            *StateCnt = 0;
            break;
        }
    }
}

bool IO_ChkPFCOK(void)
{
	Uint16 u16LpCnt = 0;
	   do
	   {
		   u16LpCnt++;
		   if (getPin_PFCOK() == LOW && getPin_PFCOK() == LOW && getPin_PFCOK() == LOW)
		   {
			   return TRUE; // return TRUE if it is low for 3 times
		   }
		   if (getPin_PFCOK() == HIGH && getPin_PFCOK() == HIGH && getPin_PFCOK() == HIGH)
		   {
			   return FALSE; //    return FALSE if it is high for 3 times
		   }
	   }
	   while (u16LpCnt < 3);
	   return FALSE; // return FALSE if it is undeterminable for 3 checks
}
void IO_UpdInput_PFCOK(void)
{
	static Uint16 u16PFCOK_StateCnt = 0;
	IO_UpdState(&PFCOK_State_e, &u16PFCOK_StateCnt, &IO_ChkPFCOK, K16_PFCOK_OFF_T, K16_PFC_ON_T, False);
}



bool LEDCtrl_LED1OnCond(void)
{
    if(1)
    {
        return TRUE;        
    }
    else
    {
        return FALSE;
    }

}

bool LEDCtrl_LED2OnCond(void)
{
    if(1)
    {
        return TRUE;        
    }
    else
    {
        return FALSE;
    }

}

bool LEDCtrl_LED3OnCond(void)
{
    if(1)
    {
        return TRUE;        
    }
    else
    {
        return FALSE;
    }

}


void IO_UpdOutput_LED1(void)
{
	switch (LED1State)
	   {
		   case LED_OFF:	   // LED_OFF State
		   { 
			   LEDCtrl_LED1Off(); 
			   
			   if (LEDCtrl_LED1OnCond() == TRUE)	   
			   { 
				   LED1State = LED_ON;
			   }
			   break;
		   }
		   
		   case LED_ON: // LED_ON Stage
		   {
			   LEDCtrl_LED1On(); 
			   
			   if (LEDCtrl_LED1OnCond() == FALSE) 	
			   {
				   LED1State = LED_OFF; 
			   }
			   break;
		   }
	
		   default:
		   {
			   LED1State = LED_OFF;
			   break;
		   }
	   }
}

void IO_UpdOutput_LED2(void)
{
	switch (LED2State)
	   {
		   case LED_OFF:	   // LED_OFF State
		   { 
			   LEDCtrl_LED2Off(); 
			   
			   if (LEDCtrl_LED2OnCond() == TRUE)	   
			   { 
				   LED2State = LED_ON;
			   }
			   break;
		   }
		   
		   case LED_ON: // LED_ON Stage
		   {
			   LEDCtrl_LED2On(); 
			   
			   if (LEDCtrl_LED2OnCond() == FALSE) 	
			   {
				   LED2State = LED_OFF; 
			   }
			   break;
		   }
	
		   default:
		   {
			   LED2State = LED_OFF;
			   break;
		   }
	   }

}

void IO_UpdOutput_LED3(void)
{
	switch (LED3State)
	   {
		   case LED_OFF:	   // LED_OFF State
		   { 
			   LEDCtrl_LED3Off(); 
			   
			   if (LEDCtrl_LED3OnCond() == TRUE)	   
			   { 
				   LED3State = LED_ON;
			   }
			   break;
		   }
		   
		   case LED_ON: // LED_ON Stage
		   {
			   LEDCtrl_LED3On(); 
			   
			   if (LEDCtrl_LED3OnCond() == FALSE) 	
			   {
				   LED3State = LED_OFF; 
			   }
			   break;
		   }
	
		   default:
		   {
			   LED3State = LED_OFF;
			   break;
		   }
	   }

}

void IO_UpdSignal(void)
{
	IO_UpdInput_PFCOK();
	
	IO_UpdOutput_LED1();
	IO_UpdOutput_LED2();
	IO_UpdOutput_LED3();
}



