
//
//    =====================
//    Nintendo WII Nunchack 
//    Servo controll
//    By Alex Noyanov
//    17 December 2015
//    =====================
//                __________________
//    |--___--|  | 1- A5  |  4- 3.3V|
//    |1| 2 |3|  | 2-empty|  5- emty|
//    |4| 5 |6|  | 3- GND |  6- A4  |
//     -------   |________|_________|
//
//  Libraries:
#include <Servo.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>

Servo servo[6];
int Zbtn = 0;
int Cbtn = 0;
int flag = 0;
int x,y,z,xj,yj;
int mode;
#define BAUDRATE 9600
//19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  
 // Attaching servos:
 int pin = 6;
 for(int i=0;i<5;i++){
   servo[i].attach(pin);
   pin++;
  }
  nunchuk.init();
  nunchuk.update();
}

void loop() {
  // put your main code here, to run repeatedly:
  //  Read from nunchack:
    nunchuk.update();
 // Use results:
  y = nunchuk.accelY;
  x = nunchuk.accelX;
  z = nunchuk.accelZ;
  
  //  Button read:
  Zbtn = nunchuk.zButton;
  Cbtn = nunchuk.cButton;
  
  // Read from joystick : 
 //  xj =  nunchuk.readJoyX();
   //yj = nunchuk.readJoyY();
   
  //  Print Serial (For testing):
  
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("      Y = ");
  Serial.println(y);
  Serial.print("      Z = ");
  Serial.println(z);
 
 // Mapping all axis:
  int anglex = map(x,290,750,10,180);
  int angley = map(y,290,750,10,180);
  int anglez = map(z,290,750,10,180);
  //  Turn servos by accelerometer:
  servo[0].write(anglex);
  servo[1].write(angley);
  servo[3].write(anglez);
  
  delay(100);
  
}
