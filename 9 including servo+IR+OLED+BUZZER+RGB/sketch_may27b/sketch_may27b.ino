#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
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


int dcMotorSpeed = 0;  // DC motor speed (0 - 255)
int verticle_sevo_angle = 60;
int horizontal_sevo_angle = 90;


#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
#define IR_BUTTON_6 67
#define IR_BUTTON_7 7
#define IR_BUTTON_8 21
#define IR_BUTTON_9 9
#define IR_BUTTON_0 25
#define IR_BUTTON_star 22
#define IR_BUTTON_hash 13
#define IR_BUTTON_up 24
#define IR_BUTTON_left 8
#define IR_BUTTON_down 82
#define IR_BUTTON_right 90
#define IR_BUTTON_ok 28

#define OLED_ADDR 0x3C         // OLED display address (may vary depending on the module)
Adafruit_SSD1306 display(-1);  // Use -1 for the default address

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  printOnOLED("Air Plus");
  delay(200);
  V_servo.attach(V_SERVO_PIN);
  H_servo.attach(H_SERVO_PIN);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Turn on red color
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    // Turn on green color
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    beep();
    switch (command) {
      case IR_BUTTON_1:
        {

         /*  printOnOLED("Slow");
          dcMotorSpeed = 100;  // Set DC motor speed to 100 (example value)
 */
          break;
        }
      case IR_BUTTON_2:
        {
          /* printOnOLED("Medium");
          dcMotorSpeed = 200;  // Set DC motor speed to 200 (example value) */
          Serial.println("pressed 2 -> set DC speed 200");
          break;
        }
      case IR_BUTTON_3:
        {
          /* printOnOLED("High");
          dcMotorSpeed = 255;  // Set DC motor speed to maximum */
          Serial.println("pressed 3 -> set DC speed 255");
          break;
        }
      case IR_BUTTON_4:
        {
         /*  printOnOLED("down");
          verticle_sevo_angle = 120; */
          Serial.println("pressed 4-> V_angle 60");
          break;
        }
      case IR_BUTTON_5:
        {
         /*  printOnOLED("middle");
          verticle_sevo_angle = 90; */
          Serial.println("pressed 5-> V_angle 90");
          break;
        }
      case IR_BUTTON_6:
        {
         /*  printOnOLED("up");
          verticle_sevo_angle = 60; */
          Serial.println("pressed 6-> V_angle 120");
          break;
        }
      case IR_BUTTON_7:
        {
        /*   printOnOLED("left");
          horizontal_sevo_angle = 60; */
          Serial.println("pressed 7-> V_angle 60");
          break;
        }
      case IR_BUTTON_8:
        {
          /* printOnOLED("middle");
          horizontal_sevo_angle = 90; */
          Serial.println("pressed 8-> V_angle 90");
          break;
        }
      case IR_BUTTON_9:
        {
         /*  printOnOLED("right");
          horizontal_sevo_angle = 120; */
          Serial.println("pressed 9-> V_angle 120");
          break;
        }
      case IR_BUTTON_ok:
        {

          printOnOLED("OFF");
         /*  dcMotorSpeed = 0;  // Set DC motor speed to 100 (example value)
          // Turn on red color
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW); */

          break;
        }
      default:
        {
          Serial.println("Button not recognized");
          break;
        }
    }
    delay(100);
  }

  // Update servo and motor control based on the current state
  V_servo.write(verticle_sevo_angle);
  H_servo.write(verticle_sevo_angle);
  // Control the DC motor with dcMotorSpeed value (analogWrite example)
  analogWrite(dcMotorPin, dcMotorSpeed);
}

void printOnOLED(const char* message) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  display.println(message);
  display.display();
  delay(100);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 2);
  String msg1 = "Motor Speed   " + String(dcMotorSpeed);
  display.println(msg1);
  display.setCursor(0, 12);
  String msg2 = "Verticle Angle  " + String(verticle_sevo_angle);
  display.println(msg2);
  display.setCursor(0, 22);
  String msg3 = "Horizintal Angle " + String(horizontal_sevo_angle);
  display.println(msg3);
  display.display();
}



void beep() {
  digitalWrite(buzzerPin, HIGH);  // Turn the buzzer on
  delay(100);                     // Keep the buzzer on for 100 milliseconds
  digitalWrite(buzzerPin, LOW);   // Turn the buzzer off
}