#include<OLED_I2C.h>

OLED myOLED(SDA,SCL,8);

int x0 = 60;
int y0 = 0;
int height = 10;
int lenght = 20;
int v0y = 0;
int v0x = 0;
int x;
int ax;
int ay = 1;;
float t = 1;
int ymax = 63;
int xmax = 127;
int k = 1;
int vy =0;
void setup() {
  // put your setup code here, to run once:
myOLED.begin();
myOLED.clrScr();
myOLED.drawLine(0,63,128,63);
myOLED.update();
}
void loop() {
  // put your main code here, to run repeatedly:
  
if(y0+height == ymax){
   y0 = 0;
   t = 0;
 }

 y0 =y0 + v0y*t+ay*t*t/2;
 x0 = x0 + v0x*t+ ax*t*t/2;
 vy = v0y + ax*t;
  
myOLED.drawRoundRect(x0,y0,x0+lenght,y0+height);

myOLED.update();
t++;
delay(20);

myOLED.clrRoundRect(x0,y0,x0+lenght,y0+height);

}
