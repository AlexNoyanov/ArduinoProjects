void Tone(int pin ,int friq , int volume){
  analogWrite(pin,volume);
  delay(1/friq);
  analogWrite(pin,0);
  delay(1/friq);
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<1023;i++){
Tone(A1,2000,i);
delay(100);
  }
}
