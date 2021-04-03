 int l = 6;
 int ledd = 13;
 int v =12;
 int n = 10;
 int b = 9;
 int c = 8;
 int d = 7;


void setup() {
  // put your setup code here, to run once:
   pinMode(ledd, OUTPUT);
   pinMode(v, OUTPUT);
   pinMode(n, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
    pinMode(l, OUTPUT);
   
 
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledd, HIGH);
digitalWrite(v, HIGH);
digitalWrite(n, HIGH);
digitalWrite(b, LOW);  
  digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
  digitalWrite(l, HIGH);
   
    delay(1000);
    digitalWrite(ledd, LOW);
    digitalWrite(d, LOW);
    digitalWrite(l, LOW);
    digitalWrite(v, LOW);
    delay(1000);
    digitalWrite(d, HIGH);
    digitalWrite(l, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(v, HIGH);
   
   
   
    
    
    
    
   
  
}
