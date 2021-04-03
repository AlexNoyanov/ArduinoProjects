void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  
  
  // put your main code here, to run repeatedly:
//поворот на право
digitalWrite(13,HIGH);//левое вперед
digitalWrite(12,HIGH);//правое вперед
delay(400);
digitalWrite(12,LOW);//правое вперед
digitalWrite(13,LOW);//левое вперед
//ждем
delay(2000);
//едем вперед
digitalWrite(11,HIGH);//левое вперед
digitalWrite(10,HIGH);//правое вперед
delay(400);
digitalWrite(11,LOW);//правое стоп
digitalWrite(10,LOW);//левое стоп
delay(200);
//поворот на лево
digitalWrite(11,HIGH);//левое вперед
digitalWrite(12,HIGH);//правое вперед
delay(500);
digitalWrite(11,LOW);//левое стоп
digitalWrite(12,LOW);//правое стоп

delay(2000);
//едем назад
digitalWrite(13,HIGH);//левое назад
digitalWrite(12,HIGH);//правое назад
delay(400);
digitalWrite(12,LOW);//правое стоп
digitalWrite(13,LOW);//левое стоп
//ждем
delay(2000);

}
