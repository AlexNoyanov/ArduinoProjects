#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int y = 0;
LiquidCrystal_I2C lcd(0x27,20,4);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

void setup()
{
  lcd.init();                            // Инициализация lcd             
  lcd.backlight(); 
 
 
}

void loop() {
  int x = 1;
  for( y=0; y<=4;y++){
    x = x+1;
    lcd.clear(); 
    lcd.setCursor(x, y);                   // Устанавливаем курсор в начало 2 строки
  lcd.print("npuBeT Mup!");              // Выводим текст 
  delay(300);
  } 
  
  
}

