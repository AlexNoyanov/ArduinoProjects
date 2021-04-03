int friq=11111;
void setup() {
  // put your setup code here, to run once:
  while(friq%10!=0){
friq = random(500,3000);
}
Serial.begin(9600);
Serial.print("Friqency = ");
Serial.println(friq);
}

void loop() {
  // put your main code here, to run repeatedly:
tone(8,1000);
}
