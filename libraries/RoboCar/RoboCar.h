//
//  RoboCar.hpp
//  RoboCar
//
//  Created by Alex Noyanov on 31.10.17.
//  Copyright © 2017 Alex Noyanov. All rights reserved.
//

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef RoboCar_h
#define RoboCar_h

class RoboCar       // Class RoboCar
{
public:                             // Public functions
    void begin(int LF, int LB, int RF,int RB);                   // Starting
    
    void goForward(int delayTime);  // Moving forward   (L-F R-F)
    void goBack(int delayTime);     // Moving back      (L-B R-B)
    void turnLeft(int delayTime);   // Turn Left        (L-F R-S)
    void turnRight(int delayTime);  // Turn Right       (L-S R-F)
    
    void fastturnLeft(int delayTime);  // Turn Left fast   (L-F R-B)
    void fastturnRight(int delayTime); // Turn Right fast  (L-B R-F)
    
    void stop();                    // Stop all motors
    
    void RotateLeft(int angle);
    void RotateRight(int angle);
};


#endif /* RoboCar_h */
