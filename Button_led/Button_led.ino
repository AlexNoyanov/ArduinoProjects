int flag = 0;       // Флаг
int buttonState = 0;
int buttonValue;
int buttonPin = 8;  // Пин для кнопки
int ledPin = 9;     // Пин для светодиода
int musicSpeed = 5;
int buzPin = 10;

void musicOn(){
  for(int i = 100; i < 1000; i = i+10){
    tone(buzPin,i);
    delay(musicSpeed);
    noTone(buzPin);
  }
}

void musicOff(){
  for(int i = 1000; i > 100; i = i-10){
    tone(buzPin,i);
    delay(musicSpeed);
    noTone(buzPin);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonValue = digitalRead(buttonPin);
//  Для тестов:
  //Serial.print("Значение кнопки:");
  //Serial.println(buttonValue);

 if(buttonValue == 1 && flag==0 && buttonState == 0) // Нажали на кнопку
 {  
  digitalWrite(ledPin, HIGH);                        // Загорелся светодиод
  musicOn();
 flag = 1;
 }
  if(flag ==1 && buttonValue == 0)         // Отпустили кнопку
  {
  buttonState = 1;                         // Подняли флаг, что горит
  } 
if(buttonValue == 1 && flag == 1 && buttonState ==1)  // Нажали с зажженной 
{
  digitalWrite(ledPin,LOW);                           // Потушили 
  musicOff();
  flag = 0;
}
if(buttonValue == 0 && flag ==0  && buttonState ==1){  // Отпустили потушенною
buttonState = 0;                                       // Опустили флаг
}




  
  //delay(100);
}
