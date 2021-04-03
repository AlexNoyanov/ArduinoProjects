#include <IRremote.h> // eto skachannaya biblioteka

int RECV_PIN = 11; //vkhod IK priyemnika
IRrecv irrecv(RECV_PIN);
decode_results results;
int a=0; // peremennaya pereklyucheniya rezhima , pri nazhatii knopki ona prinimayet znacheniye +1
int b=0; //
int c=0; //
int d=0; //
int e=0; //
int f=0; //
int g=0; //
 

void setup()
{
irrecv.enableIRIn(); // vklyuchit? priyemnik

pinMode(13, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT); // naznachayem piny kak vykhody
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

} 

void loop() {
if (irrecv.decode(&results)) {
delay(300); // zaderzhka pered vypolneniyem opredeleniya knopok , chtoby izbezhat? bystroye dvoynoye nazhatiye

if (results.value == 0xFFB24D) {a=a+1;} // obrabotka nazhitya klavishi , zdes peremennaya prinimayet znacheniye 1
if (results.value == 0xFF2AD5) {b=b+1;} //VAZHNO !!! ( FFB24D ) Eto kod knopki ¹ 1 - moyego pulta - u vashego pul?ta budet drugoy kod - zamenite na svoy
if (results.value == 0xFF6897) {c=c+1;}
if (results.value == 0xFF32CD) {d=d+1;}
if (results.value == 0xFFA05F) {e=e+1;}
if (results.value == 0xFF30CF) {f=f+1;}
if (results.value == 0xFF50AF) {g=g+1;}

// nachinayem vklyuchat svetodiody na pinah
if (a==1){digitalWrite(13, HIGH);} else {digitalWrite(13, LOW); a=0;} // deystviye posle nazhatiya knopki , yesli peremennaya stala ravna 1 to
if (b==1){digitalWrite(2, HIGH);} else {digitalWrite(2, LOW); b=0;} // proizvesti pereklyucheniye pina v rezhim HIGH, yesli zhe net to vernut? peremennuyu v iskhodnoye sostoyaniye
if (c==1){digitalWrite(3, HIGH);} else {digitalWrite(3, LOW); c=0;} // Destviye mozhet byt? drugim
if (d==1){digitalWrite(4, HIGH);} else {digitalWrite(4, LOW); d=0;} // Destviye posle nazhatiya knopki  
if (e==1){digitalWrite(5, HIGH);} else {digitalWrite(5, LOW); e=0;} // Destviye posle nazhatiya knopki
if (f==1){digitalWrite(6, HIGH);} else {digitalWrite(6, LOW); f=0;} // Destviye posle nazhatiya knopki
if (g==1){digitalWrite(7, HIGH);} else {digitalWrite(7, LOW); g=0;} // Destviye posle nazhatiya knopki

{ //
delay(50); //pauza mezhdu povtorami //
} //
irrecv.resume(); // 

}

}