//**************************************************************//
//  Name    : shiftOutCode, Hello World                               
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006   
//  Modified: 21 Mar 2010 
//  Modified: 19 Feb 2011                              
//  Version : 2.0                                            
//  Notes   : Программа использует два сдвиговых регистра 74HC595
//          : для вывода значений от 0 до 255                         
//****************************************************************
 
//Пин подключен к ST_CP входу 74HC595
int latchPin = 8;
//Пин подключен к SH_CP входу 74HC595
int clockPin = 12;
//Пин подключен к DS входу 74HC595
int dataPin = 11;
 
 
 
void setup() {
  //устанавливаем режим OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
void loop() {
  // отсчитываем от 0 до 255  и отображаем значение на светодиоде
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // устанавливаем синхронизацию "защелки" на LOW
    digitalWrite(latchPin, LOW);
    // передаем отсчет для вывода на зеленые светодиоды
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay); 
    // передаем обратный отсчет  для вывода на красные светодиоды
    shiftOut(dataPin, clockPin, MSBFIRST, 255-numberToDisplay);
    //"защелкиваем" регистр, тем самым устанавливая значения на выходах
    digitalWrite(latchPin, HIGH);
    // пауза перед следующей итерацией
    delay(1);
  }
}

