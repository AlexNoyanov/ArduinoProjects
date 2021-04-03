
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
//tone(8,3500);
for(int i = 0; i < 1000; i++)
{
 analogWrite(A1, i);
 delayMicroseconds(45);
}
/*
for(int i = 1000; i >=0 ; i--)
{
 analogWrite(A1, i);
 delayMicroseconds(5);
}
*/

}
