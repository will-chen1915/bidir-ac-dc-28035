#include "DSP2803x_Device.h"      // DSP2803x Headerfile Include File



#define HAEDER_CODE  0x0000
#define REAR_CODE    0x0000

#define SET_KP_CMD   0x0001
#define SET_KI_CMD   0x1110
#define SET_KD_CMD   0x1010

#define K32_SCI_INTERVAL   hptsc_MsToTicks(10)

Sci_packet_t* Rxd_buf = ( Sci_packet_t* ) NULL;
Uint16 KP_set = 0;
Uint16 KI_set = 0;
Uint16 KD_set = 0;

Uint16	Txd_buf[800];
Uint16  Txd_Cnt=0;



bool SCI_DataRx ( Sci_packet_t* Rbuf )
{
	char* pbuf = ( char* ) Rbuf->buf;
	//char errbuf;
	if ( SciaRegs.SCIRXST.bit.RXRDY )
	{
		*pbuf++ = SciaRegs.SCIRXBUF.bit.RXDT;
		Rbuf->nLen++;
		if ( Rbuf->nLen == MAX_SCI_SIZE )
		{
			Rbuf->nLen = 0;
			pbuf = ( char* ) Rbuf->buf;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

void SCI_DoRx ( void )
{
	app_packe_t *pRvd = (app_packe_t *)NULL;
//	app_packe_t* pRvd;
	if ( TRUE == SCI_DataRx ( Rxd_buf ) )
	{
		pRvd = ( app_packe_t* ) Rxd_buf->buf;
		if ((pRvd->header==HAEDER_CODE) &&  (pRvd->rear==REAR_CODE))
		{
			switch ( pRvd->command )
			{
				case SET_KP_CMD:
					KP_set = pRvd->data;
					break;

				case SET_KI_CMD:
					KI_set = pRvd->data;
					break;

				case SET_KD_CMD:
					KD_set = pRvd->data;
					break;

				default:
					break;
			}
		}
	}
}

void SCI_DoTx ( void )
{
	if ( SciaRegs.SCICTL2.bit.TXRDY )
	{
		SciaRegs.SCITXBUF = Txd_buf[Txd_Cnt++];
//		SciaRegs.SCITXBUF = 0x54;
	}
	if (Txd_Cnt>=790)
	{Txd_Cnt=0;
	Flag_Txd=0;}

}
void SCICommu_Control ( void )
{
	//SCI_DoRx();
	static HptscTicks_t ts_SCI = 0;
if (hptsc_IsElapsedRepetitive(&ts_SCI, K32_SCI_INTERVAL))
	{
		if(Flag_Txd)
		{
			SCI_DoTx();
//			LEDCtrl_LED3Toggle();
		}
	}

}

