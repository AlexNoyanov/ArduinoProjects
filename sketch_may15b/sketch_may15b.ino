   #include <Servo.h>
Servo myservo;
int i =80;

void setup() {
  // put your setup code here, to run once:
myservo.attach(13);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(85);
delay(5000);
myservo.write(180);
delay(1000);
myservo.write(0);
delay(1000);
}


