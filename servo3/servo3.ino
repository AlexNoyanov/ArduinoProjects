int a = 500;
#include <Servo.h>
Servo serva;
void setup() {
  // put your setup code here, to run once:
serva.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
 serva.write(0);
 delay(1000);
 int angle = random(0,180);
 serva.write(angle);
 delay(a);
}
