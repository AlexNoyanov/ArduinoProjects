/**
 * DebugPin - Simple library for using an I/O pin as debugging signal
 *
 * @author Neven Boyanov
 *
 * This is part of the Tinusaur/TinyAVRLib project.
 *
 * Copyright (c) 2018 Neven Boyanov, The Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Retain in your source code the link http://tinusaur.org to the Tinusaur project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/tinyavrlib
 *
 */

// ============================================================================

#ifndef DEBUGPIN_H
#define DEBUGPIN_H

// ----------------------------------------------------------------------------

#include <avr/io.h>

// ----------------------------------------------------------------------------

#define DEBUGPIN_ENABLED	// DebugPin enabled
// NOTE: Comment/uncomment the above line to disable/enable the DEBUGPIN functionality.
// NOTE: Enabling it might sligtly increasy the timingsof the code, so be careful.
#ifdef DEBUGPIN_ENABLED
#define DEBUGPIN_PORT		PB2 // DebugPin output port
#define DEBUGPIN_INIT()		{ DDRB |= (1 << DEBUGPIN_PORT); DEBUGPIN_LO(); }
#define DEBUGPIN_HI()		PORTB |= (1 << DEBUGPIN_PORT)
#define DEBUGPIN_LO()		PORTB &= ~(1 << DEBUGPIN_PORT)
#define DEBUGPIN_TICK1()		{ DEBUGPIN_HI(); DEBUGPIN_LO(); }	// One tick
#define DEBUGPIN_TICK2()	{ DEBUGPIN_TICK1(); DEBUGPIN_TICK1(); }	// Double tick
#define DEBUGPIN_TICK3()	{ DEBUGPIN_TICK1(); DEBUGPIN_TICK1(); DEBUGPIN_TICK1(); }	// Triple tick
#else
#define DEBUGPIN_PORT		// empty
#define DEBUGPIN_INIT()		// empty
#define DEBUGPIN_HI()		// empty
#define DEBUGPIN_LO()		// empty
#define DEBUGPIN_TICK1()		// empty
#define DEBUGPIN_TICK2()	// empty
#define DEBUGPIN_TICK3()	// empty
#endif

// ============================================================================

#endif
