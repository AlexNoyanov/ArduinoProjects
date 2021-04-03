/*--------------------------------------------------------------
  Program:      eth_websrv_page

  Description:  Arduino web server that serves up a basic web
                page. Does not use the SD card.
  
  Hardware:     Arduino Uno and official Arduino Ethernet
                shield. Should work with other Arduinos and
                compatible Ethernet shields.
                
  Software:     Developed using Arduino 1.0.3 software
                Should be compatible with Arduino 1.0 +
  
  References:   - WebServer example by David A. Mellis and 
                  modified by Tom Igoe
                - Ethernet library documentation:
                  http://arduino.cc/en/Reference/Ethernet

  Date:         7 January 2013
 
  Author:       W.A. Smith, http://startingelectronics.com
--------------------------------------------------------------*/

#include <SPI.h>
#include <Ethernet.h>

// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 0, 0, 177); // IP address, may need to change depending on network
EthernetServer server(80);  // create a server at port 80

const int LEDPin = 3;

int connection_count=0;
char connection_count_buffer[10];

void setup()
{
    Ethernet.begin(mac, ip);  // initialize Ethernet device
    server.begin();           // start to listen for clients
    pinMode(LEDPin, OUTPUT);
}

void loop()
{
    EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    digitalWrite(LEDPin, HIGH);
                    // send a standard http response header
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
                    client.print("<p>Your are ");
                    connection_count++;
                    if(connection_count == 1)
                      client.print("first");
                    else if(connection_count == 2)
                      client.print("second");
                    else if(connection_count == 3)
                      client.print("third");
                    else {
                      client.print(connection_count);
                      client.print("-th");
                    }
                    client.println(" visitor of the server!</p>");
                    client.println("</body>");
                    client.println("</html>");
                    digitalWrite(LEDPin, LOW);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
            else { // no data available
                //digitalWrite(LEDPin, LOW);
            }
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}

