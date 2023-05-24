// Motor pin assignment
const int motorPin = 5;

// Minimum and maximum speed values
const int minSpeed = 0;
const int maxSpeed = 255;

// Speed increment value
const int speedIncrement = 5;

// Delay between speed changes
const int speedDelay = 50;

// Current motor speed
int currentSpeed = minSpeed;

// Flag to indicate speed direction (1: increasing, -1: decreasing)
int speedDirection = 1;

void setup() {
  // Set motor pin as output
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Update the motor speed
  currentSpeed += speedDirection * speedIncrement;

  // Check if the speed has reached the minimum or maximum value
  if (currentSpeed <= minSpeed) {
    currentSpeed = minSpeed;
    speedDirection = 1;  // Change direction to increasing
  } else if (currentSpeed >= maxSpeed) {
    currentSpeed = maxSpeed;
    speedDirection = -1;  // Change direction to decreasing
  }

  // Set the motor speed
  analogWrite(motorPin, currentSpeed);

  // Delay for the specified time
  delay(speedDelay);
}
