################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gyro/inv_mpu.c \
../gyro/inv_mpu_dmp_motion_driver.c 

OBJS += \
./gyro/inv_mpu.o \
./gyro/inv_mpu_dmp_motion_driver.o 

C_DEPS += \
./gyro/inv_mpu.d \
./gyro/inv_mpu_dmp_motion_driver.d 


# Each subdirectory must supply rules for building sources it contributes
gyro/%.o: ../gyro/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


