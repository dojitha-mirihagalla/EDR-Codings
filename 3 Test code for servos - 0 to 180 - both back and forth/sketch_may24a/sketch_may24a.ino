#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(5); // Connect servo 1 to digital pin 5
  servo2.attach(6); // Connect servo 2 to digital pin 6
}

void loop() {
  // Move servo 1 from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servo1.write(angle);
    delay(10);
  }
  
  delay(1000); // Pause for 1 second
  
  // Move servo 1 back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo1.write(angle);
    delay(10);
  }
  
  delay(1000); // Pause for 1 second
  
  // Move servo 2 from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servo2.write(angle);
    delay(10);
  }
  
  delay(1000); // Pause for 1 second
  
  // Move servo 2 back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo2.write(angle);
    delay(10);
  }
  
  delay(1000); // Pause for 1 second
}
