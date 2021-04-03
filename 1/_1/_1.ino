/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

int red    = 13;
int yellow = 12;
int green  = 11;
int vremya = 1000;
int knopka = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(8, INPUT);

  pinMode(red, OUTPUT);
  digitalWrite(red, LOW);  
  pinMode(yellow, OUTPUT);
  digitalWrite(yellow, LOW);  
  pinMode(green, OUTPUT);
  digitalWrite(green, LOW);  
}

// the loop routine runs over and over again forever:
void loop() {
    knopka = digitalRead(8);
    if(knopka == HIGH)
    {
    digitalWrite(green, HIGH);  
    delay(vremya);               
    digitalWrite(green, LOW);  
    delay(300);               
    digitalWrite(green, HIGH);
    delay(300);               
    digitalWrite(green, LOW); 
    delay(300);               
    digitalWrite(green, HIGH); 
    delay(300);               
    digitalWrite(green, LOW); 
    delay(300);               
    digitalWrite(green, HIGH); 
    digitalWrite(yellow, HIGH); 
    delay(300);               
    digitalWrite(green, LOW);  
    delay(300); 
    digitalWrite(yellow, LOW); 
    delay(300);
    digitalWrite(yellow, HIGH);
    delay(300);
    digitalWrite(yellow, LOW);
    delay(300);
    digitalWrite(yellow, HIGH);
    delay(300);
    digitalWrite(yellow, LOW);
    delay(300);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);  
    delay(vremya);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(300);
    digitalWrite(yellow, LOW);
    delay(300);
    digitalWrite(yellow, HIGH);
    delay(300);
    digitalWrite(yellow, LOW);    
    delay(300);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);  
    }  
}
