#ifndef SPI_H
#define SPI_H

#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

void SPI_Init(void);
void SPI_Receive_IT(uint8_t *data, uint16_t size);

#endif
