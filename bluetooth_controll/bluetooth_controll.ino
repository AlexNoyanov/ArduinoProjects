#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>


int cnt = 0;    // счетчик
char incomingByte;
String buffer;

const int PIN_RED    = 13;
const int PIN_YELLOW = 8;
const int PIN_GREEN  = 9;

const int PIN_TONE = 6;

SoftwareSerial mySerial(10, 11); // RX, TX

RTC_DS1307 rtc;
 
void setup() {

   Serial.begin(9600);   // инициализация порта
   Serial.println("Started");  // выводим надпись

   mySerial.begin(9600);
   mySerial.println("Hello BB from Arduino");


  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);

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
   cnt++;
   //Serial.print("Hello BB from Arduino! Counter:");  // выводим надпись
   //Serial.println(cnt);    // выводим значение счетчика и переводим на новую строку
   delay(1000);   // ждем 1 секунду

  // read from monitor to send to Bluetoth
   if (Serial.available() > 0) {
      buffer = "";
      while (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;
      }
      mySerial.print(">>Papa said:");
      mySerial.println(buffer);
      Serial.print("<<Papa said:");
      Serial.println(buffer);
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

    if(buffer.indexOf("all on") == 0) {
      Serial.println("ALL lights on");
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_YELLOW, HIGH);      
      digitalWrite(PIN_GREEN, HIGH);      
    }
    if(buffer.indexOf("red on") == 0) {
      Serial.println("RED light on");
      digitalWrite(PIN_RED, HIGH);
    }
    if(buffer.indexOf("green on") == 0) {
      Serial.println("GREEN light on");
      digitalWrite(PIN_GREEN, HIGH);      
    }
    if(buffer.indexOf("yellow on") == 0) {
      Serial.println("YELLOW light on");
      digitalWrite(PIN_YELLOW, HIGH);      
    }
    if(buffer.indexOf("all off") == 0) {
      Serial.println("ALL lights on");
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_YELLOW, LOW);      
      digitalWrite(PIN_GREEN, LOW);      
    }
    if(buffer.indexOf("red off") == 0) {
      Serial.println("RED light off");
      digitalWrite(PIN_RED, LOW);
    }
    if(buffer.indexOf("green off") == 0) {
      Serial.println("GREEN light off");
      digitalWrite(PIN_GREEN, LOW);      
    }
    if(buffer.indexOf("yellow off") == 0) {
      Serial.println("YELLOW light off");
      digitalWrite(PIN_YELLOW, LOW);      
    }
    if(buffer.indexOf("tone off") == 0) {
      noTone(PIN_TONE);
      Serial.println("Tone off");
    } else if(buffer.indexOf("tone") == 0) {
      String strTone = buffer.substring(5);
      int freq = strTone.toInt();
      tone(PIN_TONE, freq);
      Serial.print("Tone at ");
      Serial.print(freq, DEC);
      Serial.println("Hz");
    }

    if(buffer.indexOf("time") == 0) {
      DateTime now = rtc.now();
    
      mySerial.print(now.year(), DEC);
      mySerial.print('/');
      mySerial.print(now.month(), DEC);
      mySerial.print('/');
      mySerial.print(now.day(), DEC);
      mySerial.print(' ');
      mySerial.print(now.hour(), DEC);
      mySerial.print(':');
      mySerial.print(now.minute(), DEC);
      mySerial.print(':');
      mySerial.print(now.second(), DEC);
      mySerial.println();    
      Serial.print("time is ");
      Serial.print(now.year(), DEC);
      Serial.print('/');
      Serial.print(now.month(), DEC);
      Serial.print('/');
      Serial.print(now.day(), DEC);
      Serial.print(' ');
      Serial.print(now.hour(), DEC);
      Serial.print(':');
      Serial.print(now.minute(), DEC);
      Serial.print(':');
      Serial.print(now.second(), DEC);
      Serial.println();    
    }
    buffer="";
   
}
