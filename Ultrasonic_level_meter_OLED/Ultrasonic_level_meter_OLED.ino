/*
 *      ======================
 *      Ultrasonic level meter
 *      By Alexander Noyanov
 *      ======================
 * 
 *  TODO:
 *  o Connect and get value from Ultrasonic sensor HC-SR04
 *  o Connect OLED screen and print values on it
 *  o Drawing level bar on the screen
 *  o Send sensors data on the web with ETHERNET module/shield
 *  o
 * 
 */

// FOR OLED:
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

 int sensEchoPin = 2;
 int sensTrigPin = 3;
 

long getLevel(int echoPin,int trigPin){
  // Clears the trigPin condition
  long _duration;
  int _distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  _duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  _distance = _duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(_distance);
  Serial.println(" cm");

  return _distance;
}

void OLEDPrintLevel(int sensLevel){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print(F("DISTANCE"));
  display.setCursor(0,30);  
  display.println(sensLevel);
  display.display();
  delay(200);
}


void testdrawstyles() {
  display.clearDisplay();

//  display.setTextSize(1);             // Normal 1:1 pixel scale
//  display.setTextColor(SSD1306_WHITE);        // Draw white text
//  display.setCursor(0,0);             // Start at top-left corner
//  display.println(F("Hello, world!"));
//
//  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
//  display.println(3.141592);

  int sensDistance = 100;
  
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print(F("LEVEL"));
  display.setCursor(0,30);  
  display.println(sensDistance);

  display.display();
  delay(2000);
}


void OLEDSetup(){
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64 (C ADRESS NAME!!!!)
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensTrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(sensEchoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  OLEDSetup();
  //testdrawstyles();
}

void loop() {
  // put your main code here, to run repeatedly:
  long sens1Distance = getLevel(sensEchoPin,sensTrigPin);
  OLEDPrintLevel(sens1Distance);

}
