#ifndef _ANALOGCHK_CONTROL_H
#define _ANALOGCHK_CONTROL_H

#include "Flash2803x_API.h"
#include "config.h"
#include <stdbool.h>

typedef union {
	UINT16 Word;

    struct {
        UINT16 LVOVP : 1; // output OV flag
        UINT16 LVUVP : 1; // output UV flag
        UINT16 OutPutOCP : 1; // output OC flag
        UINT16 HVOVP : 1; //  HV OV flag
        UINT16 HVUVP : 1; // HV UV flag
		UINT16 OTP : 1; // OTP flag
        UINT16 reserved : 10;
    }bit;
} u16FaultRegType;

#define RESOLUTION        ((1<<15) - 1)
#define ADC_RESOLUTION    ((1<<12) - 1)

#define HV_RANGE          (720.0)// HV voltage measurable range, V

#define HV_VOLT(x)        ((Uint16)((double)x*RESOLUTION/HV_RANGE))

#define LH_RANGE          (18.0)

#define LV_VOLT(x)        ((Uint16)((double)x*RESOLUTION/LH_RANGE))

extern Uint16 u16LVoltInst;


void analog_HVmetering(void);
void analog_monitor(void);
void analog_ChkLVUVP(void);
void analog_ChkLVOVP(void);
void analog_ChkHVUVP(void);
void analog_ChkHVOVP(void);
extern bool is_PFC_OK(void);






extern bool is_fault(void);
extern bool is_OCP(void);
extern bool is_LVOVP(void);
extern bool isHV_OVP(void);



#endif
