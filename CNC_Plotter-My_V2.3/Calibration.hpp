//
//  Calibration.hpp
//  
//
//  Created by Александр Ноянов on 28/01/2019.
//

// Module for plotter autocalibration
// Motors rolls on zero and press the button
// It stops when button is pressd


#ifndef Calibration_hpp
#define Calibration_hpp

#include <stdio.h>

#endif /* Calibration_hpp */

};

class Calibrator
{
    int buttonPin;                      // Pin for button
    int tmeMove = 50;                   // Delay time between steps
public:
    bool buttonStatus();                // Bool can indicate button status
    void moveZero(Stepper motor);       // Move to zero this stepper motor
    void autoCalibrate(Stepper motor);  // Autocalibrate this motor
    Cailbrator(int bPin)                // Class constructor with parameters
    {
        buttonPin = bPin;
        pinMode(buttonPin,INPUT);       // Set button pin as input pin on Arduino
    }
};

