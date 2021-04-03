/*
** Ночник
**
** www.hobbytronics.co.uk
*/


int sensorPin = A0;            // устанавливаем входную ногу для АЦП
unsigned int sensorValue = 0;  // цифровое значение фоторезистора
void setup()
{
  pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
  Serial.begin(9600);        // старт последовательного вывода данных (для тестирования)
}
 
void loop()
{
  sensorValue = analogRead(sensorPin);  // считываем значение с фоторезистора
  if(sensorValue<500) digitalWrite(13, HIGH); // включаем
  else  digitalWrite(13, LOW);   // выключаем   

 

  // Для отладки раскомментируйте нижеследующие строки
  //Serial.print(sensorValue, DEC);     // вывод данных с фоторезистора (0-1024)
  //Serial.println("");                 // возврат каретки  
  //delay(500);  
}
