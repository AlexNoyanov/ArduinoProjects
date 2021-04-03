#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("3arpy3ka");    // change this text to whatever you like. keep it clean.
    int x = 0;
  while (x < 16) {
 lcd.setCursor(x,1);           // set cursor to column 0, row 1
  lcd.print("#");
   x = x+1;
   delay( 200);
  }
  if ( x = 16) {
   lcd.clear();                  // start with a blank screen
  lcd.setCursor(3,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("3arpy3ka");
 lcd.setCursor(3,1); 
 lcd.print("3akoH4eHa");
delay (500); 
  }
delay (1000);
}
