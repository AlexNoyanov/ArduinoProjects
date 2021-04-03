#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>

int r1Pin = 13;
int r2Pin = 12;

char incomingByte;
String buffer;

SoftwareSerial mySerial(10, 11); // RX, TX

RTC_DS1307 rtc;
 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);         // Serial port begin 
   Serial.println("Started");  // Printing on serial port

   mySerial.begin(9600);
   mySerial.println("Hello BB from Arduino");

   
  pinMode(r1Pin, OUTPUT);
  pinMode(r2Pin, OUTPUT);

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

     // Reading data from bluetooth: 
     if (Serial.available() > 0) {          // If bluetooth send something:
      buffer = "";                          // Get this data to this buffer 
      while (Serial.available() > 0) {      // And while bluetooth reciving some data
        // read the incoming byte:          // Save symbol to incomingByte
        incomingByte = Serial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;           // Buffer plus this symbol
      }      
      mySerial.print(">>Bluetooth send message:");
      mySerial.println(buffer);                 // Print message on bluetooth 
      Serial.print("<<Arduino recive message:");
      Serial.println(buffer);                   // Print message on arduino
      } 

         
   // read from Bluetooth incomming data to show on Monitor
   if (mySerial.available() > 0) {
      buffer = "";
      while (mySerial.available() > 0) {
        // read the incoming byte:
        incomingByte = mySerial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;
      }
      // say what you got:
      Serial.print("I received: ");
      Serial.println(buffer);
    } else {
      Serial.println("---");      
    }

    // Comands for bluetooth data:
      if(buffer.indexOf("on") == 0) {  // If input data is "on"
      Serial.println("Relay 1 is ON");
      digitalWrite(r1Pin, HIGH);
    }

      if(buffer.indexOf("off") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(r1Pin, LOW);
    }
    
  delay(2000);    
}
