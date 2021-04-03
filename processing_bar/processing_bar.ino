//  Processing bar graph
//  15 December 2015

//Sending 8 bit reading (256) so analogue 
//reading can be sent in 1 byte
int Analogue0 = A0; // first analog sensor
int Analogue1 = A1; // second analog sensor
int Analogue2 = A2; // digital sensor
int Analogue3 = A3; // second analog sensor
int Analogue4 = A4; // second analog sensor
int Analogue5 = A5; // second analog sensor
int inByte = 0; // incoming serial byte
void setup()
{
 // start serial port at 9600 bps:
 Serial.begin(9600);
establishContact(); // send a byte to establish contact until Processing responds 
}
void loop()
{
 // if we get a valid byte, read analog ins:
 if (Serial.available() > 0) {
 // get incoming byte:
 inByte = Serial.read();
 // read first analog input, divide by 4 to make the range 0-255:
 Analogue0 = analogRead(0)/4;
 // delay 10ms to let the ADC recover:
 delay(10);
 // read second analog input, divide by 4 to make the range 0-255:
 Analogue1 = analogRead(1)/4;
 // read switch, multiply by 155 and add 100
 // so that you're sending 100 or 255:
 delay(10);
 Analogue2 = analogRead(2)/4;
 delay(10);
 Analogue3 = analogRead(3)/4;
 delay(10);
 Analogue4 = analogRead(4)/4;
 delay(10);
 Analogue5 = analogRead(5)/4;
 delay(10);
// send sensor values:
 Serial.write(Analogue0 );
 Serial.write(Analogue1 );
 Serial.write(Analogue2 );
 Serial.write(Analogue3 );
 Serial.write(Analogue4 );
 Serial.write(Analogue5 );
 }
}
void establishContact() {
 while (Serial.available() <= 0) {
 Serial.write('A');// send a capital A
 delay(300);
 }
}
