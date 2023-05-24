#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremote.h>

#define OLED_ADDR 0x3C // OLED display address (may vary depending on the module)
#define IR_RECEIVE_PIN 2 // Digital pin connected to IR receiver

Adafruit_SSD1306 display(-1); // Use -1 for the default address
IRrecv irReceiver(IR_RECEIVE_PIN);
decode_results irResults;

void setup() {
  // Initialize I2C communication
  Wire.begin();

  // Initialize OLED display with the specified address
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);

  // Initialize IR receiver
  irReceiver.enableIRIn();
  
  // Clear the display buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  // Check if an IR signal is received
  if (irReceiver.decode(&irResults)) {
    // Clear the display buffer
    display.clearDisplay();

    // Get the received IR command
    unsigned long command = irResults.value;

    // Convert the command to a string
    String commandString = String(command, HEX);

    // Print the received command on the OLED display
    display.setCursor(0, 0);
    display.print("Command: ");
    display.println(commandString);
    
    // Display the updated buffer contents
    display.display();

    // Resume IR receiver
    irReceiver.resume();
  }
}
