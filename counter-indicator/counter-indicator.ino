//  =========================
//  Counter
//  Created by Alex Noyanov
//  20 May 2016
//  =========================

/*    7-SEGMENT INDICATOR 
 *     CONNECTING SCHEME:     
 *    _______________
 *  /_______________/| /5V
 * |    <=====>    | |/
 * |   ^   UP  ^   | | 
 * |LUP|       |RUP| |
 * |   v  MDL  v   | | 
 * |    <=====>    | |
 * |   ^       ^   | |
 * |LDN|       |RDN| |
 * |   v  DWN  v   | |
 * |    <=====> O  | |
 * |_______________|/
 * 
 * 
 * (Better use Resistors!)
 *  CONNECT PINS 
 *  TO THE SEGMENTS:
 *    UP  --> 13
 *    MDL --> 7
 *    DWN --> 4
 *    LUP --> 12
 *    LDN --> 11
 *    RUP --> 6
 *    RDN --> 5
 *    
 *    
 *    SEGMENT | PIN
 *    --------|-----
 *        A   | 13
 *        B   | 6
 *        C   | 5
 *        D   | 4
 *        E   | 11
 *        F   | 12
 *        G   | 7
 *    
 *    
 *    OTHER SYMBOLS: A,C,E,F,G,H,I(use1),O(use0),L,P
 *    1,2,3,4,5,6,7,8,9,0
 */
// Library:
#include<LedIndicator.h>

// Speed:
int spd = 500;
void setup() {
// Make indicator pins in OUTPUT mode:
PinsOut();
// Turn OFF all segments:
Off();
}

void loop() {

oUp();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

oDn();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Zero();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);
  
One();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Two();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Three();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Four();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Five();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Six();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Seven();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Eight();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

Nine();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

// Now lets's print "H" "E" "L" "L" "O" 
H();        // Turn On H
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

E();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

L();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

L();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

PrintNum(0);
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);


}
