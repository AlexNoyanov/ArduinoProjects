#include <etherShield.h>
#include <ETHER_28J60.h>
//#include "ETHER_28J60.h"
// Define MAC address and IP address - both should be

//unique in your network
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};
static uint8_t ip[4] = {192, 168, 1, 15};
static uint16_t port = 80; // Use port 80 - the standard for HTTP

ETHER_28J60 ethernet;

void setup()
{ 
  ethernet.setup(mac, ip, port);
}

void loop()
{
  if (ethernet.serviceRequest())
  {
    ethernet.print("<H1>Hello World</H1>");
    ethernet.respond();
  }
  delay(100);
}


