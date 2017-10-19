//
//  AlexOLED.cpp
//  
//
//  Created by Александр Ноянов on 19.10.17.
//
//

#include "AlexOLED.hpp"


void AlexOLED::sendcommand(unsigned char com)
{
    Wire.beginTransmission(_address);     //begin transmitting
    Wire.write(0x80);                          //command mode
    Wire.write(com);
    Wire.endTransmission();                    // stop transmitting
}

// Turns display on.
void AlexOLED::displayOn(void)
{
    sendcommand(0xaf);        //display on
}

// Turns display off.
void AlexOLED::Off(void)
{
    sendcommand(0xae);		//display off
}

void AlexOLED::SetPIxel (void){
    
}
