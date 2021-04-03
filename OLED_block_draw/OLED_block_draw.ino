// Drawing on OLED Display 
//

#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];

float y;
// Function for drowing 
//  rect round figure:
//drawRoundRect(heigh,lenght,x,y);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
   myOLED.begin();
   myOLED.setFont(SmallFont);
  
   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  myOLED.clrScr();
  myOLED.drawRect(0, 0, 127, 63);
  myOLED.drawLine(0, 31, 127, 31);
  myOLED.drawLine(63, 0, 63, 63);
  for (int c=0; c<4; c++)
  {
    for (int i=0; i<128; i++)
    {
      y=i*0.04974188368183839294232518690191;
      myOLED.invPixel(i, (sin(y)*28)+31);
      myOLED.update();
      delay(10);
    }
  }
}
