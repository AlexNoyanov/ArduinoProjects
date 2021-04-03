#include<Servo.h>
Servo servo1;
Servo servo2;
int i,k;
void setup() {
  // put your setup code here, to run once:
servo1.attach(8);
servo2.attach(9);
i = k = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
 servo1.write(90);
 servo2.write(90);
 delay(1000);
  //servo1.write(90);
 //servo2.write(0);
// delay(1000);
   servo1.write(0);
 servo2.write(0);
 */
 i = 0;
 k = 80;
 while(i<=80){
 servo1.write(i);
 servo2.write(k);
 delay(10);
 k--;
 i++;
 }
 while(k<=80){
   servo1.write(i);
 servo2.write(k);
 delay(10);
 k++;
 i--;
 }
delay(100);
}
