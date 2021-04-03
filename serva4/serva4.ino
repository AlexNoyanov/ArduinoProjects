#include <Servo.h>
Servo serva ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
serva.attach(10); 
pinMode(13,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

serva.write(10);
delay(1000);
serva.write(190);
delay(100);

}
