#ifndef _SCICOMMU_CTRL_H
#define _SCICOMMU_CTRL_H


#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File


#define MAX_SCI_SIZE 64


typedef struct AppPacket
{
	Uint16      header;
	Uint16      command;
	Uint16      data;
	Uint16      rear;
} app_packe_t;

typedef struct SciPacket
{
	char 	nLen;
	char    buf[MAX_SCI_SIZE];
} Sci_packet_t;


extern Uint16	Txd_buf[800];
extern Uint16  Txd_Cnt;


extern Sci_packet_t* Rxd_buf;
 
//extern unsigned short	Txd_buf[1000];

extern void SCICommu_Control ( void );

#endif
