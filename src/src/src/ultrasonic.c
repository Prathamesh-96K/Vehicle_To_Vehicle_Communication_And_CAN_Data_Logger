#include "ultrasonic.h"

// Timer handle for input capture
extern TIM_HandleTypeDef htim2;

// Variables for echo timing
uint32_t ic_val1 = 0;
uint32_t ic_val2 = 0;
uint8_t is_first_capture = 0;
float distance = 0;

void Ultrasonic_Trigger(void)
{
    // Send trigger pulse
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    HAL_Delay(1);  // ~10us
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}

// Input capture callback (echo measurement)
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        if (is_first_capture == 0)
        {
            // Capture rising edge
            ic_val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            is_first_capture = 1;

            // Switch to falling edge
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
        }
        else
        {
            // Capture falling edge
            ic_val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);

            // Calculate time difference
            uint32_t diff = ic_val2 - ic_val1;

            // Convert to distance (cm)
            distance = (diff * 0.034) / 2;

            is_first_capture = 0;

            // Reset to rising edge
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
        }
    }
}

float Ultrasonic_Read(void)
{
    Ultrasonic_Trigger();
    HAL_Delay(50);  // wait for measurement
    return distance;
}
