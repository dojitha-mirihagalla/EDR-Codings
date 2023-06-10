#include <IRremote.h>
#include <Servo.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_ADDR 0x3C  // OLED display address (may vary depending on the module)

Adafruit_SSD1306 display(-1);  // Use -1 for the default address


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


int dcMotorSpeed = 100;  // DC motor speed (0 - 255)
int verticle_sevo_angle = 60;
int horizontal_sevo_angle = 90;

void setup() {
  Wire.begin();

  // Initialize OLED display with the specified address
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);

  // Clear the display buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Print "Hello, World!" on the OLED display
  display.setCursor(0, 0);
  display.println("Hello,");
  display.setCursor(0, 10);
  display.println("World!");

  // Display the updated buffer contents
  display.display();




  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
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
  String msg = String(dcMotorSpeed) + "  V: " + String(verticle_sevo_angle) + " H: " + String(horizontal_sevo_angle);
  Serial.println(msg);
  // Update servo and motor control based on the current state
  V_servo.write(verticle_sevo_angle);
  H_servo.write(verticle_sevo_angle);
  // Control the DC motor with dcMotorSpeed value (analogWrite example)
  digitalWrite(dcMotorPin, dcMotorSpeed);




  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    //Serial.println(command);

    if (command == 69) {
      Serial.println("Pressed on button 1");
      dcMotorSpeed = 100;
    } else if (command == 70) {
      Serial.println("Pressed on button 2");
      dcMotorSpeed = 200;
    } else if (command == 71) {
      Serial.println("Pressed on button 3");
      dcMotorSpeed = 255;
    } else if (command == 68) {
      Serial.println("Pressed on button 4");
      verticle_sevo_angle = 120;
    } else if (command == 64) {
      Serial.println("Pressed on button 5");
      verticle_sevo_angle = 90;
    } else if (command == 67) {
      Serial.println("Pressed on button 6");
      verticle_sevo_angle = 60;
    } else if (command == 7) {
      Serial.println("Pressed on button 7");
      horizontal_sevo_angle = 60;
    } else if (command == 21) {
      Serial.println("Pressed on button 8");
      horizontal_sevo_angle = 90;
    } else if (command == 9) {
      Serial.println("Pressed on button 9");
      horizontal_sevo_angle = 120;
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
    } else if (command == 82) {
      Serial.println("Pressed on button down");
    } else if (command == 90) {
      Serial.println("Pressed on button right");
    } else if (command == 28) {
      Serial.println("Pressed on button OK");
      dcMotorSpeed = 0;
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
