#ifndef _APP_STATECTRL_H
#define _APP_STATECTRL_H

//#include "config.h"

typedef enum tag_PSUModeType {
    STANDBY_MODE = 0,
    CHARGE_MODE = 1,
    DISCHARGE_MODE = 2
} PSUModeType;


typedef enum tag_StateType {
    POWER_UP = 0,
    SHUT_DOWN = 1,
    SOFT_START = 2,
    STABILIZITING = 3,
    NORMAL_OPERATION = 4,
    OCP_BOUNCE_OFF = 5,
    BOUNCE_OFF = 6,
    OCP_BOUNCE_OFF_WIT = 7
} PSU_StateType;

/*
typedef enum tag_DischgStateType {
    POWER_UP = 0,
    SHUT_DOWN = 1,
    SOFT_START = 2,
    STABILIZITING = 3,
    NORMAL_OPERATION = 4,
    OCP_BOUNCE_OFF = 5,
    BOUNCE_OFF = 6,
    OCP_BOUNCE_OFF_WIT = 7
} PSUDischarge_StateType;
*/

extern void App_initStateCtrl(void);
extern void App_StateCtrl(void);


extern void Enable_MainPWMCtrl(void);
extern void Disable_MainPWMCtrl(void);
extern void Disable_SYNCPWMCtrl(void);
extern void Enable_SYNCPWMCtrl(void);



#endif
