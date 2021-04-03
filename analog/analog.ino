
const int pinA = 14;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 1024; i++)
  {
    analogWrite(pinA, i);
    delay(20);
  }
}
