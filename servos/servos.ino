#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
void setup() {
  // put your setup code here, to run once:
myservo1.attach(9);
myservo2.attach(8);
myservo3.attach(7);
myservo4.attach(6);
myservo5.attach(5);
myservo6.attach(4);
}

void loop() {
  // put your main code here, to run repeatedly:
myservo1.write(0); 
myservo2.write(0);
myservo3.write(0); 
myservo4.write(0); 
myservo5.write(0); 
myservo6.write(0); 
delay(2000);
myservo1.write(90);
myservo2.write(90);
myservo3.write(90);
myservo4.write(90);
myservo5.write(90);
myservo6.write(90);
delay(2000);
}
