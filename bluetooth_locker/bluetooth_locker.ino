
// Libraries:w
#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
Servo servo;
String buffer;
char incomingByte;
//  Connecting bluetooth module on that pins:
SoftwareSerial mySerial(10, 11); // RX, TX

RTC_DS1307 rtc;
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // Port initializing
  mySerial.begin(9600);
  servo.attach(9);
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
    servo.write(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   
  // Read from monitor to send to Bluetoth
   if (Serial.available() > 0) {
      buffer = "";
      while (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;
      }
      mySerial.print(">>From terminal:");
      mySerial.println(buffer);
      Serial.print("<<To device:");
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

          // Say what you got:
      Serial.print("I received: ");
      Serial.println(buffer);
    } else {
      Serial.println("---");      
  }

  //    ====== Commands:======
        // Do iy we transmit this string:
    if(buffer.indexOf("1234") == 0) {
      Serial.println("Welcome!");    
      tone(8,1000);
    delay(100);
    noTone(8);
    servo.write(0);
    }else{
      Serial.println("Acess Denied! Wrong password");
    for(int i = 0; i<= 10;i++){
    tone(8,1000);
    delay(100);
    noTone(8);
    delay(100);
    tone(8,1500);
    delay(100);
    noTone(8);
    delay(100);
      }
    }
  
}
