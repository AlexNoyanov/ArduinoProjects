#include <Servo.h>
Servo serva;
Servo serva2;
 int a = 0;
 int st = 10;


void setup() {
  // put your setup code here, to run once:
serva.attach(9);
serva2.attach(10);
a = 0;
st = 10;
 serva.write(a);
 serva2.write(80);
}

void loop() {
  // put your main code here, to run repeatedly:
   a = a+st;
   if ( a >= 150) {
     st = -1;
   }
   if ( a <= 10) {
     st = 1;
   }  
   
   serva.write(a);
   delay(300);
}
