//#include "math.h"
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
while(!Serial);
for(int i = 0; i <10;i++){
Serial.println(0);
delay(100);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
for(double i = -1.0; i <= 1.0; i = i + 0.08) {
  Serial.println(sin(i));
  delay(10);
}
for(double i = -1.0;i <= 1.0; i = i + 0.08) {
  Serial.println(sin(i));
  delay(10);
}
*/
Serial.println(analogRead(A0));
delay(100);
}
