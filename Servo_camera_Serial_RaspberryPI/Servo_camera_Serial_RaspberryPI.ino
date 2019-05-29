// Servo camera controll 
// This program get srting with x and y strings 
// from serial port and rotate servo on the following angle

// September 13 2018
// By Alexander Noyanov <alex.noyanov@gmail.com>

#include<string.h>
#include<Servo.h>

int x,y;      // X and Y angle
String s;     // Input string
String sX,sY; // Substrings with X and Y position
int servoXpin = 8;
int servoYpin = 7;

Servo servoX,servoY;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print(" === Servo X pin:");
Serial.print(servoXpin);
Serial.println(" ===");
Serial.print(" === Servo Y pin:");
Serial.print(servoYpin);
Serial.println(" ===");

servoX.attach(servoXpin);
servoY.attach(servoYpin);

servoX.write(0);
servoY.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
 // s = Serial.read();
 // Serial.println(s);
  if(Serial.available())   // Read the line from Serial
   {
//  int i = 0;
//    while(Serial.available());
//      {
//        s[i] = Serial.read();
//        i++;
//      }

    s = Serial.readString();
    
    //Serial.println(s);
      
    sX = s.substring(0,3); // Get X value
    sY = s.substring(4,7); // Get Y value

    x = atoi(sX.c_str());  // Convert string to integer
    y = atoi(sY.c_str());

    Serial.print("X:");    // Print X and Y
    Serial.print(x);
    Serial.print("  Y:");
    Serial.println(y);

    servoX.write(x);      // Move the right servo
    servoY.write(y); 
  }

  delay(100);
}
