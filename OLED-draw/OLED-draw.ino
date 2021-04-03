// OLED drawing
//  Something
//  By Alex Noyanov


//  == COMMANDS: ==
/*
 * 
 */

#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
extern uint8_t SmallFont[];
extern uint8_t logo[];
extern uint8_t The_End[];
extern uint8_t pacman1[];
extern uint8_t pacman2[];
extern uint8_t pacman3[];
extern uint8_t pill[];

// Integers:
  int x = 60;
  int y = 20;

//  Draw circle:
void DrawCircle(int x , int y){
   for(int i = 10;i<40;i++){
      myOLED.drawCircle(x,y,i);
      if (i == 15){
        i = i+2;
      }
   }
}
//Draw Disk:
void DrawDisk(){

     DrawCircle(x,y);
   x++;
   y++;
}

//  Draw cool lines:
void DrawLines(){
    myOLED.drawRect(0, 0, 127, 63);
  for (int i=0; i<64; i+=4)
  {
    myOLED.drawLine(0, i, i*2, 63);
    myOLED.update();
  }
  for (int i=0; i<64; i+=4)
  {
    myOLED.drawLine(127, 63-i, 127-(i*2), 0);
    myOLED.update();
  } 
}


void drawSpace(int x , int y){
   for(int r = 0;r<=150;){
    myOLED.drawCircle(x,y,r);
    r = r+2;
    }
}
//  Draw moving space
void DrawSpaceMovie(){
      drawSpace(x,y);
    x++;
    y++;
    if (y>60){
      while(y>20){
           myOLED.update();
   myOLED.clrScr();
      drawSpace(x,y);
    x--;
    y--;
}
    }
}
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  Clearing display:
   myOLED.update();
   myOLED.clrScr();

/*
     myOLED.drawRect(0, 0, 127, 63);
  myOLED.drawLine(0, 31, 127, 31);
  myOLED.drawLine(63, 0, 63, 63);
  for (int c=0; c<4; c++)
  {
    for (int i=0; i<128; i++)
    {
      y=i*0.04974188368183839294232518690191;
      myOLED.invPixel(i, (sin(y)*28)+31);
      myOLED.update();
      delay(10);
    }
  }
  */
    for (int i=0; i<25; i++)
  {
    myOLED.drawCircle(64, 32, i*3);
    myOLED.update();
  }

//     delay(1000);
 myOLED.clrScr();
      for (int i=25; i>0; i--)
  {
    
    myOLED.drawCircle(64, 32, i*3);
    myOLED.update();
  }

   myOLED.clrScr();
  for (int i=0; i<10; i++)
  {
    myOLED.drawRoundRect(i*3, i*3, 127-(i*3), 63-(i*3));
    myOLED.update();
  }

//delay(2000);
/*
 myOLED.clrScr();
  //myOLED.drawRect(0, 0, 127, 63);
 // myOLED.drawLine(0, 31, 127, 31);
  //myOLED.drawLine(63, 0, 63, 63);
  for (int c=0; c<4; c++)
  {
    for (int i=0; i<128; i++)
    {
      y=i*0.04974188368183839294232518690191;
      myOLED.invPixel(i, (sin(y)*28)+31);
      myOLED.update();
      //delay(10);
    */
    /*
  //}
for(int i =0;i<=60;i++){
    myOLED.update();
   myOLED.clrScr();
      drawSpace(x,y);
    x++;
    y++;
}
    if (y>60){
      while(y>20){
   myOLED.update();
   myOLED.clrScr();
      drawSpace(x,y);
    x--;
    y--;
}

    }
    */
}
