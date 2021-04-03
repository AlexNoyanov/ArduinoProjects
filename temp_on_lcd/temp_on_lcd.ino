#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11 ,10 , 5, 4, 3, 2);
#include "DHT.h"
#define DHTPIN 13    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
int fan = 13;
void setup() {
  Serial.begin(9600); 
  Serial.println("arduino.ru.com"); 
  dht.begin();
  pinMode(13,OUTPUT);
}
void loop() {  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);   
    Serial.print("humidity = "); 
    lcd.print(h);
    Serial.println(" %\t");
    Serial.print("TEMIIEPATyPA = "); 
     lcd.setCursor(0,1);
    lcd.println(t);
    Serial.println(" *C");
    
  }
  if  (isnan(t) || t < 25) {
    digitalWrite( fan, HIGH);
  }else {
    digitalWrite(fan,LOW);
  }
  delay(1000);
}
