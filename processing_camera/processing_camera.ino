#include<Servo.h>
Servo sx;
Servo sy;

int buz = 9;
//  Beep Function:
 void Beep(){
  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,1000);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
 }
void setup() {
  // put your setup code here, to run once:
sx.attach(8);
sy.attach(7);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
   }
   if (val == '.') 
   { // If 1 was received
     digitalWrite(ledPin, HIGH); // turn the LED on
   } else {
     digitalWrite(ledPin, LOW); // otherwise turn it off
   }

}
