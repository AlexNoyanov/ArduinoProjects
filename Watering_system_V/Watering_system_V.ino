//  Libraries:
#include <SPI.h>
#include <Ethernet.h>
//#include <LiquidCrystal.h>              //Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "Screen.hpp"


LiquidCrystal_I2C lcd(0x27,20,4);         // set the LCD address to 0x27 for a 16 chars and 2 line display

IPAddress ip(192, 168, 1, 93);            // IP address, may need to change depending on network
EthernetServer server(80);                // Create a server at port 80

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
