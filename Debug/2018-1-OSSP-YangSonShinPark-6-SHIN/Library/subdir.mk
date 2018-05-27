################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CAnimationRenderer.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGameManager.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGraphicsManager.cpp \
../2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CImageRenderer.cpp 

OBJS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CAnimationRenderer.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGameManager.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGraphicsManager.o \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CImageRenderer.o 

CPP_DEPS += \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CAnimationRenderer.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGameManager.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CGraphicsManager.d \
./2018-1-OSSP-YangSonShinPark-6-SHIN/Library/CImageRenderer.d 


# Each subdirectory must supply rules for building sources it contributes
2018-1-OSSP-YangSonShinPark-6-SHIN/Library/%.o: ../2018-1-OSSP-YangSonShinPark-6-SHIN/Library/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/Library/Frameworks/SDL2_image.framework -I/Library/Frameworks/SDL2.framework -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


