//
// работа с температурным датчиком LM335
//   /======\
//   |======|
//   |======|
//   \======/
//     | | |
//     | | ----- GROUND
//       |     _____
//       |----|_____|-|--- +5v
//                    |_____ANALOG IN ARDUINO 
int ledpin=13;
int lm335=A1;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop()
{
  double val = analogRead(A0);
  Serial.print("Analog 0: ");
  Serial.print(int(val));
  double voltage = val*5.0/1024;
  Serial.print(" : ");
  Serial.print(voltage);
  double temp = voltage*100 - 273.15;
  Serial.print(" : ");
  Serial.println(temp);
  delay(100);
}
