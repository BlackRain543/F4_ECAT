################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UserApp/port/math_port.cpp \
../UserApp/port/var_port.cpp 

OBJS += \
./UserApp/port/math_port.o \
./UserApp/port/var_port.o 

CPP_DEPS += \
./UserApp/port/math_port.d \
./UserApp/port/var_port.d 


# Each subdirectory must supply rules for building sources it contributes
UserApp/port/%.o: ../UserApp/port/%.cpp UserApp/port/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

