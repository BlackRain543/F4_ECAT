################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/EtherCAT/port/el9800appl.c \
../Platform/EtherCAT/port/el9800hw.c 

C_DEPS += \
./Platform/EtherCAT/port/el9800appl.d \
./Platform/EtherCAT/port/el9800hw.d 

OBJS += \
./Platform/EtherCAT/port/el9800appl.o \
./Platform/EtherCAT/port/el9800hw.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/EtherCAT/port/%.o: ../Platform/EtherCAT/port/%.c Platform/EtherCAT/port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

