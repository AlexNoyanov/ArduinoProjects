/**
 * Soundlib - Library for playing sounds.
 *
 * @author Neven Boyanov
 *
 * This is part of the Tinusaur/TinyAVRLib project.
 *
 * Copyright (c) 2017 Neven Boyanov, The Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Retain in your source code the link http://tinusaur.org to the Tinusaur project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/tinyavrlib
 *
 */

// ----------------------------------------------------------------------------

#ifndef SOUNDLIB_NOTES_H
#define SOUNDLIB_NOTES_H

// ----------------------------------------------------------------------------

// Suffixes:
// N - natural
// S - Sharp ♯
// F - Flat ♭

// #define	NOTE_A0N	((8 << 8) | 142)	// NOTE: Do not use these notes so the higher 5 bits
// #define	NOTE_A0S	((8 << 8) | 134)	//       are available for other purposes, e.g. length.
#define	NOTE_B0N	((7 << 8) | 253)
#define	NOTE_C0N	((7 << 8) | 239)
#define	NOTE_C0S	((7 << 8) | 225)
#define	NOTE_D0N	((7 << 8) | 213)
#define	NOTE_D0S	((7 << 8) | 201)
#define	NOTE_E0N	((7 << 8) | 190)
#define	NOTE_F0N	((7 << 8) | 179)
#define	NOTE_F0S	((7 << 8) | 169)
#define	NOTE_G0N	((7 << 8) | 159)
#define	NOTE_G0S	((7 << 8) | 150)
#define	NOTE_A1N	((7 << 8) | 142)
#define	NOTE_A1S	((7 << 8) | 134)
#define	NOTE_B1N	((6 << 8) | 253)
#define	NOTE_C1N	((6 << 8) | 239)
#define	NOTE_C1S	((6 << 8) | 225)
#define	NOTE_D1N	((6 << 8) | 213)
#define	NOTE_D1S	((6 << 8) | 201)
#define	NOTE_E1N	((6 << 8) | 190)
#define	NOTE_F1N	((6 << 8) | 179)
#define	NOTE_F1S	((6 << 8) | 169)
#define	NOTE_G1N	((6 << 8) | 159)
#define	NOTE_G1S	((6 << 8) | 150)
#define	NOTE_A2N	((6 << 8) | 142)
#define	NOTE_A2S	((6 << 8) | 134)
#define	NOTE_B2N	((5 << 8) | 253)
#define	NOTE_C2N	((5 << 8) | 239)
#define	NOTE_C2S	((5 << 8) | 225)
#define	NOTE_D2N	((5 << 8) | 213)
#define	NOTE_D2S	((5 << 8) | 201)
#define	NOTE_E2N	((5 << 8) | 190)
#define	NOTE_F2N	((5 << 8) | 179)
#define	NOTE_F2S	((5 << 8) | 169)
#define	NOTE_G2N	((5 << 8) | 159)
#define	NOTE_G2S	((5 << 8) | 150)
#define	NOTE_A3N	((5 << 8) | 142)
#define	NOTE_A3S	((5 << 8) | 134)
#define	NOTE_B3N	((4 << 8) | 253)
#define	NOTE_C3N	((4 << 8) | 239)
#define	NOTE_C3S	((4 << 8) | 225)
#define	NOTE_D3N	((4 << 8) | 213)
#define	NOTE_D3S	((4 << 8) | 201)
#define	NOTE_E3N	((4 << 8) | 190)
#define	NOTE_F3N	((4 << 8) | 179)
#define	NOTE_F3S	((4 << 8) | 169)
#define	NOTE_G3N	((4 << 8) | 159)
#define	NOTE_G3S	((4 << 8) | 150)
#define	NOTE_A4N	((4 << 8) | 142)
#define	NOTE_A4S	((4 << 8) | 134)
#define	NOTE_B4N	((3 << 8) | 253)
#define	NOTE_C4N	((3 << 8) | 239)
#define	NOTE_C4S	((3 << 8) | 225)
#define	NOTE_D4N	((3 << 8) | 213)
#define	NOTE_D4S	((3 << 8) | 201)
#define	NOTE_E4N	((3 << 8) | 190)
#define	NOTE_F4N	((3 << 8) | 179)
#define	NOTE_F4S	((3 << 8) | 169)
#define	NOTE_G4N	((3 << 8) | 159)
#define	NOTE_G4S	((3 << 8) | 150)
#define	NOTE_A5N	((3 << 8) | 142)
#define	NOTE_A5S	((3 << 8) | 134)
#define	NOTE_B5N	((2 << 8) | 253)
#define	NOTE_C5N	((2 << 8) | 239)
#define	NOTE_C5S	((2 << 8) | 225)
#define	NOTE_D5N	((2 << 8) | 213)
#define	NOTE_D5S	((2 << 8) | 201)
#define	NOTE_E5N	((2 << 8) | 190)
#define	NOTE_F5N	((2 << 8) | 179)
#define	NOTE_F5S	((2 << 8) | 169)
#define	NOTE_G5N	((2 << 8) | 159)
#define	NOTE_G5S	((2 << 8) | 150)
#define	NOTE_A6N	((2 << 8) | 142)
#define	NOTE_A6S	((2 << 8) | 134)
#define	NOTE_B6N	((1 << 8) | 253)
#define	NOTE_C6N	((1 << 8) | 239)
#define	NOTE_C6S	((1 << 8) | 225)
#define	NOTE_D6N	((1 << 8) | 213)
#define	NOTE_D6S	((1 << 8) | 201)
#define	NOTE_E6N	((1 << 8) | 190)
#define	NOTE_F6N	((1 << 8) | 179)
#define	NOTE_F6S	((1 << 8) | 169)
#define	NOTE_G6N	((1 << 8) | 159)
#define	NOTE_G6S	((1 << 8) | 150)
#define	NOTE_A7N	((1 << 8) | 142)
#define	NOTE_A7S	((1 << 8) | 134)
#define	NOTE_B7N	((1 << 8) | 127)
#define	NOTE_C7N	((1 << 8) | 119)
#define	NOTE_C7S	((1 << 8) | 113)
#define	NOTE_D7N	((1 << 8) | 106)
#define	NOTE_D7S	((1 << 8) | 100)
#define	NOTE_E7N	((1 << 8) | 95)
#define	NOTE_F7N	((1 << 8) | 89)
#define	NOTE_F7S	((1 << 8) | 84)
#define	NOTE_G7N	((1 << 8) | 80)
#define	NOTE_G7S	((1 << 8) | 75)
#define	NOTE_A8N	((1 << 8) | 71)

// ----------------------------------------------------------------------------

/*
    values range (5-bits) 0..31

    code         ticks         name                  short code
    -----------  ------------  -----------------     ----------
    111,1=0x0F   192 (128+64)  long-dotted           04XD
    111,0=0x0E   128           long                  04XL
    110,1=0x0D    96 (64+32)   double-dotted         02XD
    110,0=0x0C    64           double                02XL
    101,1=0x0B    48 (32+16)   whole-dotted          01XD
    101,0=0x0A    32           whole                 01XL
    100,1=0x09    24 (16+8)    half-dotted           02TD
    100,0=0x08    16           half                  02TH
    011,1=0x07    12 (8+4)     quarter-dotted        04TD
    011,0=0x06     8           quarter               04TH
    010,1=0x05     6 (4+2)     eighth-dotted         08TD
    010,0=0x04     4           eighth                08TH
    001,1=0x03     3 (2+1)     sixteenth-dotted      16TD
    001,0=0x02     2           sixteenth             16TH
    000,1=0x01     1           thirty-second-dotted  32TD
    000,0=0x00   ---           default               DEF
*/

#define NOTE_04XD (0x0F << 11)	// long-dotted
#define NOTE_04XL (0x0E << 11)	// long
#define NOTE_02XD (0x0D << 11)	// double-dotted
#define NOTE_02XL (0x0C << 11)	// double
#define NOTE_01XD (0x0B << 11)	// whole-dotted
#define NOTE_01XL (0x0A << 11)	// whole
#define NOTE_02TD (0x09 << 11)	// half-dotted
#define NOTE_02TH (0x08 << 11)	// half
#define NOTE_04TD (0x07 << 11)	// quarter-dotted
#define NOTE_04TH (0x06 << 11)	// quarter
#define NOTE_08TD (0x05 << 11)	// eighth-dotted
#define NOTE_08TH (0x04 << 11)	// eighth
#define NOTE_16TD (0x03 << 11)	// sixteenth-dotted
#define NOTE_16TH (0x02 << 11)	// sixteenth
#define NOTE_32TD (0x01 << 11)	// thirty-second-dotted
#define NOTE_DEF  (0x00 << 11)	// The default note length

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------
