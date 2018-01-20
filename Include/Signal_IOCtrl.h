#ifndef _SIGNAL_IOCTRL_H
#define _SIGNAL_IOCTRL_H


typedef enum tagT_LedState
{
    LED_OFF = 0,
    LED_ON = 1
} T_LedState;

typedef enum tag_LogicState
{
    False = 0,
    FalseWait = 1,
    True = 2,
    TrueWait = 3
} LogicStateType;


#define getPin_PFCOK()           GpioDataRegs.GPADAT.bit.GPIO12

#define LEDCtrl_LED1Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO17=1
#define LEDCtrl_LED1Off()        GpioDataRegs.GPACLEAR.bit.GPIO17=1
#define LEDCtrl_LED1On()         GpioDataRegs.GPASET.bit.GPIO17=1

#define LEDCtrl_LED2Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO18=1
#define LEDCtrl_LED2Off()        GpioDataRegs.GPACLEAR.bit.GPIO18=1
#define LEDCtrl_LED2On()         GpioDataRegs.GPASET.bit.GPIO18=1

#define LEDCtrl_LED3Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO16=1
#define LEDCtrl_LED3Off()        GpioDataRegs.GPACLEAR.bit.GPIO16=1
#define LEDCtrl_LED3On()         GpioDataRegs.GPASET.bit.GPIO16 =1
 
extern LogicStateType PFCOK_State_e;
extern void IO_UpdSignal(void);

#endif
