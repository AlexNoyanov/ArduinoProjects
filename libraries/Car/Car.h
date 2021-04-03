//
//  Car.h
//  
//
//  Created by Alex Noyanov on 11/11/15.
//
//

#ifndef ____Car__
#define ____Car__

//#include <iostream>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

    void FWD();
    void BCK();
    void STP();
    void LFT();
    void RGT();

#endif /* defined(____Car__) */
