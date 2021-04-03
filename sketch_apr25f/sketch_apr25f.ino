/* =========================================================== 

  Название игры: ArduMan 
  Версия игры: v1.0 (Demo) 
  Разработчик игры: ZSeregaA 
  Сайт проекта: http://robocontroller.ru/ 
  Описание игры, 
  вопросы и отзывы:  

============================================================ */ 

#include <IRremote.h> 
#include <IRremoteInt.h> 
#include <LiquidCrystal.h> 

// Графические символы в игре 
// 1 ArduMan - Основная стойка, голова вправо. 
byte ArduMan[8] = { 
  0b00110, 
  0b00110, 
  0b00100, 
  0b01110, 
  0b10101, 
  0b00100, 
  0b01010, 
  0b01010 
}; 

// 2 ArduMan - Основная стойка, голова влево. 
byte AM_Head_Left[8] = { 
  0b01100, 
  0b01100, 
  0b00100, 
  0b01110, 
  0b10101, 
  0b00100, 
  0b01010, 
  0b01010 
}; 
// 3 ArduMan - Шаг Вправо движение 1 
byte AM_R_Step_1[8] = { 
  0b00110, 
  0b00110, 
  0b00100, 
  0b01110, 
  0b00101, 
  0b00100, 
  0b11010, 
  0b00010 
}; 

// 4 ArduMan - Шаг Вправо движение 2 
byte AM_R_Step_2[8] = { 
  0b00110, 
  0b00110, 
  0b00100, 
  0b01110, 
  0b10100, 
  0b00110, 
  0b01010, 
  0b01000 
}; 

// 5 Чистый символ. 
byte ClearChar[8] = { 
  0b00000, 
  0b00000, 
  0b00000, 
  0b00000, 
  0b00000, 
  0b00000, 
  0b00000, 
  0b00000 
}; 

// 6 ArduMan - Правая рука вверх, движение 1. 
byte AM_R_Hend_Up_1[8] = { 
  0b00110, 
  0b00110, 
  0b00100, 
  0b11110, 
  0b00101, 
  0b00100, 
  0b01010, 
  0b01010 
}; 

// 7 ArduMan - Правая рука вверх, движение 2. 
byte AM_R_Hend_Up_2[8] = { 
  0b00110, 
  0b00110, 
  0b10100, 
  0b01110, 
  0b00101, 
  0b00100, 
  0b01010, 
  0b01010 
}; 

// 8 ArduMan - Правая рука вверху, движение 3. 
byte AM_R_Hend_Up_3[8] = { 
  0b00110, 
  0b00110, 
  0b01100, 
  0b01110, 
  0b00101, 
  0b00100, 
  0b01010, 
  0b01010 
}; 

// 9 ArduMan - Шаг Влево движение 1 
byte AM_L_Step_1[8] = { 
  0b01100, 
  0b01100, 
  0b00100, 
  0b01110, 
  0b10100, 
  0b00100, 
  0b01011, 
  0b01000 
}; 

// 10 ArduMan - Шаг Влево движение 2 
byte AM_L_Step_2[8] = { 
  0b01100, 
  0b01100, 
  0b00100, 
  0b01110, 
  0b00101, 
  0b01110, 
  0b01010, 
  0b00010 
}; 

// 11 Коробка сплошная 
byte Box_1[8] = { 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111 
}; 

// 12 Стрелка вверх 
byte Arrow_Up[8] = { 
  0b00000, 
  0b00000, 
  0b00100, 
  0b01110, 
  0b10101, 
  0b00100, 
  0b00100, 
  0b00000 
}; 

// 13 Стрелка вправо 
byte Arrow_Right[8] = { 
  0b00000, 
  0b00000, 
  0b00100, 
  0b00010, 
  0b11111, 
  0b00010, 
  0b00100, 
  0b00000 
}; 

// 14 Стрелка влево 
byte Arrow_Left[8] = { 
  0b00000, 
  0b00000, 
  0b00100, 
  0b01000, 
  0b11111, 
  0b01000, 
  0b00100, 
  0b00000 
}; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD Пины 
IRrecv irrecv(31); // IR Пин 
decode_results results; // IR 
int AM_X = 0; // Координата X для ArduMan 
int AM_Y = 1; // Координата Y для ArduMan 
int ir_code = 0; 

// Измените коды с пульта на свои 
int AM_GO_RIGHT = -8161; // IR код движения ArduMan влево 
int AM_GO_LEFT = -12241; // IR код движения ArduMan вправо 
int AM_GO_JUMP = 18615; // IR код прыжка ArduMan 

int AM_GO = 1; // Текущее направление движения ArduMan. 1=Вправо, 2=Влево 
int Game_Step_Speed = 40; // Скорость передвижения в игре. 40 = Норма 
int Game_Jump_Speed = 180; // Скорость прыжка. 180 = норма 
int AM_Step_Speed = 200; // Скорость передвижения ArduMan в интро 
int AM_R_Step = 3; // Номер текущего символа движения ArduMan вправо 
int AM_L_Step = 3; // Номер текущего символа движения ArduMan влево 
long previousMillis = 0; // Переменная для таймера  
long interval = 800; // Время таймера 
int AM_intro = 1; // Интро 1 = Вкл, 0 = Откл. 
// Коробка 1 
int Box_1_X = 8; // X координата коробки 1 
int Box_1_Y = 1; // Y координата коробки 1 

void setup() 
{ 
  Serial.begin(9600); 
  irrecv.enableIRIn(); 
  lcd.createChar(1, ArduMan); // 1-й символ  
  lcd.createChar(2, AM_Head_Left); // 2-й символ 
  lcd.createChar(3, AM_R_Step_1); // 3-й символ 
  lcd.createChar(4, AM_R_Step_2); // 4-й символ 
  lcd.createChar(5, ClearChar); // 5-й символ 
  lcd.createChar(6, AM_R_Hend_Up_1); // 6-й символ 
  lcd.createChar(7, AM_R_Hend_Up_2); // 7-й символ 
  lcd.createChar(8, AM_R_Hend_Up_3); // 8-й символ 
  lcd.begin(16, 2); // Настройки для LCD 
  delay(3000); 
   
  // Интро заставка 
  if (AM_intro == 1){ 
  lcd.setCursor(1, 0); 
  lcd.print("ROBOCONTROLLER"); 
  delay(2000); 
  lcd.setCursor(4, 1); 
  lcd.print("present"); 
  delay(4000); 
  lcd.clear(); 
  lcd.setCursor(4, 1); 
  lcd.print("present"); 
  delay(1500); 
  lcd.clear(); 
  delay(2000); 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на экран графического символа 1 
  delay(1500); 
   
   
  // ArduMan идет на середину 
  for (int AM_R_Move = 1; AM_R_Move < 8; AM_R_Move++){ 
  // Изменение анимации шагов 
  if (AM_R_Step < 4){ 
  AM_R_Step = 4; 
  } 
  else{ 
  AM_R_Step = 3; 
  } 
  lcd.setCursor(AM_R_Move - 1, 1); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(5); // Стирание символа на предыдущей позиции ArduMan 
  lcd.setCursor(AM_R_Move, 1); // Установка курсора на текущей позиции 
  lcd.write(AM_R_Step); // Индикация текущего символа движения ArduMan 
  delay(AM_Step_Speed); 
  } 
  // ArduMan смотрит по сторонам 
  lcd.setCursor(7, 1); 
  lcd.write(1); 
  delay(1000); 
  lcd.setCursor(7, 1); 
  lcd.write(2); 
  delay(1000); 
  lcd.setCursor(7, 1); 
  lcd.write(1); 
  delay(500); 
  // Название игры 
  lcd.setCursor(4, 0); 
  lcd.print("ARDUMAN"); 
  delay(1000); 
   
  // ArduMan поднимает правую руку. 
  lcd.setCursor(7, 1); 
  lcd.write(6); 
  delay(200); 
  lcd.setCursor(7, 1); 
  lcd.write(7); 
  delay(200); 
   
  // ArduMan машет рукой и опускает её. 
  lcd.setCursor(7, 1); 
  lcd.write(8); 
  delay(500); 
  lcd.setCursor(7, 1); 
  lcd.write(7); 
  delay(500); 
  lcd.setCursor(7, 1); 
  lcd.write(8); 
  delay(500); 
  lcd.setCursor(7, 1); 
  lcd.write(7); 
  delay(200); 
  lcd.setCursor(7, 1); 
  lcd.write(6); 
  delay(200); 
  lcd.setCursor(7, 1); 
  lcd.write(1); 
  delay(1000); 
  AM_R_Step = 3; 
   
  // ArduMan уходит с экрана 
  for (int AM_R_Move = 8; AM_R_Move < 16; AM_R_Move++){ 
  // Изменение анимации шагов 
  if (AM_R_Step < 4){ 
  AM_R_Step = 4; 
  } 
  else{ 
  AM_R_Step = 3; 
  } 
  lcd.setCursor(AM_R_Move - 1, 1); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(5); // Стирание символа на предыдущей позиции ArduMan 
  lcd.setCursor(AM_R_Move, 1); // Установка курсора на текущей позиции 
  lcd.write(AM_R_Step); // Индикация текущего символа движения ArduMan 
  delay(AM_Step_Speed); 
  } 
  lcd.setCursor(15, 1); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(5); // Стирание символа на предыдущей позиции ArduMan 
  delay(1000); 
  lcd.clear(); 
  lcd.setCursor(3, 0); 
  lcd.print("created by"); 
  delay(1500); 
  lcd.setCursor(4, 1); 
  lcd.print("ZSeregaA"); 
  delay(3000); 
  lcd.clear(); 
  lcd.setCursor(4, 1); 
  lcd.print("ZSeregaA"); 
  delay(1500); 
  lcd.clear(); 
} 
  // Сообщение о начале игры 
  lcd.setCursor(6, 0); 
  lcd.print("GAME"); 
  lcd.setCursor(4, 1); 
  lcd.print("STARTING"); 
  delay(3000); 
  lcd.clear(); 
  delay(500); 
   
  // ArduMan на исходной позиции 
  AM_X = 0; 
  AM_Y = 1; 
  lcd.clear(); 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на LCD экран графического символа 1 
   
  // Настройки для движения 
  // AM_R_Step = 3; 
  // AM_L_Step = 3; 
   
  // Прорисовка коробки на поле 
  lcd.createChar(5, Box_1); 
  lcd.setCursor(Box_1_X, Box_1_Y); 
  lcd.write(5); 
} 

void loop() 
{ 
  // Если нет движения ArduMan встает в исходное положение 
  // В том направлении в котором двигался 
  unsigned long currentMillis = millis(); 
  if(currentMillis - previousMillis > interval) { 
  previousMillis = currentMillis; 
  // Вправо 
  if (AM_GO == 1){ 
  lcd.createChar(1, ArduMan); // ArduMan стоит и смотрит вправо 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на LCD экран графического символа 
  } 
  // Влево 
  else{ 
  lcd.createChar(1, AM_Head_Left); // ArduMan стоит и смотрит влево 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на LCD экран графического символа 
  } 
  } 
   
  // Если есть сигнал с пульта 
  //if (irrecv.decode(&results)) { 
  //ir_code = results.value; 
   
  // ArduMan идет ВПРАВО 
  if(A0==1) //((ir_code == AM_GO_RIGHT) && (AM_X < 15) && (AM_X != Box_1_X - 1) && (AM_GO == 1)){ 
  AM_GO = 1; // Текущее направление движения ArduMan. 1=Вправо 
  lcd.createChar(1, ArduMan); // ArduMan смотрит вправо 
  lcd.createChar(2, AM_R_Step_1); // Шаг 1 
  lcd.createChar(3, AM_R_Step_2); // Шаг 2 
  lcd.createChar(4, ClearChar); // Пустой символ 
  // Если ArduMan находится на коробке 1 
  if ((AM_X != Box_1_X + 1) && (AM_Y == 0)){ 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  AM_Y++; 
  } 
  AM_X = AM_X + 1; // Шаг 
  // Изменение анимации шагов 
  if (AM_R_Step < 3){ 
  AM_R_Step = 3; 
  } 
  else{ 
  AM_R_Step = 2; 
  } 
  // При спуска с коробки 1 
  if (AM_X - 1 != Box_1_X){ 
  lcd.setCursor(AM_X - 1, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  } 
   
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(AM_R_Step); // Индикация текущего символа движения ArduMan 
  delay(Game_Step_Speed); // Скорость передвижения 
  } 
   
  // Поворот вправо 
  if (digitalRead(13)==1)//(//((ir_code == AM_GO_RIGHT) && (AM_GO == 2)){ 
  AM_GO = 1; 
  lcd.createChar(1, ArduMan); // Символ ArduMan стоит и смотрит вправо 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на LCD экран графического символа 1 
  delay(Game_Step_Speed); // Скорость передвижения 
  } 
   
  // ArduMan идет ВЛЕВО 
  if ((ir_code == AM_GO_LEFT) && (AM_X > 0) && (AM_X != Box_1_X + 1) && (AM_GO == 2)){ 
  AM_GO = 2; // Текущее направление движения ArduMan. 2=Влево 
  lcd.createChar(1, AM_Head_Left); // ArduMan смотрит влево 
  lcd.createChar(2, AM_L_Step_1); // Шаг 1 
  lcd.createChar(3, AM_L_Step_2); // Шаг 2 
  lcd.createChar(4, ClearChar); // Пустой символ 
   
  // Если ArduMan находится на коробке 1 
  if ((AM_X != Box_1_X + 1) && (AM_Y == 0)){ 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  AM_Y++; 
  } 
  AM_X = AM_X - 1; // Шаг 
  // Изменение анимации шагов 
  if (AM_L_Step < 3){ 
  AM_L_Step = 3; 
  } 
  else{ 
  AM_L_Step = 2; 
  } 
  // при спуске с коробки 1 
  if (AM_X + 1 != Box_1_X){ 
  lcd.setCursor(AM_X + 1, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  } 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(AM_L_Step); // Индикация текущего символа движения ArduMan 
  delay(Game_Step_Speed); // Скорость прыжка 
  } 
   
  // Поворот влево 
  if ((ir_code == AM_GO_LEFT) && (AM_GO == 1)){ 
  AM_GO = 2; 
  lcd.createChar(1, AM_Head_Left); // ArduMan стоит и смотрит влево 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на LCD 
  lcd.write(1); // Вывод на LCD экран графического символа 
  delay(Game_Step_Speed); // Скорость прыжка 
  } 
   
  // Прыжок ВПРАВО 
  if ((ir_code == AM_GO_JUMP) && (AM_GO == 1) && (AM_X != 15) && (AM_Y != 0)){ 
  AM_GO = 1; // Текущее направление движения ArduMan. 1=Вправо 
  lcd.createChar(1, ArduMan); // ArduMan смотрит вправо 
  lcd.createChar(2, AM_R_Step_1); // Анимация Шаг 1 
  lcd.createChar(4, ClearChar); // Пустой символ 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  AM_X = AM_X + 1; 
  AM_Y = AM_Y - 1; 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(2); // Индикация текущего символа движения ArduMan 
  delay(Game_Jump_Speed); // Скорость прыжка 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  if (AM_X != 15){ 
  AM_X = AM_X + 1; 
  } 
  if (AM_X != Box_1_X){ 
  AM_Y = AM_Y + 1; 
  } 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(1); // Индикация текущего символа движения ArduMan 
  delay(Game_Jump_Speed); // Скорость прыжка 
  } 
   
  // Прыжок ВЛЕВО 
  if (A3=1)//((ir_code == AM_GO_JUMP) && (AM_GO == 2) && (AM_X != 0) && (AM_Y != 0)){ 
  AM_GO = 2; // Текущее направление движения ArduMan. 2=Влево 
  lcd.createChar(1, AM_Head_Left); // ArduMan смотрит влево 
  lcd.createChar(2, AM_L_Step_1); // Анимация Шаг 1 
  lcd.createChar(4, ClearChar); // Пустой символ 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  AM_X = AM_X - 1; 
  AM_Y = AM_Y - 1; 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(2); // Индикация текущего символа движения ArduMan 
  delay(Game_Jump_Speed); // Скорость прыжка 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на предыдущую позицию ArduMan 
  lcd.write(4); // Стирание символа на предыдущей позиции ArduMan 
  if (AM_X != 0){ 
  AM_X = AM_X - 1; 
  } 
  if (AM_X != Box_1_X){ 
  AM_Y = AM_Y + 1; 
  } 
  lcd.setCursor(AM_X, AM_Y); // Установка курсора на текущей позиции 
  lcd.write(1); // Индикация текущего символа движения ArduMan 
  delay(Game_Jump_Speed); // Скорость прыжка 
   
  } 
   
  irrecv.resume(); 
  } 
   
}
