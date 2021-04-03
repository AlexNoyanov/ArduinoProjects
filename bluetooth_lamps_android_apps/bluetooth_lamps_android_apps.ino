
// Arduino Bluetooth controll from Android 
// Use HC-05 Bluetooth module 
// And Bluetooth Control Lamp Aplication in Google Play

#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>

// Lamps pins:
int l1 = 13;
int l2 = 12;
int l3 = 11;
int l4 = 10;
int l5 = 9;
int l6 = 8;
int l7 = 7; 
int l8 = 6;

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

   
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);

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

    //    Turning ON lamps:
          if(buffer.indexOf("1") == 0) {  // If input data is "on"
      Serial.println("Lamp 1 is ON");
      digitalWrite(l1, HIGH); 
    }
          if(buffer.indexOf("2") == 0) {  
      Serial.println("Lamp 2 is ON");
      digitalWrite(l2, HIGH); 
    }
           if(buffer.indexOf("3") == 0) {  
      Serial.println("Lamp 3 is ON");
      digitalWrite(l3, HIGH); 
    }
           if(buffer.indexOf("4") == 0) {  
      Serial.println("Lamp 4 is ON");
      digitalWrite(l4, HIGH); 
    }
           if(buffer.indexOf("5") == 0) {  
      Serial.println("Lamp 5 is ON");
      digitalWrite(l5, HIGH); 
    }
          if(buffer.indexOf("6") == 0) {  
      Serial.println("Lamp 6 is ON");
      digitalWrite(l6, HIGH); 
    }
          if(buffer.indexOf("7") == 0) {  
      Serial.println("Lamp 7 is ON");
      digitalWrite(l7, HIGH); 
    }
          if(buffer.indexOf("8") == 0) {  
      Serial.println("Lamp 8 is ON");
      digitalWrite(l8, HIGH); 
    }
    // Turning OFF lamps:
          if(buffer.indexOf("A") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l1, LOW);
    }
          if(buffer.indexOf("B") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l2, LOW);
    }
              if(buffer.indexOf("C") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l3, LOW);
    }

              if(buffer.indexOf("D") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l4, LOW);
    }

              if(buffer.indexOf("E") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l5, LOW);
    }

              if(buffer.indexOf("F") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l6, LOW);
    }
              if(buffer.indexOf("G") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(l7, LOW);
    }

              if(buffer.indexOf("H") == 0) { 
      Serial.println("Relay 1 is OFF");
      digitalWrite(l8, LOW);
    }

    // Turn ON ALL:
              if(buffer.indexOf("9") == 0) {  
      Serial.println("ALL is ON");
      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(l3, HIGH);
      digitalWrite(l4, HIGH);
      digitalWrite(l5, HIGH);
      digitalWrite(l6, HIGH);
      digitalWrite(l7, HIGH);
      digitalWrite(l8, HIGH);
    }
              if(buffer.indexOf("I") == 0) { 
      Serial.println("ALL is OFF");
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(l3, LOW);
      digitalWrite(l4, LOW);
      digitalWrite(l5, LOW);
      digitalWrite(l6, LOW);
      digitalWrite(l7, LOW);
      digitalWrite(l8, LOW);
    }   
  delay(100);    
}
