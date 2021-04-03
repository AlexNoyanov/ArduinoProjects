#include <Servo.h>
Servo serv;


void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
  pinMode(14, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = analogRead(14);
  if(v == 1023)
  {
    serv.write(90);
    delay(100);
    serv.write(0);
    delay(100);
  }
  if(v == 0)
  {
    serv.write(90);
    delay(1000);
    serv.write(0);
    delay(1000);
  } else {
  
    float angle = float(v) * 90.0 / 1024.0f;
    
    serv.write(angle);
    
    delay(1000);
  
  }
}
