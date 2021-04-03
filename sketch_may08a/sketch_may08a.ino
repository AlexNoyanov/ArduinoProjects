long a = random(7,12);
long t = random(2000);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(a,OUTPUT);
/*pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(19,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(13,OUTPUT);
*/pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(a,HIGH);
delay(t);
digitalWrite(a,LOW);
delay(t);
}
