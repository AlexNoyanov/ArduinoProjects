//  Turn On and Off LED 
//  with IR remote
//  IR on 11 pin
//  LED on 8 pin
//  
//  ================
//  Button  | Value
//  ======= | ======
/*  ON/OFF  | FFA25D
 *    +     | FF906F
 *    -     | FFA857
 *    Back  | FF02FD
 *  Forward | FFC23D
 */

#include <IRremote.h>
int RECV_PIN = 11;
int flag = 0;
int ledBrightnes = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(8,OUTPUT);
}

void loop() {
   delay(100);
  if (irrecv.decode(&results)) {
    Serial.println(ledBrightnes);
    Serial.println(results.value,HEX);
    irrecv.resume(); // Receive the next value
    
  
  if(results.value == 0xFFA25D && flag == 0){
    digitalWrite(8,HIGH);
    //delay(100);
    flag =1;
 
  }else{
     if(results.value == 0xFFA25D && flag == 1){
    digitalWrite(8,LOW);
   // delay(100);
    flag =0;
   }
//  If "+", then get brightness higher
   if(results.value == 0xFF906F){
  ledBrightnes = ledBrightnes + 10;
   }

      if(results.value == 0xFFA857){
  ledBrightnes = ledBrightnes - 10;
  
   }
  // analogWrite(A1,ledBrightnes);
  }
  
 }
analogWrite(A0,ledBrightnes);
}
