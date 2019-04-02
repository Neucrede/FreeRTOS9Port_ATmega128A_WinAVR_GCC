# FreeRTOS9Port_ATmega128A_WinAVR_GCC
FreeRTOS 9.0.0 porting to AVR ATmega128 microcontrollers. To be used with WinAVR GCC toolchain only.

# Notes on FreeRTOSConfig.h
## configCPU_CLOCK_HZ
Normally configCPU_CLOCK_HZ will be set to F_CPU if the later is defined somewhere (usu. project settings),
otherwise configCPU_CLOCK_HZ is set to 16000000 i.e. max value for ATmega128A with 5V DC power.

## configUSE_TIMER0_FOR_TICKING
If configUSE_TIMER0_FOR_TICKING is set to 1, TIMER0 will be used to generate a tick interrupt, 
otherwise TIMER1 will be used if configUSE_TIMER0_FOR_TICKING is set to 0 or other values or not defined.

Value

configCPU_CLOCK_HZ / (configTICK_RATE_HZ * 1024) - 1

shall **NOT** exceed 255 when using TIMER0 as your tick source, if this requirement is not satisfied use TIMER1
instead by setting configUSE_TIMER0_FOR_TICKING to 0.

# Heap Management
See https://www.freertos.org/Documentation/161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf
Chapter2 for details.

Recommended using heap_4.c.

