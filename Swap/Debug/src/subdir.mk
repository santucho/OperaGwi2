################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/administradorDeSwap.c \
../src/sockets.c \
../src/swapArranque.c 

OBJS += \
./src/administradorDeSwap.o \
./src/sockets.o \
./src/swapArranque.o 

C_DEPS += \
./src/administradorDeSwap.d \
./src/sockets.d \
./src/swapArranque.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


