
int tonen = 1000;
int timen = 100;

void setup() {
  // put your setup code here, to run once:
  
}

void bomb()
{
  for(int i = 5000; i > 1000; i -= 10)
  {
    //tone(7,i);
    delay(10);
    noTone(7);
  }
}

void loop() {
  bomb();
  
  // put your main code here, to run repeatedly:
  //tonen = random(1000, 5000);
  //timen = random(300, 1500);
  //tone(7,tonen);
  //delay(timen);
  //noTone(7);
  //delay(timen);
}
