int a = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while ( a >= 11) {
  int t = random(1,100);
  digitalWrite(a,HIGH);
  delay(t);
  digitalWrite(a,LOW); 
  delay(t);
  a = a-1;
}
a = 13;
}
