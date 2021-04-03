
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  // put your setup code here, to run once:
  lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.begin(20,4);
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TESTING. it WORKING!");
  lcd.setCursor(1,1);
  lcd.print(" Hello world!");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
