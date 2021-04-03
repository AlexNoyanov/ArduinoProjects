/* 
Buzzer tutorial
*/
int buzzerPin = 2; //using digital pin 8
#define NOTE_C6 1047
#define NOTE_D6 1157
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1976
#define NOTE_C7 2093
void setup()
{

  
//nothing to set up
}
void loop(){

//tone(pin,frequency,duration)
tone(buzzerPin, NOTE_A6, 500);
delay(500);
tone(buzzerPin, NOTE_A6, 500);
delay(500);
tone(buzzerPin, NOTE_B6, 500);
delay(500);
tone(buzzerPin, 1568, 500);
delay(500);
tone(buzzerPin, NOTE_A6, 500);
delay(500);
tone(buzzerPin, NOTE_B6, 500);
delay(200);
tone(buzzerPin, NOTE_C7, 500);
delay(300);
tone(buzzerPin, NOTE_B6, 500);
delay(500);
tone(buzzerPin, 1568, 500);
delay(500);
tone(buzzerPin, NOTE_A6, 500);
delay(500);
tone(buzzerPin, NOTE_B6, 500);
delay(200);
tone(buzzerPin, NOTE_C7, 500);
delay(300);
tone(buzzerPin, NOTE_B6, 500);
delay(500);
tone(buzzerPin, NOTE_A6, 500);
delay(500);
tone(buzzerPin, 1568, 500);
delay(500);
tone(buzzerPin, NOTE_A6, 500);
delay(500);
}
