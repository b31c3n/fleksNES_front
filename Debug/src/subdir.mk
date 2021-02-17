################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FLEKS.cpp \
../src/colors.cpp \
../src/display.cpp \
../src/stuff.cpp 

OBJS += \
./src/FLEKS.o \
./src/colors.o \
./src/display.o \
./src/stuff.o 

CPP_DEPS += \
./src/FLEKS.d \
./src/colors.d \
./src/display.d \
./src/stuff.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


