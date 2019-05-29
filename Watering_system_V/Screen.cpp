//
//  Screen.cpp
//  
//
//  Created by Alex Noyanov on 27.04.19.
//

#include "Screen.hpp"
#include <stdio.h>
#include <string.h>

Screen::Screen() : lcd(0x27,20,4) 
{
    //LiquidCrystal_I2C lcd(0x27,20,4);         // set the LCD address to 0x27 for a 16
                                                //chars and 2 line display
}

void Screen::backLight(bool mode)    // Backlight control
{
    if(mode)
      lcd.backlight();
    else 
      lcd.noBacklight();
}

void Screen::printMessage(String message, int x, int y)     // Printing messages on LCD
{
    lcd.setCursor(x,y);
}

//  For Printing on I2C LCD:
void Screen::Print(char* str)
{
        //char* str;
        for(int i = 0; i < strlen(str); i++) {
            lcd.print(str[i]);
            // delay(100);
        }
}
        
void Screen::Prrint(char* str, int dtime)
{
       for(int i = 0; i < strlen(str); i++) {
            lcd.print(str[i]);
            delay(dtime);
       }
}
