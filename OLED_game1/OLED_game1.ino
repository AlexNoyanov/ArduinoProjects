/*  =================
 *  OLED Game
 *  by Alex Noyanov
 *  10 February 2016
 *  =================
 */

// OLED librarie:
#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
// Values:
    int x0=0;
    int y0=54;
    int R=20;
    
// Get degrees into radians:
void angle(double ADeg, double R, int& x2, int& y2)
{
      double ARad = (ADeg)*M_PI/180.0;
      x2 = x0 + R*sin(ARad);
      y2 = y0 - R*cos(ARad);
}

//  Drawing cannon:
//  This funcion input angle and drawing cannon
void drawCannon(int alfa){
     int x2, y2, x3, y3;
      angle(alfa, R, x2, y2);
      angle(alfa, R-20, x3, y3);
      myOLED.drawLine(x3,y3,x2,y2);
      myOLED.drawLine(x3+5,y3+5,x2+5,y2+5);
     // Drawing Rect:(X0,Y0,X,Y)
      myOLED.drawRect(0,54,10,60);
       //myOLED.drawRect(0,54,10,56);
}

void setup() {
  // put your setup code here, to run once:
   myOLED.begin();
   myOLED.setFont(SmallFont);
   myOLED.clrScr();
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int i = 0; i <=90; i+=10) {
      myOLED.clrScr();
   drawCannon(i);
      delay(100);
        
      myOLED.update();
    }
    myOLED.update();
   myOLED.clrScr();
    delay(1000);
   
}
