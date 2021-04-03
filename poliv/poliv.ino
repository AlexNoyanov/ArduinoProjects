#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int h1 = A2;
int h2 = A1;
int rel = 6;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(A2,800);
analogRead(A0);
analogRead(A1);
lcd.begin(16,2);    
  lcd.clear();  
lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Hum:");
  lcd.setCursor(5,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print(h1);
  lcd.setCursor(0,1);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Hum:");
  lcd.setCursor(5,1);           // set cursor to column 0, row 0 (the first row)
  lcd.print(h2);
  delay(1000);
  
}
