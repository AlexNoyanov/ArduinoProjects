// PS2 Keyboard printing
// on LCD Dispaly
// By Alex Noyanov
// 1 07 2016

#include <PS2Keyboard.h>
#include <LiquidCrystal.h>
const int DataPin = 2;
const int IRQpin =  3;

int x = 0; // LCD coordinate

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

PS2Keyboard keyboard;

// Function Reading from 
// Keypad shield:
/*
int read_LCD_buttons()
{
int  adc_key_in = analogRead(A0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.0 comment the other threshold and use the one below:

 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
 return btnNONE;  // when all others fail, return this...
}
*/

void setup() {
  // Set the lcd size:
  lcd.begin(16, 2); 
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");

    lcd.setCursor(0,0);
    lcd.print("=Keyboard Test=");
}

void loop() {

  lcd.setCursor(0,1);
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
      x--;
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
      x++;
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
       //lcd.clear();
       x--;
      lcd.setCursor(x,1);
      lcd.print(" ");
      
    } else {
      
      // otherwise, just print all normal characters
      Serial.print(c);
      lcd.setCursor(x,1);
      lcd.print(c);
      x++;
    }
  }
}
