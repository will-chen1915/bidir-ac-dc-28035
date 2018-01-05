################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/TI/ccsv6/tools/compiler/c2000_6.2.7

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./Source/App_stateCtrl.obj" \
"./Source/DSP2803x_Adc.obj" \
"./Source/DSP2803x_CSMPasswords.obj" \
"./Source/DSP2803x_CpuTimers.obj" \
"./Source/DSP2803x_DefaultIsr.obj" \
"./Source/DSP2803x_ECan.obj" \
"./Source/DSP2803x_EPwm.obj" \
"./Source/DSP2803x_GlobalVariableDefs.obj" \
"./Source/DSP2803x_Gpio.obj" \
"./Source/DSP2803x_I2C.obj" \
"./Source/DSP2803x_InitPeripherals.obj" \
"./Source/DSP2803x_PieCtrl.obj" \
"./Source/DSP2803x_PieVect.obj" \
"./Source/DSP2803x_Sci.obj" \
"./Source/DSP2803x_Spi.obj" \
"./Source/DSP2803x_SysCtrl.obj" \
"./Source/DSP280x_usDelay.obj" \
"./Source/Interrupt_Ctrl.obj" \
"./Source/SCICommu_Ctrl.obj" \
"./Source/Signal_IOCtrl.obj" \
"./Source/analogChk_control.obj" \
"./Source/main.obj" \
"./Source/power_loopCtrl.obj" \
"../DSP2803x_Headers_nonBIOS.cmd" \
"../F28035.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Source/subdir_vars.mk
-include subdir_rules.mk
-include Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
28035_v01.out \

EXE_OUTPUTS__QUOTED += \
"28035_v01.out" \

BIN_OUTPUTS += \
28035_v01.hex \

BIN_OUTPUTS__QUOTED += \
"28035_v01.hex" \


# All Target
all: 28035_v01.out

# Tool invocations
28035_v01.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"D:/TI/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --diag_warning=225 --display_error_number --diag_wrap=off -z -m"28035_v01.map" --stack_size=0x300 --warn_sections -i"D:/TI/ccsv6/tools/compiler/c2000_6.2.7/lib" -i"D:/TI/ccsv6/tools/compiler/c2000_6.2.7/include" --reread_libs --display_error_number --diag_wrap=off --xml_link_info="28035_v01_linkInfo.xml" --rom_model -o "28035_v01.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

28035_v01.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"D:/TI/ccsv6/tools/compiler/c2000_6.2.7/bin/hex2000"  -o "28035_v01.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Source\DSP2803x_Adc.pp" "Source\DSP2803x_CpuTimers.pp" "Source\DSP2803x_DefaultIsr.pp" "Source\DSP2803x_ECan.pp" "Source\DSP2803x_EPwm.pp" "Source\DSP2803x_GlobalVariableDefs.pp" "Source\DSP2803x_Gpio.pp" "Source\DSP2803x_I2C.pp" "Source\DSP2803x_InitPeripherals.pp" "Source\DSP2803x_PieCtrl.pp" "Source\DSP2803x_PieVect.pp" "Source\DSP2803x_Sci.pp" "Source\DSP2803x_Spi.pp" "Source\DSP2803x_SysCtrl.pp" "Source\Interrupt_Ctrl.pp" "Source\SCICommu_Ctrl.pp" "Source\main.pp" 
	-$(RM) "Source\App_stateCtrl.pp" "Source\Signal_IOCtrl.pp" "Source\analogChk_control.pp" "Source\power_loopCtrl.pp" 
	-$(RM) "Source\App_stateCtrl.obj" "Source\DSP2803x_Adc.obj" "Source\DSP2803x_CSMPasswords.obj" "Source\DSP2803x_CpuTimers.obj" "Source\DSP2803x_DefaultIsr.obj" "Source\DSP2803x_ECan.obj" "Source\DSP2803x_EPwm.obj" "Source\DSP2803x_GlobalVariableDefs.obj" "Source\DSP2803x_Gpio.obj" "Source\DSP2803x_I2C.obj" "Source\DSP2803x_InitPeripherals.obj" "Source\DSP2803x_PieCtrl.obj" "Source\DSP2803x_PieVect.obj" "Source\DSP2803x_Sci.obj" "Source\DSP2803x_Spi.obj" "Source\DSP2803x_SysCtrl.obj" "Source\DSP280x_usDelay.obj" "Source\Interrupt_Ctrl.obj" "Source\SCICommu_Ctrl.obj" "Source\Signal_IOCtrl.obj" "Source\analogChk_control.obj" "Source\main.obj" "Source\power_loopCtrl.obj" 
	-$(RM) "Source\DSP2803x_CSMPasswords.pp" "Source\DSP280x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

