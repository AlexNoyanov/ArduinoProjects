
#include <LedIndicator.h>
//  Set PINS to OUTPUT mode:


void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
     pinMode(6,OUTPUT);
      pinMode(7,OUTPUT);
       pinMode(8,OUTPUT);
        pinMode(9,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Off();
 H();
 delay(1000);
 Off();
 delay(1000);
 Two();
 delay(1000);
 Off();
 delay(1000);
}
