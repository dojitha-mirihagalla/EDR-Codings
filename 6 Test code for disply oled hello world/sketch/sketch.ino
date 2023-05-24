#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR 0x3C // OLED display address (may vary depending on the module)

Adafruit_SSD1306 display(-1); // Use -1 for the default address

void setup() {
  // Initialize I2C communication
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
}

void loop() {
  // Nothing to do here
}
