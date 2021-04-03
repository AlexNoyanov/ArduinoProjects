//  ===================
//  Signal lenght meter
//    Simple example
//    5 December 2015
//  ===================

//  Use 7 pin:
int pin = 7;
//  So long number:
unsigned long duration;
 
void setup()
{
  //  Set pin as INPUT:
  pinMode(pin, INPUT);
}
 
void loop()
{
  //  Read signal if pin HIGH:
  duration = pulseIn(pin, HIGH);
  Serial.print("Signal lenght = ");
  Serial.println(duration);
}

