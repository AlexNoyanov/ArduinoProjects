#include <OLED_I2C.h>
#include <OzOLED.h>

OLED  myOLED(SDA, SCL, 8);

extern uint8_t SmallFont[];

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  myOLED.begin();
  myOLED.setFont(SmallFont);
}

void loop() {
// clr
  
  // put your main code here, to run repeatedly:
  myOLED.print("Hello,World!",30,10);
  myOLED.update();

}
