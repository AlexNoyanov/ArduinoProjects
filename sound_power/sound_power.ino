int sound = 0;
int friq= 100;
int friq2 = 300;
int tme = 100;
int ltme = 1000;

void bipton(){
  tone(9,friq2);
delay(10);
}

void basbip(){

 tone(8,friq);
delay(ltme);
noTone(8); 
}
void bass() {

basbip();
friq=200;
delay(tme);
basbip();
delay(tme);
friq = 100;
basbip();
delay(ltme);
}

void up() {
   while (friq2<800) {
    bipton();
    friq2 = friq2+ 10;
    noTone(9);
    delay(5);
  }
}
  void down() {
while (friq2>100) {
    bipton();
    friq2 = friq2- 10;
    noTone(9);
    delay(5);
  }
  }

void setup() {
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  friq2 = 800;
  
  noTone(9);
  // put your setup code here, to run once:
  for(int k = 0;k<=1;k++){
   bass();
   friq2 = 100;
up();
down();
bass();
delay(1000);
Serial.begin(9600);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
bipton();
delay(1000);
friq2 = 1500;
bipton();
delay(1000);
bipton();
friq2 = 1000;
delay(1000);
*/

}
