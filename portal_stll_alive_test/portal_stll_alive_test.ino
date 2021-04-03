/*
Still Alive

Plays a the song Still Alive


circuit:
* 8-ohm speaker on digital pin 8

created 21 Jan 2010
modified 14 Oct 2010
by Tom Igoe

This example code is in the public domain.

http://arduino.cc/en/Tutorial/Tone

*/
/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
//#include <"pitches.h”>
#define REST 0

double song[] = {

// First line
REST, 2.0, NOTE_G3, 0.5, NOTE_FS3, 0.5, NOTE_E3, 0.5, NOTE_E3, 0.5,
NOTE_FS3, 2.0, REST, 2.0,

REST, 1.5, NOTE_A2, 0.5,
NOTE_G3, 0.5, NOTE_FS3, 0.5, NOTE_E3, 0.5, NOTE_E3, 1.0,

NOTE_FS3, 1.5,
NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_A2, 2.5,

REST, 1.5, NOTE_A2, 0.5,

// Second line
NOTE_E3, 1.0, NOTE_FS3, 0.5, NOTE_G3, 1.5, NOTE_E3, 0.5, NOTE_CS3, 1.0,
NOTE_D3, 1.5, NOTE_E3, 1.0, NOTE_A2, 0.5, NOTE_A2, 1.0,
NOTE_FS3, 1.5, REST, 2.0,

REST, 2.0, NOTE_G3, 0.5, NOTE_FS3, 0.5, NOTE_E3, 0.5, NOTE_E3, 0.5,
NOTE_FS3, 2.0, REST, 2.0,

// Third line
REST, 1.0, REST, 0.5, NOTE_A2, 0.5, NOTE_G3, 0.5, NOTE_FS3, 0.5, NOTE_E3, 0.5, NOTE_E3, 1.5,
NOTE_FS3, 0.5, NOTE_D3, 1.5, NOTE_E3, 0.5, NOTE_A2, 2.5,
REST, 2.0,

NOTE_E3, 1.0, NOTE_FS3, 0.5, NOTE_G3, 1.5, NOTE_E3, 0.5, NOTE_CS3, 1.5,
NOTE_D3, 0.5, NOTE_E3, 1.0, NOTE_A2, 0.5, NOTE_D3, 0.5, NOTE_E3, 0.5,

// Fourth line
NOTE_F3, 0.5, NOTE_E3, 0.5, NOTE_D3, 0.5, NOTE_C3, 0.5, REST, 1.0, NOTE_A2, 0.5, NOTE_AS2, 0.5,
NOTE_C3, 1.0, NOTE_F3, 1.0, NOTE_E3, 0.5, NOTE_D3, 0.5, NOTE_D3, 0.5, NOTE_C3, 0.5,
NOTE_D3, 0.5, NOTE_C3, 0.5, NOTE_C3, 1.0, NOTE_C3, 1.0, NOTE_A2, 0.5, NOTE_AS2, 0.5,
NOTE_C3, 1.0, NOTE_F3, 1.0, NOTE_G3, 0.5, NOTE_F3, 0.5, NOTE_E3, 0.5, NOTE_D3, 0.5,
NOTE_D3, 0.5, NOTE_E3, 0.5, NOTE_F3, 1.0, NOTE_F3, 1.0, NOTE_G3, 0.5, NOTE_A3, 0.5,

// Fifth line
NOTE_AS3, 0.5, NOTE_AS3, 0.5, NOTE_A3, 1.0, NOTE_G3, 1.0, NOTE_F3, 0.5, NOTE_G3, 0.5,
NOTE_A3, 0.5, NOTE_A3, 0.5, NOTE_G3, 1.0, NOTE_F3, 1.0, NOTE_D3, 0.5, NOTE_C3, 0.5,
NOTE_D3, 0.5, NOTE_F3, 0.5, NOTE_F3, 0.5, NOTE_E3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,



// and belive me…
REST, 2.0, NOTE_A3, 0.5, NOTE_A3, 0.5, 
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,
REST, 1.5, NOTE_A3, 0.5, NOTE_A3, 0.5, NOTE_A3, 0.5, 


// science and im still…
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

REST, 1.5, NOTE_A3, 0.5, NOTE_A3, 0.5, NOTE_A3, 0.5, 
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

REST, 2.0, NOTE_A3, 0.5, NOTE_A3, 0.5, 
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

REST, 1.5, NOTE_A3, 0.5, NOTE_A3, 0.5, NOTE_A3, 0.5, 
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

REST, 1.5, NOTE_A3, 0.5, NOTE_A3, 0.5, NOTE_A3, 0.5, 
NOTE_B3, 0.5, NOTE_A3, 0.5, NOTE_FS3, 0.5, NOTE_D3, 1.0, NOTE_E3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

// still alive… still alive…
REST, 1.5, NOTE_G3, 0.5, NOTE_A3, 0.5, NOTE_A3, 1.5, 
REST, 1.5, NOTE_G3, 0.5, NOTE_FS3, 0.5, NOTE_FS3, 1.5,

// End of song
0.0, 0.0
};


void setup() {
pinMode(10 ,OUTPUT); 
digitalWrite(10, LOW);

double duration = 1;
for (int i = 0; duration > 0.0; i += 2)
{
int note = song[i];
duration = song[i + 1];

int noteDuration = (1600.0 * (duration / 4));
tone(8, note, noteDuration);

int pauseBetweenNotes = noteDuration * 1.3;
delay(pauseBetweenNotes);
noTone(8);
}
}

void loop() {
// no need to repeat the melody.
}
