

//  Example #1 for Arduino-based two wheels robot
//  Using library "RoboCar" you can easely control your robot
//  
//  This library is under MIT License protection  
//
//  Created by Alex Noyanov 
//  mail: Alex.noyanov@gmail.com

// Connection scheme:
//  Pin | Action
//  ____|_________________________
//  9   | Left motor Back (LB)
//  8   | Left motor Forward (LF)
//  11  | Right motor Back  (RB)
//  10  | Right motor Forward (RF)
//  ____|_________________________
//

#include <RoboCar.h>  // Library 

RoboCar myCar; 
void setup() {
  
  myCar.begin(8,9,10,11);  // LF, LB, RF, RB

  myCar.stop()            // Stop all motors 
  myCar.goForward(1000);  // Move Forward for 1 second
  myCar.turnRight(100);   // Turn Right 
  myCar.goForward(500);   // Move Forward for 0,5 second
  myCar.turnLeft(100);    // Turn Left
  myCar.goBack(1000);     // Move Back for 1 second
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
