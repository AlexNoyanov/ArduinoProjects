#include <Servo.h>;
Servo sx;
Servo sy;
const int pin = 8; //пин кнопки
int button = 0; // состояние кнопки
int flag = 0; // флаг
const int sxpin = 9;
const int sypin = 10;
int ax; 
int ay;
const int stepplus = 5;
void setup() {
  // put your setup code here, to run once:
 sx.attach(sxpin);
sy.attach(sypin);
ay = 90;
ax = 90;
sy.write(ay);
sx.write(ax);
pinMode(8,INPUT);
pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int x = analogRead(A0);
int y = analogRead(A1);
if(y> 600) {
  ay = ay+stepplus;
  //delay(100);
  sy.write(ay);
}
if (y<300) {
  ay = ay-stepplus;
  //delay(100);
  sy.write(ay);
}


if(x> 600) {
  ax = ax+stepplus;
  //delay(100);
  sx.write(ax);
}
if (x<300) {
  ax = ax-stepplus;
  //delay(100);
  sx.write(ax);
}

/*if (ax>=180) {
  ax= 0;
}
*/
//sx.write(ax);
button = digitalRead(pin);
if (button == HIGH && flag == 0) {
  ax = ax +stepplus;
  sx.write(ax);
digitalWrite(13,HIGH);
flag =1;
}else{

if (button== HIGH&& flag ==1) {
  digitalWrite(13,LOW);
  flag = 0;
}
}
delay(100);
}
