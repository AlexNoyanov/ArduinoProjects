/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 1;
int ledEllow = 2;
int raz = 0;
void beep(){
 /*for(int k = 1; k>0 ;k--){
  for (int i = 1000; i<2500;){
    tone(11,i);
    delay(100);
    noTone(11);
    i = i +100;
    }
  }
  */
  tone(11,100);
  delay(100);
  noTone(11);
  delay(100);
  
  tone(11,1000);
  delay(100);
  noTone(11);
  delay(100);
  
  tone(11,500);
  delay(100);
  noTone(11);
  delay(100);

  
}
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
 int led = 13;
int ledEllow = 12;
int raz = 0;

  pinMode(12, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
 beep();
  /*
  raz = raz +1;
  if(raz % 5 == 0)
  {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(3000);               // wait for a second
  }
  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);
  delay(300);
  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);
  */
}
