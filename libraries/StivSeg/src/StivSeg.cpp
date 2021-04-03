#include "Arduino.h"
#include "StivSeg.h"

/*TERMINOLOGY
 *seg = a segment on the display
 *dig = a digit on the display
 *RHDP = right hand decimal point
 */

StivSeg::StivSeg(int numD, int dp[], int sp[], bool isCath) {
    numDigits = numD;
    isComCathode = isCath;
    
    //stores digit pins
    for(int i = 0; i < numDigits; i++) {
        digitPins[i] = dp[i];
        pinMode(digitPins[i], OUTPUT);
    }
    
    //stores segment pins
    for(int i = 0; i <= 7; i++) {
        segPins[i] = sp[i];
        pinMode(segPins[i], OUTPUT);
    }
    
    //determines common type and preps pin states
    if(!isComCathode) {
        for(int i = 0; i < numDigits; i++) {
            digitalWrite(digitPins[i], HIGH);
        }
        
        for(int i = 0; i <= 7; i++) {
            digitalWrite(segPins[i], HIGH);
        }
    }
}

StivSeg::writeInt(int n) {
    int nray[numDigits];                
    
    //splits each digit of input and saves to a temporary array
    for(int i = 0; i < numDigits; i++) {
        nray[i] = n % 10;
        n /= 10;
    }
    
    //writes to display here, decides how to treat display based off common type
    if(isComCathode) {
        //cycles through each dig
        for(int dig = 0; dig < numDigits; dig++) {
            //cathode pulled low to allow seg illumination
            digitalWrite(digitPins[dig], LOW);
            
            //cycles through each seg and sets state in accordance with array SYMBOL[][]
            for(int seg = 0; seg <= 6; seg++) {
                digitalWrite(segPins[seg], SYMBOL[nray[dig]][seg]);
            }
            delay(10);
            //cathode pulled high to disallow illumination
            digitalWrite(digitPins[dig], HIGH);
        }
    }
    else {
        //cycles through each dig in physical display
        for(int dig = 0; dig < numDigits; dig++) {
            //anode pulled high to allow seg illumination
            digitalWrite(digitPins[dig], HIGH);
            
            //cycles through each seg and sets state in accordance with the boolean opposite of array SYMBOL[][]
            for(int seg = 0; seg <= 6; seg++) {
                digitalWrite(segPins[seg], !SYMBOL[nray[dig]][seg]);
            }
            delay(10);
            //anode pulled low to disallow illumination
            digitalWrite(digitPins[dig], LOW);
        }
    }
}

StivSeg::writeFloat(float n) {
    int nray[numDigits];
    int pointPos = numDigits + 1;
    
    //determines which physical display digit will "own" the decimal point (based off RHDP)
    while(n > 1.0) {
        n /= 10.0;
        pointPos--;
    }
    //converts input to integer
    n *= (float)pow(10.0, (float)numDigits);
    
    for(int i = 0; i < numDigits; i++) {
        nray[i] = (int)n % 10;
        n /= 10;
    }
    
    if(isComCathode) {
        for(int dig = 0; dig < numDigits; dig++) {
            digitalWrite(digitPins[dig], LOW);
            
            for(int seg = 0; seg <= 6; seg++) {
                digitalWrite(segPins[seg], SYMBOL[nray[dig]][seg]);
            }
            
            //sets RHDP
            if(pointPos == dig + 1) {
                digitalWrite(segPins[7], HIGH);
            }
            else {
                digitalWrite(segPins[7], LOW);
            }
            delay(10);
            digitalWrite(digitPins[dig], HIGH);
        }
    }
    else {
        for(int dig = 0; dig < numDigits; dig++) {
            digitalWrite(digitPins[dig], HIGH);
            
            for(int seg = 0; seg <= 6; seg++) {
                digitalWrite(segPins[seg], !SYMBOL[nray[dig]][seg]);
            }
            
            //sets RHDP
            if(pointPos == dig + 1) {
                digitalWrite(segPins[7], LOW);
            }
            else {
                digitalWrite(segPins[7], HIGH);
            }
            delay(10);
            digitalWrite(digitPins[dig], LOW);
        }
    }
}

StivSeg::clear() {
    //sets all dig pins and seg pins to low
    for(int dig = 0; dig < numDigits; dig++) {
        digitalWrite(digitPins[dig], LOW);
        
        for(int seg = 0; seg <= 7; seg++) {
            digitalWrite(segPins[seg], LOW);
        }
    }
}