#ifndef _SIGNAL_IOCTRL_H
#define _SIGNAL_IOCTRL_H


typedef enum tagT_LedState
{
    LED_OFF = 0,
    LED_ON = 1
} T_LedState;

#define LEDCtrl_LED1Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO12
#define LEDCtrl_LED1Off()        GpioDataRegs.GPACLEAR.bit.GPIO12
#define LEDCtrl_LED1On()         GpioDataRegs.GPASET.bit.GPIO12

#define LEDCtrl_LED2Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO25
#define LEDCtrl_LED2Off()        GpioDataRegs.GPACLEAR.bit.GPIO25
#define LEDCtrl_LED2On()         GpioDataRegs.GPASET.bit.GPIO25

#define LEDCtrl_LED3Toggle()     GpioDataRegs.GPATOGGLE.bit.GPIO27
#define LEDCtrl_LED3Off()        GpioDataRegs.GPACLEAR.bit.GPIO27
#define LEDCtrl_LED3On()         GpioDataRegs.GPASET.bit.GPIO27
 
extern void IO_UpdSignal(void);

#endif
