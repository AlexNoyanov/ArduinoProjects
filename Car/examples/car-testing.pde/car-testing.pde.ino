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
//  Simple exaple code:
FWD();
delay(tme);
RGT();
delay(tme);
FWD();
delay(tme);
LFT();
delay(tme);
BCK();
delay(tme);
STP();
delay(tme);
}
