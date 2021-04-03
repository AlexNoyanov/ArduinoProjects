
// screen
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);

// Joistick
const int POS_Y_PIN = 1;
const int POS_X_PIN = 0;
const int BUTTON_PIN = 7;
const int MAX_POS = 1023;   // VRx и VRy выдают значения от 0 до 1023
const int MAX_ANGLE = 180; 

// Snake
int x; // head
int y;
int dx; // movement
int dy;
const int SNAKE_BUFFER_LEGTH = 100;
int snake[SNAKE_BUFFER_LEGTH];
int snake_begin;
int snake_end;
int snake_length;
int snake_remove_tail_delay;

// Apple
boolean ap_new;
int ap_x;
int ap_y;
int ap_time;
const int MAX_AP_TIME = 40;

// Game
boolean game;

// Records
const int MAX_LEVEL = 3;
int record_length[MAX_LEVEL];

// Menu
int menu_position = 0;
int menu_level = 1;


void setup() {
  // debug
 Serial.begin(9600);
 // screen
  lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.begin(20,4);
  lcd.clear();
  // joistik
  //pinMode(BUTTON_PIN, INPUT);
  // records
  for(int i = 0; i < MAX_LEVEL; i++)
     record_length[i] = 0;
}

void init_game()
{
  // snake
  x = 0;
  y = 0;
  dx = 1;
  dy = 0;
  snake_begin = 0;
  snake_end = 1;
  snake[snake_begin] = xy2pos(0, 0);
  snake[snake_end] = xy2pos(0, 0);
  snake_length = 1;
  snake_remove_tail_delay = 0;
  // apple
  ap_new = true;
  ap_time = 0;
  // game
  game = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  //testJoystick();
  menu();
  
  lcd.clear();  
  
  if(menu_position == 0) {
    zastavka_snake();
    lcd.clear();  
    run_snake();
  }
  else if(menu_position == 1) {
    zastavka_tennis();
    lcd.clear();  
    tennis_run();
  }
}

void run_snake()
{ 
  init_game();

  while(game)
  {
    // generate new apple
    if(ap_time == 0)
    {
      lcd.setCursor(ap_x, ap_y);
      lcd.print(" ");
      do {
        ap_x = random(20);
        ap_y = random(4);
        Serial.print("Generate new apple at ");
        Serial.print(ap_x);
        Serial.print(",");
        Serial.println(ap_y);
      } while( ((ap_x == 0) && (ap_y == 0)) || isInSnake(ap_x, ap_y) );
      ap_new = false;
      ap_time = MAX_AP_TIME;
      lcd.setCursor(ap_x, ap_y);
      lcd.print("@");
    } else { // change apple char
       char apchar = aptime2apchar(ap_time);
       ap_time--;
       char apcharnew = aptime2apchar(ap_time);
       if(apcharnew != apchar)
       {
         lcd.setCursor(ap_x, ap_y);
         lcd.print(apcharnew);
       }
    }
        
    delay(getDelay());
    int yVal = analogRead(POS_Y_PIN);
    int xVal = analogRead(POS_X_PIN);
    float yAngle = 1.0 * yVal * MAX_ANGLE / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
    float xAngle = 1.0 * xVal * MAX_ANGLE / MAX_POS; // Аналогично VRx
    boolean isNotClicked = digitalRead(BUTTON_PIN);  // Считываем не было ли нажатия на джойстик
    //Serial.print("Horisontal angle = ");
    //Serial.println(xAngle);
    //Serial.print("Vertical angle = ");
    //Serial.println(yAngle);
    delay(getDelay());
    
    int newdx=0, newdy=0;
    if(xAngle < 50)
      newdx = - 1;
    else if(xAngle > 120)
      newdx = +1;
    if(newdx == 0)
    {
      if(yAngle < 50)
        newdy = +1;
      else if(yAngle > 120)
        newdy = -1;
    }
    
    if((newdx != 0) || (newdy != 0))
    {
      dx = newdx;
      dy = newdy;
    }
    
    // output legth
      lcd.setCursor(0, 0);
      lcd.print(snake_length);
    
    // clear tail
    if(snake_remove_tail_delay == 0)
    {
      int tail_pos = snake[snake_begin];
      int postaily = pos2y(tail_pos);
      int postailx = pos2x(tail_pos);
      Serial.print("snake_begin=");
      Serial.print(snake_begin);
      Serial.print(" xy=");
      Serial.print(postailx);
      Serial.print(",");
      Serial.println(postaily);
      lcd.setCursor(postailx, postaily);
      lcd.print(' ');
      snake[snake_begin] = 0;
      snake_begin++;
      if(snake_begin >= SNAKE_BUFFER_LEGTH)
        snake_begin = 0;
    } else {
      snake_remove_tail_delay--;
    }
    
    // add head to buffer
    int head_pos = xy2pos(x, y);
    snake[snake_end] = head_pos;
    snake_end++;    
    if(snake_end >= SNAKE_BUFFER_LEGTH)
      snake_end = 0;
    // replace head with body
    lcd.setCursor(x, y);
    lcd.print("o");       
    
    // move head
     x = x + dx;
     y = y + dy;    
     
    if(x < 0)
      x = 19;
    if(x >= 20)
      x = 0;
    if(y < 0)
      y = 3;
    if(y >= 4)
      y = 0; 
     
     if(isInSnake(x, y)) // Game over
     {
       break;
     }
     
     if((x == ap_x) && (y == ap_y))
     {
       //int pos = xy2pos(x, y);
       int add_length = ap_time*4/MAX_AP_TIME;
       snake_remove_tail_delay = add_length;
       snake_length += add_length;
       ap_new = true;
       ap_time = 0;
     } else {
       // clear tail
     }
     
      
    if (!isNotClicked)
    {
      Serial.println("Clicked");
      //game = false;
      //break;
    } else
    {
      
    }
    lcd.setCursor(x,y);
    char c='O';
    if(!ap_new)
    {
      if(dx > 0)
       c = '>';
      else if(dx < 0)
       c = '<';
      else if(dy > 0)
       c = 'v';
      else
       c = '^';
    } else {
      c = 'o';
    }
    lcd.print(c);
  }
  lcd.setCursor(5,0);
  lcd.print("Game Over");
  if(snake_length > record_length[menu_level])
  {
     record_length[menu_level] = snake_length;
     lcd.setCursor(5,1);
     lcd.print("New Record!!!");
     lcd.setCursor(5,2);
     lcd.print("Length=");
     lcd.print(record_length[menu_level]);
  }
  delay(10000);
}

int xy2pos(int x, int y)
{
  int pos = y*100 + x;
  return pos;
}

int pos2x(int pos)
{
  return pos - (pos / 100)*100;
}
int pos2y(int pos)
{
  return int(pos / 100);
}


boolean isInSnake(int x, int y)
{
  int p = snake_begin;
  do 
  {
    int pos = snake[p];
    int py = pos2y(pos);
    int px = pos2x(pos);
    if((px == x) && (py == y))
       return true;
    p++;
    if(p >= SNAKE_BUFFER_LEGTH)
     p = 0;
    //Serial.print("p=");
    //Serial.print(p);
    //Serial.print(" snake_end=");
    //Serial.print(snake_end);
    //Serial.print(" SNAKE_BUFFER_LEGTH=");
    //Serial.println(SNAKE_BUFFER_LEGTH);
  } while(p != snake_end);
  Serial.println("Not in snake");
  return false;
}

char aptime2apchar(int aptime)
{
  if(aptime > (MAX_AP_TIME * 4 / 5))
    return '@';
  if(aptime > (MAX_AP_TIME * 3 / 5))
    return '0';
  if(aptime > (MAX_AP_TIME * 2 / 5))
    return 'o';
  if(aptime > (MAX_AP_TIME * 1 / 5))
    return '.';
  return '.';
}


void testJoystick()
{
  while(true)
  {
    boolean isNotClicked = digitalRead(BUTTON_PIN);  // Считываем не было ли нажатия на джойстик
    if(isNotClicked)
       Serial.println("NotClicked");
    else
       Serial.println("Clicked");

    int yVal = analogRead(POS_Y_PIN);
    int xVal = analogRead(POS_X_PIN);
    float yAngle = 1.0 * yVal * MAX_ANGLE / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
    float xAngle = 1.0 * xVal * MAX_ANGLE / MAX_POS; // Аналогично VRx
    //boolean isNotClicked = digitalRead(BUTTON_PIN);  // Считываем не было ли нажатия на джойстик
    Serial.print("Horisontal angle = ");
    Serial.println(xAngle);
    Serial.print("Vertical angle = ");
    Serial.println(yAngle);
    
    delay(200);
  }
}


void zastavka_snake()
{
  char* title[6] = {
    " ## #  #  #  # # ##",
    "#   #  # # # # # #"    ,
    "#   ## # # # ##  #"    ,
    " #  # ## ### ##  ##",
    "  # # ## # # # # #"    ,
    "### #  # # # # # ##"
  };
  for(int y0 = 6; y0 >= -6; y0--)
  {
     lcd.clear();
     for(int y = 0; y < 4; y++)
     {
       lcd.setCursor(0, y);
       if(y0+y >= 0 && y0+y < 6)
       {
         lcd.print(title[y0+y]);
       }
     }
     delay(400);
  }
}

void zastavka_tennis()
{
  char* title[6] = {
    "### ## #  # ### ###",
    " #  #  ## #  #  #  "    ,
    " #  ## # ##  #   # "    ,
    " #  #  #  #  #    #",
    " #  #  #  #  #    #"    ,
    " #  ## #  # ### ## "
  };
  for(int y0 = 6; y0 >= -6; y0--)
  {
     lcd.clear();
     for(int y = 0; y < 4; y++)
     {
       lcd.setCursor(0, y);
       if(y0+y >= 0 && y0+y < 6)
       {
         lcd.print(title[y0+y]);
       }
     }
     delay(400);
  }
}

void menu()
{
  menu_position = 0;
  show_menu();
  while(true)
  {
    int yVal = analogRead(POS_Y_PIN);
    int xVal = analogRead(POS_X_PIN);
    float yAngle = 1.0 * yVal * MAX_ANGLE / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
    float xAngle = 1.0 * xVal * MAX_ANGLE / MAX_POS; // Аналогично VRx
    boolean isNotClicked = digitalRead(BUTTON_PIN);  // Считываем не было ли нажатия на джойстик
    delay(300);
    int newposition = menu_position;
    if(yAngle < 50)
        newposition += 1;
    else if(yAngle > 120)
        newposition -= 1;
        
      if(newposition < 0)
        newposition = 0;
      if(newposition > 2)
        newposition = 2;
     if(newposition != menu_position)
     {
       menu_position = newposition;
       show_menu();
     } else {
      if(menu_position == 0 || menu_position == 1)
      { 
        boolean start = false;
        if(xAngle < 50)
          start = true;
        else if(xAngle > 120)
          start = true;
          if(start)
            return;
      }
      if(menu_position == 2)
      { 
        int newlevel = menu_level;
        if(xAngle < 50)
          menu_level--;
        else if(xAngle > 120)
          menu_level++;
        if(menu_level < 1)
         menu_level = 1;
        if(menu_level > 3)
         menu_level = 3;
         if(menu_level != newlevel)
         {
            show_menu();
         }
       }
     }    
  }
}

void show_menu()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("S N A K E   ");
  if(menu_position == 0)
    printMenuSelection();
  lcd.setCursor(2, 1);
  lcd.print("T E N I S   ");
  if(menu_position == 1)
    printMenuSelection();
  lcd.setCursor(2, 3);
  lcd.print("L E V E L  ");
  lcd.print(menu_level);
  if(menu_position == 2)
    printMenuSelection();
}

void printMenuSelection()
{
  lcd.print(" <==");
}


int getDelay()
{
  if(menu_level <= 0)
    return 500;
  if(menu_level <= 2)
    return 300;
  if(menu_level <= 3)
    return 100;
  return 500;
}



double r_y;
double r_vy;
double c_y;
double c_vy;
double ball_x, ball_y;
double ball_vx, ball_vy;
int score_man, score_computer;
void tennis_init()
{
  r_y = 2;
  r_vy = 0;
  c_y = 0;
  c_vy = 0;
  ball_x = 1;
  ball_y = r_vy;
  ball_vy = 0.2;
  ball_vx = 0.2;
  score_man = 0;
  score_computer = 0;
  game = true;
}

void tennis_run()
{
  tennis_init();
  while(game)
  {
    // show score
    tennis_showScore();
    // user movement
    int yVal = analogRead(POS_Y_PIN) - MAX_POS/2 - 5;
    Serial.print("yVal=");
    Serial.println(yVal);
    if((yVal <  -10) || (yVal > 10))
    {
       double dVy = yVal * 0.1 / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
       r_vy -= dVy;
    }
    delay(100);
    
    // rocket movement
    lcd.setCursor(0, int(r_y+0.5));
    lcd.print(" ");
    r_y = r_y + r_vy;
    if(r_y < 0)
    {
      r_y = 0;
      r_vy = 0;
    }
    if(r_y > 3)
    {
      r_y = 3;
      r_vy = 0;
    }
    r_vy -= r_vy / 10;
    
    lcd.setCursor(0, int(r_y+0.5));
    lcd.print("]");
    
    // computer movement
    lcd.setCursor(19, int(c_y+0.5));
    lcd.print(" ");
    c_y = c_y + c_vy;
    double dvy = ((ball_y - c_y) > 0) ? 0.05 : -0.05;
    c_vy += (ball_y - c_y) / 5;
    lcd.setCursor(19, int(c_y+0.5));
    lcd.print("[");
    
    // ball movement
    int oldballx = int(ball_x+0.5);
    int oldbally = int(ball_y+0.5);
    ball_x += ball_vx;
    ball_y += ball_vy;
    if(ball_y < 0)
    {
      ball_y = 0;
      ball_vy = -ball_vy;
    }
    if(ball_y > 3)
    {
      ball_y = 3;
      ball_vy = -ball_vy;
    }


    int newball_x = int(ball_x+0.5);
    int newball_y = int(ball_y+0.5);
    boolean propusk_man = false;
    boolean propusk_comp = false;
    if(newball_x < 1) // прилетел влево
    {
      if(fabs(ball_y - r_y)<0.5) // otbili
      {      
        ball_vy += r_vy;
        ball_vx = -ball_vx;
        ball_x = 1;
        //ball_y = r_y;
      } else { // пропустили
        score_computer++;
        propusk_man = true;
      }
    }  
    if(newball_x >= 19) // прилетел вправо
    {
     if(fabs(ball_y - c_y)<0.5) // otbil computer
     {
        double dv = c_vy;
        if(dv > 0.2)
          dv = 0.2;
        if(dv < -0.2)
          dv = -0.2;
        ball_vy = -(ball_vy + dv);
        ball_vx = -ball_vx;
        ball_x = 18;
       //ball_y = c_y;
     } else { // пропустил компьютер
        score_man++;
        propusk_comp = true;
     }
    }  
    
    lcd.setCursor(oldballx, oldbally);
    lcd.print(" ");
    lcd.setCursor(newball_x, newball_y);
    lcd.print("o");
    
    if(propusk_man || propusk_comp)
    {
       tennis_showScore();
       delay(1000);
       lcd.setCursor(int(ball_x+0.5), int(ball_y+0.5));
       lcd.print(" ");
       if(propusk_man)
       {
        ball_x = 1;
        ball_y = r_y;
        r_vy = 0;
        c_vy = 0;
        ball_vy = 0.1;
        ball_vx = 0.2;
       }
       if(propusk_comp)
       {
        ball_x = 18;
        ball_y = c_y;
        r_vy = 0;
        c_vy = 0;
        ball_vy = -0.1;
        ball_vx = -0.2;
       }
       lcd.setCursor(int(ball_x+0.5), int(ball_y+0.5));
       lcd.print("o");
       delay(1000);
    }
    
    if(score_man > 7 || score_computer > 7)
     game = false;
  }
}

void tennis_showScore()
{
    lcd.setCursor(8,0);
    lcd.print(score_man);
    lcd.print(":");
    lcd.print(score_computer);
}


