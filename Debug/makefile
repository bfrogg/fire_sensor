################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs613/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./driverlib/MSP430FR57xx/adc10_b.obj" \
"./driverlib/MSP430FR57xx/comp_d.obj" \
"./driverlib/MSP430FR57xx/crc.obj" \
"./driverlib/MSP430FR57xx/cs.obj" \
"./driverlib/MSP430FR57xx/dma.obj" \
"./driverlib/MSP430FR57xx/eusci_a_spi.obj" \
"./driverlib/MSP430FR57xx/eusci_a_uart.obj" \
"./driverlib/MSP430FR57xx/eusci_b_i2c.obj" \
"./driverlib/MSP430FR57xx/eusci_b_spi.obj" \
"./driverlib/MSP430FR57xx/framctl.obj" \
"./driverlib/MSP430FR57xx/gpio.obj" \
"./driverlib/MSP430FR57xx/mpu.obj" \
"./driverlib/MSP430FR57xx/mpy32.obj" \
"./driverlib/MSP430FR57xx/pmm.obj" \
"./driverlib/MSP430FR57xx/ref.obj" \
"./driverlib/MSP430FR57xx/rtc_b.obj" \
"./driverlib/MSP430FR57xx/sfr.obj" \
"./driverlib/MSP430FR57xx/sysctl.obj" \
"./driverlib/MSP430FR57xx/timer_a.obj" \
"./driverlib/MSP430FR57xx/timer_b.obj" \
"./driverlib/MSP430FR57xx/tlv.obj" \
"./driverlib/MSP430FR57xx/wdt_a.obj" \
"../lnk_msp430fr5729.cmd" \
$(GEN_CMDS__FLAG) \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include driverlib/MSP430FR57xx/subdir_vars.mk
-include subdir_rules.mk
-include driverlib/MSP430FR57xx/subdir_rules.mk
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
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
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
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
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
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
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
fire_sensor.out \

EXE_OUTPUTS__QUOTED += \
"fire_sensor.out" \

BIN_OUTPUTS += \
fire_sensor.hex \

BIN_OUTPUTS__QUOTED += \
"fire_sensor.hex" \


# All Target
all: fire_sensor.out

# Tool invocations
fire_sensor.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccs613/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/bin/cl430" -vmspx --code_model=large --data_model=restricted --near_data=none --use_hw_mpy=F5 --advice:power=all -g --define=__MSP430FR5729__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal -z -m"fire_sensor.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccs613/ccsv6/ccs_base/msp430/include" -i"C:/ti/ccs613/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccs613/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/lib" -i"C:/ti/ccs613/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/include" --reread_libs --display_error_number --warn_sections --diag_wrap=off --xml_link_info="fire_sensor_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "fire_sensor.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

fire_sensor.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccs613/ccsv6/tools/compiler/ti-cgt-msp430_15.12.1.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "fire_sensor.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.d" "driverlib\MSP430FR57xx\adc10_b.d" "driverlib\MSP430FR57xx\comp_d.d" "driverlib\MSP430FR57xx\crc.d" "driverlib\MSP430FR57xx\cs.d" "driverlib\MSP430FR57xx\dma.d" "driverlib\MSP430FR57xx\eusci_a_spi.d" "driverlib\MSP430FR57xx\eusci_a_uart.d" "driverlib\MSP430FR57xx\eusci_b_i2c.d" "driverlib\MSP430FR57xx\eusci_b_spi.d" "driverlib\MSP430FR57xx\framctl.d" "driverlib\MSP430FR57xx\gpio.d" "driverlib\MSP430FR57xx\mpu.d" "driverlib\MSP430FR57xx\mpy32.d" "driverlib\MSP430FR57xx\pmm.d" "driverlib\MSP430FR57xx\ref.d" "driverlib\MSP430FR57xx\rtc_b.d" "driverlib\MSP430FR57xx\sfr.d" "driverlib\MSP430FR57xx\sysctl.d" "driverlib\MSP430FR57xx\timer_a.d" "driverlib\MSP430FR57xx\timer_b.d" "driverlib\MSP430FR57xx\tlv.d" "driverlib\MSP430FR57xx\wdt_a.d" 
	-$(RM) "main.obj" "driverlib\MSP430FR57xx\adc10_b.obj" "driverlib\MSP430FR57xx\comp_d.obj" "driverlib\MSP430FR57xx\crc.obj" "driverlib\MSP430FR57xx\cs.obj" "driverlib\MSP430FR57xx\dma.obj" "driverlib\MSP430FR57xx\eusci_a_spi.obj" "driverlib\MSP430FR57xx\eusci_a_uart.obj" "driverlib\MSP430FR57xx\eusci_b_i2c.obj" "driverlib\MSP430FR57xx\eusci_b_spi.obj" "driverlib\MSP430FR57xx\framctl.obj" "driverlib\MSP430FR57xx\gpio.obj" "driverlib\MSP430FR57xx\mpu.obj" "driverlib\MSP430FR57xx\mpy32.obj" "driverlib\MSP430FR57xx\pmm.obj" "driverlib\MSP430FR57xx\ref.obj" "driverlib\MSP430FR57xx\rtc_b.obj" "driverlib\MSP430FR57xx\sfr.obj" "driverlib\MSP430FR57xx\sysctl.obj" "driverlib\MSP430FR57xx\timer_a.obj" "driverlib\MSP430FR57xx\timer_b.obj" "driverlib\MSP430FR57xx\tlv.obj" "driverlib\MSP430FR57xx\wdt_a.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

