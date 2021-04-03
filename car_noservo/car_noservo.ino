   // #include "DHT.h"
  // #define DHTPIN 2     
 //#define DHTTYPE DHT11   
//DHT dht(DHTPIN, DHTTYPE);
 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);
 const int TrigL = 4; 
 const int EchoL = 5;
 const int TrigC = 7; 
 const int EchoC = 8;
 const int TrigR = 6; 
 const int EchoR = 9;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
  int kuda_ehat=0; // -1 - vlevo, +1 - vpravo, 0 - nazad
  int rasstoyanie=0;
  int vramya_povorotov=0;
/////////////////////////////////////////////////////////////////////////////////
void setup() {
/////////////////////////////////////////////////////////////////////////////////  
  Serial.begin(9600);
  lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5,1);
  lcd.print("3ArPy3kA");
  
  tone(3,2000);
  delay(500);
  noTone(3);
  tone(3,1500);
  delay(500);
  noTone(3);
  tone(3,1000);
  delay(500);
  noTone(3);
  tone(3,2500);
  tone(3,1600);
  delay(500);
  noTone(3);
  delay(500);
  noTone(3);
  // put your setup code here, to run once:   
   pinMode(TrigL, OUTPUT); 
   pinMode(EchoL, INPUT);   
   pinMode(TrigC, OUTPUT); 
   pinMode(EchoC, INPUT);   
   pinMode(TrigR, OUTPUT); 
   pinMode(EchoR, INPUT);   

   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   
//if(firsttime == 1)
//{
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("npuBeT Mup!");
  delay(100);
//  firsttime = 0;
//}
   
}

void motor_stop()
{
  Serial.print("motor_stop");
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  noTone(3);
}

void motor_vpered()
{
   lcd.setCursor(0,1);
    lcd.print("Bnepeg");
    //delay(100);
  Serial.print("motor_vpered");
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  tone(3,1000);
  
}

void motor_nazad()
{
   lcd.setCursor(0,1);
    lcd.print("Ha3ag");
  Serial.print("motor_nazad");
  //delay(100);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  tone(3,1500);
}

void motor_vlevo()
{ delay(500);
   lcd.setCursor(0,1);
    lcd.print("noBopoT Ha ^eBo");
    //delay(100);
  Serial.print("motor_vlevo");
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  tone(3,2000);
}

void motor_vpravo()
{
   lcd.setCursor(0,1);
    lcd.print("noBopoT Ha npaBo");
    //delay(100);
  Serial.print("motor_vpravo");
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  tone(3,2500);
}

int readDistance(int trig, int echo)
{
  digitalWrite(trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
   digitalWrite(trig, LOW); // Затем убираем 
     time_us=pulseIn(echo, HIGH); // Замеряем длину импульса 
       distance_sm=time_us/58; // Пересчитываем в сантиметры 
  if(distance_sm == 0)
    return 200;
  return distance_sm;
}
int readDistanceL()
{
  return readDistance(TrigL, EchoL);
}
 int readDistanceC()
{
  return readDistance(TrigC, EchoC);
}
int readDistanceR()
{
  return readDistance(TrigR, EchoR);
}

const int EHAT_VLEVO  = -1;
const int EHAT_VPRAVO = +1;
const int EHAT_VPERED = 2;

int naidi_levo_pravo()
{
    int dd1 = readDistanceL();
    int dd2 = readDistanceR();
    if(dd1 < 5 && dd2 < 5)
    {
      return 0;
    } else {
      if(dd1 < dd2) {
        return EHAT_VLEVO;
      } else {
       return EHAT_VPRAVO;
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
  if(kuda == EHAT_VLEVO)
    motor_vlevo();
  else if(kuda == EHAT_VPRAVO)
    motor_vpravo(); 
  else
    motor_vpered();
   delay(skorost*15); 
}

int distance2speed(int d1)
{
  int skorost = 21;
  if(d1 < 70)
    skorost = 19;
  if(d1 < 65)
    skorost = 17;
  if(d1 < 60)
    skorost = 15;
  if(d1 < 55)
    skorost = 13;
  if(d1 < 50)
    skorost = 11;
  if(d1 < 45)
    skorost = 9;
  if(d1 < 40)
    skorost = 7;
  if(d1 < 35)
    skorost = 5;
  if(d1 < 30)
    skorost = 3;
  if(d1 < 25)
    skorost = 0;
    
   return skorost;
}

int firsttime = 1;
int povorot=0;
int skorost = 0;
/////////////////////////////////////////////////////////////////////////////////////
void loop() {
/////////////////////////////////////////////////////////////////////////////////////

//   int h = dht.readHumidity();
//    int t = dht.readTemperature();
//    int tt = t;
//    int hh = h;
//      lcd.setCursor(13,0);
//       lcd.print("T=");
//        lcd.setCursor(15,0);
//         lcd.print(tt );
//         lcd.setCursor(16,1);
//       lcd.print("H=");
//        lcd.setCursor(18,1);
//         lcd.print(hh );


  // put your main code here, to run repeatedly:
//  delay(1000);
//  digitalWrite(10, LOW); //10-> правая вперед
//  digitalWrite(11, LOW); //11-> левая вперед
//  digitalWrite(12, LOW);//12-> правая назад
//  digitalWrite(13, HIGH);//13->левая назад
//  return;

//  int dL = readDistanceL();
//  int dC = readDistanceC();
//  int dR = readDistanceR();

  
  int dC = readDistanceC();
  lcd.setCursor(0,3);
  lcd.print("dC=");
  lcd.print(dC);

  lcd.print("   ");
  
  int mindistance = 25 + skorost * 4;
  lcd.setCursor(0,2);
  lcd.print("minD=");
  lcd.print(mindistance);
  if(dC > mindistance)
  {
    lcd.print(" =>    ");
    motor_vpered();
    delay(100);
    skorost++;
    if(skorost > 4)
       skorost = 4;
  } else {
    if(skorost == 0)
    {
     lcd.print(" <>    ");
     if(povorot == +1)
       motor_vlevo();
     else
       motor_vpravo();
     delay(160);
     povorot = 1;
     motor_stop();
     delay(300);
     skorost = 0;
    } else {
      lcd.print(" ||    ");
      motor_stop();
      delay(100);
      skorost = 0;
      int dL = readDistanceL();
      int dR = readDistanceR();
      if(dL > 25 || dR > 25) // есть куда повернуть
      {
      if(dL < dR)
        povorot = +1;
       else
        povorot = -1;
      } else { // тупик - назад
        motor_nazad();
        delay(200);
        motor_stop();
        povorot = random(10) < 5 ? +1 : -1;
      }
     lcd.setCursor(8,2);
     lcd.print(" dL=");
     lcd.print(dL);
     lcd.print(" dR=");
     lcd.print(dR);   
    }     
  }
//  Serial.print("dL=");
//  Serial.print(dL);
//  Serial.print("    dC=");
//  Serial.print(d1);
//  Serial.print("    dR=");
//  Serial.print(dR);
//  Serial.println("");
/*
  if( ((dL < 5) && (dR < 5)) || (vramya_povorotov == 5))
  {
    Serial.println("(dL < 10) && (dR < 10)");
    motor_nazad();
    int rdelay = random(50);
    delay(rdelay);
    if(dR < dL)
      ehat(EHAT_VLEVO, 5);
    else  
      ehat(EHAT_VPRAVO, 5);
    vramya_povorotov = 0;
    return;
  } else {
    Serial.print("rasstoyanie=");
    Serial.println(d1);
    lcd.setCursor(0,2);
     lcd.print("nepeg:");
       lcd.setCursor(8,2);
         lcd.print(d1);
        
       lcd.setCursor(11,3);
        lcd.print("^eBo:");
         lcd.print(dL);
          
          lcd.setCursor(0,3);
           lcd.print("npaBo:");
            lcd.print(dR);
        delay(100);
    if(dL < 3) // зацепит углом
    {
      ehat(EHAT_VPRAVO, 5);
    } else  if(dR < 3) // зацепит правым углом
    {
      ehat(EHAT_VLEVO, 5);
      return;
    } else { 
      if(d1 > 25)
      { 
        int skorost = distance2speed(d1);
        Serial.print("Svobodbo. Edem skorost= ");
        Serial.println(skorost);
        ehat(EHAT_VPERED, skorost);
        rasstoyanie += skorost;
        if(rasstoyanie > 100)
           vramya_povorotov = 0;
      } else {
        motor_stop();
        kuda_ehat = naidi_levo_pravo();
        Serial.print("Prepatstvie. Povorot ");
        Serial.println(kuda_ehat);
        ehat(kuda_ehat, 10);
        vramya_povorotov++;
      } 
    }
  }
    motor_stop();
    delay(50);
*/

}
