#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];

    int x0=65;
    int y0=30;
    int R=20;
void setup() {
  // put your setup code here, to run once:
myOLED.begin();
    myOLED.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:

for(R=0;R<50;R++){
  
}
}
