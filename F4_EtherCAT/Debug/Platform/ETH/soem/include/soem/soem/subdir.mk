################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/ETH/soem/include/soem/soem/ethercatbase.c \
../Platform/ETH/soem/include/soem/soem/ethercatcoe.c \
../Platform/ETH/soem/include/soem/soem/ethercatconfig.c \
../Platform/ETH/soem/include/soem/soem/ethercatdc.c \
../Platform/ETH/soem/include/soem/soem/ethercatfoe.c \
../Platform/ETH/soem/include/soem/soem/ethercatmain.c \
../Platform/ETH/soem/include/soem/soem/ethercatprint.c \
../Platform/ETH/soem/include/soem/soem/ethercatsoe.c 

C_DEPS += \
./Platform/ETH/soem/include/soem/soem/ethercatbase.d \
./Platform/ETH/soem/include/soem/soem/ethercatcoe.d \
./Platform/ETH/soem/include/soem/soem/ethercatconfig.d \
./Platform/ETH/soem/include/soem/soem/ethercatdc.d \
./Platform/ETH/soem/include/soem/soem/ethercatfoe.d \
./Platform/ETH/soem/include/soem/soem/ethercatmain.d \
./Platform/ETH/soem/include/soem/soem/ethercatprint.d \
./Platform/ETH/soem/include/soem/soem/ethercatsoe.d 

OBJS += \
./Platform/ETH/soem/include/soem/soem/ethercatbase.o \
./Platform/ETH/soem/include/soem/soem/ethercatcoe.o \
./Platform/ETH/soem/include/soem/soem/ethercatconfig.o \
./Platform/ETH/soem/include/soem/soem/ethercatdc.o \
./Platform/ETH/soem/include/soem/soem/ethercatfoe.o \
./Platform/ETH/soem/include/soem/soem/ethercatmain.o \
./Platform/ETH/soem/include/soem/soem/ethercatprint.o \
./Platform/ETH/soem/include/soem/soem/ethercatsoe.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/ETH/soem/include/soem/soem/%.o: ../Platform/ETH/soem/include/soem/soem/%.c Platform/ETH/soem/include/soem/soem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

