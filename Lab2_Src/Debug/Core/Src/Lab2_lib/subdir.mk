################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lab2_lib/Lab2_Ex.c \
../Core/Src/Lab2_lib/MyLED7SEG.c 

OBJS += \
./Core/Src/Lab2_lib/Lab2_Ex.o \
./Core/Src/Lab2_lib/MyLED7SEG.o 

C_DEPS += \
./Core/Src/Lab2_lib/Lab2_Ex.d \
./Core/Src/Lab2_lib/MyLED7SEG.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lab2_lib/%.o: ../Core/Src/Lab2_lib/%.c Core/Src/Lab2_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Documents/DaiHoc/HK241/VXL_MCU/Labs/Lab2/Lab2_GIT/Lab2_Src/Core/Src/Lab2_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

