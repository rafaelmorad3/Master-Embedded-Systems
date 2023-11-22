################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -c -I"D:/Master-Embedded-Systems/Bootloader_CAN/APP" -I"D:/Master-Embedded-Systems/Bootloader_CAN/HAL" -I"D:/Master-Embedded-Systems/Bootloader_CAN/Inc" -I"D:/Master-Embedded-Systems/Bootloader_CAN/LIB" -I"D:/Master-Embedded-Systems/Bootloader_CAN/Src" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f103c8tx.d ./Startup/startup_stm32f103c8tx.o

.PHONY: clean-Startup

