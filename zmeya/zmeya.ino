
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);
const int POS_Y_PIN = A1;
const int POS_X_PIN = A0;
const int BUTTON_PIN = 7;
const int MAX_POS = 1023;   // VRx и VRy выдают значения от 0 до 1023
const int MAX_ANGLE = 180; 
int x; // head
int y;
int dx; // movement
int dy;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 lcd.init();                       // Инициализация lcd             
  lcd.backlight();
  lcd.begin(20,4);
  lcd.clear();
  x = 0;
  y = 0;
  dx = 1;
  dy = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
   delay(3000);
    int yVal = analogRead(POS_Y_PIN);
    int xVal = analogRead(POS_X_PIN);
    float yAngle = 1.0 * yVal * MAX_ANGLE / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
    float xAngle = 1.0 * xVal * MAX_ANGLE / MAX_POS; // Аналогично VRx
    boolean isNotClicked = digitalRead(BUTTON_PIN);
     Serial.print("Horisontal angle = ");
    Serial.println(xAngle);
    Serial.print("Vertical angle = ");
    Serial.println(yAngle);
  lcd.setCursor(x,y);
lcd.print ("o");
if(xAngle

}
