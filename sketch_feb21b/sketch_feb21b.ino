
//  Bot Automatic driving test

//  This library is under MIT License protection  
//
//  Created by Alex Noyanov 
//  mail: Alex.noyanov@gmail.com

// Connection scheme:
//  Pin | Action
//  ____|_________________________
//  9   | Left motor Back (LB)
//  8   | Left motor Forward (LF)
//  11  | Right motor Back  (RB)
//  10  | Right motor Forward (RF)
//  ____|_________________________

#include <RoboCar.h>
#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);
RoboCar myBot;

extern uint8_t SmallFont[];
float y,yy = 0;
const int a = 25;

  // Pins:
 int Ltrig = 2;
 int Ftrig = ;
 int Rtrig = ;

 int Lecho = ;
 int Fecho = ;
 int Recho = ;

int buz = 8;  // Buzzer pin

void drawEmblem(){
  myOLED.clrScr();
      for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+40);
      myOLED.invPixel(i+15, (cos(yy)*a)+33);
      myOLED.update();
     
    }
    
      delay(1000);
        myOLED.drawCircle(50,45,6);
        myOLED.update();
        
        delay(500);
        
        myOLED.drawCircle(50,45,8);
        myOLED.update();
         
                 for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+39);
      myOLED.invPixel(i+15, (cos(yy)*a)+38);
      myOLED.invPixel(i+15, (cos(y)*a)+37);
      myOLED.invPixel(i+15, (cos(yy)*a)+36);
      //myOLED.invPixel(i+15, (cos(yy)*a)+3);
      myOLED.invPixel(i+15, (cos(y)*30)+35);
      myOLED.invPixel(i+15, (cos(yy)*a)+34);
      
       myOLED.update();
    }
     myOLED.drawCircle(50,45,7);
             myOLED.update();

}

// Original boot sound for my projects
 void BootSound(){
  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,1000);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
 }

void Break(int tme)
{
  int breakStep = 10;
  int steps = tme / breakStep;  
  for(i = tme; i > 0 ; i = i-steps)
  {
    myBot.stop(i);
    myBot.goForward(tme-i);
  }
}


void ReadDistance(int Trig, int Echo)
{
  digitalWrite(Trig, HIGH);     // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10);        // Удерживаем 10 микросекунд 
  digitalWrite(Trig, LOW);      // Затем убираем 
  time_us=pulseIn(Echo, HIGH);  // Замеряем длину импульса 
  distance_sm=time_us/58;       // Пересчитываем в сантиметры 
  return distance_sm;
}

void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);
 
  myOLED.begin();
  myOLED.setFont(SmallFont);
  
  BootSound();                // Boot sound
  drawEmblem();               // Drawing logo on OLED
  
  myBot.begin();   // LF, LB, RF, RB
  myBot.stop(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
