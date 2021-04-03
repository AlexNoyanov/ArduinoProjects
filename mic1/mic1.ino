int mic = 0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(13,OUTPUT);
}


int pattern[5] = {0,0,0,0,0};
int index = 0;

bool checkPattern

void loop() {
  // put your main code here, to run repeatedly:
  int mic = analogRead(A1);
  Serial.println(mic);
//  if (mic != 50)
//  {
//    digitalWrite(13,HIGH); 
//    delay(1000); 
//  } else {
//   digitalWrite(13,LOW);
//   delay(500);
//  }

  pattern[index] = mic;
  index++;
  if(index > 5)
    index = 0;
  
  for
  if(pattern[0] != 50 && pattern[1] == 50 && pattern[2] != 50)
  {
    digitalWrite(13,HIGH); 
    delay(3000); 
    digitalWrite(13,LOW); 
  } else {
    delay(200);
  }

}
