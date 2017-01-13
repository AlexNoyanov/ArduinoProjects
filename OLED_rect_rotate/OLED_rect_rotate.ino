
#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

float pi = 3.14159265359;
int height = 20;  // Block Height
int lenght = 20;  // Block Lenght
float rad;      //
float oneRad = 0.0174533; //

 float Radian(int angle){
  float radian = (pi/180.0f) * angle;
 // int radian = angle * oneRad;
 return radian;
 }

 void Rect(int x,int y,float angle){
  rad = Radian(angle);
  //myOLED.drawLine(x,y,x+cos(rad)*lenght,y+sin(rad)*height);

  myOLED.drawLine(x+cos(rad)*lenght,y+sin(rad)*height,x+cos(rad+pi/2)*lenght,y+sin(rad+pi/2)*height);
  
  //myOLED.drawLine(x,y,x+cos(rad+pi/2)*lenght,y+sin(rad+pi/2)*height);

  myOLED.drawLine(x+cos(rad+pi/2)*lenght,y+sin(rad+pi/2)*height,x+cos(rad+pi)*lenght,y+sin(rad+pi)*height);
  
  //myOLED.drawLine(x,y,x+cos(rad+pi)*lenght,y+sin(rad+pi)*height);

  myOLED.drawLine(x+cos(rad+pi)*lenght,y+sin(rad+pi)*height,x+cos(rad+pi*3/2)*lenght,y+sin(rad+pi*3/2)*height);
  
  //myOLED.drawLine(x,y,x+cos(rad+pi*3/2)*lenght,y+sin(rad+pi*3/2)*height);

  myOLED.drawLine(x+cos(rad+pi*3/2)*lenght,y+sin(rad+pi*3/2)*height,x+cos(rad)*lenght,y+sin(rad)*height);
 }
 
void setup() {
  // put your setup code here, to run once:
myOLED.begin();
myOLED.clrScr();

}

void loop() {
  // put your main code here, to run repeatedly:

for(float i = 0;i<360;i = i+ 0.5){
  myOLED.clrScr();
  Rect(60,30,i);
  myOLED.update();
  //delay(10);
}


}


