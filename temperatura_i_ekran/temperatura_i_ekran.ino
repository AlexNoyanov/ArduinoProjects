#include "DHT.h"
#define DHTPIN 7     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600); 
  Serial.println("arduino.ru.com"); 
  dht.begin();
}
void loop() {  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("BJLA>I<HOCTb = "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("TEMIIEPATyPA = "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}
