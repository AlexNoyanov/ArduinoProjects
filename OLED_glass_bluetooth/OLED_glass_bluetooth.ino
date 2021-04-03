
/*
 *    ================
 *       ArGlass |||
 *     With Bluetooth
 *    19 February 2016
 *    By Alex Noyanov
 *    ===============
 * 
 *  ==== Connectin ====
 *  Bluetooth: (rx->) 11
 *             (tx<-) 10
 *  OLED: A4 A5
 
     ___
 * /  |\ \
 * | \|/  |
 * | /|\  |
 * |  |/  |
 *  \___ /
 *   
 */     
// Libraries:
#include <OLED_I2C.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <OzOLED.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>

OLED  myOLED(SDA, SCL, 8);

 SoftwareSerial mySerial(10, 11); // RX, TX

 RTC_DS1307 rtc;

 extern uint8_t SmallFont[];
 extern uint8_t BigFont[];
 extern uint8_t MediumNumbers[];
 extern uint8_t BigNumbers[];


//  For brightness:
//int brightness_procent;
int brightness = 225;
//  OLED Power Pin:
const int oled_pwr = 2;
char incomingByte;
String buffer;

void setup() {
  // put your setup code here, to run once:
  // OLED:
  myOLED.begin();
  myOLED.setFont(BigFont);
// Turn ON OLED:
digitalWrite(oled_pwr,HIGH);
  
//  Bluetooth:
   mySerial.begin(9600);
   #ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif

}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   // read from Bluetooth incomming data to show on Monitor
   if (mySerial.available() > 0) {
      buffer = "";
      while (mySerial.available() > 0) {
        // read the incoming byte:
        incomingByte = mySerial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
          buffer += incomingByte;
      }
//  For testing
      Serial.println(buffer);
   }
*/

 // listen for the data
  if ( Serial.available() > 0 ) {
    // read a numbers from serial port
    int count = Serial.parseInt();
    
     // print out the received number
    if (count > 0) {
        Serial.print("You have input: ");
        Serial.println(String(count));
        // blink the LED
      //  blinkLED(count);
    }
  }
}

// For testing:

   
  // Read from monitor to send to Bluetoth
   if (Serial.available() > 0) {
      buffer = "";
      while (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();
        if(incomingByte != '\n' && incomingByte != '\r')
        buffer += incomingByte;
      }
   }
if(buffer.indexOf("off") == 0 || buffer.indexOf("turn off") == 0 ) {
      Serial.println("Turn off");
      digitalWrite(oled_pwr, LOW);      
    }

    if(buffer.indexOf("brightness") == 0 ) {
      Serial.println("Set brightness");
      mySerial.print("Set brightness:");
      brightness =  incomingByte;
    }

  int brightness_procent = brightness/255 * 100; // Procent of OLED Brightness

  //  Print on OLED display:
    //OzOled.setInverseDisplay();          // Set Display to inverse mode
    OzOled.setBrightness(brightness);  // Change the brightness 0 - 255
    myOLED.clrScr();
    myOLED.setFont(SmallFont);
    myOLED.print("Brightness:",30,28);
    //myOLED.update();
    myOLED.setFont(MediumNumbers);
    myOLED.printNumI(brightness_procent, 100, 20);
   // myOLED.print("By Alex Noyanov ",30,48);
   
    myOLED.update();
    
}
