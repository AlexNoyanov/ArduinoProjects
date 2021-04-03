#include <VirtualWire.h>
#include <LiquidCrystal.h>
byte message[VW_MAX_MESSAGE_LEN]; // Буфер для хранения принимаемых данных 
byte messageLength = VW_MAX_MESSAGE_LEN; // Размер сообщения

const int led_pin = 7; // Пин светодиода 
const int receiver_pin = 9; // Пин подключения приемника
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
void setup() 
{ pinMode(led_pin,OUTPUT);
  Serial.begin(9600); // Скорость передачиданных 
  Serial.println("MX-RM-5V is ready"); 
  vw_set_rx_pin(receiver_pin); // Пин подключения приемника
  lcd.begin(16,2); 
  vw_setup(2000); // Скорость передачи данных (бит в секунду) 
  vw_rx_start(); // Активация применика 
  lcd.clear();   
} 
void loop() 
{ 
    memset(message, 0, VW_MAX_MESSAGE_LEN);
  if (vw_get_message(message, &messageLength)) // Если есть данные.. 
  { 
    digitalWrite(led_pin, HIGH); // Зажигаем светодиод в начале приема пакета
    for (int i = 0; i < messageLength; i++) 
    {  
      //delay(100);
      Serial.write(message[i]); // выводим их в одной строке 
    } 
    lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
    lcd.print((char*)message);
     //lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
 // lcd.println(); 
    Serial.println(); 
    digitalWrite(led_pin, LOW); // Гасим светодиод в конце 
  } else {
    lcd.clear();
  }
  delay(1000);
}


