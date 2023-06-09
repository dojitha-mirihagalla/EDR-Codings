#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int IR_RECEIVE_PIN = 2;
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

}

void loop() {
    printOnOLED();
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1:
        {


          dcMotorSpeed = 100;  // Set DC motor speed to 100 (example value)

          break;
        }
      case IR_BUTTON_2:
        {

          dcMotorSpeed = 200;  // Set DC motor speed to 200 (example value)
          Serial.println("pressed 2 -> set DC speed 200");
          break;
        }
      case IR_BUTTON_3:
        {

          dcMotorSpeed = 255;  // Set DC motor speed to maximum
          Serial.println("pressed 3 -> set DC speed 255");
          break;
        }
      case IR_BUTTON_4:
        {

          verticle_sevo_angle = 60;
          Serial.println("pressed 4-> V_angle 60");
          break;
        }
      case IR_BUTTON_5:
        {

          verticle_sevo_angle = 90;
          Serial.println("pressed 5-> V_angle 90");
          break;
        }
      case IR_BUTTON_6:
        {

          verticle_sevo_angle = 120;
          Serial.println("pressed 6-> V_angle 120");
          break;
        }
      case IR_BUTTON_7:
        {

          horizontal_sevo_angle = 60;
          Serial.println("pressed 7-> V_angle 60");
          break;
        }
      case IR_BUTTON_8:
        {

          horizontal_sevo_angle = 90;
          Serial.println("pressed 8-> V_angle 90");
          break;
        }
      case IR_BUTTON_9:
        {

          horizontal_sevo_angle = 120;
          Serial.println("pressed 9-> V_angle 120");
          break;
        }
      default:
        {
          Serial.println("Button not recognized");
          break;
        }
    }
  }

  /*   // Update servo and motor control based on the current state
  verticalServo.write(verticalServoAngle);
  horizontalServo.write(horizontalServoAngle);
  // Control the DC motor with dcMotorSpeed value (analogWrite example)
  analogWrite(dcMotorPin, dcMotorSpeed); */
}

void printOnOLED() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 5);
  String msg1 = "Motor Speed   " + String(dcMotorSpeed);
  display.println(msg1);
  display.setCursor(0, 15);
  String msg2 = "Verticle Angle  " + String(verticle_sevo_angle);
  display.println(msg2);
  display.setCursor(0, 25);
  String msg3 = "Horizintal Angle   " + String(horizontal_sevo_angle);
  display.println(msg3);
  display.display();
}
