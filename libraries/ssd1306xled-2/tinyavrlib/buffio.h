/**
 * BUFFIO - Functions to handle cyclic buffered input/output.
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

#ifndef BUFFIO_H
#define BUFFIO_H

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

// Data SIZE/MASK:
//	  8/0b00000111
//	 16/0b00001111
//	 32/0b00011111
//	 64/0b00111111
#define BUFFIO_DATA_SIZE	64
#define BUFFIO_DATA_MASK	0b00111111

// ----------------------------------------------------------------------------

// The following functions must be implemented by the application

int buffio_ids_has_more(void);
uint8_t buffio_ids_receive(void);

// ----------------------------------------------------------------------------

void buffio_init(void);
void buffio_reset(void);
char buffio_put(char);
char buffio_get(void);
int buffio_has_more(void);
void buffio_skip_until(char *);
void buffio_receive_until(char *);
void buffio_receive_untilln(char *);
int8_t buffio_receive_until2(char *, char *);
int8_t buffio_receive_until2ln(char *, char *);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
