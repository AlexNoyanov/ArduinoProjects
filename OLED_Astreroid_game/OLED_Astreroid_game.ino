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
int intensFire = 10;  // Fire pixel concentration 
int astR = 5;         // Asteroid radius 
int minastR = 2;
int maxastR = 10;
int astPixX;
int astPixY;
int astPixConcent = 20; // Pixels concentration inside the asteroid
int rOut = 5;
int astX ;
int astY = 20;
int astSpd = 2;       // Asteroid speed

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
//    for(int i = 0;i< astPixConcent; i++){ // Pixels all around asteroid
//  astPixX = random(x-2*astR,x+2*astR);
//  astPixY = random(y-2*astR,y+2*astR);
//  myOLED.setPixel(astPixX,astPixY);
//  }
//    myOLED.drawCircle(x+rOut,y+rOut,astR);
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
    if(astX > 0-astR){
      Asteroid(astX,astY);
      astX = astX-astSpd;
       }else{
        astX = 128+astR;
       }
   myOLED.update();
   
   
   delay(10);
}
