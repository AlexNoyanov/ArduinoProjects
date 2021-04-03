#define mic 5
#define analogInPin A0
void setup() {
pinMode(analogInPin, INPUT);
Serial.begin(9600);
}
void loop() {

Serial.println(analogRead(analogInPin));
int sensorValue = analogRead(analogInPin);
int range = map(sensorValue, 100, 145, 1, 4);
switch (range) {
case 1:
analogWrite(mic,100);
delay(100);
analogWrite(mic,0);
break;
case 2:
analogWrite(mic,50);
delay(100);
analogWrite(mic,0);
break;
case 3:
analogWrite(mic,30);
delay(100);
analogWrite(mic,0);
break;
case 4:
analogWrite(mic,20);
delay(100);
analogWrite(mic,0);
break;
}
}
