 const int Trig = 7; 
 const int Echo = 8;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
void setup() {
   // put your setup code here, to run once:
   pinMode(Trig, OUTPUT); 
   pinMode(Echo, INPUT);  
   Serial.begin(9600);
}


  int readDistance()
{
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(Trig, LOW); // Затем убираем 
  time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
       distance_sm=time_us/58; // Пересчитываем в сантиметры 
  return distance_sm;
}




void loop() {
  // put your main code here, to run repeatedly:
 int h = readDistance() ;
 Serial.print("distance=");
 Serial.println(h);
 bool isTone = (h < 50) && (h > 2);
 if (isTone ) {
  int a = 600 + 150*h;
  tone (12, a);
 Serial.print("a=");
 Serial.println(a);
 } else {
  noTone(12);
 }
}


