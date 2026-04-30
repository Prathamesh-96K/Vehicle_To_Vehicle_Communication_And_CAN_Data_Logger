# Vehicle_To_Vehicle_Communication_And_CAN_Data_Logger
________________________________________
 Overview
This project implements vehicle-to-vehicle communication using CAN protocol and logs data for analysis in real-time embedded systems.
________________________________________
System Architecture
STM32-1 → SPI → ESP32-1 → ESP-NOW → ESP32-2 → SPI → STM32-2 → CAN → STM32-3
________________________________________
Working Flow
1. Front vehicle ECU (STM32-1) generates speed and steering data
2. Data is sent to ESP32 via SPI
3. ESP32 transmits data wirelessly using ESP-NOW
4. Receiver ESP32 forwards data to STM32-2
5. STM32-2 reads ultrasonic sensor data and applies safety logic
6. Control commands are sent via CAN to STM32-3
7. STM32-3 controls motor speed using PWM and activates alerts
________________________________________
 My Contributions
•	Implemented CAN communication (configuration, framing, filtering)
•	Developed interrupt-based SPI communication
•	Integrated ultrasonic sensor using timer input capture
•	Implemented PWM-based motor control
•	Designed FreeRTOS task structure and inter-task communication
•	Performed complete system integration and debugging
________________________________________
Technologies Used
•	Embedded C
•	STM32 (ARM Cortex-M)
•	ESP32 (ESP-NOW)
•	FreeRTOS
•	SPI, CAN Protocols
•	Ultrasonic Sensor 
•	PWM, Timers
________________________________________
 Project Structure
src/   → Source files (SPI, CAN, Motor, RTOS, Ultrasonic)
inc/   → Header files
README.md → Project documentation
________________________________________
 Features
•	Real-time CAN communication
•	Data logging system
•	Multi-tasking using FreeRTOS
•	Sensor integration and motor control
________________________________________
 Future Improvements
•	Replace ultrasonic sensor with radar
•	Add GPS-based vehicle tracking
•	Implement cloud-based data logging
•	Upgrade to AUTOSAR architecture
________________________________________
 Conclusion
  This project demonstrates strong understanding of:
•	Embedded systems
•	Real-time communication
•	Multi-ECU automotive architecture
•	Hardware-software integration
________________________________________
 Author
Prathamesh Gatkal


