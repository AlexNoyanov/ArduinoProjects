
//  PING_PONG GAME FOR I2C OLED DISPLAY
//  By Alexander Noyanov
//  15 August 2016 - 17 August 2016

// Just connect Potenciometer to the A0 pin
//  and I2c OLED display to the SDA and SCL pins
// If you want music when connect buzzer to the 8 pin

// Initializing display:
#include <OLED_I2C.h> // OLED Library
#include <OzOLED.h>   // OLED Library for numbers
//#include <Wire.h>
OLED  myOLED(SDA, SCL, 8); 

extern uint8_t MediumNumbers[]; // Medium numbers
extern uint8_t SmallFont[];     // Small Font

// Integers:
int  pot = 0;            // Potenciometer value
const byte ypin = A0;    // Potenciometer connection pin
// Screen parameters:
const int xmax = 128;    // maximim display size x
const int ymax = 64;     // maximum display size y
const int maxScore = 10; // Maximum Scores
int racketY;    // Racket Y-coordinate from Potenciometer
int comp;
int playerScore = 0;    // Player Score
int compScore = 0;      // Computer Score
const byte velocity_x0 = 5; // 
const byte velocity_y0 = 5; // 
int vx = velocity_x0;   // X-axis Ball velocity
int vy = velocity_y0;   // Y-axis Bsll velocity
int ballX = xmax / 2;   // Ball X-coordinate
int ballY = ymax / 2;   // Ball Y-coordinate
int racketSpd = 0;      // Rocket Speed value
int lastRacketcoord;    // Last Racket coordinate
const byte ballSize = 5;  // Ball Radius
const byte racketx0 = 1;  // Racket X0
const byte rackety0 = 10; // Racket Y0
const byte lenght = 30;   // Racket Lenght
const byte width = 5;     // Racket Width
const byte buzPin = 8;    // Buzzer Sound Pin
const byte vxmax = 8;     // Maximum X speed
const byte vymax = 8;     // Maximum Y speed
const byte vxmin = 0;     // Minimum X speed
const byte vymin = 1;     // Minimum Y speed
const byte friqPlus=1000; // Double Friquency 
int robotY = ymax / 2 - lenght / 2;
int robotV = 1;           // Game Difficult level

// ANlab Symbol:
float y, yy = 0;
const byte a = 25;

// Sound function:
void Beep(int friq, int tme) {
  tone(buzPin, friq);
  delay(tme);
  noTone(buzPin);
  delay(tme);
}

//    === MUSIC ===
  // Winning Song:
  void MusicWin(){

   for(int fr = 500; fr<= 1000; fr=fr+100){
    Beep(fr+friqPlus,10);
      
    }
   for(int fr = 1000; fr>= 500; fr=fr-100){
    Beep(fr+friqPlus,10);
      
    }
    
    Beep(100+friqPlus,500);
    Beep(500+friqPlus,100);
    /*
    Beep(100+friqPlus,500);
    Beep(500+friqPlus,100);
    Beep(100+friqPlus,100);
    Beep(200+friqPlus,200);
    Beep(600+friqPlus,200);
    Beep(1000+friqPlus,500);
    Beep(500+friqPlus,100);
    Beep(800+friqPlus,100);
    Beep(1500+friqPlus,100);
    Beep(100+friqPlus,100);
    */
  }

  // Losing Song:
  void MusicLose(){
    for(int friq = 1000+friqPlus ; friq >= 100; ){
      friq = friq-10;
      Beep(friq,2);
    }
    Beep(800+friqPlus,100);
    Beep(1500+friqPlus,100);
  }
  //      ====
/*
  // Drawing emblem :
  void drawEmblem(){
  myOLED.clrScr();
      for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+40);
      myOLED.invPixel(i+15, (cos(yy)*a)+33);
      myOLED.update();

    }

      delay(1000);
        myOLED.drawCircle(50,45,6);
        myOLED.update();
        delay(500);
           myOLED.drawCircle(50,45,8);
           myOLED.update();

                 for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+39);
      myOLED.invPixel(i+15, (cos(yy)*a)+38);
      myOLED.invPixel(i+15, (cos(y)*a)+37);
      myOLED.invPixel(i+15, (cos(yy)*a)+36);
      //myOLED.invPixel(i+15, (cos(yy)*a)+3);
      myOLED.invPixel(i+15, (cos(y)*30)+35);
      myOLED.invPixel(i+15, (cos(yy)*a)+34);

       myOLED.update(); // This function Update screen picture
    }
     myOLED.drawCircle(50,45,7); // Circle Drawing function
     myOLED.update();
  }
*/

// Function Menu
/*
  void Menu(){
  myOLED.clrScr();
  myOLED.print("Ping-pong Game", LEFT, 48);
  myOLED.update();
  }*/

// PING-PONG Playing Field:
void Field(int scorePlayer, int scoreComp) {
  myOLED.setFont(MediumNumbers);
  if (playerScore > 9) {                      // Move
    myOLED.printNumI(scorePlayer, xmax / 2 - 30, 0); // Print Player Score left to make number
  } else {
    myOLED.printNumI(scorePlayer, xmax / 2 - 15, 0); // Print Player Score
  }
  myOLED.printNumI(scoreComp, xmax / 2 + 5, 0); // Print Computer Score
  //myOLED.drawRect(xmax/2-15,0,xmax/2+15,15); Frame for scores
  myOLED.drawLine(xmax / 2, 0, xmax / 2, ymax);
  // myOLED.update(); // Don't update screen 'cause racket becmoe drawing with delays!
}
// Ball drawing function:
void DrawBall(int x, int y) {
  myOLED.drawCircle(x, y, ballSize);
  myOLED.update();
}

// Racket Drawing :
void Racket(int y) {
  myOLED.drawRoundRect(racketx0, lenght + y , racketx0 + width, y);
  //myOLED.update();
}
// DRawing Computer Racket:
void compRacket(int y) {
  myOLED.drawRoundRect(racketx0 + 121, lenght + y , racketx0 + 126, y);
}

// Player win:
void playerWin() {
  myOLED.clrScr(); // Clear Screen
  myOLED.setFont(SmallFont);
 // myOLED.print("CONGRATULATIONS!", CENTER, 10); // Print string on the screen
  myOLED.print("YOU WIN!", CENTER, 10); // Print string on the screen  
 // myOLED.update();                      // Update screen
  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(playerScore, xmax / 2 - 30,30); // Print Player Score
  myOLED.printNumI(compScore, xmax / 2 +10,30); // Print Computer Score
  myOLED.update();
  MusicWin();
  delay(3000);                                  // Waiting 3 seconds
  for(int y = 10; y <= ymax+5; y++){            // Move all text down
  myOLED.clrScr(); // Clear Screen
  myOLED.setFont(SmallFont);
  myOLED.print("YOU WIN!", CENTER, y); // Print string on the screen  
 // myOLED.update();                      // Update screen
  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(playerScore, xmax / 2 - 30,y+20); // Print Player Score
  myOLED.printNumI(compScore, xmax / 2 +10,y+20); // Print Computer Score
  myOLED.update();
  playerScore = 0;
  compScore = 0;
  }
}

//  Computer win:
void compWin(){
  myOLED.clrScr(); // Clear Screen
  myOLED.setFont(SmallFont);
 // myOLED.print("CONGRATULATIONS!", CENTER, 10); // Print string on the screen
  myOLED.print("YOU LOSE :(", CENTER, 10); // Print string on the screen  
 // myOLED.update();                      // Update screen
  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(playerScore, xmax / 2 - 30,30); // Print Player Score
  myOLED.printNumI(compScore, xmax / 2 +10,30); // Print Computer Score
  myOLED.update();
  MusicLose();
  delay(3000);                                  // Waiting 3 seconds 
  for(int y = 10; y<= ymax+5 ;y++){             // All text moving down
  myOLED.clrScr();
  myOLED.setFont(SmallFont);  
  myOLED.print("YOU LOSE :(", CENTER, y); 
 // myOLED.update();                      // Update screen
  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(playerScore, xmax / 2 - 30,y+20); // Print Player Score
  myOLED.printNumI(compScore, xmax / 2 +10,y+20); // Print Computer Score
  myOLED.update();
  playerScore = 0;
  compScore = 0;
  }
}

void setup() {
  // OLED Power:
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
  myOLED.begin();
  myOLED.clrScr(); // Clear Screen
  //drawEmblem();  // my ANlab emblem
  //Menu(); // Menu Background setup
  //DrawBall(10,10);
 // playerWin();
}

void loop()
{
 // compWin();
  // put your main code here, to run repeatedly:
  // Set Player coordinate and find Racket speed:
  pot = analogRead(ypin); // Rading analog value from Potenciometer
  racketY = map(pot, 0, 1023, 0, ymax - lenght); // Set Potenciometer value and Racket Y coordinate:
  lastRacketcoord = racketY; // Last Racket coordinate
  delay(100); // System Delay
  // And again set pot value:
  pot = analogRead(ypin); // Read it again
  racketY = map(pot, 0, 1023, 0, ymax - lenght); // and set values with this mathematical function
  racketSpd = racketY - lastRacketcoord;   // find racket speed
  // Set POtenciometer value and Racket Y coordinate:
  racketY = map(pot, 0, 1023, 0, ymax - lenght);

  // Now you can move Potenciometer and Racket will moving:

  // Change Ball coordinate:
  ballX = ballX + vx;
  ballY = ballY + vy;

  Field(playerScore, compScore); // Drawing Game Field
  compRacket(robotY);           // Drawing Computer Racket
  Racket(racketY);              // Drawing Player Racket
  DrawBall(ballX, ballY);       // Drawing Ball

  // Move computer rocket
  if (ballY > (robotY + lenght / 2)) {        // If Ball higher when Computer Racket center
    if ((robotY + lenght) < ymax)             // And Computer Racket coordinate isn't maximum value
      robotY = robotY + robotV;               // Move Computer Racket Down
  } else if (ballY < (robotY + lenght / 2)) { // If ball down
    if (robotY > 0)                           // Racket coordinate not on the end of the screen
      robotY = robotY - robotV;               // Move Computer Racket Up
  }

  // FOR TESTING:
  /*
    Serial.print("vX=");
    Serial.println(vx);
    Serial.print("vY=");
    Serial.println(vy);
    Serial.print("Pot");
    Serial.println(pot);
    Serial.print("racketSpd=");
    Serial.println(racketSpd);
  */

  // Check Ball and Computer Racket position:

  // Check Ball and Player Racket position:
  if (ballX <= 6 && ballY >= racketY && ballY <= racketY + lenght ) { // If Ball on the Racket
    ballX = 5 + ballSize;
    vx = -vx - racketSpd;
    vy = vy + racketSpd;
  }
  // Check Ball and Computer Racket position:
  if (ballX >= 121 && ballY >= robotY && ballY <= robotY + lenght) {
    ballX = 121;
    vx = -vx - robotV;
    vy = vy + robotV;
  }

  // If Ball Stops:
  if (vx == vxmin ) vx = random(-2, 2); // Ball X-axis speed is Random  [-2;2]

  // If Ball bounce on the wall:
  if (ballX > xmax - ballSize) { // On the Right
    Beep(500, 20);          // Sound
    Beep(250, 20);          // Sound
    Beep(125, 20);          // Sound
    ballX = xmax - ballSize; // Change ball coordinate to normal
    vx = -vx;                // Change ball velocity
    playerScore++;
  }
  if (ballX <= 0 + ballSize ) { // On the Left
    Beep(500, 20);          // Sound
    Beep(250, 20);          // Sound
    Beep(125, 20);          // Sound
    ballX = 0 + ballSize;   // Change ball coordinate to normal
    vx = -vx;               // Change ball velocity
    compScore++;            // Plus 1 Score to the computer
    // ballX = ballX + vx;
  }
  // Score Counter:        
  if(compScore == maxScore){  // Computer Win
    compWin();  
    MusicLose();              // Playing Sad music
    compScore = 0;            // Player Score
    playerScore = 0;          // Computer Score
    
  }
  if(playerScore == maxScore){
    playerWin();
    MusicWin();               // Playing Music
    compScore = 0;            // Player Score
    playerScore = 0;          // Computer Score
  }
  // Ball Speed Controll:
  if (vx > vxmax)         // X-speed so big
    vx = vxmax - 1;
  if (vy > vymax)         // Y-speed so big
    vy = vymax - 1;

  if (ballY > ymax - ballSize) { // Down
    Beep(100, 20);               // Sound
    ballY = ymax - ballSize;
    vy = -vy;
    ballY = ballY + vy;
  }
  if (ballY <= 0 + ballSize) { // Up
    Beep(100, 20);             // Sound
    ballY = 0 + ballSize;
    vy = -vy;
    // ballY = ballY + vy;
  }
      myOLED.clrScr();          // Clear Screen
}
