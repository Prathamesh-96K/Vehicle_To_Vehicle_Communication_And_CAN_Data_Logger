#include "motor.h"

// Timer handle (PWM)
extern TIM_HandleTypeDef htim1;

void PWM_Init(void)
{
    // Start PWM on channel
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void Motor_SetSpeed(uint8_t speed)
{
    // Convert speed to duty cycle
    uint32_t duty = speed * 10;

    // Update PWM duty
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);
}
