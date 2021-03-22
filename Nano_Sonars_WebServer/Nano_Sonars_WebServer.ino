
// ========================================
/*
 *    Ultrasonic level sensor Web server
 *    Showing levels on the webpage
 *    Using Web module ENC28J60
 * 
 *  By Alex Noyanov, GitHub: AlexNoyanov
 *  
 *  Ultrasonic library: https://github.com/AlexNoyanov/Sonar
 *  Library requred: etherShield.h & ETHER_28J60.h
 */
// ========================================

//#include "etherShield.h"
//#include "ETHER_28J60.h"


#include <Sonar.hpp>

//static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   // this just needs to be unique for your network, 
                                                                // so unless you have more than one of these boards                                                                // connected, you should be fine with this value.
#include <EtherCard.h>

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

const int timeDelay = 1000*60;

byte Ethernet::buffer[700];
static uint32_t timer;

const char website[] PROGMEM = "192.168.1.156";

// called when the client request is complete
static void my_callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

// Array of Sonars pins:
int trigs[3] = {2,4,6};//{2,4,6};
int echos[3] = {3,5,7}; 

int distances[3];
int distance = 0;

// Liquid level sensors:
int sensPin1 = A0;    
int sensPin2 = A2;

String testRequest = "?s1=111&s2=222&s3=333&l1=11&l2=22&k=57836";
String testPath = "/Work/insertData_test.php";

//String adress = "";
//String request = "http://192.168.1.156/Work/ArduinoWeb/insertData.php?";
//String form = "<form action='";
//String method = "' method='POST'>";
//String fullForm = " ";
//String key = "689403";              // Security key
//const char* cStr = "";
//String testForm = "<form action=http://192.168.1.156/Work/ArduinoWeb/insertData.php?s1=100&s2=200&s3=300&l1=250&l2=350&k=689403";

int sens1Value,sens2Value;

Sonar sonars[3];  // = { Sonar(22,23), Sonar(24,25), Sonar(26, 27) };

#define sonarCounter sizeof(sonars)/sizeof(sonars[0])

//void sendRequest(String request,String path,Ethernet ether){
//   ether.packetLoop(ether.packetReceive());
//
//  if (millis() > timer) {
//    timer = millis() + 5000;
//    Serial.println();
//    Serial.print("<<< REQ ");
//    ether.browseUrl(PSTR(path), request, website, my_callback);
//  }
//}

void setup()
{ 
  //ethernet.setup(mac, ip, port);

    Serial.begin(9600);
  // Creating sensors:
  for(int i = 0; i < 3; i++){
      sonars[i].setPin(trigs[i],echos[i]);
    Serial.print("Created SONAR  with Trig = ");
    Serial.print(trigs[i]);
    Serial.print("  Echo = ");
    Serial.println(echos[i]);
  }
  Serial.println(sonarCounter);
//  for(int i =0; i<4;i++){
//    Serial.print(ip[i]);
//  }
//  Serial.println("");

// ETHERNET SETUP PART:
 Serial.println(F("\n[webClient]"));

  // Change 'SS' to your Slave Select pin, if you arn't using the default pin
  if (ether.begin(sizeof Ethernet::buffer, mymac, SS) == 0)
    Serial.println(F("Failed to access Ethernet controller"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);
  ether.printIp("DNS: ", ether.dnsip);

  char websiteIP[] = "192.168.1.156";
  ether.parseIp(ether.hisip, websiteIP);

  ether.printIp("SRV: ", ether.hisip);

}

void loop()
{
    // Reading from liquid level sensors:
 
//
//  Serial.print("Level1 = ");
//  Serial.print(sens1Value);
//
//  Serial.print(" Level2 = ");
//  Serial.print(sens2Value);
//  Serial.print("   ");
  


//  for(int i = 0; i < 3; i++){
//    Serial.print("Sonar [");
//    Serial.print(i);
//    Serial.print("] =");
//    Serial.print(sonars[i].getDistance());
//    Serial.print("   ");
//  }
  
  //Serial.println(" ");

  //sendRequest(testRequest,testPath,ether);

   ether.packetLoop(ether.packetReceive());

  if (millis() > timer) {
    timer = millis() + timeDelay;

    sens1Value = analogRead(sensPin1);
    sens2Value = analogRead(sensPin2);
    //  // Reading distance from all sonars:
   for(int i = 0; i < 3; i++){
     sonars[i].readDistance();
    //delay(500);
    }
   //
   for(int i = 0; i < 3; i++){
     distance = sonars[i].getDistance();
     distances[i] = distance;
    }
    
    Serial.println();
    Serial.print("<<< REQ ");
    ether.browseUrl(PSTR("/Work/insertData_test.php"), "?s1=111&s2=222&s3=333&l1=11&l2=22&k=57836", website, my_callback);
  }

 
}
