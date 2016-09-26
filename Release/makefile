################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
two_buttons_count.lss \

FLASH_IMAGE += \
two_buttons_count.hex \

EEPROM_IMAGE += \
two_buttons_count.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: two_buttons_count.elf secondary-outputs

# Tool invocations
two_buttons_count.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,two_buttons_count.map -mmcu=atmega328p -o "two_buttons_count.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

two_buttons_count.lss: two_buttons_count.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S two_buttons_count.elf  >"two_buttons_count.lss"
	@echo 'Finished building: $@'
	@echo ' '

two_buttons_count.hex: two_buttons_count.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex two_buttons_count.elf  "two_buttons_count.hex"
	@echo 'Finished building: $@'
	@echo ' '

two_buttons_count.eep: two_buttons_count.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex two_buttons_count.elf  "two_buttons_count.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: two_buttons_count.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p two_buttons_count.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) two_buttons_count.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
