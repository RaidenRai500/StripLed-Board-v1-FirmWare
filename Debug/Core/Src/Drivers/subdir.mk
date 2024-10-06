################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Drivers/CC_BOARDLED.c \
../Core/Src/Drivers/CC_CAN.c \
../Core/Src/Drivers/CC_DIPSW.c \
../Core/Src/Drivers/CC_IPC.c \
../Core/Src/Drivers/CC_LED.c \
../Core/Src/Drivers/CC_SERIAL.c \
../Core/Src/Drivers/CC_TMR.c 

OBJS += \
./Core/Src/Drivers/CC_BOARDLED.o \
./Core/Src/Drivers/CC_CAN.o \
./Core/Src/Drivers/CC_DIPSW.o \
./Core/Src/Drivers/CC_IPC.o \
./Core/Src/Drivers/CC_LED.o \
./Core/Src/Drivers/CC_SERIAL.o \
./Core/Src/Drivers/CC_TMR.o 

C_DEPS += \
./Core/Src/Drivers/CC_BOARDLED.d \
./Core/Src/Drivers/CC_CAN.d \
./Core/Src/Drivers/CC_DIPSW.d \
./Core/Src/Drivers/CC_IPC.d \
./Core/Src/Drivers/CC_LED.d \
./Core/Src/Drivers/CC_SERIAL.d \
./Core/Src/Drivers/CC_TMR.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drivers/%.o Core/Src/Drivers/%.su Core/Src/Drivers/%.cyclo: ../Core/Src/Drivers/%.c Core/Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drivers

clean-Core-2f-Src-2f-Drivers:
	-$(RM) ./Core/Src/Drivers/CC_BOARDLED.cyclo ./Core/Src/Drivers/CC_BOARDLED.d ./Core/Src/Drivers/CC_BOARDLED.o ./Core/Src/Drivers/CC_BOARDLED.su ./Core/Src/Drivers/CC_CAN.cyclo ./Core/Src/Drivers/CC_CAN.d ./Core/Src/Drivers/CC_CAN.o ./Core/Src/Drivers/CC_CAN.su ./Core/Src/Drivers/CC_DIPSW.cyclo ./Core/Src/Drivers/CC_DIPSW.d ./Core/Src/Drivers/CC_DIPSW.o ./Core/Src/Drivers/CC_DIPSW.su ./Core/Src/Drivers/CC_IPC.cyclo ./Core/Src/Drivers/CC_IPC.d ./Core/Src/Drivers/CC_IPC.o ./Core/Src/Drivers/CC_IPC.su ./Core/Src/Drivers/CC_LED.cyclo ./Core/Src/Drivers/CC_LED.d ./Core/Src/Drivers/CC_LED.o ./Core/Src/Drivers/CC_LED.su ./Core/Src/Drivers/CC_SERIAL.cyclo ./Core/Src/Drivers/CC_SERIAL.d ./Core/Src/Drivers/CC_SERIAL.o ./Core/Src/Drivers/CC_SERIAL.su ./Core/Src/Drivers/CC_TMR.cyclo ./Core/Src/Drivers/CC_TMR.d ./Core/Src/Drivers/CC_TMR.o ./Core/Src/Drivers/CC_TMR.su

.PHONY: clean-Core-2f-Src-2f-Drivers

