/*
 *How to connect: 
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

//  Libraries:
#include "etherShield.h"
#include "ETHER_28J60.h"

//  Pins
int BluePin = 6;
int RedPin = 7;
int GreenPin = 8;

static uint8_t mac[6] = {0x89, 0x15, 0x48, 0x10, 0x01, 0x24};   // This just needs to be unique for your network, 
                                                           
static uint8_t ip[4] = {192, 168, 1, 15}; // IP address for the webserver

static uint16_t port = 80; // Use port 80 - the standard for HTTP

ETHER_28J60 e;

void setup() {
  // put your setup code here, to run once:
  pinMode(BluePin,OUTPUT);
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  e.setup(mac, ip, port);
}

void loop() {
  // put your main code here, to run repeatedly:
  char* params;

  if (params = e.serviceRequest())
  {
    e.print("<HEAD>");
    e.print("<title>");
    e.print(">Arduino Server<");
    e.print("</title>");
    e.print("</HEAD>");
    
    //e.print("<P ALIGN=CENTER>");
  //e.print("<P ALIGN=CENTER>");
    e.print("<BODY BGCOLOR=#00ff7f>");
    e.print("<ALIGN=CENTER><h1><a href='/?led=off'>Arduino Web Remote</a></h1>");
    
    if (strcmp(params, "?led=on") == 0 )
    {
      digitalWrite(BluePin, HIGH);
      e.print("<a href='?led=off'><button style='border: 1px solid #ff0000; border-left: 10px solid #ff0000' type='button'>Blue LED IS ON</button></a>");
    }
    else if (strcmp(params, "?led=off") == 0)
    {
      digitalWrite(BluePin, LOW);
      e.print("<a href='?led=on'><button style=  'border: 1px solid #000; border-left: 10px solid #000' type='button'>Blue LED IS OFF</button></a>");
    }

                  //  e.print("<button  style=width:100x;height:75px  onclick=\"window.location.href='/red OFF'\">Turn OFF RED</button>");
                  //  e.print("<p></p>");
    e.print("<h4>");
    e.print("<font color =#ffgg>Test</font><br></br>");
    e.print("By Alex Noyanov");
    e.print("</h4>");
    e.print("</BODY>");
    e.respond();
  }
}
