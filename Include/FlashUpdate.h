//###########################################################################
//
// FILE:  FlashUpdate.h	
//
// TITLE: FlashUpdate include file
//
// DESCRIPTION:
//
// Function prototypes and macros for the FlashUpdate include file.
//
//###########################################################################
// Date:June 22, 2013 $
//###########################################################################


#ifndef FLASHUPDATE_2803x_H
#define FLASHUPDATE_2803x_H

#include "Flash2803x_API_Library.h"

#ifndef NULL
    #define NULL ((void * )0)
#endif

#define Drv_DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)

#define BOOTSWV	101
//status
#define	KERNEL_READY_FOR_ERASE		0x6C
#define	KERNEL_READY_FOR_DATA_RX	0x6E
#define	KERNEL_FLASH_NOT_ERASED		0x70
#define	KERNEL_PROGRAM_COMPLETE		5
#define	KERNEL_BLOCK_HEAD_OK		0
#define	KERNEL_BLOCK_SIZE_ERROR		10
#define	KERNEL_BLOCK_ADDR_ERROR		20
#define	KERNEL_DATA_CHKSUM_OK		0x82
#define	KERNEL_DATA_CHKSUM_ERROR	0x83
#define	KERNEL_ERASE_ALLFLASH		4

/*---------------------------------------------------------------------------
  Data buffer used for serial flash programming:  
---------------------------------------------------------------------------*/
#define  	FLASH_BUFFER_SIZE				0x200               // 512 Words

//Modify the follow keys for your specific firmware protection                      
#define PRG_Key0  	0xFFFF  	//PSWD bits 15-0
#define PRG_Key1  	0xFFFF  	//PSWD bits 31-16
#define PRG_Key2  	0xFFFF  	//PSWD bits 47-32
#define PRG_Key3  	0xFFFF  	//PSWD bits 63-48
#define PRG_Key4  	0xFFFF  	//PSWD bits 79-64
#define PRG_Key5  	0xFFFF 		//PSWD bits 95-80
#define PRG_Key6  	0xFFFF  	//PSWD bits 111-96 
#define PRG_Key7  	0xFFFF  	//PSWD bits 127-112

//信息帧类型
#define	FRAME_UPDATECOMMAND			0x80
#define	FRAME_HANDSHAKE 			0x81
#define	FRAME_CSMUNLOCKSTATUS 		0x82
#define	FRAME_APIVERSIONSTATUS 		0x83
#define	FRAME_ERASE 				0x84
#define	FRAME_PROGRAM 				0x85
#define	FRAME_BLOCKHEAD 			0x86
#define	FRAME_BLOCKDATA 			0x87
#define	FRAME_CHECKSUM 				0x88
#define	FRAME_PROGRAMSTATUS 		0x89
#define	FRAME_VERIFYSTATUS 			0x8A
#define	FRAME_ERROR 				0x90

#define CMD00_FLASHUD				0x00
#define ID_FLASHUDRD				0x780
#define ID_FLASHUDWT				0x781

//For destination address validation
#define FLASH_START_ADDR  			0x3E8000
#define FLASH_END_ADDR    			0x3F7FFF
#define	FLASH_PROGRAM_START			0x3E8000
#define	FLASH_PROGRAM_END			0x3F5FFB

struct StructFlashUpdateFlag
{
	UINT16	bRecValid		:1;			// BIT0 数据接收有效
	UINT16	bFlashErased	:1;			// BIT2 FlashErase完成	
	UINT16	bReserved		:14;		// BIT2-BIT15 
};

struct StructFlashVariable
{	INT16	m_i16_FlashClockMissing;	//时钟丢失标志位
	UINT16	m_u16_RamCheckErr;			// RAM自检错误标志
	UINT16 	u16_FrameType;				// 帧类型
	UINT16	u16_EraseType;				// 擦除类型:4-全擦;3-擦BCD
	UINT16	u16_BlockSize;
	UINT16	u16_APIVersion;		
	UINT16	u16_BlockData[3];			// 每帧接收到的有效数据
	UINT16	u16_MailBoxDLC;				// 每帧数据的字数(除CommandId)
	UINT16	u16_HandShakeData;			// CAN通讯握手数据
	UINT16	u16_BlockSeqNum;			// 完成Block的数量
	UINT32	u32_BlockAddr;
	UINT32	u32_CheckSumRec;			// 接收校验和
	UINT32	u32_CheckSumDSP;			// DSP计算的校验和	
	struct StructFlashUpdateFlag  st_FlashUpdateFlag;
	UINT16 *pDestBuffer;
	UINT16* p_SourceAddr;
	UINT16* p_SourceEndAddr; 
	UINT16* p_DestAddr;  	
	UINT16* p_Flash;	
	UINT16  FlashBuffer1[2];		// 写程序分支标志缓冲区
	FLASH_ST 	FlashStatus1;  			// program api函数参数
	FLASH_ST 	FlashStatus;
	UINT16 u16_Status;
	UINT16 u16_MdlAddr;
	UINT16 u16_ModuleID;
};

extern UINT16 Flash28_API_LoadStart;
extern UINT16 Flash28_API_LoadEnd;
extern UINT16 Flash28_API_RunStart;

//============================================================
//	Class_FlashUpdate与外部的接口
//	1)
//	2)
//	3)调用
//	4)调用
//============================================================
void Drv_ExtOscSel (void);
void Drv_IntOsc1Sel (void);
void Drv_InitPll(Uint16 val, Uint16 divsel);
void Drv_InitSysCtrl(void);
void Drv_SPIInit(void);
void Drv_GPIOInit(void);
void Drv_PWMInit(void);
void Drv_eCANAInit(void);
void Drv_SystemInit(void);
void Drv_RamCheck(void);

void App_FlashAPIInit(void);
void App_FlashUpdateMain(void);		//flashUpdate 主程序
UINT16	App_Flash_CsmUnlock(void);	// 解密函数

void App_Delay1ms (void);
void App_Delay20ms (void);		
void App_MBox_Read(void);			// 读取邮箱数据
void App_MBox_Send(UINT16 t_u16MsgType, UINT16 u16_Data);  //发送数据
void App_DSPRestart(void);			// dsp重启
		
void MainSwitch(void);				//所有程序入口
extern void DSP28x_usDelay(Uint32 Count);

#endif 
