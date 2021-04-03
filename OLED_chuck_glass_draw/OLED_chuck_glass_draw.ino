

#include <OLED_I2C.h>

#include <Wire.h>
#include <ArduinoNunchuk.h>

    int ay;
    int ax;
    int az;
    int r = 5;
    int mode = 0;
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
//extern uint8_t MediumNumbers[];
//extern uint8_t BigNumbers[];


#define BAUDRATE 19200
ArduinoNunchuk nunchuk = ArduinoNunchuk();

void draw(int x,int y){
    for(int i = 0;i<r;i++){   
   myOLED.drawCircle(x,y,i);
    }
}

void drawR(int x,int y){
  myOLED.drawCircle(x,y,r); 
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  myOLED.begin();
  myOLED.setFont(SmallFont);
  nunchuk.init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
      nunchuk.update();
     ay = nunchuk.accelY;
     ax = nunchuk.accelX;
     az = nunchuk.accelZ;

   ax = map(ax,720,350,0,128);
   ay = map(ay,300,650,0,64);


  draw(ax,ay);

     if(nunchuk.zButton != 0){
   myOLED.clrScr();
   r = 1;
     }
     
     if(nunchuk.cButton != 0){
  r++;
      delay(100);
     }
//
//     if(nunchuk.cButton != 0 && nunchuk.zButton != 0 && flag ==0){
//      flag = 1;
//      
//     }
     myOLED.update();
    delay(1); 
}
