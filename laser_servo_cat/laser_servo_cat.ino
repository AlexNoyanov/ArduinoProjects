//
//  ==================
//   Playing with cat
//  Laser and X2 servos
//   By Alex Noyanov
//   5 December 2015
//  ==================

#include <Servo.h>
Servo sx;
Servo sy;
const int spd = 20;
const int ymax = 20;
const int ymin = 5;
const int spdCrlc = 15;

void Circle(int x){
  for(int y = 0; y<50;y++){
    sx.write(y);
    sy.write(y);
   delay(spdCrlc); 
   x++;
  }
  for(int y = 50; y>0;y--){
    sx.write(y);
    sy.write(y);
   delay(spdCrlc); 
   x--;
  }
}

void Move(){
 //  X-axis forward:
for(int xangle = 0;xangle<120;xangle++){
sx.write(xangle);
delay(spd);
}
//  Y-axis forward:
for(int yangle = ymin ;yangle<ymax;yangle++)
{
  sy.write(yangle);
  delay(spd);
    }
//  X-back
for(int xangle = 120;xangle>0;xangle--){
sx.write(xangle);
delay(spd);
}
//  Y-back
for(int yangle = ymax;yangle>ymin;yangle--)
{
  sy.write(yangle);
  delay(spd);
  }
}
void movex(){
 int spdx = 5;
 //  X-axis forward:
for(int xangle = 0;xangle<120;xangle++){
sx.write(xangle);
delay(spdx);
}
  //  X-back
for(int xangle = 120;xangle>0;xangle--){
sx.write(xangle);
delay(spdx);
}
}
void setup() {
  // put your setup code here, to run once:
sx.attach(10);
sy.attach(9);
// Setup position:
sy.write(90);
sx.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 0;i<10;i++){
Circle(80);
}
 delay(2000); 
  //  Move like circle at 10 times:
 for(int i = 0;i<10;i++){
  Move();
 }
 // Waiting a second:
  delay(1000);
  // Move fast right-left:
  for(int k = 0;k<5;k++){
  movex();
  }
  delay(5000);

  
}
