
int pin = 12;
int button = 0;
int flag = 0;
void setup() {
  // put your setup code here, to run once:
 
pinMode(8,INPUT);
pinMode(13,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(10,LOW);
digitalWrite(9,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

button = digitalRead(pin);
    if (button == HIGH && flag == 0) {
digitalWrite(13,HIGH);
flag =1;
}else{

if (button== HIGH && flag ==1) {
  digitalWrite(13,LOW);
  flag = 0;
  delay(100);
}
}
delay(200);
}
