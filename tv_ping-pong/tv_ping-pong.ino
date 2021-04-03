#include <TVout.h>
//#include <fontALL.h>
 
TVout TV;
int x, y, a, c1, c2, yb1, yb2, tm, tsh, s;
float ts;
boolean paused = false;
 
void setup ()
{
  TV.begin(NTSC, 120, 96);
  TV.clear_screen();
  TV.select_font(font6x8);
  TV.println( 0, 50, "Welcome to Shimo" );
  TV.delay (5000);
  TV.clear_screen();
  x = 60;
  y = 48;
  yb1 = 48;
  yb2 = 48;
  a = 8;
  ts = 900.0;
  s = 2;
}
 
void loop ()
{
  if(!paused)
  {
    TV.draw_line(60,0,60,96,1);
    TV.select_font(font8x8);
    racketsmove();
    ballscount();
    TV.print(1,1,c1); TV.print(18,1,":"); TV.print(26,1,c2);
    tm = ts / 60;
    ts -= 0.04;
    if(ts < 0)
    {
      ts = 0;
    }
    TV.draw_rect(81,1,38,10,0,0);
    TV.print(81,1,tm); TV.print(97,1,"."); TV.print(100,1,int(ts-(tm*60)));
    ballcol();
    /*if(ts < 600)
    {
      s = 4;
    }
    if(ts < 300)
    {
      s = 6;
    }*/
    ballmove(s, a);
    TV.delay(50);
    if(digitalRead(6) == HIGH)
    {
      paused = true; 
      delay(1000);
    }
  }
  else
  {
    TV.println(40,4,"pause");
    if(digitalRead(6) == HIGH)
    {
      paused = false;
      delay(1000);
      TV.clear_screen();
    }
  }
}

void ballscount()
{
  if(x == 1)
  {
    c2++;
  }
  if(x == 119)
  {
    c1++;
  }
  if(c1 > c2 && ts == 0)
  {
    TV.println(10, 45, "Player 1 won!");
    delay(10000);
    restart();
  }
  else if(c1 < c2 && ts == 0)
  {
    TV.println(10, 45, "Player 2 won!");
    delay(10000);
    restart();
  }
  else if(c1 == c2 && ts == 0)
  {
    TV.println(10, 45, "You are equal");
    delay(10000);
    restart();
  }
}

void ballcol()
{
  if(x == 1 || x == 119 || (x == 10 && y < (yb1 + 3) && y > (yb1 - 3)) || (x == 110 && y < (yb2 + 3) && y > (yb2 - 3)))
  {
    if(a==1){a=5;}else if(a==2){a=8;}else if(a==3){a=7;}else if(a==4){a=6;}else if(a==5){a=1;}else if(a==6){a=4;}else if(a==7){a=3;}else if(a==8){a=2;}
  }
  if(x == 10 && y < (yb1 - 3) && y > (yb1 - 8))
  {
    a = 2;
  }
  if(x == 10 && y > (yb1 + 3) && y < (yb1 + 8))
  {
    a = 4;
  }
  if(x == 110 && y < (yb2 - 3) && y > (yb2 - 8))
  {
    a = 8;
  }
  if(x == 110 && y > (yb2 + 3) && y < (yb2 + 8))
  {
    a = 6;
  }
  if(y == 95 || y == 1)
  {
    if(a==1){a=5;}else if(a==2){a=4;}else if(a==3){a=7;}else if(a==4){a=2;}else if(a==5){a=1;}else if(a==6){a=8;}else if(a==7){a=3;}else if(a==8){a=6;}
  }
}

void racketsmove()
{
  TV.draw_line(10, yb1+8, 10, yb1-8, 0);
  TV.draw_line(110, yb2+8, 110, yb2-8, 0);
  if((yb1 - 8) > 1)
  {
    if(digitalRead(2) == HIGH)
    {
      yb1 -= 2;
    }
  }
  if((yb1 + 8) < 95)
  {
    if(digitalRead(3) == HIGH)
    {
      yb1 += 2;
    }
  }
  if((yb2 - 8) > 1)
  {
    if(digitalRead(4) == HIGH)
    {
      yb2 -= 2;
    }
  }
  if((yb2 + 8) < 95)
  {
    if(digitalRead(5) == HIGH)
    {
      yb2 += 2;
    }
  }
  TV.draw_line(10, yb1+8, 10, yb1-8, 1);
  TV.draw_line(110, yb2+8, 110, yb2-8, 1);
}

void ballmove(int vel, int angle)
{
  TV.set_pixel(x,y,0);
  if(angle == 1)
  {
    y -= vel;
  }
  if(angle == 3)
  {
    x += vel;
  }
  if(angle == 5)
  {
    y += vel;
  }
  if(angle == 7)
  {
    x -= vel;
  }
  if(angle == 2)
  {
    x += round(vel/2);
    y -= round(vel/2);
  }
  if(angle == 4)
  {
    x += round(vel/2);
    y += round(vel/2);
  }
  if(angle == 6)
  {
    x -= round(vel/2);
    y += round(vel/2);
  }
  if(angle == 8)
  {
    x -= round(vel/2);
    y -= round(vel/2);
  }
  TV.set_pixel(x,y,1);
}
void restart()
{
  TV.clear_screen();
  x = 60;
  y = 48;
  yb1 = 48;
  yb2 = 48;
  a = 8;
  ts = 900.0;
  c1 = 0;
  c2 = 0;
}
#include <TVout.h>
#include <fontALL.h>
 
TVout TV;
int x, y, a, c1, c2, yb1, yb2, tm, tsh, s;
float ts;
boolean paused = false;
 
void setup ( )
{
  TV.begin(NTSC, 120, 96);
  TV.clear_screen();
  TV.select_font(font6x8);
  TV.println( 0, 50, "Welcome to Shimo" );
  TV.delay (5000);
  TV.clear_screen();
  x = 60;
  y = 48;
  yb1 = 48;
  yb2 = 48;
  a = 8;
  ts = 900.0;
  s = 2;
}
 
void loop ( )
{
  if(!paused)
  {
    TV.draw_line(60,0,60,96,1);
    TV.select_font(font8x8);
    racketsmove();
    ballscount();
    TV.print(1,1,c1); TV.print(18,1,":"); TV.print(26,1,c2);
    tm = ts / 60;
    ts -= 0.04;
    if(ts < 0)
    {
      ts = 0;
    }
    TV.draw_rect(81,1,38,10,0,0);
    TV.print(81,1,tm); TV.print(97,1,"."); TV.print(100,1,int(ts-(tm*60)));
    ballcol();
    /*if(ts < 600)
    {
      s = 4;
    }
    if(ts < 300)
    {
      s = 6;
    }*/
    ballmove(s, a);
    TV.delay(50);
    if(digitalRead(6) == HIGH)
    {
      paused = true; 
      delay(1000);
    }
  }
  else
  {
    TV.println(40,4,"pause");
    if(digitalRead(6) == HIGH)
    {
      paused = false;
      delay(1000);
      TV.clear_screen();
    }
  }
}

void ballscount()
{
  if(x == 1)
  {
    c2++;
  }
  if(x == 119)
  {
    c1++;
  }
  if(c1 > c2 && ts == 0)
  {
    TV.println(10, 45, "Player 1 won!");
    delay(10000);
    restart();
  }
  else if(c1 < c2 && ts == 0)
  {
    TV.println(10, 45, "Player 2 won!");
    delay(10000);
    restart();
  }
  else if(c1 == c2 && ts == 0)
  {
    TV.println(10, 45, "You are equal");
    delay(10000);
    restart();
  }
}

void ballcol()
{
  if(x == 1 || x == 119 || (x == 10 && y < (yb1 + 3) && y > (yb1 - 3)) || (x == 110 && y < (yb2 + 3) && y > (yb2 - 3)))
  {
    if(a==1){a=5;}else if(a==2){a=8;}else if(a==3){a=7;}else if(a==4){a=6;}else if(a==5){a=1;}else if(a==6){a=4;}else if(a==7){a=3;}else if(a==8){a=2;}
  }
  if(x == 10 && y < (yb1 - 3) && y > (yb1 - 8))
  {
    a = 2;
  }
  if(x == 10 && y > (yb1 + 3) && y < (yb1 + 8))
  {
    a = 4;
  }
  if(x == 110 && y < (yb2 - 3) && y > (yb2 - 8))
  {
    a = 8;
  }
  if(x == 110 && y > (yb2 + 3) && y < (yb2 + 8))
  {
    a = 6;
  }
  if(y == 95 || y == 1)
  {
    if(a==1){a=5;}else if(a==2){a=4;}else if(a==3){a=7;}else if(a==4){a=2;}else if(a==5){a=1;}else if(a==6){a=8;}else if(a==7){a=3;}else if(a==8){a=6;}
  }
}

void racketsmove()
{
  TV.draw_line(10, yb1+8, 10, yb1-8, 0);
  TV.draw_line(110, yb2+8, 110, yb2-8, 0);
  if((yb1 - 8) > 1)
  {
    if(digitalRead(2) == HIGH)
    {
      yb1 -= 2;
    }
  }
  if((yb1 + 8) < 95)
  {
    if(digitalRead(3) == HIGH)
    {
      yb1 += 2;
    }
  }
  if((yb2 - 8) > 1)
  {
    if(digitalRead(4) == HIGH)
    {
      yb2 -= 2;
    }
  }
  if((yb2 + 8) < 95)
  {
    if(digitalRead(5) == HIGH)
    {
      yb2 += 2;
    }
  }
  TV.draw_line(10, yb1+8, 10, yb1-8, 1);
  TV.draw_line(110, yb2+8, 110, yb2-8, 1);
}

void ballmove(int vel, int angle)
{
  TV.set_pixel(x,y,0);
  if(angle == 1)
  {
    y -= vel;
  }
  if(angle == 3)
  {
    x += vel;
  }
  if(angle == 5)
  {
    y += vel;
  }
  if(angle == 7)
  {
    x -= vel;
  }
  if(angle == 2)
  {
    x += round(vel/2);
    y -= round(vel/2);
  }
  if(angle == 4)
  {
    x += round(vel/2);
    y += round(vel/2);
  }
  if(angle == 6)
  {
    x -= round(vel/2);
    y += round(vel/2);
  }
  if(angle == 8)
  {
    x -= round(vel/2);
    y -= round(vel/2);
  }
  TV.set_pixel(x,y,1);
}
void restart()
{
  TV.clear_screen();
  x = 60;
  y = 48;
  yb1 = 48;
  yb2 = 48;
  a = 8;
  ts = 900.0;
  c1 = 0;
  c2 = 0;
}

