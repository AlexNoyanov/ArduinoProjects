const int a = 13;
const int b = 12;
const int c = 11;
const int d = 10;
const int e = 9;
const int f = 8;
const int g = 7;
int buttonState = 0;
const int buttonPin = 2;
const int soundPin = 7;
int state = 1;


void setup() {
  // put your setup code here, to run once:
 pinMode(buttonPin, INPUT);
 
 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
 
 pinMode(soundPin, OUTPUT);  
}

/*void bomb1()
{
  for(int i = 1000; i < 5000; i += 50)
  {
    tone(soundPin, i);
    delay(10);
  }
  noTone(soundPin);
}
void bomb2()
{
  for(int i = 5000; i > 1000; i -= 50)
  {
    tone(soundPin, i);
    delay(10);
  }
  noTone(soundPin);
}
*/

void loop() {
// считываем значения с входа кнопки
  buttonState = digitalRead(buttonPin);
 
  // проверяем нажата ли кнопка
  // если нажата, то buttonState будет HIGH:
 // if (buttonState == LOW) {   
    // включаем светодиод   
    //digitalWrite(ledPin, LOW); 
   // bomb1();
    //state = 0;
  //}
  //else {
    //state = 1;
    // выключаем светодиод
    //digitalWrite(ledPin, HIGH);
    //bomb2();
  //}  
  
 // if(state == 0)
  //return;
  
  // put your main code here, to run repeatedly:
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);

delay(100);
digitalWrite(f, LOW);
delay(100);
digitalWrite(e, LOW);
delay(100);
digitalWrite(d, LOW);
delay(100);
digitalWrite(c, LOW);
delay(100);
digitalWrite(b, LOW);
delay(100);
 digitalWrite(a, LOW);
 delay(100);
digitalWrite(f, HIGH);
delay(100);
digitalWrite(e, HIGH);
delay(100);
digitalWrite(d, HIGH);
delay(100);
digitalWrite(c, HIGH);
delay(100);
digitalWrite(b, HIGH);
delay(100);
 digitalWrite(a, HIGH);
 delay(100);
 
 //bomb();
}


