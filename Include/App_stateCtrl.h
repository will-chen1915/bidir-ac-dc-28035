#ifndef _APP_STATECTRL_H
#define _APP_STATECTRL_H

//#include "config.h"



typedef enum tag_StateType {
    POWER_UP = 0,
    SHUT_DOWN = 1,
    SOFT_START = 2,
    STABILIZITING = 3,
    NORMAL_OPERATION = 4,
    OCP_BOUNCE_OFF = 5,
    BOUNCE_OFF = 6,
    OCP_BOUNCE_OFF_WIT = 7
} PSUCharge_StateType;

extern void App_initStateCtrl(void);
extern void App_StateCtrl(void);


#endif
