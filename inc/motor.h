#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f4xx_hal.h"

void PWM_Init(void);
void Motor_SetSpeed(uint8_t speed);

#endif
