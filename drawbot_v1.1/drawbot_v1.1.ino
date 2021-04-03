
void forward() 
{
  ledGreen(HIGH);
  digitalWrite(10, HIGH);
  delay(5);
  digitalWrite(10, LOW);
  ledGreen(LOW);
  delay(100);
}
void backward()
{
  ledBlue(HIGH);
  digitalWrite(9,HIGH);
  delay(5);
  digitalWrite(9,LOW);
  ledBlue(LOW);
  delay(100);
}

void ledRed(int v)
{
  digitalWrite(6, v);
}
void ledBlue(int v)
{
  digitalWrite(7, v);
}
void ledGreen(int v)
{
  digitalWrite(8,  v);
}

int i = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(11,INPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
  calibrateBot();
  center();
}

void calibrateBot()
{
  // 1. read till first button is on
  int bs = digitalRead(11);
  while(bs != 1)
  {
    Serial.print("while bs=");
    Serial.println(bs);
    forward();
    bs = digitalRead(11);
  }
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);
  // we are at the end position now
  STEP_COUNT = 0;
  int fs = digitalRead(13);
  Serial.print("before while fs=");
  Serial.print(fs);
  Serial.println(fs != 1);
  while(fs != 1)
  {
    STEP_COUNT++;
    Serial.print("while fs=");
    Serial.println(fs);
    backward();
    fs = digitalRead(13);
  }
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);

  Serial.print("STEP_COUNT=");
  Serial.println(STEP_COUNT);
}

void center()
{
  int fs = digitalRead(13);
  while(fs != 1)
  {
    backward();
    fs = digitalRead(13);
  }
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);
  
  for(int i = 0; i < STEP_COUNT/2; i++)
  {
    forward();
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);
  for(int i = 0; i < STEP_COUNT/4; i++)
  {
    forward();
  }
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);
  for(int i = 0; i < STEP_COUNT/4; i++)
  {
    backward();
  }
  ledRed(HIGH);
  delay(50);
  ledRed(LOW);
 
}
 


 
  

