#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>

// Program remote:
//   Press Setup until red LED on top stays on
//   Enter code 605

//#include <IRremote.h>             // Must be located in sketchbook
                    //  libraries folder

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();        // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();          // Receive the next value
  }
}


