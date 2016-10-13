/*         ==================================== 
 *          Simple example for <Car.h> libriary 
 *          Created by Alex Noyanov             
 *          11 November 2015                    
 *         ====================================
 *   _______________
 *  |FUNCTION | NAME|
 *  |---------------|
 *  | forvard | FWD |
 *  |   back  | BCK |
 *  |  left   | LFT |
 *  |  right  | RGT |
 *  |  stop   | STP |
 *   ---------------
 */ 

 
//  Libriary : 
#include <Car.h>

//  Delay time:
int tme = 500;

void setup() {
  // put your setup code here, to run once:

//  Set PINs to OUTPUT mode
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop() {
//  For example:
FWD(200);            // Move Forward
STP(500);            // Stop and waiting 
RGT(100);            // Turn Right
FWD(200);            // Move Forvard
LFT(100);            // Turn Left
BCK(200);            // Move Back
STP(100);
delay(1000); // Waiting a second
}
