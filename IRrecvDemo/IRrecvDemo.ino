
#include <IRremote.h>
#define TKD2 11


int RECV_PIN2 = TKD2;

IRrecv irrecv2(RECV_PIN2);

decode_results results2;

void setup()
{
  Serial.begin(9600);
  irrecv2.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv2.decode(&results2)) 
  {
    Serial.println(results2.value, HEX);
    if(results2.value == 0xFFA25D) 
    {
      Serial.println("VKLUCHAEM");
    }

    irrecv2.resume(); // Receive the next value
  }
}
