int niz = 13;
int levbok = 12;
int pravbok = 11;
int a = 1;
int b = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(levbok, OUTPUT);
  pinMode(niz, OUTPUT);
  pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(niz, HIGH);
   digitalWrite(levbok, HIGH);                                                         
  delay(500);
   digitalWrite(levbok, LOW);
  digitalWrite(niz, LOW);
  delay(500); 
   digitalWrite(a, HIGH);
  delay(500);
   digitalWrite(a, LOW);
    delay(500); 
  digitalWrite(b, HIGH);
 delay(500); 
   digitalWrite(b, LOW);
    delay(500); 
}
