// Reprogramming Arduino using Bluetooth module
// Conect Bluetooth module to the arduino board
// Then upload this programm
// And connect to the arduino wirelessly using bluetooth  

#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);  // RX | TX

void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
digitalWrite(9,HIGH);
Serial.begin(9600);
Serial.println("Enter AT commands:");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
