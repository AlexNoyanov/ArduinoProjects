
//  Simple tennis game
//  Use I2C display on A4 and A5

// screen
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);

 
// Joistick
const int POS_Y_PIN = 1;
const int POS_X_PIN = 0;
const int BUTTON_PIN = 7;
void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:

}

 
