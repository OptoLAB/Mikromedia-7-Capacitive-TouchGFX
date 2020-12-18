################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_DEVICE/Target/subdir.mk
-include USB_DEVICE/App/subdir.mk
-include TouchGFX/target/subdir.mk
-include TouchGFX/gui/src/weather_screen/subdir.mk
-include TouchGFX/gui/src/time_screen/subdir.mk
-include TouchGFX/gui/src/temp_screen/subdir.mk
-include TouchGFX/gui/src/rgb_led_screen/subdir.mk
-include TouchGFX/gui/src/pwr_screen/subdir.mk
-include TouchGFX/gui/src/nrf_screen/subdir.mk
-include TouchGFX/gui/src/mp3_screen/subdir.mk
-include TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/gui/src/main_menu_screen/subdir.mk
-include TouchGFX/gui/src/light_screen/subdir.mk
-include TouchGFX/gui/src/gallery_screen/subdir.mk
-include TouchGFX/gui/src/flash_screen/subdir.mk
-include TouchGFX/gui/src/containers/subdir.mk
-include TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/gui/src/buzzer_screen/subdir.mk
-include TouchGFX/gui/src/accel_screen/subdir.mk
-include TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/generated/images/src/__designer/subdir.mk
-include TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/generated/gui_generated/src/weather_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/time_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/temp_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/rgb_led_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/pwr_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/nrf_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/mp3_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/main_menu_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/light_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/gallery_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/flash_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/containers/subdir.mk
-include TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/generated/gui_generated/src/buzzer_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/accel_screen/subdir.mk
-include TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/App/subdir.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BoardHardware/wifi/simplelink/source/subdir.mk
-include BoardHardware/wifi/common/subdir.mk
-include BoardHardware/wifi/subdir.mk
-include BoardHardware/touch/subdir.mk
-include BoardHardware/temp/subdir.mk
-include BoardHardware/sd/subdir.mk
-include BoardHardware/power/subdir.mk
-include BoardHardware/nRF/subdir.mk
-include BoardHardware/mp3/subdir.mk
-include BoardHardware/led/subdir.mk
-include BoardHardware/ir/subdir.mk
-include BoardHardware/internal/subdir.mk
-include BoardHardware/flash/subdir.mk
-include BoardHardware/display/subdir.mk
-include BoardHardware/buzzer/subdir.mk
-include BoardHardware/als/subdir.mk
-include BoardHardware/accel/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MC7_TouchGFX_Test.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MC7_TouchGFX_Test.list \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: MC7_TouchGFX_Test.elf secondary-outputs

# Tool invocations
MC7_TouchGFX_Test.elf: $(OBJS) $(USER_OBJS) C:\Users\Jovan\Desktop\MC7_TouchGFX_Test\STM32F767BITX_FLASH.ld
	arm-none-eabi-g++ -o "MC7_TouchGFX_Test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\Jovan\Desktop\MC7_TouchGFX_Test\STM32F767BITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MC7_TouchGFX_Test.map" -Wl,--gc-sections -static -L../Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MC7_TouchGFX_Test.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MC7_TouchGFX_Test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy.exe -O binary --only-section=ExtFlashSection "MC7_TouchGFX_Test.elf" ExtFlash.bin
	arm-none-eabi-objcopy.exe -O binary --remove-section=ExtFlashSection "MC7_TouchGFX_Test.elf" "MC7_TouchGFX_Test.bin"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
