#include<Servo.h>
Servo s1;
Servo s2;

void setup() {
  // put your setup code here, to run once:
s1.attach(9);
s2.attach(10);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x = analogRead(A0);
 int y = analogRead (A1);
 s1.write(10);
 delay(1000);
 s1.write(100);
 delay(1000);
 
}
