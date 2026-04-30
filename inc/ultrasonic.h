#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "stm32f4xx_hal.h"

// Trigger ultrasonic sensor
void Ultrasonic_Trigger(void);

// Read distance value
float Ultrasonic_Read(void);

#endif
