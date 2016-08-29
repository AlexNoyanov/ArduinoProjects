//  =========================
//  Countdown
//  Created by Alex Noyanov
//  20 May 2016
//  Connect Button on 3 pin
//  =========================
//   Mail: alex.noyanov@gmail.com
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
//Connect button on this pin
int buttonPin = 3;

void setup() {
// Make indicator pins in OUTPUT mode:
PinsOut();
// Buttonb pin mode:
pinMode(buttonPin,OUTPUT);
// Turn OFF all segments:
Off();
}
void loop() {
  // Countdown if button pressed:
if(digitalRead(buttonPin)==HIGH){
// Let's print all numbers:
for(int n=9;n>=0;n--){
  PrintNum(n);
delay(spd); // Waitind 
Off();      // Turn Off
delay(spd);
   }
  }else{
    Off();
  }
 }
