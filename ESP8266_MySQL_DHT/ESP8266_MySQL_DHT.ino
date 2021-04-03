/*
 *  ==== ESP8266 DHT Sensor Data to MySQL Database ====
 * 
 * MySQL Request: INSERT INTO room_temp_sensor(humidity,temperature,date) VALUES(38,26,'22.08.2020:01:49');
 * 
 * Example of GET method protocol HTTP:server.php?value=foo
 * 
 * 
 *  TODO:
 *  1) Get sensor data with ESP8266 to Serial for testing (DONE!)
 *  2) Get local date and time                            (DONE!)
 *  3) Get connection to MySQL database via WI-FI         (DONE!!)
 *    - Create .php script on the server                  
 *    - Understand how GET method works for HTTP protocol
 *    ...
 *  4) Save data from the sensor to database              
 *  5)
 */

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "DHT.h"
#define DHTPIN D1     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

const unsigned long SECOND = 1000;
const unsigned long HOUR = 3600*SECOND;

const char* ssid       =  "HUAWEI-E5330-E887";//"iPhone (Alex)";       // Name of the WI-FI
const char* password   = "hym0ig9q";       // Password for WI-FI
                            
int h;
int t;

//String request = "INSERT INTO room_temp_sensor(humidity,temperature,date) VALUES(";

String serverName = "https://sensors.noyanov.ru/getSensor.php";

int status = WL_IDLE_STATUS;
WiFiClient client;

// Get local date and time:

void getHumTemp(){
   h = dht.readHumidity();
   t = dht.readTemperature();
  
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Temp = "); 
    Serial.print(t);
    Serial.print(" *C\t");
    Serial.print("Hum = "); 
    Serial.print(h);
    Serial.println("%");
  }
}

// To insert data into database:
void insertToDatabase(String myServerName){
  // https://sensors.noyanov.ru/getSensor.php?temp=28&hum=31&date=27/08/2020
  String tempStr = String(t);
  String humStr = String(h);

  HTTPClient http;    //Declare object of class HTTPClient
 
  String ADCData, station, postData;

  station = "A";
 
  //Post Data
  postData = "temp=" + tempStr + "&hum=" + humStr;

  Serial.println(postData);
  
  http.begin("http://sensors.noyanov.ru/getSensor.php");                  //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  //int httpCode = http.POST(postData);   //Send the request
  int httpCode = http.POST("temp=26&hum=36");
  String payload = http.getString();    //Get the response payload
 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();                 //Close connection
  
  //delay(5000);  //Post Data at every 5 seconds
}
  


//void sendPOST(){
//  String data = "temp=25&hum=36";
//  Serial.println(data);
//  if (client.connect("www.sensors.noyanov.ru", 80)) {
//    //Serial.println("client connected");
//    client.println("POST /getSensor.php HTTP/1.1");
//    client.println("Host: sensors.noyanov.ru");
//    client.println("Connection: close");
//    client.print("Content-Length: ");
//    int thisLength = data.length();
//    //int thisLength = 26;
//    client.println(thisLength);
//    Serial.print("Content-Length: ");
//    Serial.println(thisLength);
//    client.println(data);
//  }
//
//  while (client.available()) {
//    char c = client.read();
//    Serial.write(c);
//  }
//
//  if (!client.connected()) {
//    client.stop();
//  }
//
//}

void setup() {
  Serial.begin(9600); 
  Serial.println("");
  Serial.println("==== RESTARTED ===="); 
  dht.begin();

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

}

void loop() {  

  getHumTemp();

  insertToDatabase(serverName);

 // sendPOST();
  
  delay(HOUR);
}
