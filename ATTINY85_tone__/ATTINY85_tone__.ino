
int pin = 1;
void Ton(int pn,int freq)
{
  long del = (1/freq) * 100000;
  digitalWrite(pn,HIGH);
  delay(del);
  digitalWrite(pn,LOW);
  delay(del);
}
void setup() {
  // put your setup code here, to run once:
pinMode(pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Ton(pin,100);
}
