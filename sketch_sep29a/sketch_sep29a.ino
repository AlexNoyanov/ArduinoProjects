 #include <Servo.h>
 #include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11 ,6 , 5, 4, 3, 2);
 Servo serva ; 
 const int Trig = 8; 
  const int Echo = 9;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
    void setup() 
  { 

     Serial.begin(9600); 
  }
 void loop() 
 {   Serial.begin(9600);
    lcd.clear();
      lcd.setCursor(0,0);
       lcd.print ("npuBeT Mup");
 serva.write(95);
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
   digitalWrite(Trig, LOW); // Затем убираем 
     time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
       distance_sm=time_us/58; // Пересчитываем в сантиметры 
         Serial.println(distance_sm); // Выводим на порт
         if (distance_sm < 10) 
         {
           serva.write(10);
           delay(1000);
           serva.write(200);
           delay(1000);
         }
   delay(500); 
}
