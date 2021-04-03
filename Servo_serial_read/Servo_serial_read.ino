#include <Servo.h>
Servo servoX;
Servo servoY;

int x = 0;
int y = 0;

void setup() {
  // put your setup code here, to run once:
servoX.attach(9);     // Connect servo pin to the pin 9
servoY.attach(10);    // Connect servo pin to the pin 10
Serial.println("Input X and Y:");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.read(*x);
  Serial.read(*y);
  Serial.println("X = ");
  Serial.print(x);
  Serial.println("Y = ");
  Serial.print(y
  delay(1000);
  
  
  
}
