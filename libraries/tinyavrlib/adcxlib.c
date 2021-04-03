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

#include <stdint.h>
#include <avr/io.h>

#include "adcxlib.h"

// ----------------------------------------------------------------------------

void adcx_init(void) {
	// ---- Initialize ADC ----
	ADMUX =
	    // x00 - Vcc used as Voltage Reference, disconnected from PB0 (AREF).
	    // 010 - Internal 1.1V Voltage Reference.
	    // 110 - Internal 2.56V Voltage Reference without external bypass capacitor, disconnected from PB0 (AREF).
	    (1 << REFS2) | (1 << REFS1) | (0 << REFS0) |
	    (0 << ADLAR);	// Set/Clear left shift result
	ADCSRA =
	    (1 << ADEN) |	// Enable ADC
	    (1 << ADATE) |	// Enable auto trigger enable
		// (1 << ADIE) |	// Enable ADC interrupt
	    // Setup ADC Prescaler
	    // 001=1: 1/2nd ... 1MHz / 2 = 500KHz
	    // 011=3: 1/8th ... 1MHz / 8 = 125KHz
	    // 111=7: 1/128th ... 1MHz / 128 = 7812Hz
	    (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	// Set prescaler
	ADCSRB =
	    (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);	// Set mode, 000 = free running mode
}

void adcx_select(uint8_t mask) {
	ADMUX = (ADMUX & 0b11110000) | mask;
}

void adcx_start(void) {
	ADCSRA |= (1 << ADSC);	// Set start conversions
}

uint16_t adcx_read(void) {
	union adcx_result {
		uint16_t data16;
		struct {
			uint8_t lo;
			uint8_t hi;
		};
	} adcx_result;
	adcx_result.lo = ADCL;
	adcx_result.hi = ADCH;
	return adcx_result.data16;
}

// ============================================================================
