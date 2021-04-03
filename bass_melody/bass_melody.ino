//  Buzzer pin:
const int pin = 8;

//  Get up the buss:
void bassUp(int start,int ending,int t) {
  for(start;start<ending;){
  tone(pin,start);
  delay(t);
  noTone(pin);
  delay(t);
  start = start +10;
  }
}

//  Get down bass:
void bassDown(int start,int ending,int t) {
  for(start;start>ending;){
  tone(pin,start);
  delay(t);
  noTone(pin);
  delay(t);
  start = start -10;
  }
}
void setup() {
  // put your setup code here, to run once:

  //  Power sound:
  for(int i  = 0 ; i<2;i++){
  tone(pin,100);
  delay(600);
  noTone(pin);

  delay(100);

  tone(pin,200);
  delay(600);
  noTone(pin);
  
  delay(100);

  tone(pin,100);
  delay(600);
  noTone(pin);
  
  delay(500);

  }
  //  Up and down:
bassUp(100,1100, 8);
bassDown(1100,100,8);

}

void loop() {
  // put your main code here, to run repeatedly:

}
