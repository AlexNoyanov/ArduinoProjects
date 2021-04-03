//  Button and RGB Led

int red = 8;
int green = 9;
int blue = 10;
int button = 12;
int buttonValue;
int tme = 2000;
void Bip(int friq ,int i){
  //  Beep 0,1 second
  for(i;i>0;i--){
  tone(7,friq);
  delay(25);
  noTone(7);
  delay(25);
  tone(7,friq+100);
  delay(25);
  noTone(7);
  delay(900);
  }
}
  void buttonActive(){
    
    tone(7,2000);
    delay(50);
    noTone(7);
    delay(50);
   // 
    tone(7,1000);
    delay(50);
    noTone(7);
    delay(50);
    /*
    tone(7,2000);
    delay(50);
    noTone(7);
    delay(20);
*/
    tone(7,500);
    delay(50);
    noTone(7);
    delay(50);

    /*
    tone(7,1000);
    delay(50);
    noTone(7);
    delay(100);
    */
  }

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(button,INPUT);
buttonActive();
digitalWrite(blue,HIGH);
digitalWrite(green,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
//int value = analogRead(A0);
//int friq = map(value,0,1023,100,3000);


  
buttonValue = digitalRead(button);
if(buttonValue == HIGH){
  digitalWrite(blue,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  buttonActive();
  delay(200);
 Bip(100,5);
    }else{
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  }
  
}
