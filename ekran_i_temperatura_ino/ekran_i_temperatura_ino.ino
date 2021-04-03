#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 7     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13;    // pin 13 will control the backlight
int sensorPin = A0;
unsigned int sensorValue = 0;
int time=0;
int tmin = 15;
int tmax = 28;


void setup()
{
   /*irrecv2.enableIRIn(); 
   Serial.begin(9600); 
  Serial.println("arduino.ru.com"); 
  dht.begin();
  pinMode(A1, OUTPUT);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
*/  lcd.clear();                  // start with a blank screen
}


void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Failed to read from DHT");
  } else {
    int tt = t;
    int hh = h;
    Serial.println(" *C");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(tt);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humd:"); 
    lcd.print(hh);
    lcd.print("%");
    delay(100);
    if(t < 18)
    {tone(13,1500);
    delay(1000);
    noTone(13);
    delay(1000);
    }else{
      noTone(13);}
   if( t > 25)
  {tone(13,2000);
  delay(1000);
  noTone(13);
  delay(1000);
  } else{
    noTone(13);}
  sensorValue = analogRead(sensorPin);  // считываем значение с фоторезистора
  Serial.print("sensorValue=");
  Serial.println(sensorValue);
  if(sensorValue>350) 
  {
    lcd.setCursor(12,0);    
    lcd.print("day");
    switchRele(LOW);
  } else  {
    lcd.setCursor(11,0);
    lcd.print ("night");
   }
  }
  if (sensorValue<270) 
   switchRele(HIGH); 
  
  lcd.setCursor(12,1);
  if(t > tmax)  
  {
    lcd.print("hot");
  } else {
    if(t < tmin)
    {
      lcd.print("cold");
    } else {
      lcd.print("ok");
    }      
  }
}

int lastSwitch=0;
int currentValue=-1;
void switchRele(int value)
{
  Serial.print("value=");
  Serial.println(value);
  if(currentValue == value)
    return;
  int time = millis();
  Serial.print("time - lastSwitch=");
  Serial.println((time - lastSwitch));
  if((time - lastSwitch) > 5000)
  {
    currentValue = value;
    lastSwitch = time;
    digitalWrite(A1, value);
  }
}


