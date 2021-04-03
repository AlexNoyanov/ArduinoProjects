/**
 * ADCxLib - Simple library to work with ADC
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

#ifndef ADCXLIB_H
#define ADCXLIB_H

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

#define ADCX_SELECT_MASK_ADC0	0b0000	// PB5
#define ADCX_SELECT_MASK_ADC1	0b0001	// PB2
#define ADCX_SELECT_MASK_ADC2	0b0010	// PB4
#define ADCX_SELECT_MASK_ADC3	0b0011	// PB3
#define ADCX_SELECT_MASK_ADC4	0b1111	// Internal temperature sensor

// ----------------------------------------------------------------------------

void adcx_init(void);
void adcx_select(uint8_t mask);
void adcx_start(void);
uint16_t adcx_read(void);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
