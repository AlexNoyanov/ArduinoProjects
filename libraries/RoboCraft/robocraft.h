//
//  robocraft.h
//  
//
//  Created by Alex Noyanov on 11/10/15.
//
//

#ifndef ____robocraft__
#define ____robocraft__

#include <iostream>

#endif /* defined(____robocraft__) */

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class RoboCraft
{
public:
    RoboCraft();
    void hello();
};

#endif // #ifndef robocraft_h
