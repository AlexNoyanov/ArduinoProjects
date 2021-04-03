//*******************
// Nunchack Motor Control
// 5 November 2015
//  Version 0.0 Alfa 
//*********************

//  Libraries:
  #include <Wire.h>
  #include <ArduinoNunchuk.h>
  #include <Stepper.h>

  int red = 7;
  int blue = 8;
  int green = 9;

  // change this to the number of steps on your motor
#define STEPS 100
  Stepper stepper(STEPS, 3, 4, 5, 6);
  int flag = 0;
  #define BAUDRATE 19200
  ArduinoNunchuk nunchuk = ArduinoNunchuk();
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  nunchuk.init();
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  stepper.setSpeed(100);
}

void loop() {
  // put your main code here, to run repeatedly:
    nunchuk.update();
     int y = nunchuk.accelY;
     int x = nunchuk.accelX;
     int z = nunchuk.accelZ;  
  if(x>500){
  stepper.step(x);
    nunchuk.update();
  delay(100);
  }else{ 
    //if(x<300){
  stepper.step(0);
    //}
  }
  if(y>400){
    digitalWrite(red,HIGH);
  }else{
    digitalWrite(red,LOW);
  }

   if(x>400){
    digitalWrite(blue,HIGH);
  }else{
    digitalWrite(blue,LOW);
  }

   if(z>400){
    digitalWrite(green,HIGH);
  }else{
    digitalWrite(green,LOW);
  }

  //  Serial print:
   Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);
  
  delay(100);
  
}
