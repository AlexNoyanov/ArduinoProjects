int speakerPin = 6;
char notes[] = "EDEDEbDCaceabegbCeEDEDEbDCaceabeCbaEDEDEbDCaceabegbCeEDEDEbDCaceabeCbabCDEgFEDfEDCeDCbeEeEDEDEDEDEDEDEbDCaceabegbCeEDEDEbDCaceabeCba"; 

//              E D E D E b D C a c e a b e g b C e E D|E D E b D C a c e a b e C b a E D E D E b D C|a c e a b e g b C e E D E D E b D C a c e a|b e C b a b C D E g F E D f E D C e D C|b e E e E D E D E D E D E D E D E b D C a c e a b e g b C e E D E D E b D C a c e a b e C b a
int beats[] = { 1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,3,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,6};
int tempo = 175;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'c','d','e','f','g','a','b','C', 'D', 'E', 'F', 'G', 'A', 'B', 'U'};
  int tones[] = {3822,3424,3033,2864,2551,2272,2024, 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

// play the tone corresponding to the note name
  for (int i = 0; i < sizeof(tones); i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}
void loop() {
  for (int i = 0; i < sizeof(notes); i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2); 
    if (i == sizeof(notes)-1){
      delay(1000);
    }
  }
}

