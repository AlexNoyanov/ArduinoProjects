#include <Servo.h>
Servo myservo;

 const int Trig = 10; 
 const int Echo = 11;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
  long duration;
  int distance;
  int tme = 10;
  int angle = 0;
  int prev_angle = -1;

int readDistance()
{
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(Trig, LOW); // Затем убираем 
  time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
  distance_sm=time_us/58; // Пересчитываем в сантиметры 
  //distance_sm;
  return distance_sm;
}

void setup() {
  // put your setup code here, to run once:
  // Power Up ultrasonc sensor;
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH); // Turn on 5v on 7 pin
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(Echo, INPUT); // Sets the echoPin as an Input
  myservo.write(0);
}


void loop() 
{
  // put your main code here, to run repeatedly:
  int sm = readDistance();
  Serial.print("Distance =   ");
  Serial.println(sm);
  if((sm > 10) && (sm < 20)) 
  {
    angle = 100;
    myservo.write(angle);
    delay(1500);
    //readDistance();
    //readDistance();
  } else {
    angle = 0;
  }
  if(angle != prev_angle) {
    Serial.print("Angle = ");
    Serial.println(angle);
    prev_angle = angle;
    myservo.write(angle);
  }
  delay(100);
}

