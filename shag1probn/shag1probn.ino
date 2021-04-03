#include <Stepper.h>

int Motor2A1Pin = ;// Контакт 50 для второго привода

int Motor2B1Pin = ;// Контакт 51 для второго привода

int Motor2A2Pin = ;// Контакт 52 для второго привода

int Motor2B2Pin = ;// Контакт 53 для второго привода

Stepper Motor2(200, Motor2A1Pin, Motor2A2Pin, Motor2B1Pin, Motor2B2Pin);



 

void setup()

{

Motor2.setSpeed(400);

}

 

void loop()

{

Motor2.step(100);

delay(1000);

}

