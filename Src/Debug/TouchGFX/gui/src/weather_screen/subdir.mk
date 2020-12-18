################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/weather_screen/WEATHERPresenter.cpp \
../TouchGFX/gui/src/weather_screen/WEATHERView.cpp 

OBJS += \
./TouchGFX/gui/src/weather_screen/WEATHERPresenter.o \
./TouchGFX/gui/src/weather_screen/WEATHERView.o 

CPP_DEPS += \
./TouchGFX/gui/src/weather_screen/WEATHERPresenter.d \
./TouchGFX/gui/src/weather_screen/WEATHERView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/weather_screen/WEATHERPresenter.o: ../TouchGFX/gui/src/weather_screen/WEATHERPresenter.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../TouchGFX/gui/include -I../TouchGFX/generated/fonts/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../TouchGFX/generated/texts/include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/generated/images/include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../BoardHardware -I../Middlewares/Third_Party/FatFs/src -I../FATFS/App -I../FATFS/Target -I../USB_DEVICE/Target -I../USB_DEVICE/App -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"TouchGFX/gui/src/weather_screen/WEATHERPresenter.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
TouchGFX/gui/src/weather_screen/WEATHERView.o: ../TouchGFX/gui/src/weather_screen/WEATHERView.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../TouchGFX/gui/include -I../TouchGFX/generated/fonts/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../TouchGFX/generated/texts/include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/generated/images/include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../BoardHardware -I../Middlewares/Third_Party/FatFs/src -I../FATFS/App -I../FATFS/Target -I../USB_DEVICE/Target -I../USB_DEVICE/App -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"TouchGFX/gui/src/weather_screen/WEATHERView.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

