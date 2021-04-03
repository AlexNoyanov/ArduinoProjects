#include<LiquidCrystal.h>
int pochva = 0;
int page = 1;
const int MAX_PAGE = 3;
int buttonState1=0; //переменная для хранения данных с кнопки
int buttonState2 = 0;
bool isButton1Pressed = false; // переменная для отслеживания отпуская и нажатия кнопки
bool isButton2Pressed = false;
bool isOnOff = 1;
int zvuk=0;
int svet=0;
const int piskPin = 8;
const int svetPin = 9;

LiquidCrystal lcd (12,11,10,5,4,3,2);
const int pinSB = 13;
const int button1 = 6;  // контакт кнопки 1
const int button2 = 7; //контакт кнопки 2
int a=8;
void setup() {
  // put your setup code here, to run once:
  pinMode(svetPin, OUTPUT);
  pinMode(pinSB, OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  a = 8;
  digitalWrite(pinSB, HIGH);
  drawPage1();
 Serial.begin(9600); 
}


void loop() {
 pochva = analogRead(0);
 lcd.setCursor(11, 1);
 lcd.print("H=");
 lcd.print(pochva);
 Serial.println(pochva);
  
   work_menu();
   
   delay(150);

   do_zvuk();   
}

void drawCurPage()
{
     pisk();
     lcd.clear();
     if(page == 1)
       drawPage1();
     if(page == 2)
       drawPage2();
     if(page >= 3)
       drawPage3();
}

void work_menu()
{
   // put your main code here, to run repeatedly:
   buttonState1 = digitalRead(button1); //считываем с кнопки1
   buttonState2 = digitalRead(button2); //считываем с кнопки2
   
   int newpage = page;
   if(buttonState1 == HIGH)
   {
       isButton1Pressed = true;
   }
   if(buttonState2 == HIGH)
   {
       isButton2Pressed = true;
   }
   if(buttonState1 == LOW && isButton1Pressed)
   {
     isButton1Pressed = false;
     newpage = page + 1;
     if(newpage > MAX_PAGE)
        newpage = 1;
   }
   if(buttonState2 == LOW && isButton2Pressed)
   {
     isButton2Pressed = false;
     if(page == 1)
     {
     }
     if(page == 2)
     {
       if(svet == 0) {
         svet = 1;
        digitalWrite(svetPin, HIGH);
       } else {
         svet = 0;
        digitalWrite(svetPin, LOW);
       }
     }
     if(page == 3)
     {
       if(zvuk == 0)
          zvuk = 3500;
       else
          zvuk = 0;
     }
     drawCurPage();
   }
   
   
   
   if(newpage != page)
   {
     page = newpage;
     drawCurPage();
   }
}


void do_zvuk()
{
    if(zvuk != 0)
    {    
      tone (piskPin,zvuk);
      delay(100);
      noTone(piskPin);
    }   
}

void pisk()
{
    tone (piskPin,2500);
    delay(100);
    noTone(piskPin);
}
void drawPage1()
{  
  lcd.setCursor(0,0);
  lcd.print("PE>|<UM: ");
 
//  lcd.setCursor(0,2);
  if(isOnOff)
    lcd.print(" BK^");
  else
    lcd.print(" B|dK^");
}


void drawPage2()
{ 
  lcd.setCursor(0,0);
  lcd.print("CBET: ");
  if(svet != 0)
    lcd.print("BK^");
  else
    lcd.print("B|dK^");
}


  void drawPage3()
{ 
  lcd.setCursor(0,0);
  lcd.print("3BYK: ");
  if(zvuk != 0)
    lcd.print("BK^");
  else
    lcd.print("B|dK^");
}
  
/*  
  if (buttonState2 == HIGH) {
    
     tone (1,2500);
    delay(100);
    noTone(1);
    a = a-1;
     lcd.setCursor(a,0);
  lcd.print("#");
   //lcd.setCursor(1,0);
   //lcd.print("~");
  }// else{
    // lcd.setCursor(0,0);
    //  lcd.print("~");
  // }
  
 
  if (buttonState1 == HIGH) {
    tone (1,2500);
    delay(100);
    noTone(1);
    a = a-1;
     lcd.setCursor(0,a);
  lcd.print("#");
  lcd.clear();
  }
}
  // lcd.setCursor(0,0);
  //  lcd.print(" Arduino Uno");
  //  delay(5000);
*/  

