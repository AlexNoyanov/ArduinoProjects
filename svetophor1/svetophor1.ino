int a = 13;
int b = 12;
int c = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(a, HIGH);
delay(10000);
digitalWrite(a, LOW);
delay(500);
digitalWrite(b, HIGH);
delay(1000);
digitalWrite(b, LOW);
delay(1000);
digitalWrite(c, HIGH);;
delay(100);
digitalWrite(c, HIGH);
delay(10000);
digitalWrite(c, LOW);
delay(1000);
digitalWrite(b, HIGH);
delay(1000);
digitalWrite(b, LOW);
delay(1000);
}
