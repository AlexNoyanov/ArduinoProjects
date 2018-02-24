// ArGlass By Alex Noyanov
// Applications 
// 15 of February
// 2017 

#include <OLED_I2C.h>
#include <OzOLED.h>
OLED myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];

int height = 30;
int lenght = 30;
int scale = 5;
void drawDevApp(int x,int y){
  myOLED.drawRoundRect(x,y,height,lenght);
  myOLED.drawLine(x+2,y+2,lenght/2+x+3,height/2+y+3);
 // myOLED.drawLine(x,height+y,lenght+x,y);
}

void drawApp(int x,int y,int sze){
    myOLED.drawRoundRect(x,y,x+height+sze,y+lenght+sze);         // Drawing icon
   myOLED.drawCircle(x+height/2+sze/2,y+lenght/2+sze/2,height/2-2+sze/2); // Drawing somethging there 
}

void drawWatchApp(int x,int y,int sze){
   myOLED.drawRoundRect(x,y,x+height+sze,y+lenght+sze);         // Drawing icon
   myOLED.drawCircle(x+height/2+sze/2,y+lenght/2+sze/2,height/2-2+sze/2); // Drawing somethging there 
  // myOLED.printNumI(12,x+8,y+4,1);
  if(sze <= 5){
   myOLED.print("Watch",x,y+height+2+sze);  // Printing text
  }
   myOLED.drawLine(x+height/2+sze/2,y+lenght/2+sze/2,x+height/2-8,y+lenght/2-6);  // Minutes
   myOLED.drawLine(x+height/2+sze/2,y+lenght/2+sze/2,x+height/2+8,y+lenght/2-3);  // Hours
   myOLED.drawLine(x+height/2+1+sze/2,y+lenght/2+1+sze/2,x+height/2+8+1,y+lenght/2-3+1);
}

// Original ANLab symbol:
float y,yy = 0;
const int a = 25;
void drawEmblem(){
  myOLED.clrScr();
      for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+40);
      myOLED.invPixel(i+15, (cos(yy)*a)+33);
      myOLED.update();
     
    }
    
      delay(1000);
        myOLED.drawCircle(50,45,6);
        myOLED.update();
        delay(500);
          myOLED.drawCircle(50,45,8);
             myOLED.update();
         
                 for (int i=0; i<100; i++)
    {
      y=i*0.09;
      yy = i*0.09;
      myOLED.invPixel(i+15, (cos(y)*a)+39);
      myOLED.invPixel(i+15, (cos(yy)*a)+38);
      myOLED.invPixel(i+15, (cos(y)*a)+37);
      myOLED.invPixel(i+15, (cos(yy)*a)+36);
      //myOLED.invPixel(i+15, (cos(yy)*a)+3);
      myOLED.invPixel(i+15, (cos(y)*30)+35);
      myOLED.invPixel(i+15, (cos(yy)*a)+34);
      
       myOLED.update();
    }
     myOLED.drawCircle(50,45,7);
             myOLED.update();
}

void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(SmallFont);
 // extern uint8_t SmallFont[];
   drawEmblem();
   delay(1000);
   myOLED.clrScr();
}

void loop() {
  // put your main code here, to run repeatedly:
    myOLED.clrScr();
  //drawDevApp(10,10);
  drawWatchApp(50,20,0);
    myOLED.update();
  delay(2000);
  myOLED.clrScr();
    for(int i = 0; i<50;i=i+3){
  drawWatchApp(50-i/2,20-i/2,i);
  myOLED.update();
  delay(5);
    myOLED.clrScr();
    }
//myOLED.drawCircle(lenght/2+20,height+10,6);
 myOLED.update();
}
