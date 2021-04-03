// ATTINY85 Heartbeat program


#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>

//byte array of bitmap 17x16 px
const unsigned char  img_heart_small[] PROGMEM = {
    0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 
    0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f,
    0x1f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00,
    0x00, 0x00
};

//byte array of bitmap 17x16 px
const unsigned char  img_heart_big[] PROGMEM = {

    0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0,
    0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 
    0xe0, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 
    0x7f, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03,
    0x01, 0x00
};   

SSD1306_Mini oled;


void heartBeat(int x, int y){
 // oled.cursorTo(x, y);
  static char big=1;
  static long startTime=0;
  long currentTime;

  // get current time
  currentTime= millis();
  
  // update if 1000ms passed  
  if ((currentTime - startTime) > 200){
    startTime= currentTime;  


    // --- 
    big=1-big;
    if (big){
      oled.drawImage( img_heart_big, x, y, 17, 2);      
    } else {
      oled.drawImage( img_heart_small, x, y, 17, 2);
    }
  
  }  
}

void setup() {
  // put your setup code here, to run once:
  //oled.clear();
   oled.init(0x3c);
   oled.clear();
  //prepareDisplay();
  oled.startScreen();


  oled.cursorTo(10,2);
  oled.printString( "Heartbeat example");
  for(int i = 0;i < 128; i+=2)
  {
  oled.cursorTo(i, 10);
  oled.drawImage( img_heart_small, 20, 10, 17, 2);
  delay(100);
  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 128; i++)
  {
    heartBeat(i,i);
    delay(100);
  }
}
