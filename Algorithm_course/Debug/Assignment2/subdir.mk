################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Assignment2/Bargain.cpp \
../Assignment2/Bargaint.cpp \
../Assignment2/Koi_bead.cpp \
../Assignment2/SCV.cpp \
../Assignment2/koit.cpp 

OBJS += \
./Assignment2/Bargain.o \
./Assignment2/Bargaint.o \
./Assignment2/Koi_bead.o \
./Assignment2/SCV.o \
./Assignment2/koit.o 

CPP_DEPS += \
./Assignment2/Bargain.d \
./Assignment2/Bargaint.d \
./Assignment2/Koi_bead.d \
./Assignment2/SCV.d \
./Assignment2/koit.d 


# Each subdirectory must supply rules for building sources it contributes
Assignment2/%.o: ../Assignment2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


