################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/Cpu.c \
../Generated_Code/Inhr1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/PwmLdd2.c \
../Generated_Code/TU1.c \
../Generated_Code/Term1.c \
../Generated_Code/Vectors.c \
../Generated_Code/boomVert.c \
../Generated_Code/leftSwitch.c \
../Generated_Code/rightSwitch.c \
../Generated_Code/stringVert.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Cpu.o \
./Generated_Code/Inhr1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/TU1.o \
./Generated_Code/Term1.o \
./Generated_Code/Vectors.o \
./Generated_Code/boomVert.o \
./Generated_Code/leftSwitch.o \
./Generated_Code/rightSwitch.o \
./Generated_Code/stringVert.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/Cpu.d \
./Generated_Code/Inhr1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/PwmLdd2.d \
./Generated_Code/TU1.d \
./Generated_Code/Term1.d \
./Generated_Code/Vectors.d \
./Generated_Code/boomVert.d \
./Generated_Code/leftSwitch.d \
./Generated_Code/rightSwitch.d \
./Generated_Code/stringVert.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/jc428352/Desktop/CC2511_AssignmentGroup/A2_Manual/Static_Code/PDD" -I"C:/Users/jc428352/Desktop/CC2511_AssignmentGroup/A2_Manual/Static_Code/IO_Map" -I"C:/Users/jc428352/Desktop/CC2511_AssignmentGroup/A2_Manual/Sources" -I"C:/Users/jc428352/Desktop/CC2511_AssignmentGroup/A2_Manual/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


