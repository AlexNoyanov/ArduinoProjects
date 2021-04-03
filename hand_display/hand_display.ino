 #include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4 );
unsigned int hand = 0;
// подключать к аналоговым выходам А4 и А5

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("npuBeT Mup!");
  delay (2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
hand = analogRead(A1);
Serial.println(hand);
 lcd.setCursor(0,0);
  lcd.print("PyKA:");
if (hand > 0) 
{  lcd.setCursor(0,1);
  lcd.print("BBEPX");
}else{
   lcd.setCursor(0,1);
  lcd.print("BHu3");
}
delay(100);
}
