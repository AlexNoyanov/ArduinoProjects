 const int POS_Y_PIN = 1;
const int POS_X_PIN = 0;
const int BUTTON_PIN = 7;
const int MAX_POS = 1023;   // VRx и VRy выдают значения от 0 до 1023
const int MAX_ANGLE = 180; 
void joystick(){
    int yVal = analogRead(POS_Y_PIN);
    int xVal = analogRead(POS_X_PIN);
    float yAngle = 1.0 * yVal * MAX_ANGLE / MAX_POS; // Переводим выходные данные VRy в угол наклона джойстика (от 0 до 180)
    float xAngle = 1.0 * xVal * MAX_ANGLE / MAX_POS; // Аналогично VRx
    boolean isNotClicked = digitalRead(BUTTON_PIN);  // Считываем не было ли нажатия на джойстик
    Serial.println(isNotClicked);
Serial.println(xAngle);
Serial.println(yAngle);
delay(100);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
joystick();

}
