


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int v = digitalRead(8);
  //if(v == HIGH || 1)
  {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
  } 
  //else {
 // }
}

