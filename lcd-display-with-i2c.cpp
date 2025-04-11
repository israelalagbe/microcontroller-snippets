#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (usually 0x27 or 0x3F) and dimensions (16 rows, 2 columns)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init();         
  lcd.backlight();
  
  lcd.setCursor(0, 0); // row,column
  lcd.print("Hello Israel!");
}


void loop() {
    // Display 'Hello Israel!' with animation from left 2 right
  for (int i = 0; i < 16; i++) {
    delay(200);
    lcd.scrollDisplayRight();
  }
}