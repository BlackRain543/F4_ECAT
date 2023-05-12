################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/SSC/src/aoeappl.c \
../Platform/SSC/src/bootmode.c \
../Platform/SSC/src/coeappl.c \
../Platform/SSC/src/diag.c \
../Platform/SSC/src/ecataoe.c \
../Platform/SSC/src/ecatappl.c \
../Platform/SSC/src/ecatcoe.c \
../Platform/SSC/src/ecateoe.c \
../Platform/SSC/src/ecatfoe.c \
../Platform/SSC/src/ecatslv.c \
../Platform/SSC/src/ecatsoe.c \
../Platform/SSC/src/emcy.c \
../Platform/SSC/src/eoeappl.c \
../Platform/SSC/src/fc1100hw.c \
../Platform/SSC/src/foeappl.c \
../Platform/SSC/src/mailbox.c \
../Platform/SSC/src/objdef.c \
../Platform/SSC/src/sdoserv.c 

C_DEPS += \
./Platform/SSC/src/aoeappl.d \
./Platform/SSC/src/bootmode.d \
./Platform/SSC/src/coeappl.d \
./Platform/SSC/src/diag.d \
./Platform/SSC/src/ecataoe.d \
./Platform/SSC/src/ecatappl.d \
./Platform/SSC/src/ecatcoe.d \
./Platform/SSC/src/ecateoe.d \
./Platform/SSC/src/ecatfoe.d \
./Platform/SSC/src/ecatslv.d \
./Platform/SSC/src/ecatsoe.d \
./Platform/SSC/src/emcy.d \
./Platform/SSC/src/eoeappl.d \
./Platform/SSC/src/fc1100hw.d \
./Platform/SSC/src/foeappl.d \
./Platform/SSC/src/mailbox.d \
./Platform/SSC/src/objdef.d \
./Platform/SSC/src/sdoserv.d 

OBJS += \
./Platform/SSC/src/aoeappl.o \
./Platform/SSC/src/bootmode.o \
./Platform/SSC/src/coeappl.o \
./Platform/SSC/src/diag.o \
./Platform/SSC/src/ecataoe.o \
./Platform/SSC/src/ecatappl.o \
./Platform/SSC/src/ecatcoe.o \
./Platform/SSC/src/ecateoe.o \
./Platform/SSC/src/ecatfoe.o \
./Platform/SSC/src/ecatslv.o \
./Platform/SSC/src/ecatsoe.o \
./Platform/SSC/src/emcy.o \
./Platform/SSC/src/eoeappl.o \
./Platform/SSC/src/fc1100hw.o \
./Platform/SSC/src/foeappl.o \
./Platform/SSC/src/mailbox.o \
./Platform/SSC/src/objdef.o \
./Platform/SSC/src/sdoserv.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/SSC/src/%.o: ../Platform/SSC/src/%.c Platform/SSC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Middlewares/ST/ARM/DSP/Inc -I../Platform/SOES -I../Platform/SOEM -I../Platform/SSC/Inc -I../Platform/SSC/port -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

