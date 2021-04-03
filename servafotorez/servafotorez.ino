#include<Servo.h>
Servo serva
int sensorpin = A0;
unsigned int sehsorValue = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial,begin(9600);
serva.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(13,HIGH);
if(sensorValue<500) serva.write(90);
else
serva.write(0);
}
