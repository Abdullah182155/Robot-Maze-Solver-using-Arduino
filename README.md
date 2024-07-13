# Arduino Line Following Car

This project is an Arduino-based line-following car. The car uses sensors to detect a line on the ground and adjusts its motors to follow the line. The car is controlled using an Arduino and the AFMotor library to interface with the motors.

## Getting Started

### Prerequisites

- Arduino board
- Motors (4)
- Line sensors (2)
- Motor driver shield
- AFMotor library

### Installing the AFMotor Library

1. Download the AFMotor library ZIP file from [here](https://github.com/adafruit/Adafruit-Motor-Shield-library/archive/refs/heads/master.zip).
2. Open the Arduino IDE.
3. Go to `Sketch` > `Include Library` > `Add .ZIP Library`.
4. Select the downloaded AFMotor ZIP file.

### Wiring

1. Attach the motor driver shield to the Arduino.
2. Connect the motors to the motor driver shield.
3. Connect the line sensors to analog pins `A0` (left sensor) and `A1` (right sensor).
4. Power the Arduino and motor driver shield as required.

### Code

Upload the following code to your Arduino:

```cpp
#include <AFMotor.h>

// Defining pins and variables
#define left A0
#define right A1

// Defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  // Declaring pin types
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  Serial.println(digitalRead(right));

  // Line detected by both sensors
  if (digitalRead(left) == 0 && digitalRead(right) == 0) {
    // Move forward
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
  }
  // Line detected by left sensor
  else if (digitalRead(left) == 0 && digitalRead(right) != 0) {
    // Turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
  }
  // Line detected by right sensor
  else if (digitalRead(left) != 0 && digitalRead(right) == 0) {
    // Turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }
  // Line detected by none
  else if (digitalRead(left) != 0 && digitalRead(right) != 0) {
    // Stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
  }
}






