#include <Servo.h>
Servo serv;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(14, INPUT);
  
  serv.attach(10);
}

void loop() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  // put your main code here, to run repeatedly:
  int v = analogRead(14);
  if(v > 200)
    digitalWrite(13, HIGH);
  if(v > 400)
    digitalWrite(12, HIGH);
  if(v > 600)
    digitalWrite(11, HIGH);
  if(v > 800)
    digitalWrite(8, HIGH);
  if(v > 1000)
    digitalWrite(7, HIGH);
    
    float angle = float(v) * 90.0 / 1024;
    serv.write(int(angle));
    delay(200);
}
