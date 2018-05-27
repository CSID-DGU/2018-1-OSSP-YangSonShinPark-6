################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2018-1-OSSP-YangSonShinPark-6-SHIN/main.cpp 

OBJS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/main.o 

CPP_DEPS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/main.d 


# Each subdirectory must supply rules for building sources it contributes
2018-1-OSSP-YangSonShinPark-6-SHIN/%.o: ../2018-1-OSSP-YangSonShinPark-6-SHIN/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/Library/Frameworks/SDL2_image.framework -I/Library/Frameworks/SDL2.framework -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


