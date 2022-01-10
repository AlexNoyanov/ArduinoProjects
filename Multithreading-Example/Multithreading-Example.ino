// Protothreading example

//this sketch will blink an LED at pin 13 each second
#include <TimedAction.h>

//pin / state variables
const byte ledPin = 13;
boolean ledState = false;

void Blink(){
  
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
}

//this initializes a TimedAction class that will change the state of an LED every second.
TimedAction timedAction = TimedAction(1000,Blink);




void setup(){
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState);
}

void loop(){
  timedAction.check();
  //do something else
}

void blink(){
  ledState ? ledState=false : ledState=true;
  digitalWrite(ledPin,ledState);
}
