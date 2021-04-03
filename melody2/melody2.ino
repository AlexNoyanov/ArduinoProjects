int p  = 9;
int f = 2000;
int z = 200;
int zz = 100;
void setup() {
  // put your setup code here, to run once:
tone(p,1000);
delay(z);
noTone(p);
delay(z);
tone(p,800);
delay(z);
noTone(p);
delay(z);
while(f> 1500) {
  tone(p,f);
  delay(zz);
  noTone(p);
  f = f-100;
}


tone(p,2000);
delay(z);

noTone(p);

tone(p,800);
delay(z);
noTone(p);
delay(z);
tone(p,600);
delay(z);
noTone(p);
delay(z);
tone(p,800);
delay(z);
noTone(p);
}

void loop() {
  // put your main code here, to run repeatedly:

}
