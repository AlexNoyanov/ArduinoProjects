//  Car with nunchuck control
//  8 November 2015

//  SPEED:
int spd = 200;
//  Motor puns:
int lfwd =3; 
int lbk = 5;
int rfwd = 4;
int rbk = 6;

//  Main Functions: fwd stp bck lft rgt
void stp(){
 digitalWrite(rbk,HIGH);
  digitalWrite(lbk,HIGH);
  digitalWrite(rfwd,HIGH);
  digitalWrite(lfwd,HIGH); 
}

void fwd(){
  digitalWrite(rfwd,LOW);
  digitalWrite(lfwd,LOW);
  delay(spd);
  digitalWrite(rfwd,HIGH);
  digitalWrite(lfwd,HIGH);
  //delay(spd);
}
void bck(){
 digitalWrite(rbk,LOW);
 digitalWrite(lbk,LOW);
  delay(spd);
  digitalWrite(rbk,HIGH);
  digitalWrite(lbk,HIGH);
  //delay(spd); 
}
void lft(){
   digitalWrite(lbk,LOW);
 digitalWrite(rfwd,LOW);
  delay(spd);
  digitalWrite(lbk,HIGH);
  digitalWrite(rfwd,HIGH);
  //delay(spd); 
}
void rgt(){
     digitalWrite(rbk,LOW);
 digitalWrite(lfwd,LOW);
  delay(spd);
  digitalWrite(rbk,HIGH);
  digitalWrite(lfwd,HIGH);
  //delay(spd); 
}

//  Libraries:
#include <Wire.h>
#include <ArduinoNunchuk.h>
//  LED pins:
int red = 7;
int blue = 8;
int green = 9;
//  Nunchuck :
ArduinoNunchuk nunchuk = ArduinoNunchuk();
#define BAUDRATE 19200

void setup() {
  // put your setup code here, to run once:
//  Serial Begin:
 Serial.begin(BAUDRATE);
//  Nunchuck :
   nunchuk.init();
//  Pins mode:
    pinMode(red,OUTPUT);
    pinMode(blue,OUTPUT);
    pinMode(green,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  nunchuk.update();
  
   //Serial print:
   Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);
  
//  Accelerometer:
  int y = nunchuk.accelY;
  int x = nunchuk.accelX;
  int z = nunchuk.accelZ;
  int zb = nunchuk.zButton;
//  Functions:
  if(y<400){
  bck();
}

  if(y>600){
  fwd();
}
  if(x<400){
    lft();
  }
  if(x>600){
    rgt();
  }
stp();

//    LED Function:
  if(y>400){
    digitalWrite(red,HIGH);
  }else  
    digitalWrite(red,LOW);
  
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
  delay(100);
}
