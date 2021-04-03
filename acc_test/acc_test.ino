void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x = analogRead(A0);
int y  = analogRead(A1);
int z = analogRead(A2);
//Serial.print("X=");
Serial.println(x);
//Serial.print("    Y=");
//Serial.print(y);
//Serial.print("        Z=");
//Serial.println(x);
delay(100);
}
