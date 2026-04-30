#include "stm32f4xx_hal.h"
#include "freertos.h"

int main(void)
{
    HAL_Init();

    // Configure system clock
    SystemClock_Config();

    // Initialize peripherals
    MX_GPIO_Init();
    MX_SPI1_Init();
    MX_CAN1_Init();
    MX_TIM1_Init();
    MX_TIM2_Init();

    // Initialize RTOS
    MX_FREERTOS_Init();

    // Start scheduler
    osKernelStart();

    while (1)
    {
        // Should never reach here
    }
}
