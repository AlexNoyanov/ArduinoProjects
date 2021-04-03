
#include <OLED_I2C.h>
#include <OzOLED.h>
OLED  myOLED(SDA, SCL, 8);

float y;

void graph(float stp){
  stp=stp/1000;
  myOLED.drawRect(0, 0, 127, 63);
  myOLED.drawLine(0, 31, 127, 31);
  myOLED.drawLine(63, 0, 63, 63);
  for (int c=0; c<4; c++)
  {
    for (int i=0; i<128; i++)
    {
      y=i*stp;
      myOLED.invPixel(i, (sin(y)*28)+31);
      myOLED.update();
      delay(10);
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.clrScr();

}

void loop() {
  // put your main code here, to run repeatedly:
  graph(256);
}
