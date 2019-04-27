//
//  Screen.hpp
//  
//
//  Created by Alex Noyanov on 27.04.19.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>    // Screen library
#endif /* Screen_hpp */

class Screen
{
  LiquidCrystal_I2C lcd;
  //LiquidCrystal_I2C lcd(0x27,20,4);           // set the LCD address to 0x27 for a 16
                                                 //chars and 2 line display
public:
    // Constructor:
    Screen() : lcd(0x27,20,4) {
    //LiquidCrystal_I2C lcd(0x27,20,4);         // set the LCD address to 0x27 for a 16
                                                 //chars and 2 line display
    }
    void backLight(bool b);
    void printMessage(String message, int x, int y);
private:
    //  For Printing on I2C LCD:
    void Print(char* str/*, LiquidCrystal_I2C& lcd*/){
        //char* str;
        for(int i = 0; i < strlen(str); i++) {
            lcd.print(str[i]);
            // delay(100);
        }
    }
};
