/*  ARDUINO      VGA
 *  10            1
 *  9             2          
 *  8             3
 *  NC            4
 *  GND           5
 *  GND           6
 *  GND           7
 *  GND           8
 *   NC           9
 *  GND           10
 *   NC           11
 *   NC           12
 *   7            13
 *   6            14
 *   NC           15
 * 
 */



#define NOP asm("nop")
#define BLACK    PORTB = B00000000;
#define BLUE     PORTB = B00000001;
#define GREEN    PORTB = B00000010;
#define CYAN     PORTB = B00000011;
#define RED      PORTB = B00000100;
#define MAGENTA  PORTB = B00000101;
#define YELLOW   PORTB = B00000110;
#define WHITE    PORTB = B00000111;
 
unsigned int linecount = 1;
 
void setup()
{
  //Set pins 5 to 10 as outputs
  // 7 - HSYNC
  // 6 - VSYNC
  // 10, 9 e 8 - RGB  
  DDRD |= B11100000;
  DDRB |= B11100111;
  PORTD |= B11000000;
 
  //set timer  
  TCCR2A = 0x02;                        // WGM22=0 + WGM21=1 + WGM20=0 = Mode2 (CTC)
  TCCR2B |= (1 << CS20);                //
  TCCR2B |= (1 << CS21);                // Set prescaler
  TCCR2B &= ~(1 << CS22);               //
 
  TCNT2 = 0;                            // clean counter
 
  TIMSK2 &= ~(1<<OCIE2A);                // set comparison interrupt  
  TIMSK2 |= (1<<TOIE2);                // set overflow interrupt  
}
 
void loop()
{
  noInterrupts();
  do{
    BLACK;
    if (TCNT2 > 0x0f){
 
      delayMicroseconds(1);
      NOP;NOP;NOP;NOP;
     
      TCNT2 = 0x00;
 
   
                       
      // #### HSYNC ###
      PORTD &= ~(1 << 7);      
      if (++linecount >= 525){ //525 lines
        linecount = 1;
      }      
      PORTD |= (1 << 7);
 
 
 
      // ### VSYNC ###
      if ((linecount == 1)||(linecount == 2)){
        PORTD &= ~(1 << 6);      
      } else {
        PORTD |= (1 << 6);
       
 
        NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;NOP;NOP;
       
        if ((linecount >= 1) && (linecount <= 489)){
         
                WHITE;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                BLACK;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                BLUE;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                GREEN;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                CYAN;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                RED;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                MAGENTA;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                YELLOW;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                WHITE;
                delayMicroseconds(3);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
               // WHITE;
                NOP;NOP;NOP;NOP;NOP;
        }
           
      }
 
 
}
 
 
}while(1);
 
}
