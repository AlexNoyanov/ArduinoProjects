// Arduino Servo Camera moving

// Project with OpenCV face detecting 
// Camera following faces

// Created by Alex Noyanov 
// The 26th of February 

#include <Servo.h> // Library for servo

Servo servoX;   // Servo X 
Servo servoY;   // Servo Y

char data[32];  // Data array

int angleX;     // X angle
int angleY;     // Y angle

void setup() {
  // put your setup code here, to run once:
  servoX.attach(8); // Connetcing servo to pin 8
  Serial.begin(9600); // Start serial port on 9600 bod

  Serial.println("=== Ready to read ===");
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available() > 0){
    
   int i = 0;

   // Read all symbols in array
     for(; Serial.available() > 0; i++){
      data[i] =  Serial.read();   // Read X angle
     }
      
    // Serial.print("X Angle: ");
    // Serial.println(angleX);
    // servoX.write(angleX);     // Rotate servo on angle
     Serial.println(" ");
     
     Serial.print("Inputed data:\n");
    delay(100);
     for(int k = 0; k < i; k++){
      Serial.println(data[k]);
     }


     
    delay(500);               // Wait a litle bit
  }
}
