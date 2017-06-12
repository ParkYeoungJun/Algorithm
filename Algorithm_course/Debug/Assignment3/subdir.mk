################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Assignment3/Dijkstra_Min_Heap.cpp \
../Assignment3/Refrigerator.cpp \
../Assignment3/Religion.cpp \
../Assignment3/heap.cpp 

OBJS += \
./Assignment3/Dijkstra_Min_Heap.o \
./Assignment3/Refrigerator.o \
./Assignment3/Religion.o \
./Assignment3/heap.o 

CPP_DEPS += \
./Assignment3/Dijkstra_Min_Heap.d \
./Assignment3/Refrigerator.d \
./Assignment3/Religion.d \
./Assignment3/heap.d 


# Each subdirectory must supply rules for building sources it contributes
Assignment3/%.o: ../Assignment3/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


