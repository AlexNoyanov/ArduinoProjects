
void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
digitalWrite(10,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a =  random(0,3);
  if (a == 1) { int g = random (1,10);
  while (g > 0) {
int rton = random(10,5000);
int time = random(10,300);
tone (8,rton);
delay(time);
noTone(8);
delay(time);
g = g-1;
  }
  }
  if (a == 2) {
    int minim = random( 100,2000);
    int m = random( 10,100);
    int time = random(10,50);
   int rton = random(10,5000);
  while (rton >minim ) { 
    tone (8,rton);
    rton = rton - m;
    delay(time);
    noTone(8);
  }
  }
  
  if (a == 3) {
    int maximum= random( 100,2000);
    int m = random( 10,100);
    int time = random(10,100);
   int rton = random(10,1000);
  while (rton <maximum) { 
    tone (8,rton);
    rton = rton + m;
    delay(time);
    noTone(8);
  }
  }
}
  

