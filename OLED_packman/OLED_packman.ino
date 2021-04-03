

#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

extern uint8_t pacman1[];
extern uint8_t pacman2[];
extern uint8_t pacman3[];
extern uint8_t pill[];

float y;
uint8_t* bm;
int pacy;


void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
 
  randomSeed(analogRead(7));
}

void loop() {
  // put your main code here, to run repeatedly:
 myOLED.clrScr();



  for (int pc=0; pc<3; pc++)
  {
    pacy=random(0, 44);
  
    for (int i=-20; i<132; i++)
    {
      myOLED.clrScr();
      for (int p=6; p>((i+20)/20); p--)
        myOLED.drawBitmap(p*20-8, pacy+7, pill, 5, 5);
      switch(((i+20)/3) % 4)
      {
        case 0: bm=pacman1;
                break;
        case 1: bm=pacman2;
                break;
        case 2: bm=pacman3;
                break;
        case 3: bm=pacman2;
                break;
      }
      myOLED.drawBitmap(i, pacy, bm, 20, 20);
      myOLED.update();
      delay(10);
    }
  }

  delay(2000);
}
