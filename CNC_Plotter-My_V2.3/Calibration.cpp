//
//  Calibration.cpp
//  
//
//  Created by Александр Ноянов on 28/01/2019.
//
// Mail: alex.noyanov@gmail.com

/*
             _                            _ _ _               _   _
            /\        | |                | (_) |             | | (_)
           /  \  _   _| |_ ___   ___ __ _| |_| |__  _ __ __ _| |_ _  ___  _ __
          / /\ \| | | | __/ _ \ / __/ _` | | | '_ \| '__/ _` | __| |/ _ \| '_ \
         / ____ \ |_| | || (_) | (_| (_| | | | |_) | | | (_| | |_| | (_) | | | |
        /_/    \_\__,_|\__\___/ \___\__,_|_|_|_.__/|_|  \__,_|\__|_|\___/|_| |_|
 
 */

#include "Calibration.hpp"

bool Calibrator::buttonStatus()                                     // Check calibration button status
{
    int buttonStatus = digitalRead(buttonPin);                      // Read button status
    
    if(buttonStatus == HIGH)                                        // If button pressed
    {
        return true;
    }else{
        return false;
    }
}

void Calibrator::moveZero(Stepper motor)                            // Keep moving stepper motor to zero direction
{
    motor.step(-1);                                                 // Move stepper motor one step back
    delay(tmeMove);
}

void Calibrator::autoCalibrate(Stepper motor)                       // Final method - Autocalibration
{
    int delayTime = 5000;                                           // Max delay time to move the motor
    int timer = 0;
    int timeStep = 1;                                               // Delay step for timer
    
    while(buttonStatus() == true && timer != delayTime)             // Move motor and stop when it press the button
    {
        moveZero(motor);
        
        delay(timeStep);                                             // This timer will stop the motor if there is  no button
        timer += timeStep;
    }
    
}



