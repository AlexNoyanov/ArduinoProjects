// Subscribers counter monitor
// by Alexander Noyanov
// mail: alex.noyanov@gmail.com 

// Version 1.0

// TODO list:
/*  - Sound of new subscriber and sad sound for unsubsubscribed 
 *  - Monitoring not one but multiple subscribers (friends or someone)
 *  - Cool effect "Countdown": number of subscribers increasing from zero to number by the following time  
 *  - Designing 3D printed case for this project 
 *  - Design PCB for ESP8266
 */

/* Code sources:
 *  Printing numbers on LCD: http://robocraft.ru/blog/3070.html
 *  Get numbers of followers: https://www.instructables.com/id/DIY-Subscribers-Counter-for-Instagram-Instuctables/
 *  
 * */

#include <LiquidCrystal_I2C.h>    // 
#include "InstagramStats.h"     // https://github.com/witnessmenow/arduino-instagram-stats
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include "Font/Font.hpp"

//------- Replace the following! ------
char ssid[] = "MGTS_70";       // your network SSID (name)
char password[] = "M2F3B9RX";        // your network key
String userName = "alex_noyanov";    // from their instagram url https://www.instagram.com/userName/

WiFiClientSecure secureClient;
WiFiClient client;

InstagramStats instaStats(secureClient);

unsigned long api_delay = 1 * 60000; //time between api requests (1mins)
unsigned long api_due_time;

LiquidCrystal_I2C lcd(0x27,20,4);    // set the LCD address to 0x27 for a 16 chars and 2 line display

// Parts of the numbers:
byte LT[8] = 
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte LL[8] =
{


  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};
byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};
byte MB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte block[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.home();

  lcd.createChar(0,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,MB);
  lcd.createChar(7,block);

    // sets the LCD's rows and colums:
  lcd.clear();  

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.print("Connecting Wifi: ");
  lcd.setCursor(0,0);
  lcd.print("=Instagram monitor=");
  lcd.setCursor(0,2);
  lcd.print(" =By Alex Noyanov=");
  lcd.setCursor(0,3);
  lcd.print("    Version 1.0  ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("connecting to wi-fi");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("connected");
  lcd.setCursor(0,1);
  lcd.print(ip);
  delay(7000);
  lcd.clear();
}


void custom0(int x)
{ // uses segments to build the number 0
  lcd.setCursor(x,0); // set cursor to column 0, line 0 (first row)
  lcd.write(0);  // call each segment to create
  lcd.write(1);  // top half of the number
  lcd.write(2);
  lcd.setCursor(x, 1); // set cursor to colum 0, line 1 (second row)
  lcd.write(3);  // call each segment to create
  lcd.write(4);  // bottom half of the number
  lcd.write(5);
}

void custom1(int x)
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(2);
  lcd.print(" ");
  lcd.setCursor(x,1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(4);
}

void custom2(int x)
{
  lcd.setCursor(x,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}

void custom3(int x)
{
  lcd.setCursor(x,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5); 
}

void custom4(int x)
{
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(7);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}

void custom5(int x)
{
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void custom6(int x)
{
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom7(int x)
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}

void custom8(int x)
{
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom9(int x)
{
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}


void printDigits(int digits, int x){
  // utility function for digital clock display: prints preceding colon and leading 0
  switch (digits) {
  case 0:  
    custom0(x);
    break;
  case 1:  
    custom1(x);
    break;
  case 2:  
    custom2(x);
    break;
  case 3:  
    custom3(x);
    break;
  case 4:  
    custom4(x);
    break;
  case 5:  
    custom5(x);
    break;
  case 6:  
    custom6(x);
    break;
  case 7:  
    custom7(x);
    break;
  case 8:  
    custom8(x);
    break;
  case 9:  
    custom9(x);
    break;
  }
}

// Printing number of the followers on the lcd screen
void printNumberLCD(int num,int x,String nme){
   // Printing big numbers  
   printDigits(num/100,x);
   printDigits((num%100)/10,x+4);
   printDigits(num%10,x+8);
   // Printing
   lcd.setCursor(4,2);
   lcd.print("Subscribers");
   int nx = (19-nme.length())/2;    // Name in the center
   lcd.setCursor(nx,3);
   lcd.print("@");
   lcd.print(nme);
}

  void getInstagramStatsForUser(String usrName) {
   Serial.println("Getting instagram user stats for " + usrName );
   InstagramUserStats response = instaStats.getUserStats(usrName);
   Serial.println("Response:");
   Serial.print("Number of followers: ");
   Serial.println(response.followedByCount);
   uint16_t hi = response.followedByCount / 10000, // Value on left (high digits) display
           lo = response.followedByCount % 10000; // Value on right (low digits) display
           
   printNumberLCD(response.followedByCount,4,userName);  // Printing on the screen 
}

void loop() {
// Updating status every minute:
 if (millis() > api_due_time)  {
  getInstagramStatsForUser(userName);
    delay(200);
  api_due_time = millis() + api_delay;
 }

}
