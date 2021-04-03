
int p = 8;
void setup() {
  // put your setup code here, to run once:

pinMode(5,OUTPUT);
digitalWrite(5,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int a = 0;
  

  while( a<3){
  int c= 0;
  while( c< 3){
  int i = 0; ;
  while (i<3){
  int g = 3000;
tone(p,1000);
delay(100);
noTone(p);
delay(100);
tone(p,2000);
delay(100);
noTone(p);
delay(100);
i++;
  }
  tone(p,1500);
  delay(100);
  noTone(p);
  delay(100);
  c++;
  
  } int h = 0;
  
 
  tone(p,800);
  delay(100);
  noTone(p);
  delay(100);
 a++;
  }

}
