// nunchack light analog
// 3 November 2015
// 

#include <Wire.h>
#include <ArduinoNunchuk.h>

int red = 7;
int blue = 8;
int green = 9;

#define BAUDRATE 19200
//19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  // put your setup code here
  Serial.begin(BAUDRATE);
   nunchuk.init();
  
}
  void loop() {
   nunchuk.update();
   
  int y = nunchuk.accelY;
  int x = nunchuk.accelX;
  int z = nunchuk.accelZ;



  Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);
  
     analogWrite(A0,x);
     delay(100);
    
  }

