#include <RoboCar.h>

RoboCar myCar;
void setup() {
  // put your setup code here, to run once:
myCar.begin(1,2,3,4);
myCar.stop();
myCar.goForward(1000);
myCar.turnLeft(100);
myCar.stop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
