//
//  Car.cpp
//
//  Created by Alex Noyanov on 11/11/15.
//  Simple libriary for x2-motor car
//

#include "Car.h"

//Speed:
int spd = 100;

//  Motor pins:
int lfwd = 3;   // Left motor moves forward
int lbk  = 5;   // Left motor moves back
int rfwd = 4;   // Right motor moves forward
int rbk  = 6;   // Right motor moves back

//  Main Functions to car movement:
void STP(int tme){              // Stop
    digitalWrite(rbk,HIGH);
    digitalWrite(lbk,HIGH);
    digitalWrite(rfwd,HIGH);
    digitalWrite(lfwd,HIGH);
    delay(tme);
}

void FWD(int tme){              // Forward
    digitalWrite(rfwd,LOW);
    digitalWrite(lfwd,LOW);
    delay(spd);
    digitalWrite(rfwd,HIGH);
    digitalWrite(lfwd,HIGH);
    delay(tme);
}

void BCK(int tme){              // Back
    digitalWrite(rbk,LOW);
    digitalWrite(lbk,LOW);
    delay(spd);
    digitalWrite(rbk,HIGH);
    digitalWrite(lbk,HIGH);
    delay(tme);
}

void LFT(int tme){              // Left
    digitalWrite(lbk,LOW);
    digitalWrite(rfwd,LOW);
    delay(spd);
    digitalWrite(lbk,HIGH);
    digitalWrite(rfwd,HIGH);
    delay(tme);
}

void RGT(int tme){              // Right
    digitalWrite(rbk,LOW);
    digitalWrite(lfwd,LOW);
    delay(spd);
    digitalWrite(rbk,HIGH);
    digitalWrite(lfwd,HIGH);
    delay(int tme);
}

