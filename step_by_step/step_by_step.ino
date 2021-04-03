//int a;
int c;
int g = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);

}

int result=0;

int sum(int add)
{
  result += add;
  return result;
}
 
int substruct(int minus)
{
  result -= minus;
  return result;
}

    // read the incoming byte:
char readcommand()
{
  char command=0;
 if (Serial.available() > 0) 
 {
    command = Serial.read();
 }
 return command;
}

void flash13()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void loop() 
{
  char command = readcommand();  
    if(command == '+') {
        sum(100);
        flash13();
        delay(500);
        flash13();
    } else if(command == '-') {
        flash13();
        substruct(100);
    } if(command >= '1' && command <= '9')
    {
      int count = command - '0';
      for(int i = 0; i < count; i++)
      {
        flash13();
        delay(500);
      }
    }
                // say what you got:
 Serial.println(result);
 delay(500);
/* 
        }//   put your main code here, to run repeatedly
  //int b = random ( 0,1000);
int a = random (2,14);
  digitalWrite(a,HIGH);
    int h = analogRead(A0); 
  delay(h);
  digitalWrite(a,LOW);
  //if (a == 14) {
   /* digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
  }

  while(true)
  {
    int resistor = analogRead(A0); 
    Serial.print("Resistor=");
    Serial.println(resistor);
    delay(300);
  }
  
  
  a  = 3;
 // Serial.println(c);
 while ( a <= 13) {
   digitalWrite(a,HIGH);
   delay(500);
   digitalWrite(a,LOW);
   a = a+1; 
 }
 
  /* while(a>=3) {
     digitalWrite(a,HIGH);
     delay(500);
   digitalWrite(a,LOW);
   a = a-1;
   }
  */
}





  
  




