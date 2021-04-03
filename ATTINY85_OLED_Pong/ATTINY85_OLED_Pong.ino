#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>

void die( unsigned char r, unsigned char c ){

  Wire.beginTransmission(SlaveAddress);
    Wire.send(GOFi2cOLED_Data_Mode);            // data mode

    Wire.send( 0xFF );
    Wire.send( 0x81 );
    Wire.send( 0x81 );
    Wire.send( 0xFF );
  Wire.endTransmission();
}

SSD1306_Mini oled;

void setup() {
  // put your setup code here, to run once:

    oled.init(0x3c);
    oled.clear();
    oled.startScreen();
    
      oled.cursorTo(3,63);
     die( 1, 10);
}

void loop() {
  // put your main code here, to run repeatedly:

}
