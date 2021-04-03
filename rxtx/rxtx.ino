void setup() {
  Serial.begin(9600); 
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int key = digitalRead(10);
    Serial.println("key pressed\n");
  if(key == HIGH)
  {
    Serial.println("key pressed\n");
    digitalWrite(13, HIGH);
    delay(25);
    digitalWrite(13, LOW);
//    delay(20);
  } else {
//    digitalWrite(11, LOW);
  }
//  delay(100);
  
//  digitalWrite(13, key);
  
  int signal = digitalRead(12);
  if(signal == HIGH)
  {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
/*  
  for(int i = 0; i < 10; i++)
  {
    int v = digitalRead(12);
    if(v == HIGH)
    {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }
    delay(100);
  }

  digitalWrite(13, LOW);
  for(int i = 0; i < 10; i++)
  {
    int v = digitalRead(12);
    if(v == HIGH)
    {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }
    delay(100);
  }
*/  
delay(100);
}
