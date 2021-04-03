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

// ============================================================================

#ifndef SOUNDLIB_H
#define SOUNDLIB_H

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef const uint16_t soundlib_melody_data_t;

// ----------------------------------------------------------------------------

void soundlib_init(void);
void soundlib_scheduler(void);
void soundlib_tone_play(uint16_t);
void soundlib_tone_stop(void);
void soundlib_melody_play_sync(soundlib_melody_data_t *, int, uint8_t);
void soundlib_melody_resume(soundlib_melody_data_t *, int, uint8_t, int);
void soundlib_melody_play(soundlib_melody_data_t *, int, uint8_t);
void soundlib_melody_stop(void);
int soundlib_melody_pause(void);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
