// OLED Cannon Game
// By Alex Noyanov
// 27 08 2016

// mail: alex.noyanov@gmail.com

// Just connect OLED display to SDA and SCL pins
// Potensiometer to the A0 and Button to 13 pin

// OLED Functions:
#include <OzOLED.h>   // OLED Library with numbers
#include <OLED_I2C.h> // OLED Library with main functions

OLED  myOLED(SDA, SCL, 8);  // Display pins

extern uint8_t MediumNumbers[]; // Medium numbers set
// Constants:
const int potPin = A0;      // Potensiometer Analog Pin
const int buttonPin = 9;   // Button connection pin
const int xMax = 128;       // Maximum X-coordinate
const int yMax = 64;        // Maximum Y-coordinate
const int canHigh = 6;      // Cannon armor high
const int canLenght = 20;   // Cannon armor lenght
const int bombRad = 2;      // Bomb radius
// Integers:
    int  pot = 0;           // Potenciometer value
    int x0=19;               // Cannon coordinate X
    int y0=52;              // Cannon coordinate Y
    int R=10;               // Cannon lenght
    int potAngle;           // Potenciometer angle
    int x2, y2, xprev=x0, yprev=y0; // Line integers
    int t;                  // Time for moving bomb
    int buttonValue =0;  // Button value
    bool fire=false;
    double pulya_x, pulya_y;
    const double v = 1.0;
    double vx = v;
    double vy = v;
    double g = 0.01;
//  Functions:
void angle(double ADeg, double R, int& x2, int& y2) // Mathematical function for converting degrees to the radians
{
      double ARad = (ADeg)*M_PI/180.0;
      x2 = x0 + R*sin(ARad);
      y2 = y0 - R*cos(ARad);
}

void initPulya()
{
    double ARad = (90-potAngle)*M_PI/180.0;
    pulya_x = xprev;
    pulya_y = yprev;
    vx = v*cos(ARad);
    vy = v*sin(ARad);
}

void movePulya() // Mathematical function for converting degrees to the radians
{
      double ARad = (potAngle)*M_PI/180.0;
      double pulya_x2 = pulya_x + vx;
      double pulya_y2 = pulya_y - vy;
      vy -= g;
      myOLED.clrCircle(pulya_x, pulya_y, 2);
      pulya_x = pulya_x2;
      pulya_y = pulya_y2;
      myOLED.drawCircle(pulya_x, pulya_y, 2);
}

// Game Objects:
void drawCannon(int t0)
{
  myOLED.drawRoundRect(t0-1,yMax-1,t0+canLenght-1,yMax-canHigh);
  myOLED.drawRoundRect(t0+5,50,t0+14,55);
  myOLED.drawCircle(t0,60,3);
  myOLED.drawCircle(t0+17,60,4);
  myOLED.drawCircle(t0+6,60,1);
  myOLED.drawCircle(t0+10,60,1);
  x0 = t0+16;
}

void drawBomb(int x,int y){
  myOLED.drawCircle(x,y,bombRad);
}
void drawHouse(int x,int y){
  myOLED.drawRect(x-10,y-10,x,y);
    myOLED.drawRoundRect(x-5,y-5,x-3,y-3);
}

void setup() {
  //analogWrite(A2,1023);
  Serial.begin(9600);// Serial port speed (for testing)
  myOLED.begin();   // Setup OLED
  myOLED.clrScr();  // Clear screen
  pinMode(buttonPin,INPUT); // Set button pin as INPUT
  drawHouse(90,60);          // Draw Block
  drawHouse(90,50);          // Draw Block
  drawHouse(100,60);          // Draw Block
  drawCannon(3);
}

void loop() 
{
 pot = analogRead(potPin); // Read Potensiometer value

 
 buttonValue = digitalRead(buttonPin);  // Read from button
 //delay(100);
 if(fire) {
    movePulya();
    if((pulya_x > 132) || (pulya_y > 70))
      fire = false;
 } else {
  Serial.print("Button=");   // Serial print value (for testing)
  Serial.println(buttonValue);
  if(buttonValue == 0) {
    fire = true;
    initPulya();
  }
   potAngle =  map(pot,0,1023,0,90);
 //Serial.print("Angle=");
 //Serial.println(potAngle);
   angle(potAngle, R, x2, y2);
   myOLED.clrLine(x0,y0, xprev,yprev);
   myOLED.drawLine(x0,y0, x2,y2);
      xprev = x2;
      yprev = y2;
 }
 myOLED.update();
/* // === TESTING ===

    for(int i = 0; i < 90; i++) {
      //myOLED.clrScr();  // Clear screen
      angle(i, R, x2, y2);
      //angle(i, 0, x3, y3);
      myOLED.clrLine(x0,y0, xprev,yprev);
      myOLED.drawLine(x0,y0, x2,y2);

      myOLED.update();
      //delay(100);
    }
      myOLED.clrScr();  // Clear screen
 //     ====
 */
 
}
