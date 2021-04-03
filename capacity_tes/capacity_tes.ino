/*
Thomas Ouellet Fredericks
2014-08-19

Based on Arduino Starter Kit example (by Scott Fitzgerald)
& Mind+ Banana Piano example

Parts required:
1x 10K ohm resistor
1x Banana

This example requires the CapacitiveSensor library
(CapacitiveSensor04.zip) by Paul Badger :
http://arduino.cc/playground/Main/CapacitiveSensor

This example is part of the public domain
*/

// Import the CapacitiveSensor library
// found here :(CapacitiveSensor04.zip) :
// http://playground.arduino.cc/Main/CapacitiveSensor
#include <CapacitiveSensor.h>

// Create an instance of the library with the following setup :

// Pin 3 is the OUTPUT and sends electrical energy.
// Connect Pin 3 to one side of the resistor.

// Pin 2 is the INPUT and measures the time of change.
// Connect Pin 2 to the other side of the resistor and the banana.
CapacitiveSensor banana = CapacitiveSensor(3,2);

// Threshold for turning the LED on
#define THRESSHOLD 15

// Pin the LED is connected to :
// The debug LED in this case.
#define LED_PIN 13

// The value measured.
long value;

void setup() {
        // Open a serial connection.
        Serial.begin(9600);
        // Set the LED pin as an output
        pinMode(LED_PIN, OUTPUT);
}

void loop() {
        // Trigger a mesure with 30 samples and then
        // store the value reported by the sensor in a variable.
        long newValue = banana.capacitiveSensor(30);

        if ( value != newValue ) {
                value = newValue;

                // print out the value
                Serial.print("banana ");
                Serial.println(value);

                // if the value is greater than the threshold
                if(value > THRESSHOLD) {
                        // turn the LED on
                        digitalWrite(LED_PIN, HIGH);
                }
                // if it's lower than the threshold
                else {
                        // turn the LED off
                        digitalWrite(LED_PIN, LOW);
                }
        }
}


