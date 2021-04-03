#include "Keypad.h"

#define SIZE 4

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
int keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2};    //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const char* password = "1234"; // Password

 //password[0] = '1';
 //password[1] = '2';
 //password[2] = '3';
 //password[3] = '4';

char keyIn [SIZE+1];
void setup()
{
pinMode(13,OUTPUT);
Serial.begin(9600);
}

int prevkey = NO_KEY;
void loop()
{
  char key = keypad.getKey();
    Serial.print(key);
    delay(100);
/*    
  if(key != prevkey)
  {
    Serial.print(key);
    prevkey = key;
    if(key != NO_KEY)
     processKey(key);
  }
 */ 
}

void processKey(char key)
{
  if (key != NO_KEY)
  {
    for(int i = 0;i<SIZE;i++){
       keyIn[i] = key;
       keyIn[i+1] = 0;  
       Serial.print(key);
       if(key =='#'){
         Serial.println("");
       }
    }

    int cmp = strcmp(keyIn, password);
    if(cmp == 0)
    {
      digitalWrite(13,HIGH);
    } else {
      Serial.println("Password Incorrect!"); 
    }
  }
}

