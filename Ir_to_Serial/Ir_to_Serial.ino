#include <LiquidCrystal.h>
#include <IRremote.h>	
//int TKD2 = 11;
LiquidCrystal lcd(12, A3, 10, 5, 4, 3, 2);

int RECV_PIN2 = 11;
IRrecv irrecv2(RECV_PIN2);
decode_results results2;
int s = 0;
void setup() {
  // put your setup code here, to run once:
int tmin = 15;
int tmax = 28;
 pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  irrecv2.enableIRIn();        // Start the receiver
}
int mode = HIGH;

void loop() {
  // put your main code here, to run repeatedly:
  float tmin = 15;
  float tmax = 28;
   if (v == 0xFFE21D) {
 
  
 lcd.clear();
   lcd.setCursor(0,0);
    lcd.println("MIN :");
    lcd.println(tmin); 
    lcd.setCursor(0,1);
    lcd.println("MAX :");
    lcd.println(tmax); 
     if (irrecv2.decode(&results2)) {
    long v = results2.value;
    Serial.println(results2.value, HEX);
    irrecv2.resume();          // Receive the next value
    if(v == 0xFFE21D)
    { tmin = tmin+1;
   
    }
    if(v == 0xFFE21D)
    {tmin = tmin-1;
    }
    if(v== ) {
     lcd setCursor(s,0);
     lcd print('<=');}
     
      
  }
   }
    
}
