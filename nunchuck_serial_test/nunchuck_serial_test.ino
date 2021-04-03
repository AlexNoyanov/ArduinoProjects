
#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop() {
  nunchuk.update();
  // put your main code here, to run repeatedly:
 //Serial.println(nunchuk.accelX, DEC);
 //Serial.print(",");
  Serial.println(nunchuk.accelY, DEC);
  //Serial.print(",");
 //Serial.println(nunchuk.accelZ, DEC);
 delay(100);
}
