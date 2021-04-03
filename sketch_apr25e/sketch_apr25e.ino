#include <Stepper.h>


#define STEPS 100
int Pin0 = 10; 
int Pin1 = 11; 
int Pin2 = 12; 
int Pin3 = 13; 
Stepper stepper(STEPS, 10, 11, 12, 13);

int _step = 0; 
boolean dir = true;// gre
void setup() 
{ 
  stepper.setSpeed(300);
} 
 void loop() 
{ 
  for(int i = 0; i < 50; i++)
  {
  stepper.step(1000);
 delay(20); 
  }
 delay(1000); 
  for(int i = 0; i < 50; i++)
  {
  stepper.step(-1000);
 delay(20); 
  }
}
