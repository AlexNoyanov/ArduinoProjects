#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

int rocketLenght = 10;
int rocketHight = 5;
int maxX = 128;
int maxY = 64;
int y;
int x = 8;
int pixX;
int pixY;
int flameR = 8;
int potValue;
int intensFire = 10;
int astR = 5;
int minastR = 2;
int maxastR = 10;
int astPixX;
int astPixY;
int astPixConcent = 15;


// Function for drawing rocket:
void drawRocket(int x,int y){
  myOLED.drawRect(x,y,x+rocketLenght,y+rocketHight);
  myOLED.drawLine(x+rocketLenght,y+rocketHight,x+rocketLenght+5,y+rocketHight/2);
  myOLED.drawLine(x+rocketLenght,y,x+rocketLenght+5,y+rocketHight/2);
  myOLED.drawLine(x+5,y+rocketHight,x-2,y+8); // Down 
  myOLED.drawLine(x,y+rocketHight,x-2,y+8);
  myOLED.drawLine(x+5,y,x-2,y-4); // Up
  myOLED.drawLine(x,y,x-2,y-4);
  //myOLED.drawCircle(x+2,y+2,2);
}

void drawFlame(int x,int y){
  for(int i = 0;i<= intensFire; i++){
  pixX = random(x-flameR,x);
  pixY = random(y-2,y+flameR);
  myOLED.setPixel(pixX,pixY);
  //myOLED.update();
  }
 }

 void Asteroid(int x,int y){
  //astR = random(minastR,maxastR);
  myOLED.drawCircle(x,y,astR);
    for(int i = 0;i< astPixConcent; i++){
  astPixX = random(x-astR,x+astR);
  astPixY = random(y-astR,y+astR);
  myOLED.setPixel(astPixX,astPixY);
  }
 }
 
void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  analogWrite(A1,1023);
  analogWrite(A2,0);
}

void loop() {
  // put your main code here, to run repeatedly:
   myOLED.clrScr();
   potValue = analogRead(A0);
   y = map(potValue,0,1023,4,64-rocketHight-4);
   drawRocket(x,y);
   drawFlame(x,y);
   Asteroid(60,30);
   myOLED.update();
   delay(10);
}
