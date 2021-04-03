/*
* Web Server
*
* A simple web server that shows the value of the analog input pins.
*/
/*
#include <Ethernet.h>
 
byte mac[] = {0xA0, 0xB0, 0x0C, 0x5D, 0x6E, 0xFF };
byte ip[] = { 192, 168, 1, 95 };
 
EthernetServer server(80);
 
void setup()
{
  Ethernet.begin(mac, ip);
  server.begin();
}
 
void loop()
{
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean current_line_is_blank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if we've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so we can send a reply
        if (c == '\n' && current_line_is_blank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
 
          // output the value of each analog input pin
          for (int i = 0; i < 6; i++) {
            client.print("analog input ");
            client.print(i);
            client.print(" is ");
            client.print(analogRead(i));
            client.println("<br />");
          }
          break;
        }
        if (c == '\n') {
          // we're starting a new line
          current_line_is_blank = true;
        } else if (c != '\r') {
          // we've gotten a character on the current line
          current_line_is_blank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    client.stop();
  }
}

*/







// A simple web server that always just says "Hello World"




#include "etherShield.h"
#include "ETHER_28J60.h"

static uint8_t mac[6] = {0x54, 0x55, 0x55, 0x10, 0x01, 0x24};   // this just needs to be unique for your network, 
                                                                // so unless you have more than one of these boards
                                                                // connected, you should be fine with this value.
                                                           
static uint8_t ip[4] = {192, 168, 1, 95};                       // the IP address for your board. Check your home hub
                                                                // to find an IP address not in use and pick that
                                                                // this or 10.0.0.15 are likely formats for an address
                                                                // that will work.

static uint16_t port = 80;                                      // Use port 80 - the standard for HTTP

ETHER_28J60 ethernet;

void setup()
{ 
  Serial.begin(9600);
  ethernet.setup(mac, ip, port);
}


int counter = 1;
void loop()
{
char* request = ethernet.serviceRequest();
  if(request != NULL) {
     Serial.println(request);
    char s[1024];
    sprintf(s, "<H1>Hello World!</H1>\nRequest Count=%d", counter++);
    ethernet.print(s);
    ethernet.respond();
    // Serial.println();
    delay(100);
  } else {
    delay(300);
  }
}



