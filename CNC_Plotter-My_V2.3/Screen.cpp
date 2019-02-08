
//  ==== OLED Screen for Mini CNC Arduino Plotter ====
// Use this module for OLED I2C 128x32 screen

// By Alex Noyanov
// Mail: alex.noyanov@gmail.com

// January 27th 2019 Moscow


/*    ______________________________________________
     |         ___________________________________  |
     |        |                                   | |
     | Ground |                                   | |
     |  VCC   |                                   | |
     |  SDA   |                                   | |
     |  SCL   |___________________________________| |
     |______________________________________________|
 
 */

#include "Screen.h"

// For tiny OLED screen (128x32)
#include <ssd1306.h>
#include <font6x8.h>

// Set and get screen values:
int Screen::getDefX()
{
    return defX;
}

int Screen::getDefY()
{
    return defY;
}

void Screen::setDefX(int valueX)
{
    defX = valueX;
}

void Screen::setDefY(int valueY)
{
    defY = valueY;
}

int Screen::maxString()
{
  return maxStringValue;
}

void Screen::begin()
{
  // === OLED setup: ===
   ssd1306_128x64_i2c_init();
   ssd1306_fillScreen(0x00);
   ssd1306_setFixedFont(ssd1306xled_font6x8);
}

void Screen::printString(char* str, int posX, int posY)             // Print with coordinates
{
    ssd1306_printFixedN(posX,posY,str,STYLE_BOLD,FONT_SIZE_2X);
}

void Screen::printString(char* str)                                 // Print with default coordinates
{
    ssd1306_printFixedN(defX,defY,str,STYLE_BOLD,FONT_SIZE_2X);
}
void Screen::drawLoadingAnimation(int tme)                          // Drawing loading animation by time
{
  printString("0",30,20);
  delay(tme);
  printString("0",45,20);
  delay(tme);
  printString("0",55,20);
}

void Screen::clear()
{
  ssd1306_clearScreen();
}

void Screen::printMessage(char* str, int tme)
{
  clear();
  printString(str,defX,20);
  delay(tme);
  clear();
}


