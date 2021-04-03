//    Nunchack servo control 
//    6 November 2015
//    Created by Alexander Noyanov
//    
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
   nunchuk.update();
  int y = nunchuk.accelY;
  int x = nunchuk.accelX;
  int z = nunchuk.accelZ;
//  Serial print
   Serial.print("  aX= ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("    aY= ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("    aZ= ");
  Serial.println(nunchuk.accelZ, DEC);

  // LEDs function:
   if(y>400){
    digitalWrite(red,HIGH);
  }else{
    digitalWrite(red,LOW);
  }

   if(x>400){
    digitalWrite(blue,HIGH);
  }else{
    digitalWrite(blue,LOW);
  }

   if(z>400){
    digitalWrite(green,HIGH);
  }else{
    digitalWrite(green,LOW);
  }
  //end delay
  delay(100);
}
