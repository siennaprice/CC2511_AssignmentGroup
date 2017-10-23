################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/OurMethods.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/OurMethods.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/OurMethods.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/pag.itt/Desktop/CC2511_AssignmentGroup/A2/Static_Code/PDD" -I"C:/Users/pag.itt/Desktop/CC2511_AssignmentGroup/A2/Static_Code/IO_Map" -I"C:/Users/pag.itt/Desktop/CC2511_AssignmentGroup/A2/Sources" -I"C:/Users/pag.itt/Desktop/CC2511_AssignmentGroup/A2/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


