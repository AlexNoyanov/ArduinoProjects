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

#include "buffio.h"

// ----------------------------------------------------------------------------

// NOTE: Used only during development.
// #include <stdio.h>
// #define DEBUGGING_PRINT_CHAR(ch) putchar(ch)

// ----------------------------------------------------------------------------

static int8_t buffio_head = 0;
static int8_t buffio_tail = 0;
static char *buffio_kwd_crlf = "\r\n";
static char buffio_data[BUFFIO_DATA_SIZE];

// ----------------------------------------------------------------------------

void buffio_init(void) {
	buffio_reset();
	
	// This is not necessary, at all. Should be removed.
	// for (int i = 0; i < sizeof (buffio_data); i++) buffio_data[i] = 0;
}

void buffio_reset(void) {
	buffio_head = buffio_tail = 0;	// This isn't really necessary except in some specific cases.
}

char buffio_put(char ch) {
	buffio_data[buffio_head & BUFFIO_DATA_MASK] = ch;
	buffio_head++;
	return ch;
}

char buffio_get() {
	if (buffio_head - buffio_tail > BUFFIO_DATA_MASK)	  {
		buffio_tail = buffio_head - BUFFIO_DATA_MASK - 1;
	}
	char ch = buffio_data[buffio_tail & BUFFIO_DATA_MASK];
	buffio_tail++;
	return ch;
}

/* char buffio_read() {
	return buffio_data[buffio_tail & BUFFIO_DATA_MASK];
} */

#define BUFFIO_HAS_MORE() (buffio_head != buffio_tail)
int buffio_has_more() { return BUFFIO_HAS_MORE(); }

// ----------------------------------------------------------------------------

void buffio_skip_until(char *kw) {
	char *kwp = kw;
	for (;;) {
		uint8_t ch = buffio_ids_receive();	// Receive 1 byte of data. (This may wait for the data to come)
		// Note: Received data is not stored.
		// DEBUGGING_PRINT_CHAR(ch);
		// Check for the keyword.
		if (*kwp != ch) kwp = kw;
		if (*kwp == ch) kwp++;
		if (*kwp == '\0') return;
	}
}

void buffio_receive_until(char *kw) {
	char *kwp = kw;
	for (;;) {
		uint8_t ch = buffio_put(buffio_ids_receive());	// Receive and store 1 byte of data.
		// DEBUGGING_PRINT_CHAR(ch);
		// Check for the keyword.
		if (*kwp != ch) kwp = kw;
		if (*kwp == ch) kwp++;
		if (*kwp == '\0') return;
	}
}

void buffio_receive_untilln(char *kwd) {
	buffio_receive_until(kwd);	// Receiving until a keyword is found.
	buffio_receive_until(buffio_kwd_crlf);	// Receiving until a CR/LF is found.
}

int8_t buffio_receive_until2(char *kw1, char *kw2) {
	char *kw1p = kw1;
	char *kw2p = kw2;
	for (;;) {
		uint8_t ch = buffio_put(buffio_ids_receive());	// Receive and store 1 byte of data.
		// NOTE: This may wait for the data to come)
		// DEBUGGING_PRINT_CHAR(ch);
		// Check for the keyword #1.
		if (*kw1p != ch) kw1p = kw1;
		if (*kw1p == ch) kw1p++;
		if (*kw1p == '\0') return 1;
		// Check for the keyword #2.
		if (*kw2p != ch) kw2p = kw2;
		if (*kw2p == ch) kw2p++;
		if (*kw2p == '\0') return 2;
	}
}

int8_t buffio_receive_until2ln(char *kw1, char *kw2) {
	int8_t result = buffio_receive_until2(kw1, kw2);	// Receiving until a keyword is found.
	buffio_receive_until(buffio_kwd_crlf);	// Receiving until a CR/LF is found.
	return result;
}

// ============================================================================
