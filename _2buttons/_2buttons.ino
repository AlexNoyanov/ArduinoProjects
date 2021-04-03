#include <Servo.h>
Servo serv1;
int a = 100;
void setup() {
  // put your setup code here, to run once:
serv1.attach(9);
pinMode(10,OUTPUT);
pinMode(13,OUTPUT);
pinMode(12,INPUT);
pinMode(11,INPUT);
a = 100;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int i =  digitalRead(11);
  int v =  digitalRead(12);
  if( i == HIGH)
  { 
    a = a + 10;
    if(a > 180)
      a = 180;
    serv1.write(a);
    digitalWrite(13,HIGH);
    delay(100);
  }else{
    digitalWrite(13,LOW);
  }
  
  if( v == HIGH)
  { 
    a = a - 10;
    if(a < 0)
      a = 0;
    serv1.write(a);
    digitalWrite(10,HIGH);
    delay(1 00);
  } else{
    digitalWrite(10,LOW);
  }
}


