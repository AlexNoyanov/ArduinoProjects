#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

void setup()   {                

  // initialize with the I2C addr 0x3C / mit I2C-Adresse 0x3c initialisieren
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  // random start seed / zufälligen Startwert für Random-Funtionen initialisieren
  randomSeed(analogRead(0));
}

#define DRAW_DELAY 118
#define D_NUM 47

int i;

void loop() {
  
  display.clearDisplay();
  
  // set text color / Textfarbe setzen
  display.setTextColor(WHITE);
  // set text size / Textgroesse setzen
  display.setTextSize(1);
  // set text cursor position / Textstartposition einstellen
  display.setCursor(1,0);
  // show text / Text anzeigen
  display.println("OLED - Display - Test");
  display.setCursor(14,56);
  display.println("blog.simtronyx.de");
  display.setTextSize(2);
  display.setCursor(34,15);
  display.println("Hello");
  display.setCursor(30,34);
  display.println("World!");
  display.display();
  delay(8000);
  /*
  display.clearDisplay();
  
  // invert the display / Display invertieren
  display.invertDisplay(true);
  delay(2000); 
  display.invertDisplay(false);
  delay(1000); 
  
  // draw some random pixel / zufaellige Pixel anzeigen
  for(i=0;i<380;i++){
    display.drawPixel(random(128),random(64), WHITE);
    display.display();
  }
  delay(DRAW_DELAY);
  display.clearDisplay();

  // draw some random lines / zufaellige Linien anzeigen
  for(i=0;i<D_NUM;i++){
    display.drawLine(random(128),random(64),random(128),random(64), WHITE);
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random triangles / zufaellige Dreiecke anzeigen
  for(i=0;i<D_NUM;i++){
    if(random(2))display.drawTriangle(random(128),random(64),random(128),random(64), random(128),random(64), WHITE); // normal
    else display.fillTriangle(random(128),random(64),random(128),random(64), random(128),random(64), WHITE);     // filled / ausgefuellt
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random rectangles / zufaellige Rechtecke anzeigen
  for(i=0;i<D_NUM;i++){
    int rnd=random(4);
    if(rnd==0)display.drawRect(random(88),random(44),random(40),random(20), WHITE);               // normal
    else if(rnd==1)display.fillRect(random(88),random(44),random(40),random(20), WHITE);            // filled / ausgefuellt
    else if(rnd==2)display.drawRoundRect(random(88),random(44),random(30)+10,random(15)+5,random(5), WHITE);  // normal with rounded edges / normal mit abgerundeten Ecken
    else display.fillRoundRect(random(88),random(44),random(30)+10,random(15)+5,random(5), WHITE);        // filled with rounded edges / ausgefuellt mit  mit abgerundeten Ecken
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random circles / zufaellige Kreise anzeigen
  for(i=0;i<D_NUM;i++){
    if(random(2))display.drawCircle(random(88)+20,random(44)+20,random(10), WHITE); // normal
    else display.fillCircle(random(88)+20,random(44)+20,random(10), WHITE);     // filled / ausgefuellt
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }
*/
}



