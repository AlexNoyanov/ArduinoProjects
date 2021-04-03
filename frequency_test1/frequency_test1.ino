
// Frequency Test 
// Using Arduino board as frequency generator
// and watching signals on oscilloscope 
// Changing frequency using potenciometer

// The 8 of April
// 2017 year, Moscow

// Created by Alex Noyanov

int pinValue = 0;   // Value from potenciometer
int signalPin = 11; // Output signal pin
int frequency;      // Output friquency
int minFrequency = 100; // Minimum frequency
int maxFrequency = 1000;// Maximum frequency

// Function for reading from potenciometer:
void ReadValue(){
  pinValue = analogRead(A0);
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  // Turn on power for potenciometer:
  Serial.begin(9600);
analogWrite(A2,0);
analogWrite(A1,1024); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read value:
  ReadValue();
  frequency = map(pinValue,2,1023,minFrequency,maxFrequency);
  tone(signalPin,frequency);
  if(pinValue == 1){
    noTone(signalPin);
  }
  Serial.println(frequency); // For testing
  delay(200);
}
