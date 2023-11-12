################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ROFA_RTOS/Inc/CortexMX_OS_Porting.c \
../ROFA_RTOS/Inc/RTOS_FIFO.c \
../ROFA_RTOS/Inc/Scheduler.c 

OBJS += \
./ROFA_RTOS/Inc/CortexMX_OS_Porting.o \
./ROFA_RTOS/Inc/RTOS_FIFO.o \
./ROFA_RTOS/Inc/Scheduler.o 

C_DEPS += \
./ROFA_RTOS/Inc/CortexMX_OS_Porting.d \
./ROFA_RTOS/Inc/RTOS_FIFO.d \
./ROFA_RTOS/Inc/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
ROFA_RTOS/Inc/%.o ROFA_RTOS/Inc/%.su ROFA_RTOS/Inc/%.cyclo: ../ROFA_RTOS/Inc/%.c ROFA_RTOS/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/GPIO/HAL" -I"D:/GPIO/Inc" -I"D:/GPIO/Src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ROFA_RTOS-2f-Inc

clean-ROFA_RTOS-2f-Inc:
	-$(RM) ./ROFA_RTOS/Inc/CortexMX_OS_Porting.cyclo ./ROFA_RTOS/Inc/CortexMX_OS_Porting.d ./ROFA_RTOS/Inc/CortexMX_OS_Porting.o ./ROFA_RTOS/Inc/CortexMX_OS_Porting.su ./ROFA_RTOS/Inc/RTOS_FIFO.cyclo ./ROFA_RTOS/Inc/RTOS_FIFO.d ./ROFA_RTOS/Inc/RTOS_FIFO.o ./ROFA_RTOS/Inc/RTOS_FIFO.su ./ROFA_RTOS/Inc/Scheduler.cyclo ./ROFA_RTOS/Inc/Scheduler.d ./ROFA_RTOS/Inc/Scheduler.o ./ROFA_RTOS/Inc/Scheduler.su

.PHONY: clean-ROFA_RTOS-2f-Inc

