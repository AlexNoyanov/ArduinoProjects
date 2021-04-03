// Arduino Stroboscope
// Connect led to the pin 

int freq;
int period;
int pin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
//Serial.be
}

void loop() {
  // put your main code here, to run repeatedly:
  period = map(analogRead(A0), 10,900,1,100);
  //freq= 1/(period*1000);
  digitalWrite(pin,HIGH);
  //delay(period);
  delayMicroseconds(period);
  digitalWrite(pin,LOW);
  //delay(period);
  delayMicroseconds(period);
}
