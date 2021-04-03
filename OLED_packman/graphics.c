#include <avr/pgmspace.h>

const uint8_t pacman1[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3E, 0x1C,   // 0x0010 (16) pixels
0x0C, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,   // 0x0020 (32) pixels
0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 
};

const uint8_t pacman2[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0x7C,   // 0x0010 (16) pixels
0x7C, 0x38, 0x20, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9,   // 0x0020 (32) pixels
0xF9, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 
};

const uint8_t pacman3[] PROGMEM={
0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC,   // 0x0010 (16) pixels
0xF8, 0xF0, 0xE0, 0x80, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   // 0x0020 (32) pixels
0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF9, 0x79, 0x19, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F,   // 0x0030 (48) pixels
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 
};

const uint8_t pill[] PROGMEM={
0x0E, 0x1F, 0x1F, 0x1F, 0x0E, 
};

