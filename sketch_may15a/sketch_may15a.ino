 // Моторы подключаются к клеммам M1+,M1-,M2+,M2-  
    // Motor shield использует четыре контакта 6,5,7,4 для управления моторами 
     
    #define SPEED_LEFT      6
    #define SPEED_RIGHT     5 
    #define DIR_LEFT        7
    #define DIR_RIGHT       4
     
    void go(int speed, bool reverseLeft, bool reverseRight, int duration)
    {
        // Для регулировки скорости `speed` может принимать значения от 0 до 255,
        // чем болше, тем быстрее. 
        analogWrite(SPEED_LEFT, speed);
        analogWrite(SPEED_RIGHT, speed);
        digitalWrite(DIR_LEFT, reverseLeft ? LOW : HIGH); 
        digitalWrite(DIR_RIGHT, reverseRight ? LOW : HIGH); 
        delay(duration); 
    }
     
    void setup() 
    {
        // Настраивает выводы платы 4,5,6,7 на вывод сигналов 
        for(int i = 5; i <= 8; i++)     
            pinMode(i, OUTPUT);  
    } 
     
    void loop() 
    { 
        // Задержка 5 секунд после включения питания 
        delay(5000); 
     
        // Cекуда с небольшим вперёд 
        go(150, false, false, 1100);
     
        // Разворот на 180 градусов  
        go(125, true, false, 1350);
     
        // Две секуды с небольшим вперёд 
        go(150, false, false, 2200);
     
        // Разворот на 180 градусов в другую сторону 
        go(125, false, true, 1300);
     
        // Cекуда с небольшим вперёд 
        go(150, false, false, 1200);
     
        // Поворот на 90 градусов 
        go(125, true, false, 680);
     
        // Медленно назад полторы секунды 
        go(100, true, true, 1500);
     
        // Остановка до ресета или выключения питания 
        go(0, false, false, 0);
     
        // Всё, приехали
        while (true)
            ; 
    }
