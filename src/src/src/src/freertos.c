#include "freertos.h"
#include "spi.h"
#include "can.h"
#include "motor.h"
#include "ultrasonic.h"

// Task handles
osThreadId commTaskHandle;
osThreadId decisionTaskHandle;
osThreadId actuatorTaskHandle;

// Queues for data sharing
osMessageQId v2vQueueHandle;
osMessageQId controlQueueHandle;

// SPI buffer
uint8_t spi_data[8];

// Communication Task (SPI + CAN)
void CommTask(void const * argument)
{
    for(;;)
    {
        // Receive data from ESP32
        SPI_Receive_IT(spi_data, 8);

        // Send speed to decision task
        osMessagePut(v2vQueueHandle, spi_data[0], 0);

        osDelay(10);
    }
}

// Decision Task (Sensor + Logic)
void DecisionTask(void const * argument)
{
    uint8_t speed;
    float distance;

    for(;;)
    {
        // Get data from communication task
        osEvent evt = osMessageGet(v2vQueueHandle, osWaitForever);

        if(evt.status == osEventMessage)
        {
            speed = evt.value.v;
        }

        // Read ultrasonic distance
        distance = Ultrasonic_Read();

        // Safety logic
        if(distance < 20)
            speed = speed / 2;

        // Send to actuator task
        osMessagePut(controlQueueHandle, speed, 0);

        // Send CAN message
        CAN_Send(&speed);

        osDelay(20);
    }
}

// Actuator Task (Motor control)
void ActuatorTask(void const * argument)
{
    uint8_t speed;

    for(;;)
    {
        // Receive speed value
        osEvent evt = osMessageGet(controlQueueHandle, osWaitForever);

        if(evt.status == osEventMessage)
        {
            speed = evt.value.v;

            // Update motor speed
            Motor_SetSpeed(speed);
        }
    }
}

void MX_FREERTOS_Init(void)
{
    // Create queues
    osMessageQDef(v2vQueue, 10, uint8_t);
    v2vQueueHandle = osMessageCreate(osMessageQ(v2vQueue), NULL);

    osMessageQDef(controlQueue, 10, uint8_t);
    controlQueueHandle = osMessageCreate(osMessageQ(controlQueue), NULL);

    // Create tasks
    osThreadDef(commTask, CommTask, osPriorityHigh, 0, 128);
    commTaskHandle = osThreadCreate(osThread(commTask), NULL);

    osThreadDef(decisionTask, DecisionTask, osPriorityAboveNormal, 0, 128);
    decisionTaskHandle = osThreadCreate(osThread(decisionTask), NULL);

    osThreadDef(actuatorTask, ActuatorTask, osPriorityNormal, 0, 128);
    actuatorTaskHandle = osThreadCreate(osThread(actuatorTask), NULL);
}
