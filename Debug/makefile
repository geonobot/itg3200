################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
libitg3200.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libitg3200.a secondary-outputs

# Tool invocations
libitg3200.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libitg3200.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libitg3200.lss: libitg3200.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libitg3200.a  >"libitg3200.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libitg3200.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 libitg3200.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(ARCHIVES)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) libitg3200.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
