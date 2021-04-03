

#include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);
// #include "DHT.h"
//#define DHTPIN 12    
//#define DHTTYPE DHT11   
//DHT dht(DHTPIN, DHTTYPE);

 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(A1,INPUT);
 //  dht.begin();
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.begin(9600); 
  lcd.begin(20,4);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();
// float h = dht.readHumidity();
 // float t = dht.readTemperature();
//    int tt = t;
//  int hh = h;
  // int g = analogRead(A0);
//Serial.println(g);

lcd.setCursor(0,0);     // set cursor to column 0, row 0 (the first row)
  lcd.print("TEMP:"); 
 // lcd.print(tt);   // change this text to whatever you like. keep it clean.
   lcd.print("C");
    lcd.setCursor(0,1); 
   lcd.print("HUM:"); 
// lcd.print(hh);
delay(300);
}
