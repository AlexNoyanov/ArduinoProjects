/*
 *      ==============================
 *      x3 HC-SR04 Sonars
 *      x2 Analog Liquid level sensors
 *      x1 Arduino Mega 2560
 *  
 *      By Alexander Noyanov
 *      March 12th 2021, Moscow
 *      ==============================
 * 
 */


#include <Sonar.hpp>

int trigs[3] = {22,24,26};
int echos[3] = {23,25,27}; 

long distances[3];
long distance = 0;

// Liquid level sensors:
int sensPin1 = A0;    
int sensPin2 = A2;

int sens1Value,sens2Value;

Sonar sonars[3];// = { Sonar(22,23), Sonar(24,25), Sonar(26, 27) };

#define sonarCounter sizeof(sonars)/sizeof(sonars[0])

void setup() {
  Serial.begin(9600);
  // Creating sensors:
  for(int i = 0; i < 3; i++){
      sonars[i].setPin(trigs[i],echos[i]);
    Serial.print("Created SONAR  with Trig = ");
    Serial.print(trigs[i]);
    Serial.print("  Echo = ");
    Serial.println(echos[i]);
  }
  Serial.println(sonarCounter);

//  for(int i = 0; i < 3; i++){
//    distances[i] = 0;
//  }

}

void loop() {

  // Reading from liquid level sensors:
  sens1Value = analogRead(sensPin1);
  sens2Value = analogRead(sensPin2);

  Serial.print("Level1 = ");
  Serial.print(sens1Value);

  Serial.print(" Level2 = ");
  Serial.print(sens2Value);
  Serial.print("   ");
  
  // Reading distance from all sonars:
  for(int i = 0; i < 3; i++){
    sonars[i].readDistance();
    //delay(500);
  }

  for(int i = 0; i < 3; i++){
    distance = sonars[i].getDistance();
    distances[i] = distance;
  }

  for(int i = 0; i < 3; i++){
    Serial.print("Sonar [");
    Serial.print(i);
    Serial.print("] =");
    Serial.print(sonars[i].getDistance());
    Serial.print("   ");
  }

  
  Serial.println(" ");

  delay(500);

}
