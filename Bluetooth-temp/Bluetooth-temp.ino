//  Bluetooth temperature sensor
//  By Alex Noyanov
//  15 December 2015
//       _____
//     /    |\ \
//    |  \  | \ |
//    |   \ | / |
//    |    \|/  |
//    |    /|\  |
//    |   / | \ |
//    |  /  | / |
//    |     |/  |
//     \ _____ / 
//
#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>

#include "DHT.h"
#define DHTPIN 8     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

//  For bluetooth:
int cnt = 0;    // счетчик
char incomingByte;
String buffer;
//  Bluetooth pins:
SoftwareSerial mySerial(10, 11); // RX, TX
RTC_DS1307 rtc;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 // Starting informtion:
 Serial.println("Started");  // выводим надпись 
 mySerial.begin(9600);
 mySerial.println("Hello BB from Arduino");

//  ====Bluetooth Initializing:====
  
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();  
  if (! rtc.isrunning()) {
  Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//    =====Temperature Part:=======
float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print(h);
    Serial.println(t);
  }


//  Bluetooth:
/*
// read from monitor to send to Bluetoth
   if (Serial.available() > 0) {
      buffer = "";
      while (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;
      }
      mySerial.print(">>From Computer:");
      mySerial.println(buffer);
      Serial.print("<<From computer:");
      Serial.println(buffer);
   }
      // say what you got:
      Serial.print("I received: ");
      Serial.println(buffer);
   
*/

//  Answer on input Bluetooth information:
    if(buffer.indexOf("Hello") == 0) {
      Serial.println("World!");      
    }
    
}
