#include <OLED_I2C.h>
#include <OzOLED.h>
OLED  myOLED(SDA, SCL, 8);
float y,yy = 0;
const int a = 25;
void emblem(){
        for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+40);
      myOLED.invPixel(i+15, (cos(yy)*a)+33);
      myOLED.update();
     
    }
    
      delay(1000);
        myOLED.drawCircle(50,45,6);
        myOLED.update();
        delay(500);
          myOLED.drawCircle(50,45,8);
             myOLED.update();
         
                 for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+39);
      myOLED.invPixel(i+15, (cos(yy)*a)+38);
      myOLED.invPixel(i+15, (cos(y)*a)+37);
      myOLED.invPixel(i+15, (cos(yy)*a)+36);
      //myOLED.invPixel(i+15, (cos(yy)*a)+3);
      myOLED.invPixel(i+15, (cos(y)*30)+35);
      myOLED.invPixel(i+15, (cos(yy)*a)+34);
      
  //  myOLED.drawRect(0, 0, 127, 63);
    myOLED.update();
    }
     myOLED.drawCircle(50,45,7);
     myOLED.update();
}

void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
     myOLED.drawRect(0, 0, 127, 63);
    myOLED.update();
}

void loop() {
 // OzOled.setInverseDisplay();  // Get inverse display
  // put your main code here, to run repeatedly:
  myOLED.clrScr();
  for (int i=0; i<64; i+=2)
  {
    myOLED.drawLine(0, i, 127, 63-i);
    myOLED.update();
  }
  for (int i=127; i>=0; i-=2)
  {
    myOLED.drawLine(i, 0, 127-i, 63);
    myOLED.update();
  }

 // OzOled.setInverseDisplay();
  emblem();  
  myOLED.print("By Alex Noyanov", CENTER, 30);
  myOLED.update();
delay(2000);

}
