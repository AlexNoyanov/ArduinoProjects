//#include <SPI.h>
//#include <MFRC522.h>
//
//#define SS_PIN 10
//#define RST_PIN 9
// 
//MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
//
//MFRC522::MIFARE_Key key; 
//
//void setup() {
//  // put your setup code here, to run once:
//Serial.begin(9600);
//  SPI.begin(); // Init SPI bus
//  rfid.PCD_Init(); // Init MFRC522 
//
//  for (byte i = 0; i < 6; i++) {
//    key.keyByte[i] = 0xFF;
//  }
//
//  Serial.println(F("This code scan the MIFARE Classsic NUID."));
//  Serial.print(F("Using the following key:"));
//  //printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//byte byteCount;
//
//byte buffer[18];
//
//byteCount = sizeof(buffer);
//
//status = mfrc522.MIFARE_Read(4, buffer, &byteCount);
//
//if (status != mfrc522.STATUS_OK) {
//
//    Serial.print("MIFARE_Read() failed: ");
//
//    Serial.println(mfrc522.GetStatusCodeName(status));
//
//}
//
//}


/* Дмитрий Осипов. http://www.youtube.com/user/d36073?feature=watch

v.01 Arduino Метро Единый билет RC522 Card Read Module RFID

Version 0.1 2014/06/08

====================================

бесконтактные билеты для прохода в метро.

читаем данные с бумажного билета "Единый" –

бумажный (билет / карта / проездной) на метро,

который теперь действует и на наземном транспорте.

----------------

Печатаем в serial монитор информацию о карте:

1) тип карты

2) Card UID — уникальный идентификатор карты (суть серийный номер).

3) Номер билета (который отпечатан на нем).

4) Дата выдачи билета.

5) Срок действия в днях.

6) количество оставшихся поездок.

------------------

Базовый принцип действия В карточке и в считывателе есть антенны,

при этом сигнал считывающего устройства (суть электромагнитное поле)

одновременно служит источником

питания для карточки. Т.е. и в части энергетики, и в части передачи

данных это очень похоже на беспроводные зарядки.

--------------------

что нам понадобится:

1) Arduino.

2) RC522 Card Read Module

Mifare RC522 Card Read Module Tags SPI Interface Read and Write.

http://www.ebay.com/itm/321297386758

— Поддерживаемые типы карт: MIFARE S50, MIFARE S70,

MIFARE UltraLight, MIFARE Pro, MIFARE DESfire.

! Напряжение / питание: 3.3 v.

3) Библиотека "RFID", для RC522.

Скачать http://yadi.sk/d/6XLMLCuxSjdGa

-----------------------------

Скачать sketch.

v.01 Arduino Метро Единый билет RC522 Card Read Module RFID

----------------------------

Подробную видео инструкцию выложу здесь.

v.01 Arduino Метро Единый билет RC522 Card Read Module RFID

============================================

Благодарю человека (имя не знаю), за статью,

Считыватель карточек RFID RC522 в домашнем хозяйстве.

http://mysku.ru/blog/aliexpress/23114.html

*/

#include <SPI.h>

#include <MFRC522.h> // это скачанная библиотека "RFID".

/*

подключение для Arduino Uno и Mega, производится к разным Pin!

----------------------------------------------------- Nicola Coppola

* Pin layout should be as follows:

* Signal Pin Pin Pin

* Arduino Uno Arduino Mega MFRC522 board

* ------------------------------------------------------------

* Reset 9 5 RST

* SPI SS 10 53 SDA

* SPI MOSI 11 51 MOSI

* SPI MISO 12 50 MISO

* SPI SCK 13 52 SCK

*/

// два Pin (SS и RST) допускают произвольное подключение и конфигурируются в коде.

// !(SS - он же - SDA).

#define SS_PIN 10

#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // объект MFRC522

unsigned long uidDec, uidDecTemp; // для отображения номера карточки в десятичном формате.

byte bCounter, readBit;

unsigned long ticketNumber;

void setup() {

Serial.begin(9600);

SPI.begin(); // инициализация SPI.

mfrc522.PCD_Init(); // инициализация MFRC522.

Serial.println("Prilozhite kartu / Waiting for card...");

}

void loop() {

// Поиск новой карточки.

if ( ! mfrc522.PICC_IsNewCardPresent()) {

return;

}

// Выбор карточки.

if ( ! mfrc522.PICC_ReadCardSerial()) {

return;

}

uidDec = 0;

Serial.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");

Serial.println("================================================");

// Выдача серийного номера карточки.

Serial.println("Serijnyj nomer karty / Card UID: ");
