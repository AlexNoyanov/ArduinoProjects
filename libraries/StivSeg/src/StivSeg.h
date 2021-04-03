#ifndef StivSeg_h
#define StivSeg_h

#include "Arduino.h"

class StivSeg {
    public:
        StivSeg(int numD, int dp[], int sp[], bool isCath);
        writeInt(int n);
        writeFloat(float n);
        clear();
        
    private:
        int numDigits;
        int digitPins[4];
        int segPins[8];
        bool isComCathode;
        bool SYMBOL[11][7] = {
        //A     B      C     D     E     F     G
        {true, true, true, true, true, true, false},    //0
        {false, true, true, false, false, false, false},//1
        {true, true, false, true, true, false, true},   //2
        {true, true, true, true, false, false, true},   //3
        {false, true, true, false, false, true, true},  //4
        {true, false, true, true, false, true, true},   //5
        {true, false, true, true, true, true, true},    //6
        {true, true, true, false, false, false, false}, //7
        {true, true, true, true, true, true, true},     //8
        {true, true, true, false, false, true, true},   //9
        //{true, true, true, false, true, true, true},    //A
        //{false, false, true, true, true, true, true},   //b
        //{true, false, false, true, true, true, false},  //C
        //{false, true, true, true, true, false, true},   //d
        //{true, false, false, true, true, true, true},   //E
        //{true, false, false, false, true, true, true},  //F
        {false, false, false, false, false, false, false} //blank
        }; 
};

#endif