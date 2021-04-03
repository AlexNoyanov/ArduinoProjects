#include <Servo.h>


Servo myservo;
 const int Trig = 7; 
 const int Echo = 8;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
  int kuda_ehat=0; // -1 - vlevo, +1 - vpravo, 0 - nazad

void setup() {
  // put your setup code here, to run once:
   myservo.attach(9);
   servo_center();
   
   pinMode(Trig, OUTPUT); 
   pinMode(Echo, INPUT);   

   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
}

void motor_stop()
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void motor_vpered()
{
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void motor_nazad()
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void motor_vlevo()
{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}

void motor_vpravo()
{
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
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

void servo_left()
{
  myservo.write(10);
  delay(500);
}

void servo_right()
{
  myservo.write(170);
  delay(500);
}

void servo_center()
{
  myservo.write(90);
}

int naidi_levo_pravo()
{
    servo_left();
    int dd1 = readDistance();
    servo_right();
    int dd2 = readDistance();
    servo_center();
    if(dd1 < 5 && dd2 < 5)
    {
      return 0;
    } else {
      if(dd1 < dd2) {
        return -1;
      } else {
       return +1;
      }
    }
    return 0;
}

void ehat(int kuda, int skorost)
{
  if(skorost == 0)
  {
    motor_stop();
    return;
  }
  if(kuda == -1)
    motor_vlevo();
  else if(kuda == +1)
    motor_vpravo();  //  {
//    motor_vpered();
//    delay(100);
//  } else {
//    servo_left();
//    int dd1 = readDistance();
//    servo_right();
//    delay(200);
//    int dd2 = readDistance();
//    servo_center();
//    if(dd1 < 10 && dd2 < 10)
//    {
//      motor_nazad();
//    } else {
//      if(dd1 < dd2) {
//        motor_vlevo();
//      } else {
//        motor_vpravo();
//      }
//    }
//    delay(200);
//  }
*/
}

int distance2speed(int d1)
{
  int skorost = 10;
  if(d1 < 70)
    skorost = 9;
  if(d1 < 65)
    skorost = 8;
  if(d1 < 60)
    skorost = 7;
  if(d1 < 55)
    skorost = 6;
  if(d1 < 50)
    skorost = 5;
  if(d1 < 45)
    skorost = 4;
  if(d1 < 40)
    skorost = 3;
  if(d1 < 35)
    skorost = 2;
  if(d1 < 30)
    skorost = 1;
  if(d1 < 25)
    skorost = 0;
    
   return skorost;
}


void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);
  int d1 = readDistance();
  if(d1 > 25)
  { 
    int skorost = distance2speed(d1);
    ehat(2, skorost);
  } else {
    motor_stop();
    kuda_ehat = naidi_levo_pravo();
    ehat(kuda_ehat, 15);
  } 
    motor_stop();
    delay(50);
/*  
//  if(d1 > 30)
//  {
//    motor_vpered();
//    delay(100);
//  } else {
//    servo_left();
//    int dd1 = readDistance();
//    servo_right();
//    delay(200);
//    int dd2 = readDistance();
//    servo_center();
//    if(dd1 < 10 && dd2 < 10)
//    {
//      motor_nazad();
//    } else {
//      if(dd1 < dd2) {
//        motor_vlevo();
//      } else {
//        motor_vpravo();
//      }
//    }
//    delay(200);
//  }
*/
}
