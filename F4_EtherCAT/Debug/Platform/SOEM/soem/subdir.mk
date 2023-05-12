################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/SOEM/soem/ethercatbase.c \
../Platform/SOEM/soem/ethercatcoe.c \
../Platform/SOEM/soem/ethercatconfig.c \
../Platform/SOEM/soem/ethercatdc.c \
../Platform/SOEM/soem/ethercatfoe.c \
../Platform/SOEM/soem/ethercatmain.c \
../Platform/SOEM/soem/ethercatprint.c \
../Platform/SOEM/soem/ethercatsoe.c 

C_DEPS += \
./Platform/SOEM/soem/ethercatbase.d \
./Platform/SOEM/soem/ethercatcoe.d \
./Platform/SOEM/soem/ethercatconfig.d \
./Platform/SOEM/soem/ethercatdc.d \
./Platform/SOEM/soem/ethercatfoe.d \
./Platform/SOEM/soem/ethercatmain.d \
./Platform/SOEM/soem/ethercatprint.d \
./Platform/SOEM/soem/ethercatsoe.d 

OBJS += \
./Platform/SOEM/soem/ethercatbase.o \
./Platform/SOEM/soem/ethercatcoe.o \
./Platform/SOEM/soem/ethercatconfig.o \
./Platform/SOEM/soem/ethercatdc.o \
./Platform/SOEM/soem/ethercatfoe.o \
./Platform/SOEM/soem/ethercatmain.o \
./Platform/SOEM/soem/ethercatprint.o \
./Platform/SOEM/soem/ethercatsoe.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/SOEM/soem/%.o: ../Platform/SOEM/soem/%.c Platform/SOEM/soem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/SOES -I../Platform/SOEM -I../Platform/SSC/Inc -I../Platform/SSC/port -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

