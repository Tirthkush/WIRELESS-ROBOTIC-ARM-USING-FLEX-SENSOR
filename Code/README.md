# Code Files

This folder contains the firmware used in the Wireless Gesture-Controlled Robotic Arm project.

## Transmitter Code

* Reads analog values from the flex sensors.
* Processes finger movement data.
* Transmits sensor readings wirelessly using ESP-NOW.

## Receiver Code

* Receives sensor data from the transmitter ESP32.
* Maps sensor values to corresponding servo angles.
* Communicates with the PCA9685 PWM driver using I2C.
* Controls servo motors to replicate hand movements.

The code was developed using the Arduino framework and uploaded using Arduino IDE.
