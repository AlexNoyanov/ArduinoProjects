//     Nunchack mouse programm
//     From http://www.instructables.com/files/orig/F0T/0YIK/GQ5Q49T5/F0T0YIKGQ5Q49T5.tmp
//     Testing version Alfa
//     7 November 2015


signed int xanal;
signed int yanal;
int mouse_l;
int mouse_r;

unsigned int i = 0;

#define x_t_low    190
#define x_db_low   480
#define x_ctr      123
#define x_db_hi    505
#define x_t_hi     772

#define y_t_low    222
#define y_db_low   520
#define y_ctr      133
#define y_db_hi    550
#define y_t_hi     831

void setup() {
 pinMode(8,INPUT_PULLUP);
 pinMode(7,INPUT_PULLUP);
}
  
void loop() {
  
  signed int xmove = 0;
  signed int ymove = 0;
  
  xanal=analogRead(0);
  yanal=analogRead(2);


//  linear - low speed
  if (xanal < x_db_low && xanal > x_t_low || xanal > x_db_hi && xanal < x_t_hi) {
    xmove = ((xanal / 4) - x_ctr)/18;
  }
  if (yanal < y_db_low && yanal > y_t_low || yanal > y_db_hi && xanal < x_t_hi) {
    ymove = (-1*((yanal / 4) - y_ctr))/18;
  }
//  linear - turbo
  if (xanal < x_t_low || xanal > x_t_hi) {
    xmove = ((xanal / 4) - x_ctr)/12;
  }
  if (yanal < y_t_low || yanal > y_t_hi) {
    ymove = (-1*((yanal / 4) - y_ctr))/12;  
  }
  Mouse.move(xmove,ymove);

// click and drag
  // right click
  if(digitalRead(7) == HIGH)
  { if(digitalRead(7) == LOW)
    {
    mouse_r = 1;
     } else {
    mouse_r = 0;
    }
  } else {
    mouse_r = 1;
    }  

  // left click
  if(digitalRead(8) == HIGH)
  { if(digitalRead(8) == LOW)
    {
    mouse_l = 1;
    } else {
    mouse_l = 0;
    }
  } else {
    mouse_l = 1;
    }  
    
  Mouse.set_buttons(mouse_r, 0, mouse_l);
}
