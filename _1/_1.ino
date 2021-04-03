#include <LiquidCrystal.h>
//#include "DHT.h"
//#define DHTPIN 7     
//#define DHTTYPE DHT11   
//DHT dht(DHTPIN, DHTTYPE);
// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int sensorPin = A0;
int backLight = 13;    // pin 13 will control the backlight

void setup()
{
   Serial.begin(9600); 
  //Serial.println("arduino.ru.com"); 
  //dht.begin();
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  //lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  //lcd.clear();                  // start with a blank screen
  //lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  //lcd.print("hello");    // change this text to whatever you like. keep it clean.
  //lcd.setCursor(0,1);           // set cursor to column 0, row 1
  //lcd.print("hacktronics.com");
  
  // if you have a 4 row LCD, uncomment these lines to write to the bottom rows
  // and change the lcd.begin() statement above.
//  lcd.setCursor(0,2);         // set cursor to column 0, row 2
  //lcd.print("Row 3");
  //lcd.setCursor(0,3);         // set cursor to column 0, row 3
  //lcd.print("Row 4");
}
void loop ()
{
   //Serial.begin(9600); 
  Serial.println("arduino.ru.com"); 
 // dht.begin();
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();     // start with a blank screen
  delay (1000);
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("HELLO");   // change this text to whatever you like. keep it clean.
  delay (1000);
  lcd.setCursor(11,1);           // set cursor to column 0, row 1
  lcd.print("WORLD !!!");
  delay(1000);
   sensorValue = analogRead(sensorPin);  // считываем значение с фоторезистора
   
  if(sensorValue<500)
  {
    lsd.setCursor(12,0);
    lsd.print("day");
  } else  {
    lsd.setCursor(12,0);
     lsd.print("night");
  }
  
}
