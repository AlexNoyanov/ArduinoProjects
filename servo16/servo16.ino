#include <string>

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
}


void move(int servo, int position, int time) {
Serial.print("#");
Serial.print(servo);
Serial.print(" P");
Serial.print(position);
Serial.print(" S");
Serial.println(time);
//Serial.println("\r\n");//
//Serial.print(0x0a);
}

void loop() {

 move(4, 1000, 1500);
 delay(1500);
 
 move(0, 500, 1000);
 delay(1000);
 move(4, 1350, 1000);
 move(0, 2150, 1000);
 move(1, 800, 1000);
 delay(1000);
 move(1, 1100, 1000);
 delay(1000);
 move(4, 1200, 1000);
 delay(1000);
 
 
// for(int i = 1000; i <= 2400; i+=100)
//{ 
//  move(0, i, 200);
//  delay(200);
//}
//delay(1000);
  // put your main code here, to run repeatedly:
//move(1, 2000, 100);
//delay(1000);
//move(1, 1000, 100);
//delay(1000);
//move(2, 2000, 100);
//delay(1000);
//move(1, 2000, 100);
//delay(1000);
//Serial.println("#1P700T500");
//Serial.println("#2P700T500");
//delay(1000);
//Serial.println("#1P2000T500"); 
//Serial.println("#2P2000T500"); 
//delay(1000);

/*

Serial.println("#0 P1450 T1000");
Serial.println("#1 P663 T1000");
Serial.println("#2 P1017 T1000");
Serial.println("#3 P1480 T1000");
Serial.println("#4 P987 T1000");
Serial.println("#5 P950 T1000");
delay(1000);

Serial.println("#0 P1450 T1000");
Serial.println("#1 P663 T1000");
Serial.println("#2 P1017 T1000");
Serial.println("#3 P1480 T1000");
Serial.println("#4 P987 T1000");
Serial.println("#5 P950 T1000");

delay(1000);

Serial.println("#0 P1745 T1000");
Serial.println("#1 P663 T1000");
Serial.println("#2 P812 T1000");
Serial.println("#3 P665 T1000");
Serial.println("#4 P1362 T1000");
Serial.println("#5 P940 T1000");
delay(1000);

Serial.println("#0 P1695 T1000");
Serial.println("#1 P663 T1000");
Serial.println("#2 P812 T1000");
Serial.println("#3 P665 T1000");
Serial.println("#4 P1522 T1000");
Serial.println("#5 P940 T1000");
delay(1000);

char* cmd = 
"#0 P1645 #1 P663 #2 P812 #3 P720 #4 P1522 #5 P1095 "
"#0 P1645 #1 P663 #2 P812 #3 P1035 #4 P1522 #5 P975 "
"#0 P1595 #1 P663 #2 P812 #3 P1035 #4 P1607 #5 P975 "
"#0 P1595 #1 P1303 #2 P812 #3 P1035 #4 P1607 #5 P975 "
"#0 P1310 #1 P1303 #2 P952 #3 P1035 #4 P1187 #5 P975 "
"#0 P1310 #1 P1303 #2 P952 #3 P500 #4 P1187 #5 P975 ";

sendCommands(cmd);


/*
for(int i = 100; i < 2000; i+=300)
{
 for(int s = 1; s <= 5; s++)
 {
   Serial.print("#");
   Serial.print(s);
   Serial.print(" P");
   Serial.print(i);
   Serial.println(" T500");
   delay(700);
 }
}

// Serial.println("#0 P500 T1000");
// delay(1000);
// Serial.println("#1 P1200 T1000");
// delay(1000);
// Serial.println("#2 P1000 T1000");
// delay(1000);
// Serial.println("#3 P700 T1000");
// delay(1000);
// Serial.println("#4 P300 T1000");
// delay(1000);
// Serial.println("#4 P1700 T1000");
// delay(1000);
*/


}

void sendCommands(char* cmds)
{
  char* commands = (char*)malloc(strlen(cmd)+1);
  strcpy(commands, cmd);
  int needdelay = 0;
  while(true)
  {
    char* end_of_command = strchr(commands, ' ');
    if(end_of_command != NULL)
    {
      *end_of_command = '\0';
      Serial.print(commands);
      commands = end_of_command + 1;
    } else {
      Serial.println("");
      break;
    }
    Serial.print(' ');
    char* end_of_command2 = strchr(commands, ' ');
    if(end_of_command2 != NULL)
    {
      *end_of_command2 = '\0';
      Serial.print(commands);
      commands = end_of_command2 + 1;
    } else {
      Serial.println("");
      break;
    }
    Serial.println(" T1000");
    if( ((needdelay++) % 5) == 0)
      delay(1000);
  }
  free(commands);
}
