################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_UPPER_SRCS += \
../source/App_stateCtrl.C \
../source/Signal_IOCtrl.C \
../source/analogChk_control.C \
../source/power_loopCtrl.C 

LIB_SRCS += \
../source/IQmath.lib 

ASM_SRCS += \
../source/DSP2803x_CodeStartBranch.asm \
../source/DSP2803x_DisInt.asm \
../source/DSP2803x_usDelay.asm 

C_SRCS += \
../source/DSP2803x_Adc.c \
../source/DSP2803x_CpuTimers.c \
../source/DSP2803x_DefaultIsr.c \
../source/DSP2803x_EPwm.c \
../source/DSP2803x_GlobalVariableDefs.c \
../source/DSP2803x_Gpio.c \
../source/DSP2803x_I2C.c \
../source/DSP2803x_InitPeripherals.c \
../source/DSP2803x_MemCopy.c \
../source/DSP2803x_PieCtrl.c \
../source/DSP2803x_PieVect.c \
../source/DSP2803x_Sci.c \
../source/DSP2803x_SysCtrl.c \
../source/Interrupt_Ctrl.c \
../source/SCICommu_Ctrl.c \
../source/main.c 

OBJS += \
./source/App_stateCtrl.obj \
./source/DSP2803x_Adc.obj \
./source/DSP2803x_CodeStartBranch.obj \
./source/DSP2803x_CpuTimers.obj \
./source/DSP2803x_DefaultIsr.obj \
./source/DSP2803x_DisInt.obj \
./source/DSP2803x_EPwm.obj \
./source/DSP2803x_GlobalVariableDefs.obj \
./source/DSP2803x_Gpio.obj \
./source/DSP2803x_I2C.obj \
./source/DSP2803x_InitPeripherals.obj \
./source/DSP2803x_MemCopy.obj \
./source/DSP2803x_PieCtrl.obj \
./source/DSP2803x_PieVect.obj \
./source/DSP2803x_Sci.obj \
./source/DSP2803x_SysCtrl.obj \
./source/DSP2803x_usDelay.obj \
./source/Interrupt_Ctrl.obj \
./source/SCICommu_Ctrl.obj \
./source/Signal_IOCtrl.obj \
./source/analogChk_control.obj \
./source/main.obj \
./source/power_loopCtrl.obj 

ASM_DEPS += \
./source/DSP2803x_CodeStartBranch.pp \
./source/DSP2803x_DisInt.pp \
./source/DSP2803x_usDelay.pp 

C_DEPS += \
./source/DSP2803x_Adc.pp \
./source/DSP2803x_CpuTimers.pp \
./source/DSP2803x_DefaultIsr.pp \
./source/DSP2803x_EPwm.pp \
./source/DSP2803x_GlobalVariableDefs.pp \
./source/DSP2803x_Gpio.pp \
./source/DSP2803x_I2C.pp \
./source/DSP2803x_InitPeripherals.pp \
./source/DSP2803x_MemCopy.pp \
./source/DSP2803x_PieCtrl.pp \
./source/DSP2803x_PieVect.pp \
./source/DSP2803x_Sci.pp \
./source/DSP2803x_SysCtrl.pp \
./source/Interrupt_Ctrl.pp \
./source/SCICommu_Ctrl.pp \
./source/main.pp 

C_UPPER_DEPS += \
./source/App_stateCtrl.pp \
./source/Signal_IOCtrl.pp \
./source/analogChk_control.pp \
./source/power_loopCtrl.pp 

C_DEPS__QUOTED += \
"source\DSP2803x_Adc.pp" \
"source\DSP2803x_CpuTimers.pp" \
"source\DSP2803x_DefaultIsr.pp" \
"source\DSP2803x_EPwm.pp" \
"source\DSP2803x_GlobalVariableDefs.pp" \
"source\DSP2803x_Gpio.pp" \
"source\DSP2803x_I2C.pp" \
"source\DSP2803x_InitPeripherals.pp" \
"source\DSP2803x_MemCopy.pp" \
"source\DSP2803x_PieCtrl.pp" \
"source\DSP2803x_PieVect.pp" \
"source\DSP2803x_Sci.pp" \
"source\DSP2803x_SysCtrl.pp" \
"source\Interrupt_Ctrl.pp" \
"source\SCICommu_Ctrl.pp" \
"source\main.pp" 

C_UPPER_DEPS__QUOTED += \
"source\App_stateCtrl.pp" \
"source\Signal_IOCtrl.pp" \
"source\analogChk_control.pp" \
"source\power_loopCtrl.pp" 

OBJS__QUOTED += \
"source\App_stateCtrl.obj" \
"source\DSP2803x_Adc.obj" \
"source\DSP2803x_CodeStartBranch.obj" \
"source\DSP2803x_CpuTimers.obj" \
"source\DSP2803x_DefaultIsr.obj" \
"source\DSP2803x_DisInt.obj" \
"source\DSP2803x_EPwm.obj" \
"source\DSP2803x_GlobalVariableDefs.obj" \
"source\DSP2803x_Gpio.obj" \
"source\DSP2803x_I2C.obj" \
"source\DSP2803x_InitPeripherals.obj" \
"source\DSP2803x_MemCopy.obj" \
"source\DSP2803x_PieCtrl.obj" \
"source\DSP2803x_PieVect.obj" \
"source\DSP2803x_Sci.obj" \
"source\DSP2803x_SysCtrl.obj" \
"source\DSP2803x_usDelay.obj" \
"source\Interrupt_Ctrl.obj" \
"source\SCICommu_Ctrl.obj" \
"source\Signal_IOCtrl.obj" \
"source\analogChk_control.obj" \
"source\main.obj" \
"source\power_loopCtrl.obj" 

ASM_DEPS__QUOTED += \
"source\DSP2803x_CodeStartBranch.pp" \
"source\DSP2803x_DisInt.pp" \
"source\DSP2803x_usDelay.pp" 

C_UPPER_SRCS__QUOTED += \
"../source/App_stateCtrl.C" \
"../source/Signal_IOCtrl.C" \
"../source/analogChk_control.C" \
"../source/power_loopCtrl.C" 

C_SRCS__QUOTED += \
"../source/DSP2803x_Adc.c" \
"../source/DSP2803x_CpuTimers.c" \
"../source/DSP2803x_DefaultIsr.c" \
"../source/DSP2803x_EPwm.c" \
"../source/DSP2803x_GlobalVariableDefs.c" \
"../source/DSP2803x_Gpio.c" \
"../source/DSP2803x_I2C.c" \
"../source/DSP2803x_InitPeripherals.c" \
"../source/DSP2803x_MemCopy.c" \
"../source/DSP2803x_PieCtrl.c" \
"../source/DSP2803x_PieVect.c" \
"../source/DSP2803x_Sci.c" \
"../source/DSP2803x_SysCtrl.c" \
"../source/Interrupt_Ctrl.c" \
"../source/SCICommu_Ctrl.c" \
"../source/main.c" 

ASM_SRCS__QUOTED += \
"../source/DSP2803x_CodeStartBranch.asm" \
"../source/DSP2803x_DisInt.asm" \
"../source/DSP2803x_usDelay.asm" 


