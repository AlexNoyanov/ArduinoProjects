// This progrsm draw an original AN logo on OLED display
// Connect display to NodeMCU esp8266 wifi board
//
// D2->SCL
// D1->SDA
//
// Created be Alexander Noyanov 
// 23.10.2017


#include <Wire.h>
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
//#include "SSD1306Wire.h"
SSD1306  display(0x3c, D1, D2);


float y,yy = 0;
const int a = 25;
void drawEmblem(){
  display.clear();
      for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
     display.setPixel(i+15, (cos(y)*a)+40);
      display.setPixel(i+15, (cos(yy)*a)+33);
      delay(10);
      display.display();
     
    }
    
      delay(1000);
        display.drawCircle(50,45,6);
        display.display();
        delay(500);
          display.drawCircle(50,45,8);
             display.display();
         
                 for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      display.setPixel(i+15, (cos(y)*a)+39);
      display.setPixel(i+15, (cos(yy)*a)+38);
      display.setPixel(i+15, (cos(y)*a)+37);
      display.setPixel(i+15, (cos(yy)*a)+36);
      //display.setPixel(i+15, (cos(yy)*a)+3);
      display.setPixel(i+15, (cos(y)*30)+35);
      display.setPixel(i+15, (cos(yy)*a)+34);
      delay(10);
       display.display();
    }
     display.drawCircle(50,45,7);
            // display.update();
            display.display();

}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println();
  Serial.println();

  display.init();

  display.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

  drawEmblem();
  delay(5000);

}
