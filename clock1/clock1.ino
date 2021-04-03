#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int h = 18;
int m = 7;
int s = 0;
int day = 6;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.begin(16,2); 
 lcd.clear();  
  lcd.setCursor(0,0);
   lcd.print("Time :");
    lcd.setCursor(9,0);
     lcd.print("Day :");
      lcd.setCursor(0,1);           // set cursor to column 0, row 1
       lcd.print(h);
        lcd.setCursor(2,1);
         lcd.print(":");
          lcd.setCursor(3,1);
           lcd.print(m);
            lcd.setCursor(5,1);
             lcd.print(":");
              lcd.setCursor(6,1);
               lcd.print(s);
char* names_of_days[7] = 
   { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
lcd.setCursor(8,1);
lcd.print(names_of_days[day-1]);

s = s +1;
if (s > 59){
s = 0;
m = m+1;
}

if (m > 59) {
  h = h+1;
  m = 0;
}
if ( h > 23 ) {
   h = 0;
   day = day+1;
   if(day>6){
     day = 1;
   }
  }

delay(1000);
  
}
