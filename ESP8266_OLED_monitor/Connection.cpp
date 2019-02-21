// Connecting to the following adress through HTTP
//


// Instagram adress: https://www.instagram.com/alex_noyanov/

#include <ESP8266WiFi.h>
#include "Connection.h"

// Methods from class WIFI_Connector

void WIFI_Connector::SerialData()
{
   // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

bool WIFI_Connector::begin()
{

  
 return 0;   
}



