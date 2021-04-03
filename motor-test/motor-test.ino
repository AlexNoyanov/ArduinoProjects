int i = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(A0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(4,HIGH);
//delay(1000);
digitalWrite(4,LOW);
//delay(100);
/*i = 0;
while(i<1024){
  i = i*2;
analogWrite(A0,i);
Serial.print("I= ");
Serial.println(i);
delay(100);
}
/*
delay(1000);
digitalWrite(4,LOW);
delay(1000);
*/
}
