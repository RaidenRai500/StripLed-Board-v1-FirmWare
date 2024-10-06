################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MiddleLayer/CC_ML.c 

OBJS += \
./Core/Src/MiddleLayer/CC_ML.o 

C_DEPS += \
./Core/Src/MiddleLayer/CC_ML.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MiddleLayer/%.o Core/Src/MiddleLayer/%.su Core/Src/MiddleLayer/%.cyclo: ../Core/Src/MiddleLayer/%.c Core/Src/MiddleLayer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MiddleLayer

clean-Core-2f-Src-2f-MiddleLayer:
	-$(RM) ./Core/Src/MiddleLayer/CC_ML.cyclo ./Core/Src/MiddleLayer/CC_ML.d ./Core/Src/MiddleLayer/CC_ML.o ./Core/Src/MiddleLayer/CC_ML.su

.PHONY: clean-Core-2f-Src-2f-MiddleLayer

