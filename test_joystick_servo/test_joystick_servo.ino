#include <Servo.h>;
Servo sx;
Servo sy;
//int ax = 10;
//int ay = 10;
void setup() {
  // put your setup code here, to run once:
 // int ax = 10;
//int ay = 10;
sx.attach(9);
sy.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ax;
int x = analogRead(A0);
int y = analogRead(A1);
if(x> 519) 
{ while (ax< 180)
{
  ax = ax+10;
  delay(500);
  sx.write(ax);
}
}
delay(10);
// sx.write(ax);

//delay(500);

  
}
