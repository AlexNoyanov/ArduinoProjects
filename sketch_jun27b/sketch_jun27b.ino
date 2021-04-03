
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 #include "DHT.h"
#define DHTPIN 12    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,4);   /* Задаем размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 16х4 ничего в коде изменять не требуется, cледует только заменить цифру отвечающую за количество сторок */

void setup()
{  dht.begin();
  pinMode(11,OUTPUT);
  // Выводим текст
}

void loop()
{float h = dht.readHumidity();
 float t = dht.readTemperature();
    int tt = t;
  int hh = h;
   int g = analogRead(A0);
Serial.println(g);
int l = analogRead(A1);
   lcd.init();                               
  lcd.backlight();                  
  lcd.print("Temp:"); 
lcd.print(tt);
lcd.print("C");
  lcd.setCursor(0,1);             
  lcd.print("Humd:");
  lcd.print(hh);
  lcd.print("%");
   lcd.setCursor(0,2);  
   lcd.print("Gas:");
  lcd.print(g);
  lcd.setCursor(0,3);  
   lcd.print("Svet:");
  lcd.print(l);
 int m;
  if (l< 500){
   lcd.setCursor(12,0);  
   lcd.print("Time:");
  lcd.print("DAY");
  }else{
    lcd.setCursor(10,0);  
   lcd.print("Time:");
  lcd.print("NIGHT");
  }
  
  lcd.setCursor(15,0);  
  // lcd.print("Svet:");
  //lcd.print(mode);
  delay(500);
}

