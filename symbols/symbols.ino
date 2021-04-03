//  =========================
//  7-segments led indicator
//  simple example
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
 *    OTHER SYMBOLS: A,C,E,F,G,H,I(use1),O(use0),L,P
 *    1,2,3,4,5,6,7,8,9,0
 */
// Library:
#include<LedIndicator.h>

// Speed:
int spd = 500;
void setup() {
  // put your setup code here, to run once:
// Make indicator pins in OUTPUT mode:
PinsOut();
// Turn OFF all segments:
Off();
}


//typedef void (*printFunc)(void);
//printFunc printFuncts[] = { One, Two, Three };

void loop() {

oUp();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

oDn();
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);

// Let's print all numbers:
for(int n=0;n<=9;n++){
  PrintNum(n);
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);
}

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

PrintNum(1);


}
