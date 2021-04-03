/* StivSeg Library 1.0.1
 *  By Stephen "Stiv" Racz
 * https://github.com/stephentracz/StivSeg
 * 
 * TimerOne MUST be installed to use this example.  Search
 * "TimerOne" in the library manager.
 * 
 * Set required values for your display below.  Then connect
 * the wiper of a voltage-dividing potentiometer up to A0.
 */

#include <TimerOne.h>
#include <StivSeg.h>

volatile int potVal;
int numDigits = 2;
int digitPins[2] = {12, 11};
int segPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; //A-G and DP
bool isComCathode = true;
StivSeg disp(2, digitPins, segPins, isComCathode);

void setup() {
  checkPot(); //Manually checks pot so display isn't blank for 1st .25s of operation
  Timer1.initialize(250e3); //TimerOne stuff: triggers interrupt every 250e3us (.25s)
  Timer1.attachInterrupt(checkPot); //More TimerOne stuff
}

void loop() {
  disp.writeInt(potVal); //Continuously writes potVal to disp
}

void checkPot() {
  potVal = map(analogRead(A0), 0, 1023, 0, 99); //Change last arg to same number of digits as numDigits
}

