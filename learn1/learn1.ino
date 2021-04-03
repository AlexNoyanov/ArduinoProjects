
//#include <math.h> 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
}

//double v;
void loop() {
  tone(7,1000);
 digitalWrite(8,HIGH);
 delay(1);
 digitalWrite(8,LOW);
 noTone(7);
 delay(1);
  // put your main code here, to run repeatedly:
 /* v = pow(2,9);
  Serial.println("2^79=");
  Serial.println(v, DEC);
  delay(1000);
*/

}
