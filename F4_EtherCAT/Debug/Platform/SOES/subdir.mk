################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/SOES/ecat_slv.c \
../Platform/SOES/esc_coe.c \
../Platform/SOES/esc_eep.c \
../Platform/SOES/esc_eoe.c \
../Platform/SOES/esc_foe.c \
../Platform/SOES/esc_soes.c 

C_DEPS += \
./Platform/SOES/ecat_slv.d \
./Platform/SOES/esc_coe.d \
./Platform/SOES/esc_eep.d \
./Platform/SOES/esc_eoe.d \
./Platform/SOES/esc_foe.d \
./Platform/SOES/esc_soes.d 

OBJS += \
./Platform/SOES/ecat_slv.o \
./Platform/SOES/esc_coe.o \
./Platform/SOES/esc_eep.o \
./Platform/SOES/esc_eoe.o \
./Platform/SOES/esc_foe.o \
./Platform/SOES/esc_soes.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/SOES/%.o: ../Platform/SOES/%.c Platform/SOES/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

