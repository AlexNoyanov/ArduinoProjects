
int friq1 = 200;
int friq2= 100;
void lowbip() {
tone(9,friq2);
}

void basbip(){

 tone(8,friq1); 
}
void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);
pinMode(6,INPUT);
//basbip();
lowbip();
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
int button1 = digitalRead(7);
int button2 = digitalRead(6);
if (button2 == HIGH) {
  lowbip();
  delay(100);
}

else {
  noTone(9);
}
if(button1 == HIGH) 
{ friq2 = 300;
  lowbip();
  delay(100);
}
else {
  friq2 = 100;
noTone(9);
}
}
