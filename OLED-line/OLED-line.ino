
#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];

    int x0=65;
    int y0=30;
    int R=20;
     int value;
    int secStp =252;

    struct Point
    {
      int x, y;
    };
   
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myOLED.begin();
  myOLED.setFont(SmallFont);
}

void angle(double ADeg, double R, int& x2, int& y2)
{
      double ARad = (ADeg)*M_PI/180.0;
      x2 = x0 + R*sin(ARad);
      y2 = y0 - R*cos(ARad);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(secStp);
  //  Clearing display:
    myOLED.clrScr();
    //Draw circle:
    for(int i = 0; i < 360; i+=10) {
      int x2, y2, x3, y3;
      angle(i, R, x2, y2);
      //angle(i, R-1, x3, y3);
      //myOLED.drawLine(x3,y3, x2,y2);
      myOLED.setPixel(x2, y2);
    }
    for(int i = 0; i < 360; i+=30) {
      int x2, y2, x3, y3;
      angle(i, R, x2, y2);
      angle(i, R-5, x3, y3);
      myOLED.drawLine(x3,y3, x2,y2);
    }
    //myOLED.drawCircle(x0,y0,R);

      int x2, y2;
      angle(secStp, R, x2, y2);
    //  Drawing line:
     myOLED.drawLine(x0,y0, x2,y2);
     myOLED.print("12",59,0);
     myOLED.print("6",60,56);
     myOLED.print("9",35,25);
     myOLED.print("3",90,25);
     
    myOLED.update();
    secStp = secStp+6;
    if(secStp > 360) {
      secStp -= 360;
    }
//    if(secStp<-102)
//    secStp = 258;
    delay(1000);
}
