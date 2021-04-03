int ymin = 5;
int ymax = 7;
int yval = 1;

int xmin = 8;
int xmax = 13;
int xval = 1;

//int Word[]= {6,4};
int Word[] = { 6, 4, 7, 6, 8 }; // IDRIS
//int Word[] = { 4, 1, 9, 6, 4 }; // DAVID
// int Word[] = { 5,1,2,6,0 };
int Wordsize = 5;

char letters[10][50] = {
  { "rdlu" }, 
  { "dddddduuuuuurrrdddlllrrrddduuuuuulll" },   // A 
  { "rrdrdldllrrdrdldlluuuuuuddddddrrurulullrrurulull" }, // B
  { "rrrlllddddddrrrllluuuuuu" }, // C
  { "ddddddrrururuululullrrdrdrddldldlluuuuuu" }, // D
  { "rrrllldddrrllddduuurrlluuu" }, // F
  { "rrrrllddddddrrllllrruuuuuull" }, // I
  { "dddddduuuuuurrdrdldllrrdrdduuluurulull" }, // R
  { "rrrllldddrrrdddlllrrruuullluuu" }, // S
  { "ddddddrururuuuuddddldldluuuuuu" } // V
};

void setup() 
{ 
  Serial.begin(9600);  
  for( int i=ymin; i<=ymax ; i++ ){
    pinMode(i, OUTPUT);
  }  
  for( int i=xmin; i<=xmax ; i++ ){
    pinMode(i, OUTPUT);
  }
} 
 
void setYPins(){
  PORTD = yval << 5; 
}
 
 
void setXPins(){
  int xcpy = xval;
  int xout = 0;
  int xbit;
  
  for ( int i=xmax; i >= xmin ; i-- ) {
    xout = xout << 1;
    xbit = xcpy & 1;
    xout = xout | xbit;
    xcpy = xcpy >> 1;
  }
  
  PORTB = xout >> 1;  
}

void setoutputs(){
 
  PORTD = yval << 5;
  delayMicroseconds(20);
  
  int xcpy = xval;
  int xout = 0;
  int xbit;
  
  for ( int i=xmax; i >= xmin ; i-- ) {
    xbit = xcpy & 1;
    xout = xout | xbit;
    xout = xout << 1;
    xcpy = xcpy >> 1;
  }
  
  PORTB = xout;
//  delayMicroseconds(20);  
}
 
void loop() 
{ 
  xval=1;
  yval=1;
  setXPins();
  setYPins();
  delay(1);
  
  for( int l=0; l != Wordsize; l++ ){

    for( int repeat=0; repeat != 3; repeat++ )    {
  
      char c = 255;
      int i=0;

      while( c != '\0' ){
        c = letters[Word[l]][i];
        switch( c ){
          case 'l':
          xval -= 1;
          setXPins();
          break;
        
          case 'r':
          xval += 1;
          setXPins();
          break;
        
          case 'u':
          yval -= 1;
          setYPins();
          break;
        
          case 'd':
          yval += 1;
          setYPins();
          break; 
        }
        i++;
        //setoutputs();  
        delayMicroseconds(50);
      }
    }
    xval += 5;
    setXPins();
    delay(1);
  
  }


} 
