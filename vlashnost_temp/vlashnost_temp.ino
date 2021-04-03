
#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600); 
  Serial.println("arduino.ru.com"); 
  dht.begin();
}
void loop() {  
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else { 
    int tt = t;
    int hh = h;
    Serial.print("HUMIDITY = "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("TEMPERATURE = "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}
