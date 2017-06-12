################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Assignment4/a.c 

CPP_SRCS += \
../Assignment4/Cliquet.cpp \
../Assignment4/Jop.cpp \
../Assignment4/Max_Clique.cpp \
../Assignment4/Scales.cpp \
../Assignment4/good_s.cpp \
../Assignment4/jopt.cpp \
../Assignment4/t.cpp 

OBJS += \
./Assignment4/Cliquet.o \
./Assignment4/Jop.o \
./Assignment4/Max_Clique.o \
./Assignment4/Scales.o \
./Assignment4/a.o \
./Assignment4/good_s.o \
./Assignment4/jopt.o \
./Assignment4/t.o 

C_DEPS += \
./Assignment4/a.d 

CPP_DEPS += \
./Assignment4/Cliquet.d \
./Assignment4/Jop.d \
./Assignment4/Max_Clique.d \
./Assignment4/Scales.d \
./Assignment4/good_s.d \
./Assignment4/jopt.d \
./Assignment4/t.d 


# Each subdirectory must supply rules for building sources it contributes
Assignment4/%.o: ../Assignment4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Assignment4/%.o: ../Assignment4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


