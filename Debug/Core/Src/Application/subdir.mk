################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Application/CC_APP.c \
../Core/Src/Application/CC_LEDPWM.c \
../Core/Src/Application/CC_SCHDLR.c \
../Core/Src/Application/CC_SM.c 

OBJS += \
./Core/Src/Application/CC_APP.o \
./Core/Src/Application/CC_LEDPWM.o \
./Core/Src/Application/CC_SCHDLR.o \
./Core/Src/Application/CC_SM.o 

C_DEPS += \
./Core/Src/Application/CC_APP.d \
./Core/Src/Application/CC_LEDPWM.d \
./Core/Src/Application/CC_SCHDLR.d \
./Core/Src/Application/CC_SM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Application/%.o Core/Src/Application/%.su Core/Src/Application/%.cyclo: ../Core/Src/Application/%.c Core/Src/Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Application

clean-Core-2f-Src-2f-Application:
	-$(RM) ./Core/Src/Application/CC_APP.cyclo ./Core/Src/Application/CC_APP.d ./Core/Src/Application/CC_APP.o ./Core/Src/Application/CC_APP.su ./Core/Src/Application/CC_LEDPWM.cyclo ./Core/Src/Application/CC_LEDPWM.d ./Core/Src/Application/CC_LEDPWM.o ./Core/Src/Application/CC_LEDPWM.su ./Core/Src/Application/CC_SCHDLR.cyclo ./Core/Src/Application/CC_SCHDLR.d ./Core/Src/Application/CC_SCHDLR.o ./Core/Src/Application/CC_SCHDLR.su ./Core/Src/Application/CC_SM.cyclo ./Core/Src/Application/CC_SM.d ./Core/Src/Application/CC_SM.o ./Core/Src/Application/CC_SM.su

.PHONY: clean-Core-2f-Src-2f-Application

