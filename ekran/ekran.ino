#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>

#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11 ,10 , 5, 4, 3, 2);
void setup() {
                    // put your setup code here, to run once:
 Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);

     lcd.clear();
      lcd.setCursor(0,0);
       lcd.print ("npuBeT Mup!");

         delay(500);


}

