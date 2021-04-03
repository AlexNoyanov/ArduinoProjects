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
int d = 500;

void setup() {
  // put your setup code here, to run once:

//  Set PINs to OUTPUT mode
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop() {
//  Simple exaple code:
FWD();
delay(d);
RGT();
delay(d);
FWD();
delay(d);
LFT();
delay(d);
BCK();
delay(d);
STP();
delay(d);
}
