#include <Servo.h>
   int buttonState1=0; //переменная для хранения данных с кнопки
   bool isButton1Pressed = false; // переменная для отслеживания отпуская и нажатия кнопки
   Servo serva ;
   Servo serva2;
   const int buttonPin = 6;  // контакт кнопки 1
   const int ledPin=12;
   const int soundPin=11;
   
   
void setup() {
  // put your setup code here, to run once:
   pinMode(buttonPin, INPUT);
   pinMode(ledPin,OUTPUT);
   pinMode(soundPin,OUTPUT);
   serva.attach(9);
   serva2.attach(10);
   digitalWrite(ledPin, LOW);
    Serial.begin(9600); 
   serva.write(10);
   serva2.write(10);  
   for(int i = 1000; i < 3000; i+=300)
   {
     tone(soundPin,i);
     delay(50);
   }  
   noTone(soundPin);
}

void loop() {
  // 
  // digitalWrite(ledPin, LOW);
   buttonState1 = digitalRead(buttonPin); //считываем с кнопки1
  if(buttonState1 == HIGH)
   { 
     digitalWrite(ledPin,LOW);
     tone(soundPin,3000);
     delay(100);
     tone(soundPin,2000);
     delay(100);
     tone(soundPin,1000);
     delay(100);
     noTone(soundPin);
     delay(800);
     serva.write(150);
     delay(1000);
     serva2.write(100);
     delay(1000);
    serva2.write(10);
    delay(1000);
    serva.write(10);
    delay(1000);
    serva.write(10);
    serva2.write(10);  
     digitalWrite(ledPin, HIGH);
     delay(100);
   }
   else {
     digitalWrite(ledPin, HIGH);
     delay(100);
   }
}
