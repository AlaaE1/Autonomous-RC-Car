# Autonomous-RC-Car

In this project we develop an autonomous RC car that can follow a predefined path using a line-following algorithm, avoid obstacles, and be manually controlled via Bluetooth. The car can switch between autonomous and manual modes seamlessly.


## Features

- **Obstacle Avoidance**: Ultrasonic sensor for obstacle detection. The car will stop or change direction when it detects an obstacle in its path, using the ultrasonic sensor to measure the distance to obstacles.
- **Bluetooth Control**: Bluetooth module (e.g., HC-05), DC motors, relays, transistors. Allow manual control of the car via a smartphone app through Bluetooth. Users can control the speed, direction, and mode (autonomous/manual) remotely.
- **Mode Switching (Autonomous vs. Manual)**: DIP switches, push buttons. Provide the user the ability to toggle between manual control and autonomous mode via a switch or Bluetooth command.
- **Status Display**: Character LCD, LEDs. Display the car’s current mode (obstacle avoidance, or Bluetooth control), speed, and obstacle detection status on the LCD.
- **Performance Monitoring and Data Logging**: Internal EEPROM. Log performance data such as speed,and number of obstacles avoided for later analysis and system improvements.
- **Motor Control**: DC motors for driving, relays for control. Use pulse-width modulation (PWM) for precise motor control to adjust speed smoothly.


## Hardware Used

- **Atmega32**
- **Bluetooth Module (HC-05)**
- **2 Dc Motors**
- **Ultrasonic Sensor**
- **2 IR Sensor**
- **LCD**
- **LEDs**
- **Push Button**
- **Batteries**
