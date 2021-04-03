
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(12,INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int water = 13;
  int a = analogRead(A0);
//int b = digitalRead(12);
  Serial.begin(9600); 
Serial.println(a);
delay(500);
if (a < 300)
{ digitalWrite(water,HIGH);
 delay(10000);
}
 else  
 digitalWrite(water,LOW);
 
}
