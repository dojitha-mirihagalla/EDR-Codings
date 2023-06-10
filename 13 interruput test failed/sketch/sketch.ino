#include <IRremote.h>
#include <Servo.h>

Servo V_servo;
Servo H_servo;

const int IR_RECEIVE_PIN = 2;
const int V_SERVO_PIN = 5;  // servo 1
const int H_SERVO_PIN = 6;  // servo 2
const int dcMotorPin = 3;
const int redPin = A0;
const int greenPin = A1;
const int bluePin = A2;
const int buzzerPin = A3;

int dcmotor_speed = 100;  // DC motor speed (0 - 255)
int verticle_servo_angle = 60;
int horizontal_servo_angle = 90;

volatile bool irInterrupted = false;  // Interrupt flag
unsigned long debounceTime = 1000;    // Debounce delay in milliseconds
unsigned long lastIRTime = 0;         // Last time IR interrupt occurred

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);

  // Configure IR receiver pin for interrupt
  attachInterrupt(digitalPinToInterrupt(IR_RECEIVE_PIN), handleIRInterrupt, CHANGE);

  V_servo.attach(V_SERVO_PIN);
  H_servo.attach(H_SERVO_PIN);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(dcMotorPin, OUTPUT);

  // Turn on red color
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if debounce time has elapsed
  if (irInterrupted && (currentMillis - lastIRTime >= debounceTime)) {
    handleIRRemote();
    irInterrupted = false;  // Reset the interrupt flag
  }
  
  String msg = String(dcmotor_speed) + "  V: " + String(verticle_servo_angle) + " H: " + String(horizontal_servo_angle);
 // Serial.println(msg);
  //delay(400);
  // Update servo and motor control based on the current state
  V_servo.write(verticle_servo_angle);
  H_servo.write(horizontal_servo_angle);

  // Control the DC motor with dcmotor_speed value (analogWrite example)
  digitalWrite(dcMotorPin, dcmotor_speed);

  // Add any other code or functionality you want to run in the loop
  // ...

  // Update last IR time after debounce time
  if (currentMillis - lastIRTime >= debounceTime) {
    lastIRTime = currentMillis;
  }
}

void handleIRInterrupt() {
  irInterrupted = true;  // Set the interrupt flag
}

void handleIRRemote() {
   //Serial.println("Decoding IR signal...");
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);
   

    if (command == 69) {
      Serial.println("Pressed on button 1");
      dcmotor_speed = 100;
    } else if (command == 70) {
      Serial.println("Pressed on button 2");
      dcmotor_speed = 180;
    } else if (command == 71) {
      Serial.println("Pressed on button 3");
      dcmotor_speed = 255;
    } else if (command == 68) {
      Serial.println("Pressed on button 4");
      verticle_servo_angle = 120;
    } else if (command == 64) {
      Serial.println("Pressed on button 5");
      verticle_servo_angle = 90;
    } else if (command == 67) {
      Serial.println("Pressed on button 6");
      verticle_servo_angle = 60;
    } else if (command == 7) {
      Serial.println("Pressed on button 7");
      horizontal_servo_angle = 60;
    } else if (command == 21) {
      Serial.println("Pressed on button 8");
      horizontal_servo_angle = 90;
    } else if (command == 9) {
      Serial.println("Pressed on button 9");
      horizontal_servo_angle = 120;
    } else if (command == 25) {
      Serial.println("Pressed on button 0");
    } else if (command == 22) {
      Serial.println("Pressed on button *");
    } else if (command == 13) {
      Serial.println("Pressed on button #");
    } else if (command == 24) {
      Serial.println("Pressed on button up");
    } else if (command == 8) {
      Serial.println("Pressed on button left");
      dcmotor_speed-=50;
    } else if (command == 82) {
      Serial.println("Pressed on button down");
      
    } else if (command == 90) {
      Serial.println("Pressed on button right");
      dcmotor_speed= 50;
    } else if (command == 28) {
      Serial.println("Pressed on button OK");
      dcmotor_speed = 0;
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    } else {
      Serial.println("Button not recognized");
    }
  }
}

void beep() {
  digitalWrite(buzzerPin, HIGH);  // Turn the buzzer on
  delay(100);                     // Keep the buzzer on for 100 milliseconds
  digitalWrite(buzzerPin, LOW);   // Turn the buzzer off
}
