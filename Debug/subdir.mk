################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CAniRenderer.cpp \
../CGraphicsManager.cpp \
../CImageRenderer.cpp \
../CManager.cpp \
../main.cpp 

OBJS += \
./CAniRenderer.o \
./CGraphicsManager.o \
./CImageRenderer.o \
./CManager.o \
./main.o 

CPP_DEPS += \
./CAniRenderer.d \
./CGraphicsManager.d \
./CImageRenderer.d \
./CManager.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


