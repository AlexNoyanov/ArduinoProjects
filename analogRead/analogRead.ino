
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
/*
Serial.println(" ===============");
Serial.println(" | Name | Value|");
Serial.println(" ===============");
*/

analogWrite(A2,0);
analogWrite(A1,1024);
}

void loop() {
  // put your main code here, to run repeatedly:
 // tone(8,500);
int pin = analogRead(A0);
Serial.println(pin);
delay(100);
/*
Serial.print("|  ");
Serial.print("Pulse");
Serial.print(" | ");
Serial.print(pin);
Serial.println(" |");
Serial.println("|________|______|");
*/
//delay(100);
}
