
/*
  Кнопка
  
 Включаем и выключаем светодиод нажатием кнопки.
  
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 28 Oct 2010
 by Tom Igoe
  
 This example code is in the public domain.
 */
 
// задаем константы
const int buttonPin = 2;     // номер входа, подключенный к кнопке
const int ledPin =  13;      // номер выхода светодиода
const int soundPin = 7;      // номер выхода для динамика
 
// переменные
int buttonState = 0;         // переменная для хранения состояния кнопки
 
void setup() {
  // инициализируем пин, подключенный к светодиоду, как выход
  pinMode(ledPin, OUTPUT);     
  // инициализируем пин, подключенный к кнопке, как вход
  pinMode(buttonPin, INPUT);   
}


void bomb()
{
  for(int i = 5000; i > 1000; i -= 50)
  {
    tone(soundPin, i);
    delay(10);
  }
  noTone(soundPin);
}
 
void loop(){
  // считываем значения с входа кнопки
  buttonState = digitalRead(buttonPin);
 
  // проверяем нажата ли кнопка
  // если нажата, то buttonState будет HIGH:
  if (buttonState == LOW) {   
    // включаем светодиод   
    digitalWrite(ledPin, LOW); 
  }
  else {
    // выключаем светодиод
    digitalWrite(ledPin, HIGH);
    bomb();
  }
}


