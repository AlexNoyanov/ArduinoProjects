/*
int a;
const int buzzer = 8;
const int ground = 10;
const int pin = 2;
int friq = 2500;
void bip(){
  tone(buzzer,friq);
  delay(10);
  noTone(buzzer);
  delay(10);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ground,OUTPUT);
pinMode(pin,INPUT);
digitalWrite(ground,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = digitalRead(pin);

Serial.println(value);
delay(10);
if (value == 0){
 tone(buzzer,friq);
} else
noTone(buzzer);
}*/

//  =====================
//      Simple piano 
//   Just connect fruit
//   8 February 2016
//    By Alex Noyanov
//  =====================


/*                       TO FRUIT 
 *          RESISTOR 10K   ___
 *          __________      |
    OUT____|          |_____|---->INPUT
 *         |__________|
 *         
 *         // Second sensor:
CapacitiveSensor banana2 = CapacitiveSensor(OUT,IN);
//
   MY OWN EMBLEM:  

       ==================================================
  //                                                       \\
 ||          _____________    ___                   __      ||
 ||       /   _           /  /  /        ___      / _  \    ||
 ||      /  / _ \     /  /  /  /       / _  |    / /_| /    ||
 ||     /  / |_| \   /  /  /  /       / /_| |   /  __  \    ||
 ||    /  /       \_/  /  /  /____   / _ _  |  /  /__|  |   ||
 ||   / ____________  /  /_______/  /_/   |_| /________/    ||
  \\                                                       //
       =================================================

 */
//  Librarie:
#include <CapacitiveSensor.h>

// Connect Pin 2 to the other side of the resistor and the banana.
CapacitiveSensor banana = CapacitiveSensor(3,2);
// Second sensor:
CapacitiveSensor banana2 = CapacitiveSensor(4,5);

// Threshold for turning the LED on
#define THRESSHOLD 15

// The debug LED in this case.
#define LED_PIN 13

// The value measured.
long value;
long value2;
const int buzzer = 8;
const int friq1 = 3000;
const int friq2 = 2500;

void setup(){
      // Set the LED pin as an output
        pinMode(LED_PIN, OUTPUT);
        pinMode(10,OUTPUT);
        digitalWrite(10,LOW);
}

void loop(){

   // Trigger a mesure with 30 samples and then
        // store the value reported by the sensor in a variable.
        long newValue = banana.capacitiveSensor(30);
        long newValue2 = banana2.capacitiveSensor(30);
        
        if ( value != newValue ) {
                value = newValue;

                // if the value is greater than the threshold
                if(value > THRESSHOLD) {
                        // turn the LED on
                        digitalWrite(LED_PIN, HIGH);
                        tone(buzzer,friq1);
                }
                // if it's lower than the threshold
                else {
                        // turn the LED off
                        digitalWrite(LED_PIN, LOW);
                        noTone(buzzer);
                }

        }

        
                if ( value2 != newValue2 ) {
                value2 = newValue2;

                // if the value is greater than the threshold
                if(value2> THRESSHOLD) {
                        // turn the LED on
                        digitalWrite(LED_PIN, HIGH);
                        tone(buzzer,friq2);
           }  else {
                        // turn the LED off
                        digitalWrite(LED_PIN, LOW);
                        noTone(buzzer);
                }
        }
  
}

