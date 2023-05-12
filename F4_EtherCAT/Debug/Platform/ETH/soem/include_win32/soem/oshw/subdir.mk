################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/ETH/soem/include_win32/soem/oshw/nicdrv.c \
../Platform/ETH/soem/include_win32/soem/oshw/oshw.c 

C_DEPS += \
./Platform/ETH/soem/include_win32/soem/oshw/nicdrv.d \
./Platform/ETH/soem/include_win32/soem/oshw/oshw.d 

OBJS += \
./Platform/ETH/soem/include_win32/soem/oshw/nicdrv.o \
./Platform/ETH/soem/include_win32/soem/oshw/oshw.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/ETH/soem/include_win32/soem/oshw/%.o: ../Platform/ETH/soem/include_win32/soem/oshw/%.c Platform/ETH/soem/include_win32/soem/oshw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

