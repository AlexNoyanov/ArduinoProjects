int friq = 100;
int ltme =50;
void bip() {
  tone(8,friq);
  delay(ltme);
  noTone(8);
}
void ton() {
bip();
delay(100);
friq = 1000;

bip();
delay(100);
friq = 1500;

bip();
delay(100);
friq = 1000;

bip();
delay(100);
friq = 2000;
  
}
void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
digitalWrite(5,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
ton();

bip();
delay(100);
friq = 500;
ton();

bip();
delay(100);
friq = 1000;

bip();
delay(100);
friq = 1500;

bip();
delay(100);
friq = 4000;

bip();
delay(100);
friq = 3000;

bip();
delay(100);
friq = 1000;

bip();
delay(100);
friq = 1500;

bip();
delay(100);
friq = 1000;

ton();

bip();
delay(100);
friq = 4000;

ton();

bip();
delay(100);
friq = 3500;





  }
