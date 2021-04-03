
 const int Trig = 10; 
 const int Echo = 11;
 unsigned int time_us=0;
 unsigned int distance_sm=0;

  void readDistance()
{
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(Trig, LOW); // Затем убираем 
  time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
  distance_sm=time_us/58; // Пересчитываем в сантиметры 
  //distance_sm;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readDistance();
//Serial.print("Distance =   ");
Serial.println(distance_sm);
/*tone(8,(distance_sm*10));
delay(10);
noTone(8);
delay(10);
*/
delay(1000);
}
