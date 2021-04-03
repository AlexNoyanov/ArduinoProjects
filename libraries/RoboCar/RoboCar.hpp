//
//  RoboCar.hpp
//  RoboCar
//
//  Created by Alex Noyanov on 31.10.17.
//  Copyright © 2017 Popoff Developer Studio. All rights reserved.
//

#ifndef RoboCar_hpp
#define RoboCar_hpp

#include <stdio.h>

#endif /* RoboCar_hpp */

class RoboCar       // Class RoboCar
{
public:                         // Public functions
    void begin(int LF, int LB, int RF,int RB);                   // Starting
    void goForward(int delayTime);  // Moving forward   (L-F R-F)
    void goBack(int delayTime);     // Moving back      (L-B R-B)
    void turnLeft(int delayTime);   // Turn Left        (L-F R-S)
    void turnRight(int delayTime);  // Turn Right       (L-S R-F)
    
    void fastturnLeft(int delayTime);  // Turn Left fast   (L-F R-B)
    void fastturnRight(int delayTime); // Turn Right fast  (L-B R-F)
    
    void stop();                    // Stop all motors
};
