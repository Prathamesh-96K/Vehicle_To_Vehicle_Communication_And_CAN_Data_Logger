#include "can.h"

CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
uint8_t rxData[8];
uint32_t TxMailbox;

void CAN_Init(void)
{
    MX_CAN1_Init();

    TxHeader.StdId = 0x123;
    TxHeader.DLC = 1;
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.RTR = CAN_RTR_DATA;

    HAL_CAN_Start(&hcan);

    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void CAN_Send(uint8_t *data)
{
    HAL_CAN_AddTxMessage(&hcan, &TxHeader, data, &TxMailbox);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, rxData);
}
