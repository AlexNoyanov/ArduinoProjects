//  Serial test programm
//  By Alex Noyanov

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int t = 10;
 // for(int i = 10;i<100;i++){
Serial.print(t);
Serial.print("\n");
delay(2);
  //}
}
