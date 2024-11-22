#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0, 1); // RX AND TX

const int flexSensorPin = A0; // Flex sensor connected to analog pin A0

void setup() {
    BTSerial.begin(9600); // Ensure baud rate matches receiver
    pinMode(flexSensorPin, INPUT);
}

void loop() {
    int flexValue = analogRead(flexSensorPin);
    int angle = map(flexValue, 0, 1023, 0, 180); // Adjust mapping as needed
    BTSerial.println(angle); // Send angle as a string
    delay(100); // Adjust delay as needed
}
