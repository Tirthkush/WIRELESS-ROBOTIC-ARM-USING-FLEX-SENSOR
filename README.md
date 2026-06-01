# WIRELESS-ROBOTIC-ARM-USING-FLEX-SENSOR

## Overview

This project demonstrates a wireless gesture-controlled robotic arm using flex sensors, ESP32 microcontrollers, and servo motors. Human finger movements are captured using flex sensors and transmitted wirelessly via ESP-NOW to a receiver unit that controls multiple servos through a PCA9685 PWM driver.

The project explores real-time human-machine interaction, wireless embedded communication, sensor interfacing, and robotic actuation.

---

## Features

* Real-time gesture detection using flex sensors
* Wireless communication using ESP-NOW
* ESP32-based transmitter and receiver architecture
* PCA9685-based multi-servo control
* Battery-powered portable transmitter
* Low-latency device-to-device communication

---

## Hardware Used

* 2 × ESP32 Development Boards
* Flex Sensors
* Servo Motors
* PCA9685 PWM Driver
* 18650 Li-ion Batteries
* Buck Converter (5V Regulation)
* Breadboard / Prototyping Hardware
* Connecting Wires

---

## System Architecture

### Transmitter Unit

* Reads analog values from flex sensors
* Converts finger movements into sensor data
* Transmits data wirelessly using ESP-NOW

### Receiver Unit

* Receives sensor data from transmitter
* Maps sensor values to servo angles
* Controls servo motors through PCA9685 using I2C communication

This separation simplifies the system and allows independent optimization of sensing and actuation modules.

---

## Working Principle

1. Flex sensors detect finger bending.
2. Resistance changes are converted into voltage variations.
3. ESP32 reads the sensor values using ADC.
4. Data is transmitted wirelessly using ESP-NOW.
5. Receiver ESP32 processes incoming data.
6. Sensor values are mapped to servo positions.
7. PCA9685 generates PWM signals.
8. Servo motors replicate the detected hand movements.

---

## Communication Protocols

### ESP-NOW

* Direct ESP32-to-ESP32 communication
* No Wi-Fi router required
* Low latency
* Suitable for real-time control systems

### I2C

Used between ESP32 and PCA9685:

* SDA – Data Line
* SCL – Clock Line

Allows multiple servo channels to be controlled using only two communication lines.

---

## Challenges Encountered

### Flex Sensor Damage

During prototyping, hot glue was used to secure the flex sensors. This negatively affected the sensing layer and reduced sensor performance, making the final glove-based implementation unreliable.

### Servo Jitter

Minor servo jitter was observed due to power supply fluctuations and noise introduced by breadboard connections.

### Analog Noise

Small variations in ADC readings resulted in occasional fluctuations in servo movement.

---

## Results

The prototype successfully demonstrated:

* Wireless sensor data transmission
* Real-time gesture recognition
* Servo-based robotic motion control
* ESP-NOW communication between ESP32 devices

Although the final glove assembly required further refinement, the core wireless control system was successfully validated through prototype testing.

---

## Key Learnings

* ESP-NOW communication
* ADC data acquisition
* Servo motor control
* PCA9685 interfacing
* I2C communication
* Power management for embedded systems
* Rapid prototyping and debugging

---

## Future Improvements

* Custom glove design for sensor mounting
* PCB implementation
* Signal filtering for smoother movement
* Improved calibration algorithms
* 3D-printed robotic hand structure
* Portable rechargeable system

---

## Applications

* Prosthetic Hand Systems
* Human-Machine Interfaces
* Robotics Control Systems
* Industrial Automation
* Teleoperation Systems

---

## Author

Tirth Kushwaha

Electronics & Telecommunication Engineering

Embedded Systems | IoT | Robotics
