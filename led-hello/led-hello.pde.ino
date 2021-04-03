
//*************************
//  HELLO example sketch
//  10 November 2015
//  Created by Alex Noyanov
//*************************

//  7-Segments LED indicator
/* =================
 * | SEGMENT | PIN |
 * =================
 * |  UP     |  3  |
 * |  MIDLE  |  7  |
 * |  DOWN   |  6  |
 * | LEFT UP |  4  |
 * |LEFT DOWN|  5  |
 * |RIGHT UP |  9  |
 * |RIGHT DWN|  8  |
 * =================
 */

 /* Main Functions:  
  * Numbers - [ Zero() to Nine() ]   
  *   H()  E()  L()
  *   Function clear - Off()
  */
//  Including Libriary:
  #include <LedIndicator.h>
//  Speed:
 int spd = 500;
 // Simple function which Off and delay:
 void Offdel(){
  delay(spd);
Off();
delay(spd);
 }
void setup() {
 // Set PINs to OUTPUT mode: 
  pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
     pinMode(6,OUTPUT);
      pinMode(7,OUTPUT);
       pinMode(8,OUTPUT);
        pinMode(9,OUTPUT);
  // Off all leds:
        Off();
}

void loop() {
  //  Simple HELLO test code:
H();
Offdel();
E();
Offdel();
L();
Offdel();
L();
Offdel();
// Using Zero symbol like O:
Zero();
Offdel();
}
