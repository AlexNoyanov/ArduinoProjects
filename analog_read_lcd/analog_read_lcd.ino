// initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11,10 , 5, 4, 3, 2);
int sensorPin = A0;            // устанавливаем входную ногу для АЦП
unsigned int sensorValue = 0;  // цифровое значение фоторезистора

void setup() {
  // put your setup code here, to run once:
 // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
   // Print a message to the LCD.
//  lcd.print("hello, world!");
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  sensorValue = analogRead(sensorPin); 
lcd.setCursor(0,0);
lcd.print("HUMIDITY=");
lcd.print(sensorValue);
lcd.setCursor(0,1);
lcd.print("GRAPHITE SENSOR");

delay(100);
}
