
// Arduino Security System
// By Alexander Noyanov
// 24 July 2016

// === CONNECTION SCHEME ===
/*
 *  PASSWORD IS 1937*258#
 *  LCD pin Arduino pin
 *  VSS         GND
 *  VDD         5V
 *  VO          GND(RESISTOR)
 *  RS          9
 *  RW          10
 *  E0          13
 *  D4          A5
 *  D5          A4
 *  D6          A3
 *  D7          A2
 *  A           A1
 *  K           GND
 *  
 *  11  RELAY
 *  12 BUZZER
 *  
 *  2 3 4 5 6 7 8
 *  KEYPAD
 */

//  ==== WARNING!!! 5 SYMBOL ON KEYPAD IS EQUAL TO 0 AND 0 ON KEYPAD IS 5!!
 
// include the library code:
 #include "Keypad.h"
 #include <LiquidCrystal.h>
 #define SIZE 10             // Password length
// initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(9, 10, 13, A5, A4,A3,A2);
 const byte ROWS = 4; //four rows
 const byte COLS = 3; //three columns
 char keys[ROWS][COLS] = {
{'1','2','3'},
{'*','0','#'},
{'7','8','9'},
{'4','5','6'}
};
 byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
 byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad

 Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Pins:
  const int relayPin = 11;
  const int buzPin = 12;
  const int lightPin = A1;
// Integers:
  const int n = 0;
  int i =0;
  int lght = 1; 
  int waitTime = 0;
  int flag = 0;
  
const char* password = "1937*258#0"; // Password
char keyIn [SIZE+1];

// Functions:
void Boot(int tme){
  lcd.setCursor(0,0);
  lcd.print("Arduino Security");
  lcd.setCursor(5,1);
  lcd.print("System");
   delay(tme);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("By:  Alexander");
  lcd.setCursor(0,1);
  lcd.print("     Noyanov");
   delay(tme);
   lcd.clear();
  }

  void Light(int lght){
    if(lght == 1){
      analogWrite(lightPin,1023);
    }else{
      if(lght == 0){
      analogWrite(lightPin,0);
      }
    }
  }
  
  //Sounds: 
  void Beep(int tme,int frq) // Input Time and Friqency
  {
   tone(buzPin,frq);
   delay(tme);
   noTone(buzPin);
   delay(tme);
  }

  void BeepOn(){
  tone(buzPin,100+n);
  delay(100);
  noTone(buzPin);
  delay(100);
  
  tone(buzPin,500+n);
  delay(100);
  noTone(buzPin);
  delay(100);
  
  tone(buzPin,1000+n);
  delay(100);
  noTone(buzPin);
  delay(100);

  tone(buzPin,500+n);
  delay(100);
  noTone(buzPin);
  delay(100);

  tone(buzPin,100+n);
  delay(100);
  noTone(buzPin);
  delay(100);
 }

    /*
    Beep(100,100);
    Beep(100,500);
    Beep(100,1000);
    Beep(100,500);
    Beep(100,100);
    */
// }

  
void setup()
{ 
  Light(lght);
  //Music
   BeepOn();
   Serial.begin(9600);
   pinMode (relayPin,OUTPUT); // Relay Pin
  // set up the LCD's number of columns and rows:
   lcd.begin(16, 2);
   Boot(2500);
   lcd.setCursor(0,0);
   lcd.print("INPUT PASSWORD:");
   lcd.setCursor(0,1);
   Serial.begin(9600);
}

void loop()
{   
  char key = keypad.getKey();
  i = 0;
 // Getting Password:
for(i;i < SIZE ; ){

  key = keypad.getKey();\
  Serial.println(key);
  delay(100);
  
  if (key != NO_KEY){
       flag = 1;
       Light(1);
       keyIn[i] = key;
       keyIn[i+1] = 0; 
       lcd.print("*");
       Beep(100,100);
       Serial.println(key);
       i++;
     }
        delay(1);
       if(waitTime<30001){
          waitTime++;
         }
    // LCD light control:
        if(waitTime > 30000 && flag == 0){
            lght = 0;
            Light(lght);
            Beep(100,100);
            waitTime = 0;
            flag = 1;
            }else{
           if(waitTime > 30000 && flag == 1){
             lght = 0;
             Light(lght);
             waitTime = 0;
              }
            } 
  }

//     
         if(strcmp(keyIn,password) == 0 ){ // If you password is right:
            digitalWrite(relayPin,HIGH);
            delay(1000);
            digitalWrite(relayPin,LOW);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("   DOOR OPENED");
            delay(2500);
            lcd.clear();
            lcd.print("INPUT PASSWORD:");
         
            for(int c = 0; c < SIZE;c++){
              keyIn[c] = 0;
              lcd.setCursor(0,1);
            }
          
         } else {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("WRONG PASSWORD!");
          Beep(100,2000);
          Beep(100,1500);
          Beep(100,1000);
          delay(5000);
          lcd.clear();
          Beep(100,200);
          lcd.print("INPUT PASSWORD:");
           for(int c = 0; c < SIZE;c++){
            keyIn[c] = 0;
           }
         }
         lcd.setCursor(0,1);

    
       /*

         delay(1);
       if(waitTime<30001){
          waitTime++;
         }
    // LCD light control:
        if(waitTime > 30000  && waitTime < 32000 ){
            lght = 0;
            Light(lght);
            Beep(100,100);
            waitTime = 0;
            }else{
          
            }
 */
}

