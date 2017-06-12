################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Assignment1/Color.cpp \
../Assignment1/Quad.cpp 

OBJS += \
./Assignment1/Color.o \
./Assignment1/Quad.o 

CPP_DEPS += \
./Assignment1/Color.d \
./Assignment1/Quad.d 


# Each subdirectory must supply rules for building sources it contributes
Assignment1/%.o: ../Assignment1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


