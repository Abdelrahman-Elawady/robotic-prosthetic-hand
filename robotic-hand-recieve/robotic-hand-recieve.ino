#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX, TX

Servo servos[5];
const int servoPins[] = {3, 5, 6, 9, 10}; // Servos connected to digital pins

void setup() {
  BTSerial.begin(9600);
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  if (BTSerial.available()) {
    String data = BTSerial.readStringUntil('\n');
    int flexValues[5];
    int index = 0;
    char *token = strtok(data.c_str(), ",");
    while (token != NULL && index < 5) {
      flexValues[index] = atoi(token);
      token = strtok(NULL, ",");
      index++;
    }
    for (int i = 0; i < 5; i++) {
      int angle = map(flexValues[i], 0, 1023, 0, 180); // Adjust mapping as needed
      servos[i].write(angle);
    }
  }
}