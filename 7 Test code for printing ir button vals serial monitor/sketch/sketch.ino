#include <IRremote.h>
const int IR_RECEIVE_PIN = 2;


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


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);

}
void loop() {
  if (IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;
      //Serial.println(command);
      switch (command) {
        case IR_BUTTON_1:
          {
            Serial.println("Pressed on button 1");
            break;
          }
        case IR_BUTTON_2:
          {
            Serial.println("Pressed on button 2");
            break;
          }
        case IR_BUTTON_3:
          {
            Serial.println("Pressed on button 3");
            break;
          }
        case IR_BUTTON_4:
          {
            Serial.println("Pressed on button 4");
            break;
          }
        case IR_BUTTON_5:
          {
            Serial.println("Pressed on button 5");
            break;
          }
        case IR_BUTTON_6:
          {
            Serial.println("Pressed on button 6");
            break;
          }
        case IR_BUTTON_7:
          {
            Serial.println("Pressed on button 7");
            break;
          }
        case IR_BUTTON_8:
          {
            Serial.println("Pressed on button 8");
            break;
          }
        case IR_BUTTON_9:
          {
            Serial.println("Pressed on button 9");
            break;
          }
        case IR_BUTTON_0:
          {
            Serial.println("Pressed on button 0");
            break;
          }
        case IR_BUTTON_star:
          {
            Serial.println("Pressed on button *");
            break;
          }
        case IR_BUTTON_hash:
          {
            Serial.println("Pressed on button #");
            break;
          }
        case IR_BUTTON_up:
          {
            Serial.println("Pressed on button up");
            break;
          }
        case IR_BUTTON_left:
          {
            Serial.println("Pressed on button left");
            break;
          }
        case IR_BUTTON_down:
          {
            Serial.println("Pressed on button down");
            break;
          }
        case IR_BUTTON_right:
          {
            Serial.println("Pressed on button right");
            break;
          }
        case IR_BUTTON_ok:
          {
            Serial.println("Pressed on button OK");
            break;
          }
        default:
          {
            Serial.println("Button not recognized");
            break;
          }
      }
    }
  
}




