
#define F_CPU 8000000UL      //ATtiny85 CPU Clock speed (8MHz optimal[8000000], 1MHz Default[1000000])
 
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
 
// ----------------------------------------------------------------------------
 
// ---------------------  // Vcc, Pin 1 on SSD1306 Board
// ---------------------  // GND, Pin 2 on SSD1306 Board
#define SSD1306_SCL   PB0 // SCL, Pin 3 on SSD1306 Board
#define SSD1306_SDA   PB1 // SDA, Pin 4 on SSD1306 Board
 
#define SSD1306_SA    0x78  // Slave address
 
// ----------------------------------------------------------------------------
 
#include "ssd1306xled.h"
 
void setup(){ 
  // Small delay is necessary if ssd1306_initis the first operation in the application.
  _delay_ms(40);
  ssd1306_init();
 
  ssd1306_fillscreen(0x00);
  ssd1306_char_f8x16(1, 2, "Photon OS");
  ssd1306_char_f6x8(1, 5, "Loading test...");
  _delay_ms(4000);
 
 
  uint8_t p = 0xff;
 
  for (uint8_t i = 0; i < 4; i++)
  {
    p = (p >> i);
    ssd1306_fillscreen(~p);
    _delay_ms(1);
  }
}
 
void loop()
{
  ssd1306_fillscreen(0x00);
  ssd1306_char_f6x8(1, 0, "I'm a ATtiny85"); //Cannot start at 0 for x. Gives problem
 
  ssd1306_char_f6x8(1, 0, "I'm a small and mighty.");
  _delay_ms(5000);
 
  ssd1306_char_f6x8(1, 0, "Who says I can't run this LED screen?");
  _delay_ms(5000);
 
 
  ssd1306_char_f6x8(1, 0, "There am I running it now.");
  _delay_ms(5000);
 
}
