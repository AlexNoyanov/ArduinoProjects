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
int lfwd =3;
int lbk = 5;
int rfwd = 4;
int rbk = 6;

//  Main Functions: fwd stp bck lft rgt
void STP(){
    digitalWrite(rbk,HIGH);
    digitalWrite(lbk,HIGH);
    digitalWrite(rfwd,HIGH);
    digitalWrite(lfwd,HIGH);
}

void FWD(){
    digitalWrite(rfwd,LOW);
    digitalWrite(lfwd,LOW);
    delay(spd);
    digitalWrite(rfwd,HIGH);
    digitalWrite(lfwd,HIGH);
    //delay(spd);
}
void BCK(){
    digitalWrite(rbk,LOW);
    digitalWrite(lbk,LOW);
    delay(spd);
    digitalWrite(rbk,HIGH);
    digitalWrite(lbk,HIGH);
    //delay(spd);
}
void LFT(){
    digitalWrite(lbk,LOW);
    digitalWrite(rfwd,LOW);
    delay(spd);
    digitalWrite(lbk,HIGH);
    digitalWrite(rfwd,HIGH);
    //delay(spd);
}
void RGT(){
    digitalWrite(rbk,LOW);
    digitalWrite(lfwd,LOW);
    delay(spd);
    digitalWrite(rbk,HIGH);
    digitalWrite(lfwd,HIGH);
    //delay(spd); 
}