################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXT1/EXT1_prog.c 

OBJS += \
./MCAL/EXT1/EXT1_prog.o 

C_DEPS += \
./MCAL/EXT1/EXT1_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXT1/%.o: ../MCAL/EXT1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\HAL\LCD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\MCAL\TIMER" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\APP" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\HAL\KEYPAD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\HAL\LED" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\HAL\PB" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\HAL\SSD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\LIB" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\MCAL\DIO" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\MCAL\EXT1" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\MCAL\GIE" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\ICU\MCAL\TIMER1" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


