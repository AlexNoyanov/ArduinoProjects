#include <VirtualWire.h>

const int led_pin = 13; // Пин светодиода 
const int transmit_pin = 8; // Пин подключения передатчика
byte incomingByte;
char msg[200];
int index=0;

void setup() 
{ 
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
  vw_set_tx_pin(transmit_pin); 
  vw_setup(2000);       // Скорость передачи (Бит в секунду) 
  pinMode(led_pin, OUTPUT);
 memset(msg, 0, sizeof(msg));
 index = 0; 
}

void loop() 
{ 
  while (Serial.available() > 0) 
  {
     // read the incoming byte:
     incomingByte = Serial.read();
     //sprintf(msg, "Read:%c", incomingByte);
     if(incomingByte == '.')
     {
       memset(msg, 0, sizeof(msg));
       index = 0; 
     } else {
       msg[index++] = incomingByte;
     }
  }
      
  if(strlen(msg) > 0)
 {  
   //strcpy(msg, "Hello World"); // Передаваемое сообщение 
  digitalWrite(led_pin, HIGH); // Зажигаем светодиод в начале передачи 
  vw_send((uint8_t *)msg, strlen(msg)); // Отправка сообщения 
  vw_wait_tx(); // Ожидаем окончания отправки сообщения 
  digitalWrite(led_pin, LOW); // Гасим светодиод в конце передачи 
 }
  delay(1000); // Пауза 1 секунда 
}
