//
//  Ultrasonic distance sensor
//
#define SIZE 10
 const int Trig = 7; 
 const int Echo = 8;
  unsigned int time_us=0;
  unsigned int distance_sm=0;
  int button = 11;
  int srednee = 0;
  int dist[SIZE];
  int sumDist = 0;
  int flag = 0;
  int tonPin = 4;
//  Function
int readDistance()
{
  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
   digitalWrite(Trig, LOW); // Затем убираем 
     time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
       distance_sm=time_us/58; // Пересчитываем в сантиметры 
  return distance_sm;
}

void Beep(){
  //if(flag = 0){
  tone(tonPin,1500);
  delay(100);
  noTone(tonPin);
  delay(100);
 // }
}
  int distance=0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(Trig, OUTPUT); 
   pinMode(Echo, INPUT);   
   pinMode(button,INPUT);
   pinMode(10, OUTPUT);
  int pos = 0;
  pos  = digitalRead(button);
   while(  pos!=0){
  pos =digitalRead(button);
  //Serial.print("Button =");
   }
   
   delay(1000);
   Beep();
   digitalWrite(10,HIGH);
   for(int i =0;i<SIZE;i++){
    dist[i] = readDistance();
      }
      
for(int i =0;i<SIZE;i++){
    sumDist = sumDist+dist[i];  
  }
   srednee = sumDist/(SIZE-1);
   Serial.println(srednee);
}
void loop() {
  Beep();
  // put your main code here, to run repeatedly:
int workMode = readDistance();
int predelUP = srednee+10;
int predelDW = srednee-10;
int sum;
 while(workMode==srednee||workMode>predelDW ||workMode<predelUP){
  if(workMode>predelUP){
    break;
  }else
  if(workMode<predelDW){
    break;
  }
  workMode = readDistance();
  Serial.println(workMode);
  delay(200);
 }
 Beep();
 // Serial.println(workMode);
 digitalWrite(10,LOW);
}
