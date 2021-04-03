int sound = 7; 
 int gerz = 0;
 int sensorValue = 0;  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
//pinMode(A1,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
/*
while (gerz<1500)
{gerz = gerz+1;
tone(sound,gerz);
delay(10);
Serial.println(gerz);
noTone(sound);
}
delay(100);
tone (sound,500);
delay(100);
noTone(sound);
*
*/

}

void loop() {
  sensorValue = analogRead(A1);   
delay(10);  
  Serial.println( sensorValue);
 int b =  digitalRead(4);
 int c =  digitalRead(5);
 if( b == HIGH)
  { tone(sound, 500);
  delay(10);
  }
  if(c == HIGH)
  {tone(sound, 1000);
  delay(10);
  }
    
  else 
  noTone(sound);
}
