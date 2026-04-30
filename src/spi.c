#include "spi.h"

SPI_HandleTypeDef hspi1;

void SPI_Init(void)
{
    MX_SPI1_Init();
}

void SPI_Receive_IT(uint8_t *data, uint16_t size)
{
    HAL_SPI_Receive_IT(&hspi1, data, size);
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if (hspi->Instance == SPI1)
    {
        // Data received
    }
}
