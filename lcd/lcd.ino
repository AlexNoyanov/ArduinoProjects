#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int x = 8;
int backLight = 13;    // pin 13 will control the backlight

void setup()
{ pinMode(6,OUTPUT);
   Serial.begin(9600); 
  //.println("arduino.ru.codht.begin();
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
 
  // if you have a 4 row LCD, uncomment these lines to write to the bottom rows
  // and change the lcd.begin() statement above.
  //lcd.setCursor(0,2);         // set cursor to column 0, row 2
  //lcd.print("Row 3");
  //lcd.setCursor(0,3);         // set cursor to column 0, row 3
  //lcd.print("Row 4");
}

void loop() {
  digitalWrite(6,HIGH);
lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("npuBeT Mup!");    // change this text to whatever you like. keep it clean.
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print("3arpy3ka");
  int x = 8;
  while (x < 12) {
 lcd.setCursor(x,1);           // set cursor to column 0, row 1
  lcd.print(".");
   x = x+1;
   delay( 500);
 //if ( x > 11) {
  // x = 7;
 //}
 
  }
  
  delay(1000);
}


