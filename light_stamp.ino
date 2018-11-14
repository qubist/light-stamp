/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  drawstamp("WILL HARRIS-BRAUN", 123465, 1.2, 12.5, "2018-11-29", 4000);
  drawstamp("WILL HARRIS-BRAUN", 22323, 8, 7, "2018-11-29", 2000);
  drawstamp("WILL HARRIS-BRAUN", 123465, 1.2, 12.5, "2018-11-29", 500);
  drawstamp("WILL HARRIS-BRAUN", 123465, 1.2, 12.5, "2018-11-29", 100);

}

void loop() {
}

void drawstamp(String name, long enlarger, float fstop, float exposure, String date, int stamptime) {
  
  name = "WILL HARRIS-BRAUN";
  
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  


  display.print(name);
  display.print("\nEN" + String(enlarger));
  display.print(" F" + String(round(fstop))); // TODO: round floats to have no trailing zeros
  display.print(" EXP" + String(exposure)); // TODO ^
  display.print("\n" + date);


  display.display();
  delay(stamptime);
  display.clearDisplay();
  display.display();
}
