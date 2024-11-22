#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX, TX

const int flexSensorPins[] = {A0, A1, A2, A3, A4}; // Flex sensors connected to analog pins

void setup() {
  BTSerial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(flexSensorPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int flexValue = analogRead(flexSensorPins[i]);
    BTSerial.print(flexValue);
    if (i < 4) BTSerial.print(","); // Separate values with commas
  }
  BTSerial.println();
  delay(100); // Adjust delay as needed
}