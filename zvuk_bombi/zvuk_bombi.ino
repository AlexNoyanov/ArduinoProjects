void setup() {
  int i = 0;
  const int a = 13;
  
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); }
void loop() {
  // put your main code here, to run repeatedly:
 
  for(int i = 7000; i > 2000; i -= 50)
  {
    tone(12, i);digitalWrite(i, HIGH);
    delay(100);
  }
  noTone(12);
  delay(1000);
}
 



