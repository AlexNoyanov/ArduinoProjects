/* Blink without Delay
 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 */
 
const int ledPin =  9;      // номер выхода, подключенного к светодиоду
// Variables will change:
int ledState = LOW;             // этой переменной устанавливаем состояние светодиода
long previousMillis = 0;        // храним время последнего переключения светодиода
 
long interval = 1000;           // интервал между включение/выключением светодиода (1 секунда)
 
void setup() {
  // задаем режим выхода для порта, подключенного к светодиоду
  pinMode(ledPin, OUTPUT);     
}
 
void loop()
{
  // здесь будет код, который будет работать постоянно
  // и который не должен останавливаться на время между переключениями светодиода
  unsigned long currentMillis = millis();

  
  //проверяем не прошел ли нужный интервал, если прошел то
  if(currentMillis - previousMillis > interval) {
    // сохраняем время последнего переключения
    previousMillis = currentMillis; 
 
    // если светодиод не горит, то зажигаем, и наоборот
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
 
    // устанавливаем состояния выхода, чтобы включить или выключить светодиод
    digitalWrite(ledPin, ledState);
  }
}

