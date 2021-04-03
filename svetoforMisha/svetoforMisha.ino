
 const int a = 13;
 const int b = 12;
 const int c = 11;
 const int d = 10; // put your setup code here, to run once:
 int prevState = HIGH;

void setup() {
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT); 
 
 //pinMode(8, INPUT);
}

//void checkTurnOff()
 //int buttonState = digitalRead(8);
 //if(buttonState == HIGH) // нажали кнопку
   // prevState = !prevState;
  //  if(prevState == LO

void loop() {
  // put your main code here, to run repeatedly:
  //checkTurnOff();
  
 if(prevState == HIGH)
 {
 digitalWrite(a, HIGH);
 digitalWrite(d, HIGH);
 delay(1400);
 // checkTurnOff();
 //if(prevState == HIGH)
 {
   digitalWrite(b, HIGH);
   delay(700);
   digitalWrite(b, LOW);
    delay(700);
   digitalWrite(b, HIGH);
   delay(700);
 //   checkTurnOff();
   if(prevState == HIGH)
   {
   digitalWrite(b, LOW);
   digitalWrite(a, LOW);
   digitalWrite(c, HIGH);
   delay(1400);
  //  checkTurnOff();
   if(prevState == HIGH)
   {
   digitalWrite(b, HIGH), digitalWrite(d, LOW);
    delay(700);
   digitalWrite(b, LOW),digitalWrite(d, HIGH);
    delay(700);
   {
     digitalWrite(b, HIGH); digitalWrite(d, LOW);
     delay(700);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
   }
   }
   }
 }
 } //else {
   delay(1000);
 }
 
 
