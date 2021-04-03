// Declaration and initialization of the input pins
int Analog_Eingang = A0; // X-axis-signal
int Digital_Eingang = 3; // Button
  
void setup ()
{
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);
       
  Serial.begin (9600); // serial output with 9600 bps
}
  
// The program reads the current values at the input pins
// and outputs them at the serial output
void loop ()
{
  float Analog;
  int Digital;
    
  // Current values will be read and converted to voltage
  Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Eingang);
    
  //... and outputted here
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  Serial.print ("Extreme value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not yet reached");
  }
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}// Declaration and initialization of the input pins

