// Arduino Servo Camera moving

// Project with OpenCV face detecting 
// Camera following faces

// Created by Alex Noyanov 
// The 26th of February 

#include <Servo.h> // Library for servo

Servo servoX;   // Servo X 
Servo servoY;   // Servo Y

#define SIZE 32 // Array size
char data[SIZE];  // Data array

int angleX;     // X angle
int angleY;     // Y angle

int inDec(int i){ // Function to get 10 in i degree
  int dec = 1;

  for(int k = 0; k < i;k++){
    dec = dec*10;
  }
  return dec;
}

int ReadData()
{
  int v = 0;
  int mul = 1;
  // Read all symbols 
  while(true) 
  {
      if(Serial.available()) {
        int c = Serial.read(); 
        Serial.print("c=");
        Serial.println(c);
        if(c == '\n' || c == '\r')
          break;
        int cc = c - '0';
        v = v*10 + cc;
      } else {
        delay(500);
      }
  }   
  Serial.print("v=");
  Serial.println(v);
  return v;   
}
/*
int ReadData()
{    // Read data from serial port
   int i = 0;
   int value = 0; 
   // Read all symbols in array
    for(; Serial.available() ; i++){
      data[i] =  Serial.read();   // Read X angle
     }
   int len = i;
   // Get normal numbers from symbols:
    for(int k = 0; k < len; k++) {
      i--;
      value = value + inDec(i)*(data[k]-'0');
     }
   return value;
}
*/

void setup() {
  // put your setup code here, to run once:
  servoX.attach(8); // Connetcing servo to pin 8
  Serial.begin(9600); // Start serial port on 9600 bod

  Serial.println("=== Ready to read ===");  // Print title 

  //Serial.println(inDec(4));
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available() > 0)
  {
    // Serial.print("X Angle: ");
    // Serial.println(angleX);
     Serial.println(" ");

     angleX = ReadData();

     // Print recieved data:
     Serial.print("Data: ");
     Serial.print(angleX);

     servoX.write(angleX);     // Rotate servo on angle
     
    delay(500);               // Wait a litle bit
  }
}
