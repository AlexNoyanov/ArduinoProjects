
#define NOTE_Ab 207.652
#define NOTE_A  220.000
#define NOTE_As 233.082
#define NOTE_Bb NOTE_As
#define NOTE_B  246.942
#define NOTE_C  261.626
#define NOTE_Cs 277.183
#define NOTE_Db NOTE_Cs
#define NOTE_D  293.665
#define NOTE_Ds 311.127
#define NOTE_Eb NOTE_Ds
#define NOTE_E  329.628
#define NOTE_F  349.228
#define NOTE_Fs 369.994
#define NOTE_Gb NOTE_Fs
#define NOTE_G  391.995
#define NOTE_Gs 415.305

#define NOTE_REST     0.0
#define NOTE_SUSTAIN -1.0


float composition[] = {
    NOTE_D, NOTE_E, NOTE_F, NOTE_G, NOTE_A*2, NOTE_As*2,
    NOTE_Db, NOTE_As*2, NOTE_A*2, NOTE_G, NOTE_F, NOTE_E,
    NOTE_F, NOTE_REST, NOTE_A*2, NOTE_REST, NOTE_D*2, NOTE_REST,
    NOTE_G, NOTE_REST, NOTE_Cs*2, NOTE_REST, NOTE_E*2, NOTE_REST,

    NOTE_D*2, NOTE_E*2, NOTE_F*2, NOTE_G*2, NOTE_A*4, NOTE_As*4,
    NOTE_Db*2, NOTE_As*4, NOTE_A*4, NOTE_G*2, NOTE_F*2, NOTE_E*2,
};


uint8_t LIGHTSENSOR = 0;
void loop()
{

    unsigned long note = composition[i++];
    if (note == NOTE_REST)
        noTone(SPEAKER);
    else if (note == NOTE_SUSTAIN)
        ;      // Don't do anything, just let the current tone continue
    else
        tone(SPEAKER, note);
  
    // Set the frequency according to the light value read off analog pin 0.
#define MAX_SIGNAL 800
#define MAX_FREQ  5000
#define MIN_SIGNAL 380
#define MIN_FREQ    20
    int lightsensor = analogRead(LIGHTSENSOR);
    int freq = (lightsensor - MIN_SIGNAL) 
                * (float)(MAX_FREQ - MIN_FREQ) 
                / (MAX_SIGNAL - MIN_SIGNAL)
               + MIN_FREQ;
    tone(SPEAKER, freq);
}

float middle_c = 262.626;
float just[] = { 1., 9./8, 5./4, 4./3, 3./2, 5./3, 15./8 };
#define NUMNOTES (sizeof(just)/sizeof(*just))
float cur_octave = 1.;

uint8_t SPEAKER = 8;


   rand = random(0, 6);
    if (rand == 0)
        whichnote = (whichnote + 1) % NUMNOTES;
    else if (rand == 1)
        whichnote = (whichnote + 1) % NUMNOTES;
    else
        whichnote = random(0, NUMNOTES);

    float freq = middle_c * just[whichnote];

    // Change octave?
    rand = random(0, 10);
    if (rand == 1 && cur_octave <= 3) {
        cur_octave *= 2.;
    } else if (rand == 2 && cur_octave >= 1) {
        cur_octave /= 2.;
    }
    freq *= cur_octave;

void setup()
{
    pinMode(SPEAKER, OUTPUT);
    // Seed the random number generator from floating analog pin 0:
    randomSeed(analogRead(0));
}

void loop()
{
    // Random frequency between 20 and 1400 (Hz).
    unsigned long freq = random(20, 1400);
    long duration = random(5, 50);

    tone(SPEAKER, freq, duration);
    delay(random(100, 300));
}
