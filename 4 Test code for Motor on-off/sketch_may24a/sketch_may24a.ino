const int motorPin = 3;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Rotate the motor clockwise
  digitalWrite(motorPin, HIGH);
  delay(1000); // Wait for 1 second

  // Stop the motor
  digitalWrite(motorPin, LOW);
  delay(1000); // Wait for 1 second

  // Rotate the motor counterclockwise
  digitalWrite(motorPin, HIGH);
  delay(1000); // Wait for 1 second

  // Stop the motor
  digitalWrite(motorPin, LOW);
  delay(1000); // Wait for 1 second
}
