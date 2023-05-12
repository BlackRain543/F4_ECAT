################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/EtherCAT/src/aoeappl.c \
../Platform/EtherCAT/src/bootmode.c \
../Platform/EtherCAT/src/coeappl.c \
../Platform/EtherCAT/src/diag.c \
../Platform/EtherCAT/src/ecataoe.c \
../Platform/EtherCAT/src/ecatappl.c \
../Platform/EtherCAT/src/ecatcoe.c \
../Platform/EtherCAT/src/ecateoe.c \
../Platform/EtherCAT/src/ecatfoe.c \
../Platform/EtherCAT/src/ecatslv.c \
../Platform/EtherCAT/src/ecatsoe.c \
../Platform/EtherCAT/src/emcy.c \
../Platform/EtherCAT/src/eoeappl.c \
../Platform/EtherCAT/src/fc1100hw.c \
../Platform/EtherCAT/src/foeappl.c \
../Platform/EtherCAT/src/mailbox.c \
../Platform/EtherCAT/src/objdef.c \
../Platform/EtherCAT/src/sdoserv.c 

C_DEPS += \
./Platform/EtherCAT/src/aoeappl.d \
./Platform/EtherCAT/src/bootmode.d \
./Platform/EtherCAT/src/coeappl.d \
./Platform/EtherCAT/src/diag.d \
./Platform/EtherCAT/src/ecataoe.d \
./Platform/EtherCAT/src/ecatappl.d \
./Platform/EtherCAT/src/ecatcoe.d \
./Platform/EtherCAT/src/ecateoe.d \
./Platform/EtherCAT/src/ecatfoe.d \
./Platform/EtherCAT/src/ecatslv.d \
./Platform/EtherCAT/src/ecatsoe.d \
./Platform/EtherCAT/src/emcy.d \
./Platform/EtherCAT/src/eoeappl.d \
./Platform/EtherCAT/src/fc1100hw.d \
./Platform/EtherCAT/src/foeappl.d \
./Platform/EtherCAT/src/mailbox.d \
./Platform/EtherCAT/src/objdef.d \
./Platform/EtherCAT/src/sdoserv.d 

OBJS += \
./Platform/EtherCAT/src/aoeappl.o \
./Platform/EtherCAT/src/bootmode.o \
./Platform/EtherCAT/src/coeappl.o \
./Platform/EtherCAT/src/diag.o \
./Platform/EtherCAT/src/ecataoe.o \
./Platform/EtherCAT/src/ecatappl.o \
./Platform/EtherCAT/src/ecatcoe.o \
./Platform/EtherCAT/src/ecateoe.o \
./Platform/EtherCAT/src/ecatfoe.o \
./Platform/EtherCAT/src/ecatslv.o \
./Platform/EtherCAT/src/ecatsoe.o \
./Platform/EtherCAT/src/emcy.o \
./Platform/EtherCAT/src/eoeappl.o \
./Platform/EtherCAT/src/fc1100hw.o \
./Platform/EtherCAT/src/foeappl.o \
./Platform/EtherCAT/src/mailbox.o \
./Platform/EtherCAT/src/objdef.o \
./Platform/EtherCAT/src/sdoserv.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/EtherCAT/src/%.o: ../Platform/EtherCAT/src/%.c Platform/EtherCAT/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/EtherCAT/Inc -I../Platform/EtherCAT/port -I../Platform/SOES -I../Platform/SOEM -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

