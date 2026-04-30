#ifndef CAN_H
#define CAN_H

#include "stm32f4xx_hal.h"

extern CAN_HandleTypeDef hcan;

void CAN_Init(void);
void CAN_Send(uint8_t *data);

#endif
