  #include <Wire.h> 
    #include <LiquidCrystal_I2C.h>
     #include <vector>

const int MAX_X = 20;

LiquidCrystal_I2C lcd(0x27,MAX_X,4);   /* Задаем размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 16х4 ничего в коде изменять не требуется, cледует только заменить цифру отвечающую за количество сторок */

int x, y;
int dx;

class Snow
{
  int _x, _y;
  boolean _dead;
  public:
  Snow(int x=0, int y=-1) 
  { 
    _x = x; 
    _y = y;
    _dead = false;
  }
  boolean isDead() 
  {
    return _dead;
  }
  
  void print()
  {
    lcd.setCursor(_x, _y);
    lcd.print("*");
  }
  void clear()
  {
    if(_y >= 0)
    {
       lcd.setCursor(_x, _y);
       lcd.print(" ");
    }
  }
  boolean down()
  {
    if(_dead)
     return false;
    clear();
    _y += 1;
     if(_y > 3) {
      _dead = true; 
      return false;
     }
      
    if(random(10) < 5)
     _x += 1;
    else
     _x -= 1;
    if(_x < 0)
     _x = 0;
     if(x > MAX_X-2)
     _x = MAX_X-2;
    print();
    return true;
  }
};

const int SNOW_COUNT = 20;
Snow snows[SNOW_COUNT];

void setup()
{
  lcd.init();                       // Инициализация lcd             
  lcd.backlight();                  // Включаем подсветку
  // Курсор находится в начале 1 строки
//  lcd.print("Hello, world!");       // Выводим текст
//  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 2 строки
//  lcd.print("zelectro.com.ua");     // Выводим текст
//  lcd.setCursor(0, 2); 
//  lcd.print("Sasha-bukashka");     // Выводим текст
//  lcd.setCursor(0, 3); 
//  lcd.print("Sasha-promokashka");     // Выводим текст
 x = 0;
 y = 0;
 dx = 1;
}


void loop()
{
  for(int i = 0; i < SNOW_COUNT; i++)
  {
    Snow& snow = snows[i];
    snow.down();
  }
  int sn = 0;
  for(int i = 0; i < SNOW_COUNT; i++)
  {
    if(!snows[i].isDead())
     sn++;
  }
  if(sn < 15)
  {
  if(random(5) < 2 || sn < 4)
  {
     for(int i = 0; i < SNOW_COUNT; i++)
     {
       if(snows[i].isDead())
       {
         snows[i] = Snow(random(MAX_X-2)+1, -1);
         break;
       }
     }
   }
  }
    
  
 // outputStrelka();
  delay(500);
 // moveStrelka();
  
  //generateChar();
}

 void generateChar()
 {
   int xx = random(20);
   int yy = random(4);
   lcd.setCursor(xx, yy);
   lcd.print("*");
 }




void outputStrelka()
{
  lcd.setCursor(x, y); 
  if(dx > 0) {
   lcd.print("<=>");
  } else {
   lcd.print("<=>");
  }
}
void moveStrelka()
{
  lcd.setCursor(x, y); 
  lcd.print("    ");
  x = x + dx;
  if(x < 0)
  {
    dx = 1;//y = y + 1;
    x = 0;
  }
  if(x > 15)
  {
    dx = -1;//y = y + 1;
    //x = 0;
  }
  if(y > 3)
  {
    y = 0;
  }
} 
