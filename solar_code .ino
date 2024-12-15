#include <Servo.h>

int servoPin1 = 9; // Pin for the first servo motor
int servoPin2 = 10; // Pin for the second servo motor

Servo servo1; // Servo object for the first motor
Servo servo2; // Servo object for the second motor

unsigned long currentMillis = 0; // Stores the current time
unsigned long previousMillis = 0; // Stores the last time action occurred
const unsigned long interval = 30000; // 30 seconds cycle
const unsigned long runTime = 10000;  // 10 seconds for servo operation

bool isRunning = false; // Tracks if servos are running

void setup() {
    servo1.attach(servoPin1); // Attach the first servo to pin 9
    servo2.attach(servoPin2); // Attach the second servo to pin 10
}

void loop() {
    currentMillis = millis(); // Get the current time

    // Check if 30 seconds have passed since the last cycle
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis; // Update the previous time
        isRunning = true; // Start the servo operation
    }

    // If running, operate the servos
    if (isRunning) {
        unsigned long operationStartTime = millis(); // Capture the start time
        while (millis() - operationStartTime < runTime) {
            // Move servos from 0 to 180 degrees
            for (int angle = 0; angle <= 180; angle++) {
                servo1.write(angle);
                servo2.write(angle);
                delay(5);
            }

            // Move servos back from 180 to 0 degrees
            for (int angle = 180; angle >= 0; angle--) {
                servo1.write(angle);
                servo2.write(angle);
                delay(5);
            }
        }
        isRunning = false; // Stop the servo operation after 10 seconds
    }
}