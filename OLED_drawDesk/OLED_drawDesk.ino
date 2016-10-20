// Arduino OLED drawing
// Connect two potenciometers to A0 and A1 pin
// By Alexander Noyanov
// 20 October 2016

#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

int x;
int y;
const int xpin = A0;
const int ypin = A1;

void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  x = map(analogRead(xpin),0,1023,0,128);
  y = map(analogRead(ypin),0,1023,0,64);
  myOLED.setPixel(x,y);
  //myOLED.clrScr();
  myOLED.update();
}
