// To Servos and acelerometer
#include<Servo.h>

Servo servox;
Servo servoy;

int anglex;
int angley;
int x;
int y;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servox.attach(8); // Attaching servos
servoy.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  x =analogRead(A0);
  y = analogRead(A1);
  anglex = map(x,200,400,0,120);
  servox.write(anglex);
  Serial.println(anglex);
  delay(10);
}
