// Arduino Servo Camera moving

// Project with OpenCV face detecting 
// Camera following faces

// Created by Alex Noyanov 
// The 26th of February 

#include <Servo.h> // Library for servo

Servo servoX;    // Servo X 


int angleX;     // X angle
void setup() {
  // put your setup code here, to run once:
  servoX.attach(8); // Connetcing servo to pin 8
  Serial.begin(9600); // Start serial port on 9600 bod

  Serial.write("=== Ready to read ===");
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available() > 0){
     angleX = Serial.read();   // Read X angle
      
    Serial.print("X Angle: ");
    Serial.println(angleX);
    servoX.write(angleX);     // Rotate servo on angle
    
    delay(500);               // Wait a litle bit
  }
}
