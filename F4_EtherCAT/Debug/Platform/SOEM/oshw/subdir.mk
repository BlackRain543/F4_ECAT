################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/SOEM/oshw/nicdrv.c \
../Platform/SOEM/oshw/oshw.c 

C_DEPS += \
./Platform/SOEM/oshw/nicdrv.d \
./Platform/SOEM/oshw/oshw.d 

OBJS += \
./Platform/SOEM/oshw/nicdrv.o \
./Platform/SOEM/oshw/oshw.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/SOEM/oshw/%.o: ../Platform/SOEM/oshw/%.c Platform/SOEM/oshw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/SOES -I../Platform/SOEM -I../Platform/SSC/Inc -I../Platform/SSC/port -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

