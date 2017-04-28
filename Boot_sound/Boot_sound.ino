
// Boot sound
// Created by Alexander Noyanov
// 2015
// alex.noyanov@gmail.com

int buz = 8;  // Buzzer pin

// Original boot sound for my projects
 void BootSound(){
  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);
  
  tone(buz,1000);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,500);
  delay(100);
  noTone(buz);
  delay(100);

  tone(buz,100);
  delay(100);
  noTone(buz);
  delay(100);
 }

void setup() {
  // put your setup code here, to run once:
 BootSound();
}

void loop() {
  // put your main code here, to run repeatedly:

}
