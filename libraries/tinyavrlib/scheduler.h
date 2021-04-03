/**
 * Scheduler - Library to schedule time tasks.
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

#ifndef SCHEDULER_H
#define SCHEDULER_H

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

//		Timer Pre-scaling
//		CS02 CS01 CS00 Description
//		---- ---- ---- --------------------------------------------------------
//		0    0    0    No clock source (Timer/Counter stopped)
//		0    0    1    clk I/O / (No prescaling)
//		0    1    0    clk I/O / 8 (From prescaler)
//		0    1    1    clk I/O / 64 (From prescaler)
//		1    0    0    clk I/O / 256 (From prescaler)
//		1    0    1    clk I/O / 1024 (From prescaler)
//		1    1    0    External clock source on T0 pin. Clock on falling edge.
//		1    1    1    External clock source on T0 pin. Clock on rising edge.

#define SCHEDULER_TCCR0B_0000	(0 << CS02) | (0 << CS01) | (0 << CS00)	// No clock source (Timer/Counter stopped)
#define SCHEDULER_TCCR0B_0001	(0 << CS02) | (0 << CS01) | (1 << CS00)	// 1 / 1 - No prescaling
#define SCHEDULER_TCCR0B_0008	(0 << CS02) | (1 << CS01) | (0 << CS00)	// 1 / 8
#define SCHEDULER_TCCR0B_0064	(0 << CS02) | (1 << CS01) | (1 << CS00)	// 1 / 64
#define SCHEDULER_TCCR0B_0256	(1 << CS02) | (0 << CS01) | (0 << CS00)	// 1 / 256
#define SCHEDULER_TCCR0B_1024	(1 << CS02) | (0 << CS01) | (1 << CS00)	// 1 / 1024
#define SCHEDULER_TCCR0B_XT0F	(1 << CS02) | (1 << CS01) | (0 << CS00)	// External clock source on T0 pin. Clock on falling edge.
#define SCHEDULER_TCCR0B_XT0R	(1 << CS02) | (1 << CS01) | (1 << CS00)	// External clock source on T0 pin. Clock on rising edge.

#define SCHEDULER_OCR0A_MIN			9	// Reasonable minimum, roughly 100 ticks/sec. at 1 MHz CPU clock and 1024 pre-scale.
#define SCHEDULER_OCR0A_DEFAULT		97	// Default, gives about 10 ticks per second at 1 MHz CPU clock and 1024 pre-scale.
#define SCHEDULER_OCR0A_MAX			255	// Absolute maximum, roughly 4 ticks/sec. at 1 MHz CPU clock and 1024 pre-scale.

#define SCHEDULER_TCCR0B			SCHEDULER_TCCR0B_1024
#define SCHEDULER_OCR0A				SCHEDULER_OCR0A_DEFAULT

#define SCHEDULER_USERFUNC_NULL		((scheduler_userfunc_p)0)

// ----------------------------------------------------------------------------

typedef struct {
	uint32_t tick;
} scheduler_status;
// NOTE: This structure may be extended in the future.

typedef scheduler_status * scheduler_status_p;

typedef void (*scheduler_userfunc_p)(uint32_t tick);

// EXAMPLE: void my_scheduler_userfunc(uint32_t tick);

typedef void (*scheduler_usertask_p)(scheduler_status_p scheduler);

// EXAMPLE: void my_scheduler_usertask(scheduler_status_p scheduler);

typedef union {
	scheduler_userfunc_p userfunc;
	scheduler_usertask_p usertask;
	void (*userproc)(void);
} scheduler_userproc;

// ----------------------------------------------------------------------------

void scheduler_init(scheduler_userfunc_p);
void scheduler_reinit(uint8_t, uint8_t);
void scheduler_usertask(scheduler_usertask_p usertask, uint8_t counter);
void scheduler_start(void);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
