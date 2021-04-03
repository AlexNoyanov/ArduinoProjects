#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];

float y,yy = 0;
const int a = 25;
void drawEmblem(){
  
}
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
   myOLED.begin();
   myOLED.setFont(SmallFont);

}

void loop() {
  // put your main code here, to run repeatedly:
   myOLED.clrScr();
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
      
    
       myOLED.update();
    }
     myOLED.drawCircle(50,45,7);
             myOLED.update();

  
  
  delay(5000);
  }
