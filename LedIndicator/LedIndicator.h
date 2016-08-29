//
//  LedIndicator.h
//  
//
//  Created by Alex Noyanov on 11/10/15.
//  Mail: alex.noyanov@gmail.com
//

#ifndef ____LedIndicator__
#define ____LedIndicator__

//#include <iostream>


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


void One();
void Two();
void Three();
void Four();
void Five();
void Six();
void Seven();
void Eight();
void Nine();
void Zero();
void Off();
void A();
void b();
void C();
void d();
void P();
void H();
void E();
void f();
void G();
void U();
void L();
void oUp();
void oDn();
void PinsOut();
void PrintNum(int i);

#endif /* defined(____LedIndicator__) */

