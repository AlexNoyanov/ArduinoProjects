
#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>

SSD1306_Mini oled;

// there are different wall types
unsigned char wall[5][4]= { 
  0x0, 0x0, 0x0, 0x0,
  0xf, 0xf, 0xf, 0xf,
  0xf, 0x9, 0x9, 0xf,
  0x9, 0x9, 0x9, 0x9,
  0x9, 0x6, 0x6, 0x9,
};

void setup() {
  // put your setup code here, to run once:
    oled.init(0x3c);
    oled.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

}
