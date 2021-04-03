#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN]; // Буфер для хранения принимаемых данных 
byte messageLength = VW_MAX_MESSAGE_LEN; // Размер сообщения

const int led_pin = 7; // Пин светодиода 
const int receiver_pin = 8; // Пин подключения приемника

void setup() 
{ pinMode(led_pin,OUTPUT);
  Serial.begin(9600); // Скорость передачиданных 
  Serial.println("MX-RM-5V is ready"); 
  vw_set_rx_pin(receiver_pin); // Пин подключения приемника

  vw_setup(2000); // Скорость передачи данных (бит в секунду) 
  vw_rx_start(); // Активация применика 
} 
void loop() 
{ 
  if (vw_get_message(message, &messageLength)) // Если есть данные.. 
  { 
    digitalWrite(led_pin, HIGH); // Зажигаем светодиод в начале приема пакета 
    for (int i = 0; i < messageLength; i++) 
    { 
      Serial.write(message[i]); // выводим их в одной строке 
    } 
    Serial.println(); 
    digitalWrite(led_pin, LOW); // Гасим светодиод в конце 
  } 
}


