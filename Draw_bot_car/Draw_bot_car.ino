
// ==========================
// Arduino marker Drawing Bot
// 28 March 2016
// By Alex Noyanov
// ==========================
//

// Motor Speed 0,6 m/sec
int motor_speed =  60;  // santimeters/sec
// Motor control:
 const int LF = 8; //Left Forward
 const int LB = 11; // Left Back
 const int RF = 13; // Right Forward
 const int RB = 12;  // Right Back
 
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
  void Turn_right(){
    motorGo(RB);
    motorGo(LF);
  }
  // Turn Left:
  void Turn_left(){
    motorGo(LB);
    motorGo(RF);
  }
  // Go back:
  void Go_back(){
    motorGo(RB);
    motorGo(LB);
  }
 //  Function for stop motors:
 void motorStop(int motorPin){
  digitalWrite(motorPin,HIGH);
  }
 // Function for go:
void motorGo(int motorPin){
  digitalWrite(motorPin,LOW);
  }

// Drawing Functions:
void Right(int angle){
  
}

void fwd(int way)
{  // Input way in santimeters
  Go();
  int d = way*1000/motor_speed + 30; 
  Serial.println(way);
  Serial.println(motor_speed);
  Serial.println(d);
  delay(d);
  Stop();
}
  
void bkw(int way)
{  // Input way in santimeters
  Go_back();
  int d = way*1000/motor_speed + 30; 
  Serial.println(way);
  Serial.println(motor_speed);
  Serial.println(d);
  delay(d);
  Stop();
}


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(LF,OUTPUT);
 pinMode(LB,OUTPUT);
 pinMode(RF,OUTPUT);
 pinMode(RB,OUTPUT);
  Stop();
  delay(5000);
  fwd(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  fwd(2);
  fwd(2);
  fwd(2);
  delay(1000);
  bkw(2);
  bkw(2);
  bkw(2);
  delay(10000);
}
