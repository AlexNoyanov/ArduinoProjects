//  ================
//  IR Transmitting
//  Use IR Emission
//  module 
//  Connect button
//  ================

#include <IRremote.h>
IRsend irsend;

int buttonPin = 8;
int button = 0;

void setup()
{
 Serial.begin(9600);
 // For button:
 pinMode(8,INPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 digitalWrite(10,LOW);
 digitalWrite(9,HIGH);
}

void loop() {
  button = digitalRead(buttonPin);
  if(button == LOW){
    irsend.sendNEC(0x20DFFF00, 32); 
    delay(1000);
  }
 /* 
if (Serial.read() != -1) {
for (int i = 0; i < 3; i++) {
irsend.sendNEC(0x20DFFF00, 32); Send IN-Start
delay(100);
}
}
*/
}
