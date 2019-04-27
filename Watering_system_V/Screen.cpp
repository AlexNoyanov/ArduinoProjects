//
//  Screen.cpp
//  
//
//  Created by Alex Noyanov on 27.04.19.
//

#include "Screen.hpp"

void Screen::backLight(bool b)      // Backlight control
{
    b == true ? lcd.backlight() : lcd.noBacklight();
}

void Screen::printMessage(String message, int x, int y)     // Printing messages on LCD
{
    lcd.setCursor(x,y);
}
