#include<LiquidCrystal.h>;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int lm335 = 0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
int temp = analogRead(A0);
int t2 = analogRead(A1);
//int tr = t2/9.31;
Serial.println(t2);
lcd.setCursor(0,0);
lcd.print("TEMP:");
lcd.setCursor(1,1);
lcd.print(temp);
delay(100);

}
