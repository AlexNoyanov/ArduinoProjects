
//LiquidCrystal library
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
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
byte empt = 0b00000;
byte line = 0b00110;
byte up =   0b01001;
//byte 
// Symbols:
byte block[8] = {
  empt,
  empt,
  line,
  up,
  up,
  line,
  empt,
  empt,
};
byte blockL[8];
byte blockR[8];


byte empty[8] {
  //0b00000,
  //0b00000,
  //0b00000,
  //0b00000,
  //0b00000,
  //0b00000,
  //0b00000,
 // 0b00000,
};

void MoveL(int c){
  for(int i = 0;i<8;i++){
     block[i] = block [i]*2;
  }
  lcd.createChar(c,block);
}
void MoveR(int c)
{
    for(int i = 0;i<8;i++){
     block[i] = block [i]/2;
  }
  lcd.createChar(c,block);
}

void setup() {
  // put your setup code here, to run once:
 lcd.begin(16, 2);              // start the library
   // create a new character
 lcd.createChar(1, block);
 lcd.createChar(0, empty);
 for(int i = 0;i<8;i++){
     blockL[i] = block [i]/2;
     blockR[i] = block [i]*2;
  }
 lcd.createChar(2, blockL);
 lcd.createChar(3, blockR);
 
 //lcd.setCursor(0,0);
 //lcd.write(byte(1));
  lcd.clear();
}

const int delay_time  = 300;
void loop() 
{
  // put your main code here, to run repeatedly:
 for(int x = 0; x < 15; x++)
 {
   lcd.setCursor(x,0);
   lcd.write(byte(3));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(1));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(2));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(0));
 }
 for(int x = 15; x >= 0; x--)
 {
   lcd.setCursor(x,0);
   lcd.write(byte(2));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(1));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(3));
   delay(delay_time);
   lcd.setCursor(x,0);
   lcd.write(byte(0));
 }
}
