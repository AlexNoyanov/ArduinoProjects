/*
 *   scopetree.c
 *
 *    Created: Dec 10, 2011
 *  
 *  Author: John M. De Cristofaro
 *
 *  License: This code CC-BY-SA 3.0 and is unsupported.
 *     (see creativecommons.org/licenses for info)
 *
 */

/* ****************************************************************************
schematic available here:

http://www.flickr.com/photos/johngineer/6493897773/in/photostream

in case you can't see the schematic, the following circuit is on both PWM ports

         R
PWM OUT ----/\/\/\-----+------------ OUTPUT
           |
          === C
                       |
                      GND

R = 10k
C = 0.1uF   

Use of a 16Mhz xtal/ceramic resonator is strongly suggested.

**************************************************************************** */


#define F_CPU 16000000UL  // Use of a 16Mhz xtal/ceram is suggested.
        // The internal 8MHz oscillator can be used but
        // might not work as expected.


#include <avr/io.h>
#include <util/delay.h>

#define XR    OCR0A
#define YR    OCR0B

#define X_PIN   PB2
#define Y_PIN   PD5

#define X_DDR   DDRB
#define Y_DDR   DDRD

#define TRACE_DELAY 2500  // trace delay in uS. making this longer will
        // result in a straighter drawing, but slower
        // refresh rate. making it too short will result
        // in an angular blob.

#define NUM_POINTS  19  // our tree is defined by 19 x/y coord. pairs


// x coords for drawing the tree (in rough clockwise order, from bottom)
unsigned char x_points[NUM_POINTS] = {  110, 110, 50, 80, 65, 95, 80, 110, 95, 125,
          155, 140, 170, 155, 185, 170, 200, 140, 140 };

// y coords
unsigned char y_points[NUM_POINTS] = {  15, 35, 35, 85, 85, 135, 135, 185, 185, 235,
          185, 185, 135, 135, 85, 85, 35, 35, 15 };

void init()
{
  X_DDR = (1<<X_PIN);
  Y_DDR = (1<<Y_PIN);
  DDRB = 0xFF;
  DDRD = 0xFF;

  TCCR0A = (  1<<COM0A1 | 0<<COM0A0 |   // clear OC0A on compare match (hi-lo PWM)
      1<<COM0B1 | 0<<COM0B0 |   // clear OC0B on compare match (hi-lo PWM)
      1<<WGM01  | 1<<WGM00);    // set PWM lines at 0xFF

  TCCR0B = (  0<<FOC0A | 0<<FOC0B |   // no force compare match
      0<<WGM02 |      // set PWM lines at 0xFF
      0<<CS02  | 0<<CS01 |    // use system clock (no divider)
      1<<CS00 );

  TIMSK = ( 0<<OCIE0B | 0<<TOIE0 |
      0<<OCIE0A );

  TCNT0 = 0;          // clear time

  OCR0A = 0;          // clear output compare registers
  OCR0B = 0;
}


int main()
{
  unsigned char t;

  init();           // initialize
  while (1)         // endless loop
  {
    for(t = 0; t < NUM_POINTS; t++)   // run through the points in x & y
    {
      XR = x_points[t];
      YR = y_points[t];
      _delay_us(TRACE_DELAY);   // wait TRACE_DELAY microseconds
    }
  }
}

