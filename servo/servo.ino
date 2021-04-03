#include <Servo.h>

Servo myservo
int led = 13;
void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
pinMode(11,INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = digitalRead(11);
  if( v ==HIGH)
  { digitalWrite(led,LOW);
    myservo.write(0);
    delay(1000);
    digitalWrite(led,HIGH);
    myservo.write(180);
    delay(1000); 
    myservo.write(0);
    digitalWrite(led,LOW);
   delay(1000);
   digitalWrite(led,HIGH);
  } else {
 // for(int i = 0; i < 180; i=i+10)
  }
}
   // myservo.write(i);
  //  delay(i*5+20);
  

