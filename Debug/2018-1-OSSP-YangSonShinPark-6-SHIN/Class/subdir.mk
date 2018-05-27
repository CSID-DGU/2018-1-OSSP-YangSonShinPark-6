################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CChar.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CGame.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CItem.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CMenu.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/COption.cpp 

OBJS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CChar.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CGame.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CItem.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CMenu.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/COption.o 

CPP_DEPS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CChar.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CGame.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CItem.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/CMenu.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Class/COption.d 


# Each subdirectory must supply rules for building sources it contributes
2018-1-OSSP-YangSonShinPark-6-SHIN/Class/%.o: ../2018-1-OSSP-YangSonShinPark-6-SHIN/Class/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/Library/Frameworks/SDL2_image.framework -I/Library/Frameworks/SDL2.framework -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


