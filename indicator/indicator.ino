#define CLOCK_PIN 2
#define RESET_PIN 3
 
/*
 * Функция resetNumber обнуляет текущее значение 
 * на счётчике
 */
void resetNumber()
{
    // Для сброса на мгновение ставим контакт
    // reset в HIGH и возвращаем обратно в LOW
    digitalWrite(RESET_PIN, HIGH);
    digitalWrite(RESET_PIN, LOW);
}
 
/*
 * Функция showNumber устанавливает показания индикаторов
 * в заданное неотрицательное число `n` вне зависимости
 * от предыдущего значения
 */
void showNumber(int n)
{
    // Первым делом обнуляем текущее значение
    resetNumber();
 
    // Далее быстро «прокликиваем» счётчик до нужного
    // значения
    while (n--) {
        digitalWrite(CLOCK_PIN, HIGH);
        digitalWrite(CLOCK_PIN, LOW);
    }
}
 
void setup()
{
    pinMode(RESET_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
 
    // Обнуляем счётчик при старте, чтобы он не оказался
    // в случайном состоянии
    resetNumber();
}
 
void loop()
{
    // Получаем количество секунд в неполной минуте
    // с момента старта и выводим его на индикаторы
    showNumber((millis() / 1000) % 60);
    delay(1000);
}
