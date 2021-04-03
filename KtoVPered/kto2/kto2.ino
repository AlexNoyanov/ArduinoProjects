const int button1Pin = 6;
const int button2Pin = 7;
const int buttonResetPin = 5;
const int redLed1Pin = 13;
const int redLed2Pin = 12;
const int yellowLedPin = 11;
int pressed = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(buttonResetPin, INPUT);
 pinMode(button1Pin, INPUT);
 pinMode(button2Pin, INPUT);
 pinMode(redLed1Pin, OUTPUT);
 pinMode(redLed2Pin, OUTPUT);
 pinMode(yellowLedPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pressed != 0)
  {
    int btn0 = digitalRead(buttonResetPin);
    if(btn0 == HIGH)
    {
      pressed = 0;
    }
  }
  if(pressed == 0)
  {
    digitalWrite(yellowLedPin, HIGH);

    int btn1 = digitalRead(button1Pin);
    int btn2 = digitalRead(button2Pin);
    if(btn1 == HIGH)
    {
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(redLed1Pin, HIGH);
      pressed = 1;
    } else {
      digitalWrite(redLed1Pin, LOW);
    }
    if(btn2 == HIGH)
    {
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(redLed2Pin, HIGH);
      pressed = 2;
    } else {
      digitalWrite(redLed2Pin, LOW);
    }
  }
}
