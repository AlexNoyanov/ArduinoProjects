void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int a = analogRead(A0);
// int b = analogRead(A1);
 // int c = analogRead(A2);
// int d = analogRead(A3);
 Serial.print("button1=");
 Serial.println(a);
 delay(500);
/* Serial.print("Y-Axis=");
 Serial.println(b);
 delay(1000);
 Serial.print("X-Axis=");
 Serial.println(c);
 delay(1000);
 Serial.print("button2=");
 Serial.println(d);
 delay(1000);
*/
}
