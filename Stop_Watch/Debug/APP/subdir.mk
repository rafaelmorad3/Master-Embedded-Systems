################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Stop_Watch.c 

OBJS += \
./APP/Stop_Watch.o 

C_DEPS += \
./APP/Stop_Watch.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Master-Embedded-Systems/Stop_Watch/APP" -I"D:/Master-Embedded-Systems/Stop_Watch/HAL" -I"D:/Master-Embedded-Systems/Stop_Watch/Inc" -I"D:/Master-Embedded-Systems/Stop_Watch/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/Stop_Watch.cyclo ./APP/Stop_Watch.d ./APP/Stop_Watch.o ./APP/Stop_Watch.su

.PHONY: clean-APP

