# Vehicle_To_Vehicle_Communication_And_CAN_Data_Logger
Overview :
This project implements a real-time embedded system for vehicle-to-vehicle (V2V) communication using a multi-ECU architecture.
The system enables vehicles to exchange data and automatically adjust speed based on obstacle detection, improving road safety.

Key Features:
•	SPI communication between STM32 and ESP32
•	ESP-NOW based wireless V2V communication
•	CAN communication between ECUs
•	Ultrasonic sensor for obstacle detection
•	PWM-based DC motor speed control
•	FreeRTOS-based task management
•	CAN Data Logging for monitoring system parameters

System Architecture:
STM32-1 → SPI → ESP32-1 → ESP-NOW → ESP32-2 → SPI → STM32-2 → CAN → STM32-3
Working Flow
1. Front vehicle ECU (STM32-1) generates speed and steering data
2. Data is sent to ESP32 via SPI
3. ESP32 transmits data wirelessly using ESP-NOW
4. Receiver ESP32 forwards data to STM32-2
5. STM32-2 reads ultrasonic sensor data and applies safety logic
6. Control commands are sent via CAN to STM32-3
7. STM32-3 controls motor speed using PWM and activates alerts

My Contribution:
•	Implemented CAN communication (configuration, framing, filtering)
•	Developed interrupt-based SPI communication
•	Integrated ultrasonic sensor using timer input capture
•	Implemented PWM-based motor control
•	Designed FreeRTOS task structure and inter-task communication
•	Performed system integration and debugging

Technologies Used:
•	Embedded C
•	STM32 (ARM Cortex-M)
•	ESP32 (ESP-NOW)
•	FreeRTOS
•	SPI, CAN Protocols
•	Ultrasonic Sensor (HC-SR04)
•	PWM, Timers

Project Structure:
src/   - Source files (SPI, CAN, Motor, RTOS, Ultrasonic)
inc/ - Header files
README.md – Project documentation

Future Improvements:
•	Replace ultrasonic sensor with radar
•	Add GPS-based vehicle tracking
•	Implement cloud data logging
•	Upgrade to AUTOSAR architecture

Conclusion:
This project demonstrates strong understanding of embedded systems, real-time communication, multi-ECU automotive architecture, and hardware-software integration.
