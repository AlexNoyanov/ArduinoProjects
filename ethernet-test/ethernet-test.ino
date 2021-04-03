#include <SPI.h>
#include <Ethernet.h> //библиотека Ethernet 
IPAddress ip(192, 168, 1, 100); // устанавливаем IP адрес
EthernetServer server(80);  // create a server at port 80
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // МАС адрес
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //скорость serial порта
Ethernet.begin(mac, ip);  // инициализируем Ethernet девайс
  server.begin();           // начинаем получать от клиентов
}

void loop() {
  // put your main code here, to run repeatedly:
EthernetClient client = server.available();  // пытаемся стать клиентом
if (client) {  // получили клиента?
 boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // данные клиента доступны для чтения
              char c = client.read(); // read 1 byte (character) from client
                // last line of client request is blank and ends with \n
                if (c == '\n' && currentLineIsBlank) 
                {
                client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title>Arduino Web Page</title>");
                    client.println("</head>");
                    client.println("<body>");
                    client.println("<h1>Hello from Alexander Noyanov Arduino!</h1>");
                    client.println("<p>A web page from the Arduino server</p>");
                    client.println("<p>This server is controlled by Noyanov</p>");
                    client.println("<p></p>"); 
            }
        }
}
}

}                    
