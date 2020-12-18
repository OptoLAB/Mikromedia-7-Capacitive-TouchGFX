################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BoardHardware/ir/NEC_TimerIC.c 

OBJS += \
./BoardHardware/ir/NEC_TimerIC.o 

C_DEPS += \
./BoardHardware/ir/NEC_TimerIC.d 


# Each subdirectory must supply rules for building sources it contributes
BoardHardware/ir/NEC_TimerIC.o: ../BoardHardware/ir/NEC_TimerIC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../TouchGFX/gui/include -I../FATFS/App -I../TouchGFX/generated/fonts/include -I../USB_DEVICE/Target -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../TouchGFX/generated/texts/include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/generated/images/include -I../Middlewares/ST/touchgfx/framework/include -I../BoardHardware -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../USB_DEVICE/App -I../TouchGFX/generated/gui_generated/include -I../FATFS/Target -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"BoardHardware/ir/NEC_TimerIC.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

