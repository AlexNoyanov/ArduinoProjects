// ========================================
/*
 *    Ultrasonic level sensor Web server
 *    Showing levels on the webpage
 *    Using Web module ENC28J60
 *    
 *    Test version: x3 Sonars only + x2 Waterproofed Sonars
 *    
 *    TESTING KALMAN FILTER IN HARDWARE
 *    
 *    VALUES ONLY! NO % IN REQUEST!
 *    ALL %  WILL BE CALULATED ON THE SERVER!
 *   
 *    CHANGE timeDelay
 * 
 *    By Alex Noyanov, GitHub: AlexNoyanov
 *  
 *  Ultrasonic library: https://github.com/AlexNoyanov/Sonar
 *  Library requred: EtherCard.h
 *  
 *  Date: August 11th 2021
 *  
 *  Version: 0.1  Mega/Nano + EtherModule + x2 Sonars Waterproof 
 *  
 *  SERVER : 192.168.0.100 для теста, а для киосков 192.168.6.100
 *  
 *  Значения в мм
 *  
 *  Новая библиотека Sonar: https://github.com/AlexNoyanov/Sonar.git
 */
// ========================================

/*
 *  Connections:
 *  
 *  ---SONAR: ----------------------
 *  
 *   TRIG - 22-26-... = (N*4+22)
 *   ECHO - 23-27-... = (N*4+22) + 1
 *   
 *   -------------------------------
 *   
 *   -----Waterproofed Sonar -------
 *   
 *   GREEN - TX 
 *   BLUE  - RX
 *   
 *  
 * 
 * 
 * SONARS        MIN     MAX
 *    1 - Coffee  3       18
 *    2 - Cups1   3       50
 *    3 - Cups2   3       50
 *(WP)4 - Water   4       35
 *(WP)5 - Dump    4       25
 *
 *
 *
 *
 */

#include <Sonar.hpp>        // My Library for HC-SR04 Ultrasonic sensor                                 
#include <EtherCard.h>      // For Ethernet Module
#include <TimedAction.h>    // For multithreading
#include "GyverFilters.h"   // Kalman filter

//0.02 0.6 0.5
GKalman testFilter(0.02, 0.6, 0.5);  // KALMAN FILTER WITH PARAMETERS

#define NUMSONARS 6         // Number of sonars
#define NUMSONARSWP 2       // WP Sonars counter
//#define DELAYTIME 30000   // Requests delay

// Array of Sonars pins:
int trigs[NUMSONARS] = {22,26,30,34,38,42};  // TRIGS
int echos[NUMSONARS] = {23,27,31,35,39,43};  // ECHOES

String token = "1";     // Arduino token access code - Secret unique code for each Mega
String id = "1";        // Arduino kiosk ID

// Variables for values:
int distances[NUMSONARS+NUMSONARSWP];   // Distances from all sonars
int distance = 0;                       // Distance to measure single
Sonar sonars[NUMSONARS];                // Sonars 

unsigned char data[4]={};
unsigned char data2[4]={};

float distanceWP = 0;
float distance2 = 0;

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

long timeDelay = 60000*5;  // Delay between requests(ms) (10 Min)
int sonarsDelay = 1000;

byte Ethernet::buffer[700];
static uint32_t timer;

//const char website[] PROGMEM = "192.168.1.156";   // Server Adress
const char website[] PROGMEM = "192.168.6.100";


//const char website[] PROGMEM = "10.1.0.43";
String path = "/sonar/insertData_test.php";        // Script Path on the server
String request = "?s1=";                           // Request for generate
String req = "?";                                  // Request for generate

// To apply KALMAN filter:
void ApplyKalmanFilter(int& value){
  value = testFilter.filtered((int)value);
}

// For WP Sonars:
void ReadSonarsWP(){
do{
     for(int i=0;i<4;i++)
     {
       data[i]=Serial1.read();
     }
  }while(Serial1.read()==0xff);

  Serial1.flush();

  if(data[0]==0xff)
    {
      int sum;
      sum=(data[0]+data[1]+data[2])&0x00FF;
      if(sum==data[3])
      {
        distanceWP=(data[1]<<8)+data[2];
        if(distanceWP>30)
          {
//           Serial.print("distance 1 =");
//           Serial.print(distance/10);
//           Serial.println("cm");
            //distanceWP = distanceWP/10;
            distances[NUMSONARS] = distanceWP/10;
          }else 
             {
               //Serial.println("Below the lower limit 1" );
             }
      }else {}//Serial.println("ERROR 1");
     }
     
     delay(50);

         do{
     for(int i=0;i<4;i++)
     {
       data2[i]=Serial2.read();
     }
  }while(Serial2.read()==0xff);

  Serial2.flush();

  if(data2[0]==0xff)
    {
      int sum2;
      sum2=(data2[0]+data2[1]+data2[2])&0x00FF;
      if(sum2==data2[3])
      {
        distance2=(data2[1]<<8)+data2[2];
        if(distance2>30)
          {
//           Serial.print("distance 2 =");
//           Serial.print(distance2/10);
//           Serial.println("cm");
          //distance2 = distance2/10;
          distances[NUMSONARS+1] = distance2/10;
          }else 
             {
               //Serial.println("Below the lower limit 2");
             }
      }else {}//Serial.println("ERROR 2");
     }

     delay(50);
} 

// Printing data from the simple sonars:
void printSonars(){
  for(int i = 0; i < NUMSONARS; i++){
      Serial.print("Sonar [");
      Serial.print (i);
      Serial.print("] = ");
      Serial.print(distances[i]);
      Serial.print("   |   ");
  }
  Serial.println(" ");
}

// Printing data for WP Sonars:
void printSonarsWP(){
  Serial.println();
           Serial.print("WP 1 =");
           //Serial.print(distanceWP/10);
           Serial.print(distances[NUMSONARS]);
           Serial.print("      | ");
           Serial.print(" WP 2 =");
           //Serial.print(distance2/10);
           Serial.print(distances[NUMSONARS+1]);
           Serial.println(" ");    
   Serial.println();   
}

void ReadSonars(){
   distance = 0;                        // Setting  distance = 0
   // Reading distance from all sonars:
   for(int i = 0; i < NUMSONARS; i++){
     sonars[i].readDistance();
    //delay(500);
    }
   //
   for(int i = 0; i < NUMSONARS; i++){
     distance = sonars[i].getDistance();

    // Applying KALMAN FILTER to sonar:
    ApplyKalmanFilter(distance);
     
     distances[i] = distance;
    }
}

//Creating threads:                       |--This Delay is FIXED! 
TimedAction WPsonarsThread = TimedAction(50,ReadSonarsWP);      // Reading WP sonars every 50ms
TimedAction printSonarsWPThread = TimedAction(sonarsDelay,printSonarsWP); // Printing WP sonars every 10s
TimedAction printSonarsThread = TimedAction(sonarsDelay ,printSonars);// For WP Sonars:
TimedAction SonarsThread = TimedAction(sonarsDelay,ReadSonars); // Printing WP 

// called when the client request is complete
static void my_callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

void setup() {
  // put your setup code here, to run once:

  // Setting up all sonars:
  Serial.begin(9600);
  Serial1.begin(9600);  // WP Sonar 1
  Serial2.begin(9600);  // WP Sonar 2
  // Creating sensors:
  for(int i = 0; i < NUMSONARS; i++){
      sonars[i].setPin(trigs[i],echos[i]);

    // Setting values to mm:
    sonars[i].setMM(1);
      
    Serial.print("Created SONAR  with Trig = ");
    Serial.print(trigs[i]);
    Serial.print("  Echo = ");
    Serial.print(echos[i]);
    Serial.print(" Is mm = ");
    Serial.println(sonars[i].isMM());
  }
  Serial.println(NUMSONARS);
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

  
  //char websiteIP[] = "192.168.1.156";
  //char websiteIP[] = "10.1.0.35";
  char websiteIP[] = "192.168.6.100";         // SERVER IP ADRESS HERE 
  
  //char websiteIP[] = "10.1.0.43";                 
  
  ether.parseIp(ether.hisip, websiteIP);
  ether.printIp("SRV: ", ether.hisip);
  ether.hisport = 8099;
  //ether.printIp("PORT: ", ether.hisport);
  
}

void loop() {
  // put your main code here, to run repeatedly:

   // Checking threads:
   // WPsonarsThread.check();      // Measure WP sonars
   // Checking threads:
   WPsonarsThread.check();         // Measure WP sonars
   SonarsThread.check();           // Measure simple sonars
       
   //printSonarsThread.check();    // Printing 
   //printSonarsWPThread.check();  // Checking threads:
   //Serial.print("WP1 = ");
   //Serial.println(distances[NUMSONARS]);

   // Getting packets from ETHER module:
  ether.packetLoop(ether.packetReceive());

  if (millis() > timer) {
    timer = millis() + timeDelay;

    // ==== All actions here: =====
    // Reading distance from all sonars:
   for(int i = 0; i < NUMSONARS; i++){
     sonars[i].readDistance();
    //delay(500);
    }
   //
   for(int i = 0; i < NUMSONARS; i++){
     distance = sonars[i].getDistance();
     distances[i] = distance;
    }

    // Generating request as answer:
    // Making request:
    //request = "?s1=";
    req = "?";
    Serial.println();
    Serial.print("<<< REQ ");
  // Creating requests for sonars:
    for(int j = 0; j < NUMSONARS+NUMSONARSWP;j++){
      //request += String(maxLevels[0]-distances[0]);
      //request += "&s2=";
      if(j == 0){
        req+="s1=";
        //percent = (maxLevels[j]-distances[j])/maxLevels[j];
        req+=String(distances[j]);
      }else{
        req+="&s";
        req+=String(j+1);
        req+="=";

    // If waterproofed:
    if(j > NUMSONARS-3){
      // NUMBER OF CHECKS TOTAL MUST BE %2=0
        WPsonarsThread.check();   // Measure WP sonars
        WPsonarsThread.check();   // Measure WP sonars
        WPsonarsThread.check();   // Measure WP sonars
        WPsonarsThread.check();   // Measure WP sonars

        //ReadSonarsWP(); 
        //printSonarsWP();
    } 
        //percent = (maxLevels[j]-distances[j])/maxLevels[j];
        //percent = distance[j] ;//map(distances[j], minLevels[j], maxLevels[j], 0, 100);
        req+=String(distances[j]);    // SAVING DISTANCE INSTEAD OF %
        //req+=String(maxLevels[j]-distances[j]);
      }
    }    
        // Adding token for access:
        req+= "&k=";
        req+= token;

        req+="&i=";
        req+= id;

    // Sending generated request:
     Serial.println(req.c_str());
    // Preparing request String to string 
    const char buf[128];
    memset(buf, 0, 128);
    strcpy(buf, req.c_str());
    
    //ether.browseUrl(PSTR("/textInsertPercent.php"), buf, website, my_callback);

     ether.browseUrl(PSTR("/textInsertPercent.php"), buf, website, my_callback);
     
    Serial.println(" ");
    Serial.print("DELAY BETWEEN REQUESTS = ");

    //Serial.print(timeDelay/3600000);
    Serial.print(timeDelay);
    //Serial.println(" HOUR(s)");9
    Serial.println(" (ms)");

   //Serial.print
   //Serial.println(" ");
   //printSonarsWP();
  } 
   //printSonarsThread.check();    // Printing 
   //printSonarsWPThread.check();  
    
}
