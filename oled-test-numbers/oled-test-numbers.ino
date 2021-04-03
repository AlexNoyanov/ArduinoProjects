
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
  int x = analogRead(A0)/10;
  int y = 10;
    
    myOLED.setFont(MediumNumbers);
    myOLED.print("8",30,40);
    
    myOLED.setFont(BigNumbers);   // Number Style
   // myOLED.print("",x, y); //  (number;X-position;Y-position)
     
    myOLED.update();
  /*
  
  myOLED.setFont(SmallFont);
  myOLED.print("|", LEFT, 24);
  myOLED.print("|", RIGHT, 24);
  myOLED.update();
  delay(500);
  for (int i=0; i<19; i++)
  {
    myOLED.print("\\", 7+(i*6), 24);
    myOLED.update();
    delay(250);
  }
  */
  delay(10);
  myOLED.clrScr();
}
