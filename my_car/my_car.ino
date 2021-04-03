
//  ==================
//  Arduino controlled 
//     X2 Robocar
//  With 3 ultrasonic
//       Sensors
//   By Alex Noyanov
//   28 January 2016
//  Version: 0.1 Alfa
//  ==================

// Speed = 0,6 m/sec
// Libraries:
 #include <OLED_I2C.h>

 OLED  myOLED(SDA, SCL, 8);
 extern uint8_t MediumNumbers[];
//=== Distances ===
 int f_distance;
 int r_distance;
 int l_distance;
 int time_us;
 //unsigned int time_us=0;
 int distance_sm=0;
//==== Const values: =====
 const int f_min = 10;
 const int l_min = 10;
 const int r_min = 10;
 
//  === Pins: ===
// Sensors:
 const int l_trig = 5; // Left Sensor
 const int l_echo = 4;
 const int f_trig = 7; // Forward sensor
 const int f_echo = 8;
 const int r_trig = 3; //  Right sensor
 const int r_echo = 2;

// Motor control:
 const int LF = 9; //Left Forward
 const int LB = 10; // Left Back
 const int RF = 12; // Right Forward
 const int RB = 11;  // Right Back

//  Distance reading function:
int readDistance(int trig, int echo)
{
  digitalWrite(trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(trig, LOW); // Затем убираем 
       time_us=pulseIn(echo, HIGH); // Замеряем длину импульса 
       distance_sm=time_us/58; // Пересчитываем в сантиметры 
  if(distance_sm == 0)
  return 200;
  return distance_sm;
}

//  Function for stop motors:
void motorStop(int motorPin){
  digitalWrite(motorPin,HIGH);
}
// Function for go:
void motorGo(int motorPin){
  digitalWrite(motorPin,LOW);
}
// ====  MAIN FUNCTIONS ====
//  Function for stop all motors:
void Go(){
  motorGo(LF);
  motorGo(RF);
}
void Stop(){
  motorStop(LF);
  motorStop(LB);
  motorStop(RF);
  motorStop(RB);
  }
  // Turn Right:
  void Right(){
    motorGo(RB);
    motorGo(LF);
  }
  // Turn Left:
  void Left(){
    motorGo(LB);
    motorGo(RF);
  }
  // Go back:
  void Back(){
    motorGo(RB);
    motorGo(LB);
  }

  void Lt(int tme){
    Left();
    delay(tme);
    Stop();
  }
  void Rt(int tme){
    Right();
    delay(tme);
    Stop();
  }
  void Fd(int tme){
    Go();
    delay(tme);
    Stop();
  }
void setup() {
  // put your setup code here, to run once:
  //  For testing:
 Serial.begin(9600); 
  //  Pins for sensors:
 pinMode(l_trig,OUTPUT);
 pinMode(l_echo,INPUT);
 pinMode(f_trig,OUTPUT);
 pinMode(f_echo,INPUT);
 pinMode(r_trig,OUTPUT);
 pinMode(r_echo,INPUT);
// Pins for motor:
 pinMode(LF,OUTPUT);
 pinMode(LB,OUTPUT);
 pinMode(RF,OUTPUT);
 pinMode(RB,OUTPUT);
    myOLED.begin();
   // myOLED.setFont(MediumNumbers);
  // myOLED.drawRoundRect(CENTER,CENTER , 40, 30);
   //myOLED.drawRect(0, 0, 40, 63);
   //myOLED.drawRect(80, 0, 40, 63);
   //myOLED.drawRect(120, 0, 40, 63);
   // myOLED.print("Hello World!",20,10);
 myOLED.update();
    
 Stop();
  delay(4000);
  Go();
  delay(500);
  Stop();
  /*
  Fd(600);
  Rt(600); // Turn Right  
  Fd(600);
  Lt(600);
  Fd(600);
  */
}

void loop() {
 
  // put your main code here, to run repeatedly:
  //  Read all distances:
  
   f_distance = readDistance(f_trig,f_echo);
   r_distance = readDistance(r_trig,r_echo);
   l_distance = readDistance(l_trig,l_echo);
  //
  /*
 // Go if f_distance is ok
if(f_distance > f_min){
  Go();
  f_distance = readDistance(f_trig,f_echo);
}else{
  Stop();
  //Read left and right:
   r_distance = readDistance(r_trig,r_echo);
   l_distance = readDistance(l_trig,l_echo);
   if(r_distance>l_distance){
   Right();
   }else{
    Left();
   }
   Stop();
}
*/  //    ===  Test mode OLED: ===
      myOLED.setFont(MediumNumbers);
    //myOLED.print("Hello World!",20,10); 
      myOLED.printNumI(r_distance, RIGHT, 40);
      myOLED.printNumI(l_distance, LEFT, 40);
      myOLED.printNumI(f_distance, CENTER, 0);
     myOLED.update();
// Previos algaritm:
/*
  if(f_distance < f_min){
    Stop(); // Stop all motors
   r_distance = readDistance(r_trig,r_echo); //read right
   l_distance= readDistance(l_trig, l_echo ); // read left
    if(r_distance>l_distance){
    Right();
    }else{
      Left();
     }
    }
//  If something on Right:
if(r_distance < r_min && l_distance > l_min){
Left();   
} else{
  Stop();
  Back();
  int choose = random(0,1);
  if (choose = 0)
  Right();
  if(choose = 1)
  Left();
}
if (l_distance<l_min){
Right();
  }


*/
  //    ===== For Test Mode: ======
  Serial.print("Forward:");
  Serial.println(f_distance);
    Serial.print("Right:");
  Serial.println(r_distance);
    Serial.print("Left:");
  Serial.println(l_distance);
    Serial.print(" ");
  delay(100);
  /*
// Test Function:
    void Test(){
  Go();
  delay(500);
  Stop();
  delay(1000);
  Right();
  delay(500);
  Stop();
  delay(1000);
  Left();
  delay(500);
  Stop();
  delay(1000);
  }
*/
  
}

  
