#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // подключаем экран на эти пины
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT); // датчик А0 подключам на А0 на ардуине
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int g = analogRead(A0);     // считываем с датчика
 lcd.clear();                  // start with a blank screen
 lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
 lcd.print("Gas:");   // change this text to whatever you like. keep it clean.
  lcd.setCursor(5,0);
   lcd.print (g);
Serial.println(g);
if (g<70) 
{   lcd.setCursor(2,1);           // set cursor to column 0, row 1
     lcd.print("NORMAL AIR");
}
/*
  if (g>70) 
{   lcd.setCursor(10,1);           // set cursor to column 0, row 1
     lcd.print("CO2");
}

if (g>100) 
{   lcd.setCursor(0,1);           // set cursor to column 0, row 1
     lcd.print("WARNING!CO2!");
}
if (g>200) 
{   lcd.setCursor(0,1);           // set cursor to column 0, row 1
     lcd.print("WARNING!FLAMMABLE GAS!");
}
*/
while( g > 500)
{int a = 500+g;
  tone(8,a);
}
if (g<500){
noTone(8);
}
delay(100);
}
