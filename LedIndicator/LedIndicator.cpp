//*************************************
//  LedIndicator.cpp
//  7-Segments LED-indicator libriary
//  Created by Alex Noyanov on 11/10/15.
//*************************************
// Mail: alex.noyanov@gmail.com

#include "LedIndicator.h"


//  Pins:
int rup = 6;
int rdwn = 5;
int dwn = 4;
int mdl = 7;
int ldwn =11;
int lup = 12;
int up = 13;

// Functions:

// Numbers
void One()
{
    digitalWrite(rup,LOW);
    digitalWrite(rdwn,LOW);
}

void Two()
{
    digitalWrite(up,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(dwn,LOW);
}

void Three()
{
    digitalWrite(up,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(dwn,LOW);
}
void Four()
{
    digitalWrite(rup,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);}

void Five() {
    digitalWrite(up,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(dwn,LOW);
}
void Six() {
    digitalWrite(up,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(dwn,LOW);
}
void Seven() {
    digitalWrite(rup,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(up,LOW);
}
void Eight() {
    digitalWrite(up,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(dwn,LOW);
    digitalWrite(rup,LOW);
}
void Nine(){
    digitalWrite(up,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(dwn,LOW);
    digitalWrite(rup,LOW);
}
void Zero()
{
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(dwn,LOW);
    digitalWrite(up,LOW);
}
// For Symbols:
void Off(){
    digitalWrite(rup,HIGH);
    digitalWrite(rdwn,HIGH);
    digitalWrite(mdl,HIGH);
    digitalWrite(lup,HIGH);
    digitalWrite(ldwn,HIGH);
    digitalWrite(up,HIGH);
    digitalWrite(dwn,HIGH);
        }
void A(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(up,LOW);
}
void b(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(dwn,LOW);
}

void C(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(up,LOW);
    digitalWrite(dwn,LOW);
}

void E(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(up,LOW);
    digitalWrite(dwn,LOW);
}

void d(){
    digitalWrite(rup,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(dwn,LOW);
}
void P(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(up,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(rup,LOW);
}
void H(){
    digitalWrite(rup,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
}


void f(){
    digitalWrite(up,LOW);
    digitalWrite(mdl,LOW);
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
}

void G(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(up,LOW);
    digitalWrite(dwn,LOW);
    digitalWrite(rdwn,LOW);
    
}

void J(){
    digitalWrite(rdwn,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(dwn,LOW);
}

void L(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(dwn,LOW);
}

void U(){
    digitalWrite(lup,LOW);
    digitalWrite(ldwn,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(dwn,LOW);
}

void oUp(){
    digitalWrite(lup,LOW);
    digitalWrite(up,LOW);
    digitalWrite(rup,LOW);
    digitalWrite(mdl,LOW);
}

void oDn(){
    digitalWrite(ldwn,LOW);
    digitalWrite(dwn,LOW);
    digitalWrite(rdwn,LOW);
    digitalWrite(mdl,LOW);
}
// Set pins as OUTPUT
void PinsOut(){
    pinMode(up,OUTPUT);
    pinMode(mdl,OUTPUT);
    pinMode(dwn,OUTPUT);
    pinMode(lup,OUTPUT);
    pinMode(ldwn,OUTPUT);
    pinMode(rup,OUTPUT);
    pinMode(rdwn,OUTPUT);
}

// Use this function for printing numbers:
void PrintNum(int i)
{
        
        switch(i)
        {
            case 0: Zero();break;
            case 1: One(); break;
            case 2: Two(); break;
            case 3: Three(); break;
            case 4: Four(); break;
            case 5: Five(); break;
            case 6: Six();break;
            case 7: Seven();break;
            case 8: Eight();break;
            case 9: Nine();break;
        }
    

}
