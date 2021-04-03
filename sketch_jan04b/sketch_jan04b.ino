#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


void setup() {
  // put your setup code here, to run once:
 myOLED.begin();
  myOLED.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:
    myOLED.clrScr();
    
  int x = analogRead(A0)/10;
  int y = 10;
    
    myOLED.setFont(MediumNumbers);
    myOLED.print("8",30,40);
    
    myOLED.setFont(BigNumbers);   // Number Style
    myOLED.print("",x, y); //  (number;X-position;Y-position)
     
    myOLED.update();

    delay(10);

}
