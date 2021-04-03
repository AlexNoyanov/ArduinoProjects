//  I2C Sympols LCD
//  9 November 2015
//  Alex Noyanov

#include "Wire.h" 
#include "LiquidCrystal_I2C.h"
 
uint8_t bukva_P[8] = {0x1F,0x11,0x11,0x11,0x11,0x11,0x11};
uint8_t bukva_Ya[8] = {
  B01111,
  B10001,
  B10001,
  B01111,
  B00101,
  B01001,
  B10001
};
const uint8_t BYTE = '*';
uint8_t bukva_L[8] = {0x3,0x7,0x5,0x5,0xD,0x9,0x19};
uint8_t bukva_Mz[8] = {0x10,0x10,0x10,0x1E,0x11,0x11,0x1E};
uint8_t bukva_I[8] = {0x11,0x13,0x13,0x15,0x19,0x19,0x11};
 
LiquidCrystal_I2C lcd(0x27,16,2);  // устанавливаем адрес 0x27, и дисплей 16 символов в 2 строки (16х2)
 
void setup()
{
  lcd.init();                      // инициализация LCD 
  lcd.backlight();                 // включаем подсветку
  lcd.clear();                     // очистка дисплея
   
  lcd.createChar(0, bukva_P);      // создаем символ и записываем его в память LCD
  lcd.createChar(1, bukva_Ya);
  lcd.createChar(2, bukva_L);
  lcd.createChar(3, bukva_Mz);
  lcd.createChar(4, bukva_I);
  lcd.home();
  lcd.print(0, BYTE);              // отображаем символ в памяти LCD по 0 адресу
  lcd.print("A");
  lcd.print(1, BYTE);
  lcd.print(2, BYTE);  
  lcd.print(3, BYTE);
  lcd.print("H");
  lcd.print(4, BYTE);
  lcd.print("K");  
}
 
void loop()
{
   
}
