//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void Print(char* str){

   //char* str;
  for(int i = 0; i < strlen(str); i++) {
    lcd.print(str[i]);
  }
}
void setup()
{
  lcd.init();                      // initialize the lcd 
 Print("World!");
  // Print a message to the LCD.
  lcd.backlight();
  /*
  lcd.setCursor(2,4);
  char* str = "Hello, World!";
  for(int i = 0; i < strlen(str); i++) {
    lcd.print(str[i]);
  }
  */
}

void loop()
{
}
