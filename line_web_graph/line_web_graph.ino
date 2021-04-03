//вывод данных с помощью web-сервера в виде графиков
// автор А. Коновалов 2015 г.
//#include <UIPEthernet.h>
#include <Ethernet.h>
#include <SPI.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,26,15);

EthernetServer server(80);
const char str1[] PROGMEM = "<!DOCTYPE html>"; 
const char str2[] PROGMEM = " »;
const char str12[] PROGMEM = " ";

const char* const string_table[] PROGMEM = {str1, str2, str3, str4, str5, str6, str7};
const char* const string_table2[] PROGMEM = {str8, str9, str10, str11, str12};
char myChar;
char buffer[80]; 

unsigned long previousMillis1 = 0;// посл момент времени
unsigned long previousMillis2 = 1;// посл момент времени
unsigned long previousMillis3 = 1;// посл момент времени

long OnTime2 = 60000; // минута
long OnTime3 = 600000; // полчаса
int In_sec = 0; // отсчет за сек
int In_min = 0; // отсчет за мин
int In_half = 0; // отсчет за полчаса

long Sum_min = 0; // сумма за мин
long Sum_half = 0; // сумма за полчаса
float Sum_base_min = 0;
float Sum_base_half = 0;
int i,j,k =0;

void setup()
{
// start the Ethernet connection and the server:
Ethernet.begin(mac, ip);
server.begin();

}
//unsigned long begMillis = millis();// тек время в мс 
void loop()
{
unsigned long currentMillis = millis();// тек время в мс 

In_sec = analogRead(0); 
Sum_min = Sum_min + (currentMillis — previousMillis1) * In_sec;
In_min = (Sum_min + Sum_base_min ) / (OnTime2 * i + currentMillis — previousMillis2);
Sum_half = Sum_half + (currentMillis — previousMillis1) * In_sec;
In_half = (Sum_half + Sum_base_half) / (OnTime3 * j + currentMillis — previousMillis3);
previousMillis1 = currentMillis; // запоминаем момент времени

if(currentMillis — previousMillis2 >= OnTime2)
{ i=1;
Sum_base_min = Sum_min;
previousMillis2 = currentMillis; // запоминаем момент времени
Sum_min = 0;
} 
if(currentMillis — previousMillis3 >= OnTime3)
{ j=1;
Sum_base_half = Sum_half;
previousMillis3 = currentMillis; // запоминаем момент времени
Sum_half = 0;
} 

EthernetClient client = server.available();
if (client) {
// an http request ends with a blank line
boolean currentLineIsBlank = true;
while (client.connected()) {
if (client.available()) {
char c = client.read();
if (c == '\n' && currentLineIsBlank) {

for (int i = 0; i < 7; i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i]))); // Necessary casts and dereferencing, just copy.
client.print(buffer);
delay( 500 );
}

client.print("['Ввод 1', ");
client.print(In_sec);
client.print(", ");
client.print(In_min);
client.print(", ");
client.print(In_half);
client.print( "],]);");


for (int i = 0; i < 5; i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table2[i]))); // Necessary casts and dereferencing, just copy.
client.print(buffer);
delay( 500 );
}

break;
}
if (c == '\n') {
// you're starting a new line
currentLineIsBlank = true;
}
else if (c != '\r') {
// you've gotten a character on the current line
currentLineIsBlank = false;
}
}
}
// give the web browser time to receive the data
delay(1);
// close the connection:
client.stop();
}
}


//вывод данных с помощью web-сервера в виде графиков
// автор А. Коновалов 2015 г.
//#include <UIPEthernet.h>
#include <Ethernet.h>
#include <SPI.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,26,15);

EthernetServer server(80);
const char str1[] PROGMEM = "<!DOCTYPE html>"; 
const char str2[] PROGMEM = " »;
const char str12[] PROGMEM = " ";

const char* const string_table[] PROGMEM = {str1, str2, str3, str4, str5, str6, str7};
const char* const string_table2[] PROGMEM = {str8, str9, str10, str11, str12};
char myChar;
char buffer[80]; 

unsigned long previousMillis1 = 0;// посл момент времени
unsigned long previousMillis2 = 1;// посл момент времени
unsigned long previousMillis3 = 1;// посл момент времени

long OnTime2 = 60000; // минута
long OnTime3 = 600000; // полчаса
int In_sec = 0; // отсчет за сек
int In_min = 0; // отсчет за мин
int In_half = 0; // отсчет за полчаса

long Sum_min = 0; // сумма за мин
long Sum_half = 0; // сумма за полчаса
float Sum_base_min = 0;
float Sum_base_half = 0;
int i,j,k =0;

void setup()
{
// start the Ethernet connection and the server:
Ethernet.begin(mac, ip);
server.begin();

}
//unsigned long begMillis = millis();// тек время в мс 
void loop()
{
unsigned long currentMillis = millis();// тек время в мс 

In_sec = analogRead(0); 
Sum_min = Sum_min + (currentMillis — previousMillis1) * In_sec;
In_min = (Sum_min + Sum_base_min ) / (OnTime2 * i + currentMillis — previousMillis2);
Sum_half = Sum_half + (currentMillis — previousMillis1) * In_sec;
In_half = (Sum_half + Sum_base_half) / (OnTime3 * j + currentMillis — previousMillis3);
previousMillis1 = currentMillis; // запоминаем момент времени

if(currentMillis — previousMillis2 >= OnTime2)
{ i=1;
Sum_base_min = Sum_min;
previousMillis2 = currentMillis; // запоминаем момент времени
Sum_min = 0;
} 
if(currentMillis — previousMillis3 >= OnTime3)
{ j=1;
Sum_base_half = Sum_half;
previousMillis3 = currentMillis; // запоминаем момент времени
Sum_half = 0;
} 

EthernetClient client = server.available();
if (client) {
// an http request ends with a blank line
boolean currentLineIsBlank = true;
while (client.connected()) {
if (client.available()) {
char c = client.read();
if (c == '\n' && currentLineIsBlank) {

for (int i = 0; i < 7; i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i]))); // Necessary casts and dereferencing, just copy.
client.print(buffer);
delay( 500 );
}

client.print("['Ввод 1', ");
client.print(In_sec);
client.print(", ");
client.print(In_min);
client.print(", ");
client.print(In_half);
client.print( "],]);");


for (int i = 0; i < 5; i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table2[i]))); // Necessary casts and dereferencing, just copy.
client.print(buffer);
delay( 500 );
}

break;
}
if (c == '\n') {
// you're starting a new line
currentLineIsBlank = true;
}
else if (c != '\r') {
// you've gotten a character on the current line
currentLineIsBlank = false;
}
}
}
// give the web browser time to receive the data
delay(1);
// close the connection:
client.stop();
}
}



