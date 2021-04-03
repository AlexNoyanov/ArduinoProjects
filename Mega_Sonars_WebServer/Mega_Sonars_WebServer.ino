
// ========================================
/*
 *    Ultrasonic level sensor Web server
 *    Showing levels on the webpage
 *    Using Web module ENC28J60
 * 
 *    By Alex Noyanov, GitHub: AlexNoyanov
 *  
 *  Ultrasonic library: https://github.com/AlexNoyanov/Sonar
 *  Library requred: EtherCard.h
 */
// ========================================

#include <Sonar.hpp>                                       
#include <EtherCard.h>

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

const int timeDelay = 30000;  // Delay between requests(ms)
//const int timeDelay1 = 6000;

byte Ethernet::buffer[700];
static uint32_t timer;

const char website[] PROGMEM = "192.168.1.156";   // Server Adress

// called when the client request is complete
static void my_callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

// Array of Sonars pins:
int trigs[3] = {22,24,26};//{2,4,6};
int echos[3] = {23,25,27}; 

int distances[3];
int distance = 0;

// Liquid level sensors:
int sensPin1 = A0;    
int sensPin2 = A2;
int sens1Value,sens2Value = 0;

//int sens1Max = 700;
//int sens2Max = 750;

String testRequest = "?s1=111&s2=222&s3=333&l1=11&l2=22&k=57836";
String path = "/Work/insertData_test.php";                        // Path on the server

String token = "57836";     // Arduino token access code
//String kiosk_id = "1";      // Kiosk name
//                 S1,S2,S3, L1 ,L2        
int maxLevels[5] = {30,20,40,750,650};  // Maximum levels for sonars 1-2-3
//                 S1,S2,S3, L1 ,L2 
int minLevels[5] = {10,20,20,350,250};  // Minimum levels values

int sens1,sens2;

String request = "?s1=";

Sonar sonars[3];  // = { Sonar(22,23), Sonar(24,25), Sonar(26, 27) };

#define sonarCounter sizeof(sonars)/sizeof(sonars[0])

void setup()
{ 
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

// ===== Measuring all values ======:
    sens1 = analogRead(sensPin1);
    sens2 = analogRead(sensPin2);

  // === Getting value from sensor value: ===
  sens1Value =  map(sens1, minLevels[3], maxLevels[3], 0, 100);
  sens2Value =  map(sens1, minLevels[4], maxLevels[4], 0, 100);
  
  //==== ==== ==== ==== ==== ==== ==== 
  
    
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
    //delay(timeDelay1);
    //delay(6000);

    // Making request:
    request = "?s1=";
    Serial.println();
    Serial.print("<<< REQ ");
    request += String(maxLevels[0]-distances[0]);
    request += "&s2=";
    request += String(maxLevels[1]-distances[1]);
    request += "&s3=";
    request += String(maxLevels[2]-distances[2]);
    request += "&l1=";
    request += String(sens1Value);
    request += "&l2=";
    request += String(sens2Value);
    //request += "&k=";
    //request += kiosk_id;
    request += "&k=";
    request += token;
    
    Serial.println(request.c_str());
   
    const char buf[128];
    memset(buf, 0, 128);
    strcpy(buf, request.c_str());
      
    ether.browseUrl(PSTR("/Work/insertData_test.php"), buf, website, my_callback);
  }
  
}
