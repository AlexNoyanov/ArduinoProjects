/*
CLK - _
NT - _
WOL - _
SO - 12
SL - 11
SCK - 13
CS - 10
RESET - rst pin
VCC- 3.5/5 Volts
GND- Ground pin
*/

#include "etherShield.h"
#include "ETHER_28J60.h"

int outputPin = 6;

static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   // this just needs to be unique for your network, 
                                                           
static uint8_t ip[4] = {192, 168, 1, 15}; // IP address for the webserver

static uint16_t port = 80; // Use port 80 - the standard for HTTP

ETHER_28J60 e;


void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin,OUTPUT);
  e.setup(mac, ip, port);
}

void loop() {
  // put your main code here, to run repeatedly:
  char* params;
  if (params = e.serviceRequest())
  {
    e.print("<HEAD>");
    e.print("<title>");
    e.print("<Arduino Server>");
    e.print("</title>");
    e.print("</HEAD>");
    
    //e.print("<P ALIGN=CENTER>");
    e.print("<BODY BGCOLOR=#00ff7f>");
    e.print("<ALIGN=CENTER><h1><a href='/?led=off'>Arduino Web Remote</a></h1>");
    if (strcmp(params, "?led=on") == 0)
    {
      digitalWrite(outputPin, HIGH);
      e.print("<a href='?led=off'><button style='border: 1px solid #ff0000; border-left: 10px solid #ff0000' type='button'>LED IS ON</button></a>");
    }
    else if (strcmp(params, "?led=off") == 0)
    {
      digitalWrite(outputPin, LOW);
      e.print("<a href='?led=on'><button style='border: 1px solid #000; border-left: 10px solid #000' type='button'>LED IS OFF</button></a>");
    }
    e.print("</BODY>");
    e.respond();
  }
}
