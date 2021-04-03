// CAR with marker
// angle test #1
//
// turn on pin:
// 12 right fwd
// 13 h r back
// 11 h left fwd
// 10 high left back


void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
/*
digitalWrite(11,HIGH);
delay(1000);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
delay(2000);
digitalWrite(13,LOW);
digitalWrite(11,LOW);
delay(3000);
*/
}
