
#include <Wire.h>

void InitDisplay () {
  Wire.beginTransmission(address);
  Wire.write(commands);
  Wire.write(0xA1);  // Flip horizontal
  Wire.write(0xAF);  // Display on
  Wire.endTransmission();
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
