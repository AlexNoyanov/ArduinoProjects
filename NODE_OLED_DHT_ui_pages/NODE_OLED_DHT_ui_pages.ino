// NodeMCU Amica Temperature and Humidity monitor
// With OLED I2C screen


// DHT sensor connection:
/*
 * 
 * 
 * 
 */

// OLED connection:
//  SCL -> D2
//  SDA -> D1

// DHT pin -> SD3
 // By Alexander Noyanov

// The 6th of June 2018

// Include the correct display library
// For a connection via I2C using Wire include


 #include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
 #include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

  // Include the UI lib
  #include "OLEDDisplayUi.h"

  // Include custom images

  #include "images.h"
  
// For DHT sensor:
#include<dht.h>
dht DHT;// For DHT sensor:

#define DHTPIN 10 // DHT sensor pin

int chk;  // dht sensor data
int temp; // temperature
int hum;  // humidity

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D3, D4);
// SH1106Wire display(0x3c, D3, D5);

OLEDDisplayUi ui     ( &display );

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  //display->setFont(ArialMT_Plain_10);
  //display->drawString(128, 0,"ov" );
}

// First page. Drawing temperature:
void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  // Read from sensor:
  int tmp = DHT.temperature;

     //Serial. print("Temp: ");
     //Serial.println(DHT.temperature);
     
  String myString = String(tmp);    // Converting 'int' in the 'string'
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0 + x, 5 + y, "Temperature"); // Arial 16 text

  display->setFont(ArialMT_Plain_24);
  display->drawString(0 + x, 30 + y,myString); //   Arial 24 text
  display->drawString(0 + x, 30 + y, "    ºC"); //  Arial 24 text
}

// Second page. Drawing humidity from the sensor:
void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Demonstrates the 3 included default sizes. The fonts come from SSD1306Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format

   Serial. print("            Hum: ");
    // Serial.println(DHT.humidity);
  int hum = DHT.humidity;

  String str = String(hum);
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(5 + x, 5 + y, "Humidity"); // Arial 16 text

  display->setFont(ArialMT_Plain_24);
  display->drawString(0 + x, 30 + y, str); //  Arial 24 text
  display->drawString(0 + x, 30 + y, "    %"); //  Arial 24 text
}

// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = { drawFrame1, drawFrame2 };

// how many frames are there?
int frameCount = 2;

// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);

  // Customize the active and inactive symbol
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);

  // You can change this to
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(BOTTOM);

  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);

  // You can change the transition that is used
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setFrameAnimation(SLIDE_LEFT);

  // Add frames
  ui.setFrames(frames, frameCount);

  // Add overlays
  ui.setOverlays(overlays, overlaysCount);

  // Initialising the UI will init the display too.
  ui.init();

  display.flipScreenVertically();


}

void loop() {
  // put your main code here, to run repeatedly:
int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.

    // Read data from the sensor:
     chk = DHT.read11(DHTPIN);
     
     // === FOR SENSOR TESTING ===
    // Serial. print("Temp: ");
    // Serial.print(DHT.temperature);
    // Serial. print("            Hum: ");
    // Serial.println(DHT.humidity);

    
    delay(remainingTimeBudget);
  }
}
