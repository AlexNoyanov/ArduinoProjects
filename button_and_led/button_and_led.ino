 const int pin = 8;
 const int LED_PIN_RED = 11;
 const int LED_PIN_GREEN = 12;
 const int LED_PIN_BLUE = 13;
 int light_time=0;


// Color Library
int RGB(int r, int g, int b)
{
  return r + (g<<1) + (b<<2);  
}
int RGB_D(int r, int g, int b)
{
  return r + g*10 + b*100;  
}
int RGB_R(int x)
{
  return (x & 0x1) ? HIGH : LOW;
}
int RGB_G(int x)
{
  return (x & 0x2) ? HIGH : LOW;
}
int RGB_B(int x)
{
  return (x & 0x4) ? HIGH : LOW;
}
int RGB_R_D(int x)
{
  return (x % 10) ? HIGH : LOW;
}
int RGB_G_D(int x)
{
  return ((x / 10) % 10) ? HIGH : LOW;
}
int RGB_B_D(int x)
{
  return (x / 100) ? HIGH : LOW;
}
const int BLACK  = RGB(0, 0, 0);
const int RED    = RGB(1, 0, 0);
const int GREEN  = RGB(0, 1, 0);
const int YELLOW = RGB(1, 1, 0);
const int BLUE   = RGB(0, 0, 1);
const int MAGENTA= RGB(1, 0, 1);
const int BROWN  = RGB(0, 1, 1);
const int WHITE  = RGB(1, 1, 1);

void color(int color)
{
      digitalWrite(LED_PIN_RED,   RGB_R(color));  
      digitalWrite(LED_PIN_GREEN, RGB_G(color));  
      digitalWrite(LED_PIN_BLUE,  RGB_B(color));  
}


// Main 


void setup() {
  // put your setup code here, to run once:
pinMode(pin,INPUT);
pinMode(LED_PIN_GREEN, OUTPUT);
pinMode(LED_PIN_RED, OUTPUT);
pinMode(LED_PIN_BLUE, OUTPUT);
color(BLACK);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
int button = digitalRead(pin);
 if (button == LOW && light_time == 0){
    light_time = 50;
    color(WHITE);
 }
 //else {
 // //digitalWrite(LED_PIN_GREEN,LOW);
 //}
 if(light_time > 0)
 {
  light_time--;
  if(light_time == 40)
  {
    color(GREEN);
  }
  if(light_time == 30)
  {
    color(YELLOW);
  }
  if(light_time == 20)
  {
    color(MAGENTA);
  }
  if(light_time == 10)
  {
    color(BROWN);
  }
  if(light_time == 0)
  {
    color(BLACK);
  }
 }

 

 
 delay(100);
}



