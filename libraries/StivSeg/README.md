# StivSeg
Multi-digit seven-segment display library for arduino.  Light-weight design allows the user to continuously write data gathered (ideally) from a TimerOne interrupt.

##Documentation
###Constructors
* `StivSeg(int numDigits, int digitPins[], int segPins[], bool isComCathode)` \- Constructs a StivSeg object with standard multiplexing.  1 object represents the whole display.
  * `numDigits` is the number of digits in the display.
  * `digitPins[]` is an array containing the pins connected to the commons of your display, ordered from least to most significant digit.
  * `segPins[]` is an array containing the pins connected to the segments of your display, ordered alphabetically with the decimal point last.
  * `isComCathode` is for indicating whether your display is common cathode or common anode.  Set **true** for common cathode.

###Functions
* `writeInt(int num)` \- Writes an integer to the display.  NOTE: make sure num does not have more digits than your display.
* `writeFloat(int num)` \- Writes a float to the display.
* `clear()` \- Clears the display.

###Example
```
#include <TimerOne.h>
#include <StivSeg.h>

volatile int potVal;
int numDigits = 2;
int digitPins[2] = {12, 11};
int segPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; //A-G and DP
bool isComCathode = true;
StivSeg disp(2, digitPins, segPins, isComCathode);

void setup() {
  checkPot(); //Manually checks pot so display isn't blank for 1st .25 of operation
  Timer1.initialize(250e3); //TimerOne stuff: triggers interrupt ever 250e3us (.25s)
  Timer1.attachInterrupt(checkPot); //More TimerOne stuff
}

void loop() {
  disp.writeInt(potVal); //Continuously writes potVal to disp
}

void checkPot() {
  potVal = map(analogRead(A0), 0, 1023, 0, 99); //Change last arg to same number of digits as numDigits
}
```
