//
//  RoboCar.cpp
//  RoboCar
//
//  Created by Alex Noyanov on 31.10.17.
//  Copyright © 2017 Alex Noyanov. All rights reserved.
//

#include "RoboCar.h"

int LF;
int LB;
int RF;
int RB;

// Turn ON motor:
void On(int pin){
    digitalWrite(pin,HIGH);
}

// Turn OFF motor:
void Off(int pin){
    digitalWrite(pin,LOW);
}

void RoboCar::begin(int LF,int LB,int RF,int RB){
    pinMode(LB,OUTPUT);
    pinMode(LF,OUTPUT);
    pinMode(RF,OUTPUT);
    pinMode(RB,OUTPUT);
}

void RoboCar::stop(){
    Off(LF);
    Off(LB);
    Off(RF);
    Off(RB);
}

void RoboCar::goForward(int delayTime){
    On(LF);
    On(RF);
    delay(delayTime);
    Off(LF);
    Off(RF);
}

void RoboCar::goBack(int delayTime){
    On(LB);
    On(RB);
    delay(delayTime);
    Off(LB);
    Off(RB);
}

void RoboCar::turnLeft(int delayTime){
    On(RF);
    delay(delayTime);
    Off(RF);
}

void RoboCar::turnRight(int  delayTime){
    On(LF);
    delay(delayTime);
    Off(LF);
}

//  For rotating on angle:
void RotateLeft(int angle){
   // On(RF);
}

void RotateRight(int angle){
    
}

