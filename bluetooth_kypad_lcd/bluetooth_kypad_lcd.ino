//  Printing on LCD from bluetooth 
// Use Kypad Shield for this project

// Use "~" for clear message on display  

#include <SoftwareSerial.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

char incomingByte;  // One symbol for creating string
String buffer;      // String from bluetooth
int x = 0;


SoftwareSerial mySerial(10, 11);      // RX, TX pins

RTC_DS1307 rtc;                       // Magic words

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // LCD pins

// Buttons :
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 /*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
*/
 // For V1.0 comment the other threshold and use the one below:

 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   

 return btnNONE;  // when all others fail, return this...
}
 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);         // Serial port begin 
   Serial.println("Started");  // Printing on serial port

   mySerial.begin(9600);
   mySerial.println("Hello BB from Arduino");

    lcd.begin(16, 2);              // start the library
    lcd.setCursor(0,0);
    lcd.print("From Bluetooth:"); // print a simple message

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
  lcd.setCursor(0,1);
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
      lcd.print(buffer);
      x++;
      } 
    if(x >=16 || incomingByte == '~' ){
      lcd.clear();
      x = 0;
      lcd.print("From Bluetooth:");
      lcd.setCursor(0,1);
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
     // lcd.print(buffer);
    } else {
      Serial.println("---");      
    }

    // Comands for bluetooth data:
    /*
      if(buffer.indexOf("on") == 0) {  // If input data is "on"
      Serial.println("Relay 1 is ON");
      digitalWrite(r1Pin, HIGH);
    }

      if(buffer.indexOf("off") == 0) {  // If input data is "off"
      Serial.println("Relay 1 is OFF");
      digitalWrite(r1Pin, LOW);
    }

   lcd_key = read_LCD_buttons();  // read the buttons

 switch (lcd_key)                 // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.print("RIGHT ");
     break;
     }
   case btnLEFT:
     {
     lcd.print("LEFT   ");
     break;
     }
   case btnUP:
     {
     lcd.print("UP    ");
     break;
     }
   case btnDOWN:
     {
     lcd.print("DOWN  ");
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     break;
     }
     case btnNONE:
     {
     lcd.print("NONE  ");
     break;
     }
 } */
    
  delay(500);    
}
