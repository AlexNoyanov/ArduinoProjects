//  =======================
//  Arduino Watering System
//    on Mega 2560
//    IP:192, 168, 1, 93
//  =======================

//  Libraries:
#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>

//  Initializing:
LiquidCrystal lcd(9, 8, 7, 5, 4, 3, 2); //подключаем экран на разъемы
IPAddress ip(192, 168, 1, 93); // IP address, may need to change depending on network
EthernetServer server(80);  // create a server at port 80

 // Setup LCD print:
 void lcdStp(){
  lcd.setCursor(0,0);   
  lcd.print("Watering System"); 
 // lcd.setCursor(1,1);   
   //lcd.print("21 November 2015");
   delay(2000); 
 }
// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
#include "DHT.h" // библиотека датчика температуры и влажности
#define DHTPIN 6   //присваиваем датчику 6 пин
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
// Pins and other:
const int buz = 23;
const int hpin1 = A0; //влажность земли 1 цветка
const int hpin2 = A1;   // влажность земли 2 цветка
const int light = A3;
const int REQUEST_SIZE = 50;
char request[REQUEST_SIZE];
//  =====POMP=====
const int pompPin = 22;
bool pomp_manual_mode=false;
bool is_pomp_working=false;
int  pomp_working_time=0;
int  pomp_stop_time=0;
void pompInit();
void pompIncreaseTime();
bool pompIsWorking();
void pompStart();
void pompStop();
int  pompWorkingTime();
bool pompIsManualMode();
void pompSetManualMode(bool mode);
void pompAuto(int hum1, int hum2);

//  Beep Function:
 void Beep(){
  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,1000);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
 }

//  Pomp on sound:
 void Pbeep(){
  tone(buz,2000);
  delay(200);
  noTone(buz);
  delay(100);

  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);
 }

 void Off_beep(){
  tone(buz,500);
  delay(200);
  noTone(buz);
  delay(100);

tone(buz,2000);
  delay(100);
  noTone(buz);
  delay(100);

 }
const int PotenciometerPin = hpin1;
//const int LEDPin = 10;
int connection_count=0;
char connection_count_buffer[10];

void setup() {
  // put your setup code here, to run once:
  //  ====== Setup Function ======
  Beep();
  lcdStp();
 Serial.begin(9600); 
  dht.begin();
   Ethernet.begin(mac, ip);  // initialize Ethernet device
    server.begin();           // start to listen for clients
  //  pinMode(LEDPin, OUTPUT);
    lcd.begin(16,2); 
    lcd.clear(); 
  pompInit();
  //request = (char*)malloc(REQUEST_SIZE);
}

void loop() 
{   
int hum1 = analogRead(hpin1);
int hum2 = analogRead(hpin2);
float h = dht.readHumidity();
  float t = dht.readTemperature();
  int hh = h;
  int tt = t;
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    lcd.setCursor(0,0);   
    lcd.print("H:"); 
    lcd.print(hh);
    lcd.print("%");
    lcd.setCursor(11,0);
    lcd.print("T:"); 
    lcd.print(tt);
    lcd.print("C");
    lcd. setCursor(0,1);
    lcd.print("Hd1:");
    lcd.print(hum1);
    //lcd. setCursor(5,1);
    lcd. setCursor(9,1);
    
    lcd.print("Hd2:");
    
    lcd.print(hum2);
     
    pompLCDStatus();

  }
   
  pompIncreaseTime();
  if(pompWorkingTime() > 100) {
         pompStop();
  } 
  if(!pompIsManualMode()) {
       pompAuto(hum1, hum2);
  }
 //           ======ETHERNET CODE PART=======
EthernetClient client = server.available();  // try to get client
if (client) {  // got client?
        memset(request, 0, REQUEST_SIZE);
        boolean currentLineIsBlank = true;
        int is=0;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                if(is < REQUEST_SIZE-1)
                   request[is++] = c;
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) 
                {
                  //  digitalWrite(LEDPin, HIGH);
                 //   int power = analogRead(A0);
             //       float voltage = float(power)*5.0f/1024.0f;
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html lang=\"ru-RU\">");
                    client.println("<head>");
                    client.println("<title>Arduino Watering System</title>");
                    client.println("</head>");
                    client.println("<body bgcolor=\"#aceg12\">");
                    //client.println("<META http-equiv=\"content-type\" content=\"text/html; charset=windows-1251\">");
                    client.println("<h1><h2><font color=\"bright blue\">Automatic Watering System</h1>");
                  client.print("</font></h2></p>");
                  
                   // client.println("<p>A web page from the Arduino server</p>");
                   // client.println("<p>This server Noyanov's flower watering system</p>");
                    client.println("<p>This server is designed and controled by Alexander Noyanov</p>");
                    client.println("<p></p>");
                    client.print("<p><h2><font color=\"#0000cd \">Flower #1 = ");
                    client.print(hum1);
                    client.print("</font></h2></p>");
                    client.print("<p><h2><font color=\"#0000cd\">Flower #2 = <b>");
                    client.print(hum2);
                    client.print("</b></font></h2></p>");
                    client.print("<p><h2><font color=\"#0000cd\">Flower (#1+#2)/2 = <b>");
                    client.print((hum1+hum2)/2);
                    client.print("</b></font></h2></p>");
                    client.print("<h2><p><font color=\"blue\">Temperature = <b>");
                    client.print(t); 
                    client.print("C</b></p></font></h2>");
                    client.print("<p><h2><font color=\"blue\">Humidity = <b><i>");
                    client.print(h); 
                    client.print("%</b></i></font></h2></p>");
                    
                    client.print("<p></p><p></p>");
//                    client.print("<button id=\"pompAuto\" type=\"button\" onclick=\"turnAutoPOMP()\">Set POMP Auto</button>");
//                    client.print("<script>");
//                    client.print("function turnAutoPOMP() {");
//                    client.print("    document.getElementById(\"pompAuto\").style.color = \"red\";");
//                    client.print("}");
//                    client.print("</script>");


                     client.print("<button onclick=\"window.location.href='/pompauto'\">POMP Auto Mode</button>");
                   client.print("<button onclick=\"window.location.href='/pompon'\">Turn ON POMP</button>");
                    client.print("<button onclick=\"window.location.href='/pompoff'\">Turn OFF POMP</button>");

//                    client.print("<button id=\"pompOn\" type=\"button\" onclick=\"turnOnPOMP()\">Turn ON POMP</button>");
//                    client.print("<script>");
//                    client.print("function turnOnPOMP() {");
//                    client.print("    document.getElementById(\"pompOn\").style.color = \"red\";");
//                    client.print("}");
//                    client.print("</script>");
//                    client.print("<button id=\"pompOff\" type=\"button\" onclick=\"turnOffPOMP()\">Turn OFF POMP</button>");
//                    client.print("<script>");
//                    client.print("function turnOffPOMP() {");
//                    client.print("    document.getElementById(\"pompOff\").style.color = \"red\";");
//                    client.print("}");
//                    client.print("</script>");
                    
                    
                    if(strstr(request, "pompauto") != NULL)
                    {
                      pompSetManualMode(false);
                      pompLCDStatus();                      
                    } else if(strstr(request, "pompon") != NULL)
                    {
                      client.println("<p><h2><font color=\"red\">POMP IS TURNING ON...</font></h2></p>");                    
                      pompSetManualMode(true);
                      pompStart();
                    }
                    else if(strstr(request, "pompoff") != NULL)
                    {
                      client.println("<p><h2><font color=\"bright green\">POMP IS TURNING OFF...</font></h2></p>");                    
                      pompSetManualMode(true);
                      pompStop();
                    } else {
                      if(pompIsWorking())
                      {
                        client.println("<p><h3>POMP is working for ");
                        client.print(pompWorkingTime());
                        client.println(" sec. </h3></p>");                    
                      } else {
                        client.println("<p><h3>POMP is off. </h3></p>");
                      }
                    }
                    client.print("<p><h3>POMP is in ");
                    if(pompIsManualMode()) {
                      client.print("<font color=\"red\"> MANUAL </font> mode");
                    } else {
                      client.print("<font color=\"green\"> AUTO </font> mode");
                      client.println("</h3></p>");
                    }
                    
                    
                    
//                    client.print("<p>Your are ");
//                    connection_count++;
//                    if(connection_count == 1)
//                      client.print("first");
//                    else if(connection_count == 2)
//                      client.print("second");
//                    else if(connection_count == 3)
//                      client.print("third");
//                    else {
//                      client.print(connection_count);
//                      client.print("-th");
//                    }
//                    client.println(" visitor of the server!</p>");

                    //client.println("<p>Client request=");
                    //client.println(request);
                    //client.println("</p>");
                    
                    
                    client.println("</body>");
                    client.println("</html>");
                   // digitalWrite(LEDPin, LOW);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
            else { // no data available
                //digitalWrite(LEDPin, LOW);
            }
        } // end while (client.connected())
        //delete[] s;
        delay(10);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
//       ========== END ==========
}
//  ------  FUNCTIONS -------
void pompInit()
{
  pomp_manual_mode = false;
  is_pomp_working = false;
  pomp_working_time = 0;
  pomp_stop_time = 0;
  pinMode(pompPin,OUTPUT);
}

bool pompIsWorking()
{
  return is_pomp_working;
}

void pompStart()
{ 
  Pbeep();
  is_pomp_working = true;
  pomp_stop_time = 0;
  digitalWrite(pompPin,HIGH);
  pompLCDStatus();
}
void pompStop()
{
  is_pomp_working = false;
  pomp_working_time = 0;
  digitalWrite(pompPin,LOW);
  Off_beep();
  pompLCDStatus();
}
void pompLCDStatus()
{
  lcd.setCursor(6,0);   
  if(pomp_manual_mode)
    lcd.print("M"); 
  else
    lcd.print("A"); 
  lcd.setCursor(7,0); 
  if(is_pomp_working)
     lcd.print("ON");
  else  
     lcd.print("OFF"); 
}

int pompWorkingTime()
{
  if(is_pomp_working)
    return pomp_working_time;
  else
    return 0;
}

void pompIncreaseTime()
{
  if(is_pomp_working)
     pomp_working_time += 1;
  else
       pomp_stop_time += 1;
}
bool pompIsManualMode()
{
  return pomp_manual_mode;
}
void pompSetManualMode(bool mode)
{
  pomp_manual_mode = mode;
}
void pompAuto(int hum1, int hum2)
{
  int midhum = (hum1+hum2)/2;
   if(pompIsWorking() && midhum < 500)
   {
     pompStop();
   } 
   if ( !pompIsWorking() && (midhum > 800) || (hum2 > 800) )
   {
      if(pomp_stop_time > 100)
          pompStart();
   } 
}

