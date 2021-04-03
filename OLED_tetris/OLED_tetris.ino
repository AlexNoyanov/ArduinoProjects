// OLED TETRIS Game
// By Alexander Noyanov
// 27 08 2016

#include <OLED_I2C.h> // OLED Library with main functions
OLED  myOLED(SDA, SCL, 8);  // Create object myOLED

// Constants:
const int xMax = 128;     // X-border
const int yMax = 64;      // Y-border
const int blockSize = 8;  // Block size
const int buzPin = 8;     // Buzzer pin
int friq = 100;           // Buzzer friquency
void drawBlock(int x,int y){
  myOLED.drawRoundRect(x-blockSize/2,y-blockSize/2,x+blockSize,y+blockSize);
}

void Beep(){
  tone(buzPin,friq);
  delay(100);
  noTone(buzPin);
}

void DrawSup1(int x,int y){
  drawBlock(x,y);
  drawBlock(x+blockSize*1.5,y);
  drawBlock(x,y+blockSize*1.5);
  drawBlock(x-blockSize*1.5,y+blockSize*1.5);
}

void DrawSr(int x,int y){
  drawBlock(x,y);
  drawBlock(x+blockSize*1.5,y);
  drawBlock(x,y-blockSize*1.5);
  drawBlock(x+blockSize*1.5,y+blockSize*1.5);
}

void DrawSl(int x,int y){
  drawBlock(x,y);
  drawBlock(x+blockSize*1.5,y);
  drawBlock(x,y+blockSize*1.5);
  drawBlock(x+blockSize*1.5,y-blockSize*1.5);
}

void DrawBlck(int x,int y){
  drawBlock(x,y);
  drawBlock(x+blockSize*1.5,y);
  drawBlock(x,y-blockSize*1.5);
  drawBlock(x+blockSize*1.5,y-blockSize*1.5);
}

void DrawSup2(int x,int y){
  drawBlock(x,y);
  drawBlock(x+blockSize*1.5,y);
  drawBlock(x,y-blockSize*1.5);
  drawBlock(x-blockSize*1.5,y-blockSize*1.5);
}


void setup() {
  // put your setup code here, to run once:
  myOLED.begin();   // Setup OLED
  myOLED.clrScr();  // Clear screen
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x = 0; x < 108;x++){
 DrawSup1(x,30);
 myOLED.update();
 delay(1);
 myOLED.clrScr();
  }
  Beep();
  delay(1000);
/*
  for(int x = 0; x < 108;x++){
 DrawSup2(x,30);
 myOLED.update();
 delay(1);
 myOLED.clrScr();
  }
  delay(1000);
  */
 
}
