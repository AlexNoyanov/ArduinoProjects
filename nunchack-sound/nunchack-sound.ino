//*******************
// Nunchack light-sound
// 5 November 2015
//  Version 1.1 Working
//*********************
//  nunchak I2C on A5 & A4 analog pins
//  LED on 7-9pins
//  buzzer on 6 pin

//  Libraries:
#include <Wire.h>
#include <ArduinoNunchuk.h>
//LED pins:
 const int red = 7;
 const int blue = 8;
 const int green = 9;

int ton;
int button = 0;
int flag = 0;
int x,y,z;
int mode;
#define BAUDRATE 19200
//19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  // put your setup code here, to run once:
Serial.begin(BAUDRATE);
  nunchuk.init();
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.begin(BAUDRATE);
  nunchuk.update();
  
  y = nunchuk.accelY;
  x = nunchuk.accelX;
  z = nunchuk.accelZ;
  button = nunchuk.zButton;
  
 // analogWrite(light,A0);

  if (button == 1 && flag == 0) {
  mode++;
    flag = 1;
  }else{
    if (button== 1&& flag ==1) {
  digitalWrite(13,LOW);
  flag = 0;
  delay(100);
}
  }
  if (mode>4){
    mode=1;}

//ton if
  if (mode==1){
  ton = nunchuk.accelX;
  tone(6,ton);
  }
  if(mode==2){
    ton =nunchuk.accelY;
    tone(6,ton);
  }
  if(mode==3){
  ton = nunchuk.accelZ;
  tone(6,ton);
  }
  if(mode==4){
  //ton = nunchuk.accelZ;
  noTone(6);
  }
  
  //Serial monitor testing:
 // ton = ton*2;
 
   Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.print(nunchuk.accelZ, DEC);
/*
if (button == 1 && flag == 0) {
  flag=1;
  
}
*/
  if(y>400){
    digitalWrite(red,HIGH);
  }else{
    digitalWrite(red,LOW);
  }

   if(x>400){
    digitalWrite(blue,HIGH);
  }else{
    digitalWrite(blue,LOW);
  }

   if(z>400){
    digitalWrite(green,HIGH);
  }else{
    digitalWrite(green,LOW);
  }
Serial.print("    Mode = ");
  Serial.println(mode);
 delay(200);
 noTone(6);
  //light = 0;
}
