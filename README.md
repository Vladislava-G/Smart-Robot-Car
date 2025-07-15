# Smart Robot Car 🚗🤖

This Arduino-powered robot car features 4 driving modes:
- 🔲 Line Tracking (IR sensors)
- 🎮 IR Remote Control
- 📲 Bluetooth Control via HC-06
- 🛑 Obstacle Avoidance (ultrasonic + servo)

## 🔧 Components Used
- Arduino Uno
- IR Receiver + Line Tracking Sensors
- HC-SR04 Ultrasonic Sensor
- HC-06 Bluetooth Module
- SG90 Servo Motor
- L298N Motor Driver + DC Motors
- 1602 I2C LCD Module

## 💻 Functionality
Each mode is programmed using Arduino IDE:
- `line_tracking.ino`
- `obstacle_avoidance.ino`
- `IR_remote.ino`
- `bluetooth.ino`

The display shows real-time data: speed, direction, angle, distance.

## 📸 Wiring

![Wiring Diagram](images.jpg)

## 📂 How to Use
1. Upload code via Arduino IDE
2. Calibrate sensors (IR, ultrasonic)
3. Use remote, app or tracking line to activate mode

## 📜 License
MIT — Feel free to use, adapt, and learn!

