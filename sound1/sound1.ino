void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int a = 100;
while ( a < 3000) {
  tone (8, a );
  delay(250);
  a = a+10;
 noTone(8);
}
  
}
