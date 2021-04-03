

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };


  

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  // draw a single pixel
  display.drawPixel(10, 10, WHITE);

  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

   // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setCursor(10,32);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  /*display.print("0x");*/ display.println("CONNECTED");
  display.display();/*
  while(1){

         display.setCursor(10,32);
         display.setTextSize(2.5);
         display.setTextColor(WHITE);
         display.println("CONNECTED");
         display.display();
         delay(500);
         display.clearDisplay();
         display.display();
         delay(500);
  }
  display.clearDisplay();
  display.display();
  */
}

void loop() {
  // put your main code here, to run repeatedly:

}
