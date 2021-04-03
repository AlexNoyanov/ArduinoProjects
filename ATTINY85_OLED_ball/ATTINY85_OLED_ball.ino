

#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>
#include <math.h>

SSD1306_Mini oled;

// the ball shape
unsigned char ball[4]= { 0x6, 0x9, 0x9, 0x6 };

void die( unsigned char r, unsigned char c ){

  Wire.beginTransmission(SlaveAddress);
    Wire.send(GOFi2cOLED_Data_Mode);            // data mode

    Wire.send( 0xFF );
    Wire.send( 0x81 );
    Wire.send( 0x81 );
    Wire.send( 0xFF );
  Wire.endTransmission();
}
//
//void heartBeat(){
//
//    digitalWrite(4, HIGH);   // set the LED on  
//    delay(200);  
//    digitalWrite(4, LOW);    // set the LED off
//    delay(100);
//
//    digitalWrite(4, HIGH);   // set the LED on  
//    delay(500);  
//    digitalWrite(4, LOW);    // set the LED off
//    delay(100);
//  
//}

void snake(){
  
  oled.cursorTo(3,63);

  die( 0, 0);
  
}

void drawBall(int x,int y){

            // send a bunch of data in one xmission
    oled.cursorTo(x,y);
          Wire.beginTransmission(SlaveAddress);
          Wire.send(GOFi2cOLED_Data_Mode);            // data mode
       uint8_t data[4];
       data[0] = ball;
            Wire.send( data[0] );
            Wire.endTransmission(); 
            
}


void setPixel(int x,int y)
{
     // send a bunch of data in one xmission
       //uint8_t data[1];
       uint8_t data = 1 >> (y%8);
       //for(uint8_t i = 0; i < 10;i++){
       //oled.clear(); 
       //data = i;
      //data = y%2;
        oled.cursorTo(x,y/8);
        Wire.beginTransmission(SlaveAddress);
        Wire.send(GOFi2cOLED_Data_Mode);            // data mode
        Wire.send( data );

        Wire.endTransmission();
          //delay(250);
//         }
}


//void setPixel2(int x,int y){
//     // send a bunch of data in one xmission
//
//          
//       //uint8_t data[1];
//       int  ky = y%4;
//       uint8_t data;
//       
////       switch(ky){
////        case 0: data = 0x2;
////        case 1: data = 0x4;
////        case 2: data = 0x8;
////        case 3: data = 0xF; 
////        
////       }
//        
//       
//       
//       //for(uint8_t i = 0; i < 10;i++){
//       //oled.clear(); 
//       //data = i;
//      //data = y%2;
//      data = 0x1;
//        oled.cursorTo(x,y);
//        Wire.beginTransmission(SlaveAddress);
//        Wire.send(GOFi2cOLED_Data_Mode);            // data mode
//        Wire.send( data );
//
//        Wire.endTransmission();
//          //delay(250);
////         }
//}


void setup() {
  // put your setup code here, to run once:
 pinMode(4, OUTPUT);   

   // heartBeat();

    oled.init(0x3c);
    oled.clear();
  //  drawBall(10,10);
  //  setPixel(127,63);
//  for(uint8_t i = 0; i <= 0xF*2; i++)
//{
//  setPixel(i,0,i%16);
//}

//for(int y = 0; y < 4; y++){
//  setPixel(10,y);
//  delay(10);
//}
  //uint8_t *buffer = new uint8_t[1024];

   //memset(buffer, 0, 1024);
/*
    for(int x = 0; x < 128; x++) {
      for(int y = 0; y < 64; y+=8) 
      {
        //int yrow = y / 8;
        //int ybit = y % 8;
        //int address = yrow * 128 + x;
        //buffer[address] |= 1 >> ybit;
        oled.cursorTo(x, (y/8));
        Wire.beginTransmission(SlaveAddress);
        Wire.send(GOFi2cOLED_Data_Mode);    
        // data mode
        uint8_t data = 0xff;//buffer[address];
        Wire.send( data );
        Wire.endTransmission();
      }
    }

    oled.getFlash(
*/
    //delete[] buffer;
}

void loop() 
{
  int x0 = 128 / 2;
  int y0 = 64 / 2;
  double R = 25;
  int xprev=-1, yprev=-1;
  for(double a = 0; a < 360*2; a++) {
    double ar = a * M_PI / 360.0;
    int x = x0 + R*cos(ar); 
    int y = y0 + R*sin(ar);
    if(x != xprev || y != yprev) {
      setPixel(x, y); 
      xprev = x;
      yprev = y;
    }
  }
  // put your main code here, to run repeatedly:
//for(int x = 0; x < 100; x++){
//  oled.clear();
//    //drawBall(67,127);
//    setPixel(67,127);
 // setPixel(128,64);
  // delay(2000);

// for(int y = 0; y < 63;y++){
//  for(int x = 0; x < 128*4;x++){
//      setPixel2(x,y);
//      delay(10);
//    }
//  }
//}


delay(100);
}
