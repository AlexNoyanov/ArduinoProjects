//
//  Screen.hpp
//  
//
//  Created by Alex Noyanov on 27.04.19.
//

#ifndef Screen_hpp
#define Screen_hpp

#include "LiquidCrystal_I2C.h"    // Screen library

class Screen
{
  LiquidCrystal_I2C lcd;
  //LiquidCrystal_I2C lcd(0x27,20,4);           // set the LCD address to 0x27 for a 16
                                                 //chars and 2 line display
public:
    // Constructor:
    Screen();
    void backLight(bool mode);                  // Backlight control
    void printMessage(String message, int x, int y);
private:
    //  For Printing on I2C LCD:
    void Print(char* str);
    void Prrint(char* str, int dtime);
};

#endif /* Screen_hpp */
