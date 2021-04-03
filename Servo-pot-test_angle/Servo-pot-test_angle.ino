
#include <Servo.h>    // Library

Servo myservo;       // Object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(8);  // Attach
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
int angle = map(analogRead(A0),0,1023,0,180);
Serial.println(angle);

myservo.write(angle);           
*/
// Test:
myservo.write(20);
delay(2000);
myservo.write(170);
delay(2000);
//delay(100);
}
