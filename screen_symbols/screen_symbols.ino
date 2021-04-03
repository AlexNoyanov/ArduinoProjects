#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);

/* Описываем наш символ в виде массива битовых масок.
 * Каждый символ - это восемь масок по пять бит.
 * тут 8 - высота клетки экрана
 */
 byte  hurt [8] =
 {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
 };
byte man_with_hat[8] =
{
  B01110,
  B11111,
  B00000,
  B01010,
  B00100,
  B10001,
  B01110,
  B00000,
};


/* Объявляем объект нашего дисплея */
 //LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

void setup()
{
  lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.begin(20,4);
  /* Регистрируем собственный символы с кодом 1 */
  lcd.createChar(1, man_with_hat);
  lcd.createChar(2, hurt);
  /* Начинаем работу с дисплееем */

}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.printByte(2);

}
