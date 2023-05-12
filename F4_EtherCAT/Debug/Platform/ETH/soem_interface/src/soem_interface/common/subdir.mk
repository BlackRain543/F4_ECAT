################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Platform/ETH/soem_interface/src/soem_interface/common/Macros.cpp \
../Platform/ETH/soem_interface/src/soem_interface/common/ThreadSleep.cpp 

OBJS += \
./Platform/ETH/soem_interface/src/soem_interface/common/Macros.o \
./Platform/ETH/soem_interface/src/soem_interface/common/ThreadSleep.o 

CPP_DEPS += \
./Platform/ETH/soem_interface/src/soem_interface/common/Macros.d \
./Platform/ETH/soem_interface/src/soem_interface/common/ThreadSleep.d 


# Each subdirectory must supply rules for building sources it contributes
Platform/ETH/soem_interface/src/soem_interface/common/%.o: ../Platform/ETH/soem_interface/src/soem_interface/common/%.cpp Platform/ETH/soem_interface/src/soem_interface/common/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

