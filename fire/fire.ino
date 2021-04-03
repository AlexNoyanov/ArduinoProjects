

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(12,INPUT);
pinMode(A0,INPUT);
}

void signal(void)
{
  //
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int digital = digitalRead(12);
  int analog = 1024-analogRead(A0);
  //Serial.print("digital=");
  //Serial.print(digital);
  Serial.print("\r\n");
  Serial.print("analog=");
  Serial.print(analog);
  Serial.print("\r\n");
  if(analog > 850)
  {
    signal();
  }
  delay(1000);
}


