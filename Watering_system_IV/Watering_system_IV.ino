//  =======================
//  Arduino Watering System
//    on Mega 2560
//    Version 3.1
//    17 January 2016
//    IP:192, 168, 1, 93
//  =======================

//  Watch how to connect pins on file "Watering_system_IV_Connection" 
//  In directory "work"

//  Libraries:
#include <SPI.h>
#include <Ethernet.h>
//#include <LiquidCrystal.h>  //Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//  Initializing:
//LiquidCrystal lcd(9, 8, 7, 5, 4, 3, 2); // Connecting LCD1602 on that pins (From last version )

IPAddress ip(192, 168, 1, 93); // IP address, may need to change depending on network
EthernetServer server(80);     // Create a server at port 80


//  For Printing on I2C LCD:
void Print(char* str){
   //char* str;
  for(int i = 0; i < strlen(str); i++) {
    lcd.print(str[i]);
   // delay(100);
  }
}


 // Setup LCD print:
 //void lcdStp(){
 // lcd.setCursor(0,0);   
  //lcd.print("Watering System"); 
  // lcd.setCursor(1,1);   
   //lcd.print("21 November 2015");
   //delay(2000); 
 //}
 
// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
#include "DHT.h"    // Library for humidity and temperature
#define DHTPIN 6    //Connect sensor on 6 pin
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

// Pins and other:
const int buz = 23;     // Buzzur pin
const int hpin1 = A0;   // 1 Flover Humidity
const int hpin2 = A1;   // 2 Flover Humidity
const int light = A3;   // Light sensor pin
const int gaspin  = A7; // Gas sensor pin
const byte minLevel = 2;// Minimum Water level on water tank

//  == Water Level ==
 const int Trig = 3;    // Uslrasonci sensor Trig pin
 const int Echo = 4;    // Ultrasonic sensor Echo pin
 unsigned int time_us=0;
 unsigned int distance_sm=0;  // Ultrasonic sensor value

  void readDistance()         // Reading distance
{
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(Trig, LOW); // Затем убираем 
  time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
  distance_sm=time_us/58; // Пересчитываем в сантиметры 
  //distance_sm;
}

const int REQUEST_SIZE = 50;
char request[REQUEST_SIZE];

//  =====POMP=====
const int pumpPin = 22; // Pomd pin
bool pump_manual_mode=false;
bool is_pump_working=false;
int  pump_working_time=0;
int  pump_stop_time=0;
void pumpInit();
void pumpIncreaseTime();
bool pumpIsWorking();
void pumpStart();
void pumpStop();
int  pumpWorkingTime();
bool pumpIsManualMode();
void pumpSetManualMode(bool mode);
void pumpAuto(int hum1, int hum2);

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
 // Pomp OFF sound
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
    pinMode(Trig,OUTPUT);
    pinMode(Echo,INPUT);
 // lcdStp();
 Serial.begin(9600); 
   dht.begin();
   Ethernet.begin(mac, ip);  // initialize Ethernet device
   server.begin();           // start to listen for clients
   lcd.init(); 
      // Print a message to the LCD.
    lcd.backlight(); 
 //  pinMode(LEDPin, OUTPUT);
    //lcd.begin(20,2);
 // Printing Setup text:
    lcd.setCursor(2,0);   
    Print("Arduino Watering");
    lcd.setCursor(5,1);   
    Print(" System");
    //delay(2000); 
    lcd.setCursor(0,2);   
    Print("IV Genereton");
    lcd.setCursor(0,3);   
    Print("By Alex Noyanov");
    delay(5000);
    lcd.clear();
//
    
  pumpInit();
  //request = (char*)malloc(REQUEST_SIZE);
}

void loop() 
{   
  // Reading from sensors:
int hum1 = analogRead(hpin1);
int hum2 = analogRead(hpin2);
float h = dht.readHumidity();
float t = dht.readTemperature();
  readDistance(); // Read water level
  distance_sm = 14-distance_sm;
  // Get Temp and Humd as integers there:
  int hh = h;
  int tt = t;
  int gas = analogRead(gaspin);
  //  In case of DHT sensor is not conected:
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
//  ==== LCD Print ====
    char str[100];
    
    sprintf(str, "Temp:%dC", tt);
    lcd.setCursor(0,0);
    Print(str); 
    
    sprintf(str, "Humd:%d%%", hh);
    lcd.setCursor(0,1);   
    Print(str); 

    sprintf(str, "Flw1:%d", hum1);
    lcd. setCursor(0,2);
    Print(str);
    if(hum1 < 1000){
      lcd.setCursor(9,2);        // Printing " " spaces for clearing last number
      lcd.print(" ");
    }
    
    sprintf(str, "Flw2:%d", hum2);
    lcd. setCursor(0,3);
    Print(str);
    if(hum2 < 1000){            // Printing " " spaces for clearing last number
      lcd.setCursor(9,3);
      lcd.print(" ");
    }
    
    sprintf(str, "Gas:%d", gas);
    lcd.setCursor(11,0);
    Print(str);
        if(gas < 100){            // Printing " " spaces for clearing last number
      lcd.setCursor(17,0);
      lcd.print(" ");
    }
    
    sprintf(str, "Water:%d", distance_sm);
    lcd.setCursor(11,1);
    Print(str);
          if(distance_sm < 10){            // Printing " " spaces for clearing last number
      lcd.setCursor(18,1);
      lcd.print(" ");
      lcd.setCursor(19,1);
      lcd.print(" ");
    }

    pumpLCDStatus();
 //     =====
  }

  // =====  FOR TESTING ======
  Serial.print("Water level = ");
  Serial.print(distance_sm);
  Serial.print("      Temp =");
  Serial.print(tt);
  Serial.print("      Humd =");
  Serial.print(hh);
  Serial.print("      Gas =");
  Serial.println(gas);
   
  pumpIncreaseTime();
  if(pumpWorkingTime() > 100) {
         pumpStop();
  } 
  if(!pumpIsManualMode()) {
       pumpAuto(hum1, hum2);
  }
 //           ======ETHERNET CODE PART=======
EthernetClient client = server.available();  // try to get client
if (client) {                                // got client?
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
                 //   digitalWrite(LEDPin, HIGH);
                 //   int power = analogRead(A0);
                 //   float voltage = float(power)*5.0f/1024.0f;
             
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
              
                    // send web page:
                    // Head:
                    client.println("<!DOCTYPE html>");
                    client.println("<html lang=\"ru-RU\">");
                    client.println("<head>");
                    client.println("<align=CENTER>");
                    client.println("<title>Arduino Watering System</title>");
                    client.println("</head>");
                    
                    // Body:
                    // Change Body color by water level:
                    /*
                    switch(distance_sm) {
                    case 0:
                       client.println("<body bgcolor=\"#ff0000\">");
                       break;
                    case 5:
                       client.println("<body bgcolor=\"#ffc33\">");
                       break;
                    case 10:
                       client.println("<body bgcolor=\"#99ff33\">");  
                       break; 
                    case 12:
                       client.println("<body bgcolor=\"#00ff7f\">");  
                       break; 
                      
                    }
                    */
                    if(distance_sm > 10){
                       client.println("<body bgcolor=\"#00ff7f\">");  
                    }
                    if(distance_sm >7 ){
                       client.println("<body bgcolor=\"#99ff33\">");  
                    }
                    if(distance_sm > 4){
                       client.println("<body bgcolor=\"#ffc33\">");
                    }
                    if(distance_sm > 1){
                       client.println("<body bgcolor=\"#ff0000\">");
                    }
                    
                    // bgcolour #aceg12
                    //client.println("<META http-equiv=\"content-type\" content=\"text/html; charset=windows-1251\">");
                    client.println("<h1><h1><font color=\"bright green\">Automatic Watering System IV</h1>");
                    client.print("</font></h1></p>");

                    if(distance_sm < 1){
                       client.println("<h1><h1><font color=\" green\"> OUT OF WATER !!!</h1>");
                       client.print("</font></h1></p>");
                    }

                    
                    if(distance_sm < 5){
                       client.println("<h1><h1><font color=\" green\"> NEED MORE WATER!</h1>");
                       client.print("</font></h1></p>");
                    }
                  
                   // client.println("<p>A web page from the Arduino server</p>");
                   // client.println("<p>This server Noyanov's flower watering system</p>");
                    client.println("<p>This server is designed and controled by Alexander Noyanov</p>");
                    //client.println("<p></p>");
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
                    client.print("%</p></h2></b></i>");
                    client.print("<h2><font color=\"blue\">Water = <b><i>");
                    client.print(distance_sm); 
                    // Check water level:
                    if(distance_sm < minLevel){
                    client.println("<h2><font color=\"red\">OUT OF WATER! </font></h2>");     // In case of out of water print message             
                    }

                    client.print("CM</b></i></font></h2></p>");
                    client.print("<h2><font color=\"blue\">Gas = <b><i>");
                    client.print(gas); 
                    
                    client.print("</b></i></font></font color></h2>");
                    
                  //  client.print("<p></p><p></p>");
//                    client.print("<button id=\"pompAuto\" type=\"button\" onclick=\"turnAutoPOMP()\">Set POMP Auto</button>");
//                    client.print("<script>");
//                    client.print("function turnAutoPOMP() {");
//                    client.print("    document.getElementById(\"pompAuto\").style.color = \"red\";");
//                    client.print("}");
//                    client.print("</script>");

                      //            ====== Buttons =======
                       client.print("<button  style=width:100x;height:75px  onclick=\"window.location.href='/refresh'\">Refresh</button>");     // Refresh button
                    client.print("<p></p>");
                    client.print("<button  style=width:100x;height:75px  onclick=\"window.location.href='/pompoff'\">Turn OFF PUMP</button>");  // Pomp OFF button
                   // client.print("<p></p>");
                    client.print("<button style=width:200x;height:150px onclick=\"window.location.href='/pompauto'\">PUMP Auto Mode</button>"); // Auto mode buton
                    
                    //client.print("<p></p>");
                    client.print("<button style=width:100x;height:75px onclick=\"window.location.href='/pompon'\">Turn ON PUMP</button>");      // Pomp ON button
                    client.println("</h2>");
                     //                   ========
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
                    
                    
                    if(strstr(request, "refresh") != NULL)    // Refreshing
                    {
                      
                    }
                    
                    if(strstr(request, "pompauto") != NULL) // If button clicked
                    {
                      pumpSetManualMode(false);
                      pumpLCDStatus();                      
                    } else if(strstr(request, "pompon") != NULL)
                    {
                      client.println("<p><h2><font color=\"red\">POMP IS TURNING ON...</font></h2></p>");                    
                      pumpSetManualMode(true);
                      pumpStart();
                    }
                    else if(strstr(request, "pompoff") != NULL)
                    {
                      client.println("<p><h2><font color=\"bright green\">POMP IS TURNING OFF...</font></h2></p>");                    
                      pumpSetManualMode(true);
                      pumpStop();
                    } else {
                      if(pumpIsWorking())
                      {
                        client.println("<p><h3>POMP is working for ");
                        client.print(pumpWorkingTime());
                        client.println(" sec. </h3></p>");                    
                      } else {
                        client.println("<p><h3>POMP is off. </h3></p>");
                      }
                    }
                    client.print("<p><h3>POMP is in ");
                    if(pumpIsManualMode()) {
                      client.print("<font color=\"red\"> MANUAL </font> mode");
                    } else {
                      client.print("<font color=\"green\"> AUTO </font> mode");
                      client.println("</h3></p>");
                    }
                    
                    
                    // ==== Print text on web page ====

                   //client.println("<p><h4>Version 4 Date: 14 April 2016</h4></p>");
                    client.println("<p><h4>Version 4.1 Date: 4 February 2017</h4></p>");
                //   client.println("</P>");
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
//  Functions:

//  Initializing pomp then setup:
void pumpInit()
{
  pump_manual_mode = false;
  is_pump_working = false;
  pump_working_time = 0;
  pump_stop_time = 0;
  pinMode(pumpPin,OUTPUT);
}
//  Bool for working pomp
bool pumpIsWorking()
{
  return is_pump_working;
}

// Turning ON pomp:
void pumpStart()
{ 
  Pbeep();
  is_pump_working = true;
  pump_stop_time = 0;
  digitalWrite(pumpPin,HIGH);
  pumpLCDStatus();
}

//  Turning OFF pomp:
void pumpStop()
{
  is_pump_working = false;
  pump_working_time = 0;
  digitalWrite(pumpPin,LOW);
  Off_beep();
  pumpLCDStatus();
}

//  Print pomp status on LCD:
void pumpLCDStatus()
{
  lcd.setCursor(11,2); 
  Print("Mode:");  
  if(pump_manual_mode){
  lcd.setCursor(16,2);
    Print("MAN "); 
}else{
    Print("AUTO");
  } 
  lcd.setCursor(11,3); 
  Print("Pump:");
  lcd.setCursor(16,3);
  if(is_pump_working)
     Print("ON ");
  else  
     Print("OFF"); 
}
//  Time for automatically turning off pomp:
int pumpWorkingTime()
{
  if(is_pump_working)
    return pump_working_time;
  else
    return 0;
}

void pumpIncreaseTime()
{
  if(is_pump_working)
     pump_working_time += 1;
  else
       pump_stop_time += 1;
}
bool pumpIsManualMode()
{
  return pump_manual_mode;
}
void pumpSetManualMode(bool mode)
{
  pump_manual_mode = mode;
}
void pumpAuto(int hum1, int hum2)
{
  int midhum = (hum1+hum2)/2;
   if(pumpIsWorking() && midhum < 500)
   {
     pumpStop();
   } 
   if ( !pumpIsWorking() && (midhum > 800) || (hum2 > 800) )
   {
      if(pump_stop_time > 100)
          pumpStart();
   } 
}
