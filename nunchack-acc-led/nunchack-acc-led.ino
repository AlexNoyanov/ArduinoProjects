// nunchack light
// 3 November 2015
// 

#include <Wire.h>
#include <ArduinoNunchuk.h>

int red = 7;
int blue = 8;
int green = 9;

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
  
  int y = nunchuk.accelY;
  int x = nunchuk.accelX;
  int z = nunchuk.accelZ;
  
 // analogWrite(light,A0);
 
   Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);

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

 delay(200);
  //light = 0;
}
