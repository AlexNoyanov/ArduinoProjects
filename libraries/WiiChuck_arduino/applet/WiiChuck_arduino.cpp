/*
 * Nunchuck -- Use a Wii Nunchuck
 * Tim Hirzel http://www.growdown.com
 
 modified by Chris Coleman to send the output of the joystick, and both buttons
 */

#include <math.h>

#include "Wire.h"
#include "WiiChuck.h"
//#include "nunchuck_funcs.h"

#define MAXANGLE 90
#define MINANGLE -90


#include "WProgram.h"
void setup();
void loop();
WiiChuck chuck = WiiChuck();


void setup() {
  //nunchuck_init();
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
  //chuck.calibrateJoy();
}


void loop() {
  delay(20);
  chuck.update(); 


  Serial.print(chuck.readRoll());
  Serial.print(", ");  
  Serial.print(chuck.readPitch());
  Serial.print(", ");  
  Serial.print((int)chuck.readAccelX()); 
  Serial.print(", ");  
  Serial.print((int)chuck.readAccelY()); 
  Serial.print(", ");  
  Serial.print((int)chuck.readAccelZ()); 
  Serial.print(", "); 
  Serial.print((int)chuck.readJoyX()); 
  Serial.print(", ");
  Serial.print((int)chuck.readJoyY()); 
  Serial.print(", ");
  Serial.print((int)chuck.cPressed()); 
  Serial.print(", ");
  Serial.print((int)chuck.zPressed()); 
  Serial.println();

}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

