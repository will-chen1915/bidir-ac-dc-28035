################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/c2000_6.2.7

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./source/App_stateCtrl.obj" \
"./source/DSP2803x_Adc.obj" \
"./source/DSP2803x_CodeStartBranch.obj" \
"./source/DSP2803x_CpuTimers.obj" \
"./source/DSP2803x_DefaultIsr.obj" \
"./source/DSP2803x_DisInt.obj" \
"./source/DSP2803x_EPwm.obj" \
"./source/DSP2803x_GlobalVariableDefs.obj" \
"./source/DSP2803x_Gpio.obj" \
"./source/DSP2803x_I2C.obj" \
"./source/DSP2803x_InitPeripherals.obj" \
"./source/DSP2803x_MemCopy.obj" \
"./source/DSP2803x_PieCtrl.obj" \
"./source/DSP2803x_PieVect.obj" \
"./source/DSP2803x_Sci.obj" \
"./source/DSP2803x_SysCtrl.obj" \
"./source/DSP2803x_usDelay.obj" \
"./source/Interrupt_Ctrl.obj" \
"./source/SCICommu_Ctrl.obj" \
"./source/Signal_IOCtrl.obj" \
"./source/analogChk_control.obj" \
"./source/main.obj" \
"./source/power_loopCtrl.obj" \
"../source/IQmath.lib" \
"../CMD/DSP2803x_Headers_nonBIOS.cmd" \
"../CMD/F28035_FLASH.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include source/subdir_vars.mk
-include CMD/subdir_vars.mk
-include source/subdir_rules.mk
-include CMD/subdir_rules.mk
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
F28035.out \

EXE_OUTPUTS__QUOTED += \
"F28035.out" \

BIN_OUTPUTS += \
F28035.hex \

BIN_OUTPUTS__QUOTED += \
"F28035.hex" \


# All Target
all: F28035.out

# Tool invocations
F28035.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --diag_warning=225 --display_error_number -z -m"F28035.map" --stack_size=0x300 --warn_sections -i"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/lib" -i"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/include" --reread_libs --display_error_number --xml_link_info="F28035_linkInfo.xml" --rom_model -o "F28035.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

F28035.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/hex2000"  -o "F28035.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "source\DSP2803x_Adc.pp" "source\DSP2803x_CpuTimers.pp" "source\DSP2803x_DefaultIsr.pp" "source\DSP2803x_EPwm.pp" "source\DSP2803x_GlobalVariableDefs.pp" "source\DSP2803x_Gpio.pp" "source\DSP2803x_I2C.pp" "source\DSP2803x_InitPeripherals.pp" "source\DSP2803x_MemCopy.pp" "source\DSP2803x_PieCtrl.pp" "source\DSP2803x_PieVect.pp" "source\DSP2803x_Sci.pp" "source\DSP2803x_SysCtrl.pp" "source\Interrupt_Ctrl.pp" "source\SCICommu_Ctrl.pp" "source\main.pp" 
	-$(RM) "source\App_stateCtrl.pp" "source\Signal_IOCtrl.pp" "source\analogChk_control.pp" "source\power_loopCtrl.pp" 
	-$(RM) "source\App_stateCtrl.obj" "source\DSP2803x_Adc.obj" "source\DSP2803x_CodeStartBranch.obj" "source\DSP2803x_CpuTimers.obj" "source\DSP2803x_DefaultIsr.obj" "source\DSP2803x_DisInt.obj" "source\DSP2803x_EPwm.obj" "source\DSP2803x_GlobalVariableDefs.obj" "source\DSP2803x_Gpio.obj" "source\DSP2803x_I2C.obj" "source\DSP2803x_InitPeripherals.obj" "source\DSP2803x_MemCopy.obj" "source\DSP2803x_PieCtrl.obj" "source\DSP2803x_PieVect.obj" "source\DSP2803x_Sci.obj" "source\DSP2803x_SysCtrl.obj" "source\DSP2803x_usDelay.obj" "source\Interrupt_Ctrl.obj" "source\SCICommu_Ctrl.obj" "source\Signal_IOCtrl.obj" "source\analogChk_control.obj" "source\main.obj" "source\power_loopCtrl.obj" 
	-$(RM) "source\DSP2803x_CodeStartBranch.pp" "source\DSP2803x_DisInt.pp" "source\DSP2803x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

