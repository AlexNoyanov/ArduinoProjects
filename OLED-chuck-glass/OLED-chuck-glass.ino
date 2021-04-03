
#include <OLED_I2C.h>

#include <Wire.h>
#include <ArduinoNunchuk.h>

OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


#define BAUDRATE 19200
ArduinoNunchuk nunchuk = ArduinoNunchuk();


void drawCross(int ax,int ay){
    myOLED.drawCircle(ax,ay,10);
    myOLED.drawCircle(ax,ay,2);

         if(nunchuk.zButton != 0){
   myOLED.clrScr();
   for(int i =0;i<5;i++){
    myOLED.drawCircle(ax,ay,i);
   }
     }    
}
void Bullet(int x,int y){
  myOLED.drawRect(x,y,x+2,y+10);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
// Serial.begin(9600);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  //Serial.begin(BAUDRATE);
  nunchuk.init();

}

void loop() {
  // put your main code here, to run repeatedly:
    nunchuk.update();
    int ay = nunchuk.accelY;
    int ax = nunchuk.accelX;
    int az = nunchuk.accelZ;
/*
      Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);

*/
    myOLED.setFont(MediumNumbers);
     myOLED.print("8",30,48);
   ax = map(ax,720,350,0,128);
   ay = map(ay,300,750,0,64);
/*
   ax = map(ax,350,720,0,128);
   ay = map(ay,300,750,0,64);
   */
   // ax = map(ax,314,748,0,48);
     myOLED.clrScr();
     drawCross(ax,ay);

     myOLED.update();
    delay(10);
}
