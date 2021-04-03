
#include <OLED_I2C.h>
#include <OzOLED.h>

void angle(double ADeg, double R, int& x2, int& y2)
{
      double ARad = (ADeg)*M_PI/180.0;
      x2 = x0 + R*sin(ARad);
      y2 = y0 - R*cos(ARad);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myOLED.begin();
  myOLED.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:

}
