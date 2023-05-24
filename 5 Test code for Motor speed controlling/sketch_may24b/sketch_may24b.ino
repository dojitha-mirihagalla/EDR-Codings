const int motorPin = 3;
const int speed = 128; // Set initial speed value (0-255)

void setup() {
  pinMode(motorPin, OUTPUT);
}
void loop()
{
    analogWrite(motorPin, 0);
  delay(500);

    analogWrite(motorPin, 200);
  delay(500);


    analogWrite(motorPin, 250);
  delay(500);
}
