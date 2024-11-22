#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(0, 1); // Use different pins for SoftwareSerial
Servo servo;

const int servoPin = 9; // Servo connected to digital pin 9

void setup() {
    BTSerial.begin(9600); // Ensure baud rate matches transmitter
    servo.attach(servoPin);
}

void loop() {
    if (BTSerial.available()) {
        String data = BTSerial.readStringUntil('\n'); // Read data as a string
        int angle = data.toInt(); // Convert string to integer
        servo.write(angle); // Move servo to the angle
        delay(100); // Adjust delay as needed
    }
}
