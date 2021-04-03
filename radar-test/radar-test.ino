
//
//  Ultrasonic radar test
//  5 December 2015
//  Use radra_arduino in Processing
//v Connect servo on D8 pin 
//  Ultrasonic sensor trig on D7 and echo on D6
//

 #include<Servo.h>

 #define ECHO_PIN 6
 #define TRIG_PIN 7
 #define SERVO_PIN 8

Servo scanner;

 int spd = 50;
 int measure()
 {
  digitalWrite(TRIG_PIN,HIGH);
  digitalWrite(TRIG_PIN,LOW);
  int distance = pulseIn(ECHO_PIN,HIGH,15000)/50;
  return constrain (distance, 1, 300);
 }
void setup() {
  // put your setup code here, to run once:
pinMode(ECHO_PIN,INPUT);
pinMode(TRIG_PIN,OUTPUT);
pinMode(SERVO_PIN,OUTPUT);
Serial.begin(9600);
scanner.attach(SERVO_PIN);
}

void loop() 
{/*
  for(int i = 0; i < 180; i++)
  {
    scanner.write(i);
    delay(500);
  }
return;
  */
  // put your main code here, to run repeatedly:
int distance = measure();
for(int  i = 0 ; i<180;i++)
{
  scanner.write(i);
 distance = measure();
 delay(spd);

  Serial.print(i);
  Serial.print(":");
  Serial.print(distance);
  Serial.println(";");
  }
  for(int k = 180;k > 0; k--){
    scanner.write(k);
    delay(spd);
  }
}


