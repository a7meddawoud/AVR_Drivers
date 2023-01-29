################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/_7Segma/_7Segma.c 

OBJS += \
./HAL/_7Segma/_7Segma.o 

C_DEPS += \
./HAL/_7Segma/_7Segma.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/_7Segma/%.o: ../HAL/_7Segma/%.c HAL/_7Segma/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


