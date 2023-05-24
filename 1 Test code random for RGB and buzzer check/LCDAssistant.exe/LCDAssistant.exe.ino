// Pin assignments
const int buzzerPin = A3;
const int redPin = A0;
const int greenPin = A1;
const int bluePin = A2;

// Delay between each blink
const int blinkDelay = 500;

// Tone frequency for the buzzer
const int buzzerFrequency = 1000;

void setup() {
  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Generate a random color
  int redValue = random(256);
  int greenValue = random(256);
  int blueValue = random(256);

  // Set the RGB LED color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Turn on the buzzer
  tone(buzzerPin, buzzerFrequency);

  // Delay for the specified time
  delay(blinkDelay);

  // Turn off the buzzer
  noTone(buzzerPin);

  // Delay for the specified time
  delay(blinkDelay);
}
