

class Screen
{
    // Default X and Y screen coordinates:
    int defX = 20;
    int defY = 5;
    // Maximum sizes:
    int maxX = 128;
    int maxY = 32;
    int maxStringValue = 25;                     // Maximum symbols in the string
    
public:
    // Get and set default string coordinates:
    int getDefX();
    int getDefY();
    void setDefX(int valueX);
    void setDefY(int valueY);

    int maxString();
    
    void begin();                         // Setup display
    void printString(char* str, int posX,int posY);
    void printString(char* str);          // Print string with default coordinates
    void drawLoadingAnimation(int tme);
    void clear();
    void printMessage(char* str,int tme); // Print message and delay time
    
};

