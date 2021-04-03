
#include <OLED_I2C.h>
#include <OzOLED.h>
#include <Wire.h>
OLED  myOLED(SDA, SCL, 8);

// Fonts:
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


void PrintHP(int hp){
 // myOLED.invertText(0);
  myOLED.print("HP",0,0);
   myOLED.update();
  myOLED.setFont(BigNumbers);
  myOLED.printNumI(hp,RIGHT, 40); // Print Integer Number
  myOLED.update();
}
void setup() {
  // put your setup code here, to run once:
   OzOled.init();  //initialze OLED display
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  OzOled.setPageMode();           //Set addressing mode to Page Mode
  myOLED.begin();

  
  PrintHP(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
