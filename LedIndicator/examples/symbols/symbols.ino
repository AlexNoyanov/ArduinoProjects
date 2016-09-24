//  =========================
//  7-segments led indicator
//  simple example
//  Created by Alex Noyanov
//  20 May 2016
//  =========================
//  Mail: alex.noyanov@gmail.com

// Version : 1.0
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
 *    OTHER SYMBOLS: A,b,C,E,F,G,H,I(use1),J,L,O(use0),P
 *    1,2,3,4,5,6,7,8,9,0
 */
 
// Library:
#include<LedIndicator.h> 

 int spd = 500;  // Speed
  
void setup() {
  PinsOut();      // Set indicator pins as OUTPUT
  Off();          // Turn OFF ingicator
}

void loop() {

// Let's print all numbers:
for(int n=0;n<=9;n++){
  PrintNum(n);
  delay(spd);   // Waitind 
  Off();        // Turn Off
  delay(spd);   // Waiting
  }

// Now lets's print "H" "E" "L" "L" "O" 
  H();          // Print "H"
  delay(spd);   // Waiting
  Off();        // Turn Off
  delay(spd);   // Waiting

  E();          // Print "E"
  delay(spd);   // Waiting 
  Off();        // Turn Off
  delay(spd);   // Waiting

  L();          // Print "L"
  delay(spd);   // Waiting 
  Off();        // Turn Off
  delay(spd);   // Waiting

  L();          // Print "l" again
  delay(spd);   // Waiting 
  Off();        // Turn Off
  delay(spd);

  O();          // Print "O"
  delay(spd);   // Waitindg
  Off();        // Turn Off
  delay(spd);   // Waiting

}
