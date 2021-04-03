//
//  robocraft.cpp
//  
//
//  Created by Alex Noyanov on 11/10/15.
//
//

#include "robocraft.h"

//
// конструктор - вызывается всегда при создании экземпляра класса RoboCraft
//
RoboCraft::RoboCraft()
{
    Serial.begin(9600);
}

//
// просто говорим "Hello" :)
//
void RoboCraft::hello()
{
    Serial.println("Hello :)");
}
