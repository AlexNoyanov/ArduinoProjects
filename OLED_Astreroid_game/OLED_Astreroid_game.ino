//  Arduino Asteroid Game with OLED display
//    Created by Alexander Noyanov
//    18 10 2016

// 

// Connect OLED  SCL-> A5
//               SDA-> A4

// Potenciometer to A0

// For help: alex.noyanov@gmail.com

// Version 1.5 Working

// Multithreading music update Feb 27 2020

// Features to update: 
/*
 * - Add three lifes 
 * - Add main menu      (Done! Feb 29 2020)
 * - Add music theme 
 * - Add bonuses and weapons
 * 
 */

// Testing Multithreading for music:
//#include <TimedAction.h>


#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

const int rocketLenght = 10;  // Rocket body Length 
const int rocketHight = 5;    // Rocket body Hight
const int maxX = 128;         // Maximum X-value
const int maxY = 64;          // Maximum Y-value
const int buzPin = 9;         // Buzzer pin
int buzzerPin = buzPin;       // using digital pin 8 or 9
int y;                        // Rocket Y-coordinate
int x = 8;                    // Rocket X-coordinate
int pixX;                     // Pixel coordinate X
int pixY;                     // Pixel coordinate Y
int flameR = 8;               // Flame radius  
int potValue;
int intensFire = 10;          // Fire pixel concentration 
int astR = 5;                 // Asteroid radius 
int minastR = 2;
int maxastR = 10;
const int astPixConcent = 20; // Pixels concentration inside the asteroid
int rOut = 5;
int astX ;
int astY ;           
int astSpd = 2;      // Asteroid speed
int score = 0;       // Game score
int record = 0;      // Game record 
int pixExpX;         //  Explosion coordinate X
int pixExpY;         //  Explsion coordinate Y
int explosionIntetsivity = 10;
int explosionR = 15;  // Radius of rocket explosion
bool gameMode = false;
int potPin = A0;      // Potenciometer pin

//  === TESTING ===
const int ledPin =  13;      
// Variables will change:
int ledState = LOW;             
long previousMillis = 0;        
 
long interval = 100; 

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
// Drawing rocket flame:
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
  //for(int i = 0; i < astR;i++){
  myOLED.drawCircle(x,y,astR);
 // }
//    for(int i = 0;i< astPixConcent; i++){ // Pixels all around asteroid
//  astPixX = random(x-2*astR,x+2*astR);
//  astPixY = random(y-2*astR,y+2*astR);
//  myOLED.setPixel(astPixX,astPixY);
//  }
//    myOLED.drawCircle(x+rOut,y+rOut,astR);
 }

 void Explosion(int x, int y){
  for(int i = 0; i < explosionIntetsivity; i++){
    //myOLED.drawCircle(x,y,i);
      pixExpX = random(x,x+explosionR);
      pixExpY = random(y-explosionR,y+explosionR);
      myOLED.setPixel(pixExpX,pixExpY);
      myOLED.setPixel(pixExpX+1,pixExpY);
      myOLED.setPixel(pixExpX,pixExpY+1);
  //myOLED.drawCircle(x+2*i,y,i);
      myOLED.update();
  }
 }

// Music:
//  Main music function:
void Ton(int friq,int tme){
  tone(buzPin,friq);
  delay(tme);
  noTone(buzPin);
  delay(tme);
}

void musicScore(){
//Ton(100,10);
Ton(2800,10);
Ton(2300,10);
}

void soundExplosion(){
  for(int i = 1000;i<1500;i= i+100){
    Ton(i,i/50);
  }
}
  extern uint8_t SmallFont[];

// Creating main Game Menu:
void drawMainMenu(int mxScr){
  myOLED.clrScr();
  myOLED.print("<--ASTEROID GAME-->", 10, 20);
  myOLED.printNumI(mxScr, 90, 35);
  myOLED.print("(move pot to start)", 10, 50);
  drawRocket(40,35);
  drawFlame(40,35);
  myOLED.update();
}

void menuStartAnimation(){                // Menu start animation
  int x = 10;
  int y = 20;
  for(int j = y; j > -10; j--){
    myOLED.clrScr();
    myOLED.print("<--ASTEROID GAME-->", x, j);
    myOLED.print("(move pot to start)", x, 70-j); 
    //delay(100); 
    myOLED.update();  
  }
}

void menu(int pPin, int maxScr){            // Main menu
  int potValue = analogRead(potPin);  
  int lastPotValue = 0;
  int dif = 900;                            // Pot sensivity for starting the game
 
  while((potValue - lastPotValue) < dif){   // Drawing game menu while no response from pot:
    drawMainMenu(maxScr);
    for(int i = 0; i < 100; i++){
    potValue = analogRead(pPin);
    delay(1);  
    lastPotValue +=potValue;
    }
    lastPotValue = lastPotValue/100;
  }
  // Starting the game when exit:
  menuStartAnimation();           // And launching nice menu animation
  gameMode = true;              
 
}

// Drawing number of hearts:
void drawLifeStatus(int n){
  
 // myOLED.print("♥", 60, 5);   // Not working
 //"♥"
}
 
void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(SmallFont);
  analogWrite(A1,1023);
  analogWrite(A2,0);
  potValue = analogRead(potPin);

// Printing menu and waiting for start:

  
}

void loop() {
  // put your main code here, to run repeatedly:
  //TimedAction musicThread = TimedAction(700,incrementNumber);
  
  if(gameMode){                       // Playing game or printing menu:
   myOLED.clrScr();
   potValue = analogRead(potPin);
   y = map(potValue,0,1023,4,64-rocketHight-4);
   
   drawRocket(x,y);   // Drawing rocket
   drawFlame(x,y);

    astSpd = map(score,0,100,2,10 );  // Asteroids speed increasing 
   
   // Moving the Asteroid:
    if(astX > 0-astR){
      Asteroid(astX,astY);
      astX = astX-astSpd;
       }else{
        musicScore();
        astY = random(astR,64-astR);
        astX = 128+astR;
        score++;
       }
       // Asteroid with rocket:
       if(astX-astR < x+rocketLenght+5 && astY < y+rocketHight+5 && astY > y-rocketHight-5){
           myOLED.clrScr();
           drawRocket(x,y);
           for(int i = astX; i > 0; i--){
            Asteroid(i,astY);
            myOLED.update();
            myOLED.clrCircle(i, astY, astR);
                    Ton(i*100,10);
           }
           Explosion(x,y);
        astY = random(astR,64-astR);
        astX = 128+astR;

        //soundExplosion();
        delay(500);
        myOLED.print("GAME OVER ", 30, 20);
        if(score > record){
          myOLED.print("NEW RECORD!", 30, 40);
          myOLED.printNumI(score, 60, 50);
          record = score;
        }else{
          myOLED.print("YOUR SCORE: ", 30, 30);
          myOLED.printNumI(score, 100, 30);
          myOLED.print("RECORD", 30, 50);
          myOLED.printNumI(record, 80, 50);
        }
        score = 0;
        myOLED.update();
        delay(2000);
        gameMode = false;       // Exiting the game to the menu
       }
   drawLifeStatus(3);
   
   myOLED.printNumI(score, 30, 2);  // Drawing score
   myOLED.printNumI(astSpd, 60,2);   // Drawing asteroids speed
   myOLED.update();
  }else{
    // If not playing the game print Main Menu:
    menu(potPin, record);
    //myOLED.update(); 
  }

}
