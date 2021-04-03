// ==== KEYPAD FREQUENCY GENERATOR ====

// FREQUENCY PIN: 3
// PRESS UP-DOWN BUTTONS TO CHANGE FREQUENCY

// Created by Alexander Noyanov 
// 17.05.2018

//Sample using LiquidCrystal library
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

float delayTime;
int frequency;  // Generating frequency
int freqPin = 2;       // Frequency generating pin
bool flag = false;     // Flag to detect when button pressed and unpressed
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 /*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
*/
 // For V1.0 comment the other threshold and use the one below:

 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   

 return btnNONE;  // when all others fail, return this...
}

// Generating frequency on selected pin:
void generateFrequency(int delayTime, int pin)
{
 digitalWrite(pin,HIGH);    // Turn this pin ON
 delay(delayTime);          // Waiting
 digitalWrite(pin,LOW);     // Turning OFF the pin
 delay(delayTime);          // Waiting again
}

void setup() {
  // put your setup code here, to run once:
 lcd.begin(16, 2);                 // start the library
 lcd.setCursor(0,0);
 lcd.print("== GENERATOR ==="); // print a simple message
 lcd.setCursor(0,1);
 lcd.print("FREQUNCY:");          // print a simple message
 lcd.setCursor(10,1);             // set cursor to print frequency
 frequency = 1000;
 lcd.print(frequency);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd_key = read_LCD_buttons();  // read the buttons
switch(lcd_key){
  case btnDOWN:
  {
    frequency--;
    lcd.setCursor(10,1);             // set cursor to print frequency
    lcd.print(frequency);
    //flag = true;
    delay(15);
    break;
  }
    case btnUP:
  {
    frequency++;
    lcd.setCursor(10,1);             // set cursor to print frequency
    lcd.print(frequency);
    //flag = true;
    delay(15);
    break;
  }
  
}
//delayTime = (1/frequency);      // Delay time from frequency
 //generateFrequency( delayTime, freqPin);
tone(freqPin,frequency);
 
}
