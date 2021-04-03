 #include <VirtualWire.h>
 byte message[VW_MAX_MESSAGE_LEN]; // Буфер для хранения принимаемых данных 
 byte messageLength = VW_MAX_MESSAGE_LEN; // Размер сообщения
const int receiver_pin = 8; // Пин подключения приемника
 int ledres = 12;
 int rf = 8;
 int rb = 9;
 int lf = 10;
 int lb = 11;
 const int transmit_pin = 7; // Пин подключения передатчика
 void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(ledres,HIGH);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
Serial.println("MX-RM-5V is ready"); 
  vw_set_rx_pin(receiver_pin); // Пин подключения приемника
 // lcd.begin(16,2); 
  vw_setup(2000); // Скорость передачи данных (бит в секунду) 
  vw_rx_start(); // Активация применика 
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
    memset(message, 0, VW_MAX_MESSAGE_LEN);
      if (vw_get_message(message, &messageLength)) // Если есть данные.. 
  { 
    digitalWrite(ledres, HIGH); // Зажигаем светодиод в начале приема пакета
    for (int i = 0; i < messageLength; i++) 
    {  
      //delay(100);
      Serial.write(message[i]); // выводим их в одной строке 
    } 
  } 
}
