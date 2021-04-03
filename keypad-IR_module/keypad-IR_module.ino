/*
 *  ==================
 *    Keypad and IR 
 *  Connect IR on 7pin
 *    
 * 
 */

#include <IRremote.h>
#include <LiquidCrystal.h>
//  IR module pin:
int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

// LCD keypad:
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

void setup()
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("IR Read Test #1"); // print a simple message
 delay(2000);
}

void loop() {
  
  if (irrecv.decode(&results)) {
    lcd.clear();
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    lcd.setCursor(0,0);
    lcd.print(results.value,HEX);
  }
  delay(100);
}
