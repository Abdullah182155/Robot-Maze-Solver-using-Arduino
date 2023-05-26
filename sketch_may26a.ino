#include <AFMotor.h>      // Include the Adafruit Motor Shield library
#include <SoftwareSerial.h>   // Include the SoftwareSerial library for Bluetooth communication

AF_DCMotor motor1(1);  // Initialize motor objects for each wheel
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

SoftwareSerial bluetooth(10, 11);  // RX, TX pins for Bluetooth module

char command;  // Variable to store incoming commands from Bluetooth

void setup() {
  motor1.setSpeed(255);  // Set the maximum speed of the motors (0-255)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  bluetooth.begin(9600);  // Set the baud rate for Bluetooth communication
}

void loop() {
  if (bluetooth.available()) {
    command = bluetooth.read();  // Read the incoming command from Bluetooth

    switch (command) {
      case 'F':  // Move forward
        forward();
        break;

      case 'B':  // Move backward
        backward();
        break;

      case 'L':  // Turn left
        left();
        break;

      case 'R':  // Turn right
        right();
        break;

      case 'S':  // Stop
        stop();
        break;
    }
  }
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
