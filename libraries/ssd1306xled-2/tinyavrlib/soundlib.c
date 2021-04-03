/**
 * Soundlib - Library for playing sounds, the TinyAVRLib Project.
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

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "scheduler.h"
#include "soundlib.h"
#include "soundlib_notes.h"

// ----------------------------------------------------------------------------

soundlib_melody_data_t *soundlib_melody_data_p;
int soundlib_melody_data_size;
int soundlib_melody_data_index;
uint8_t soundlib_melody_volume = 7;

// ----------------------------------------------------------------------------

// Task to be executed by the system scheduler.
void soundlib_scheduler_task(scheduler_status_p);

// ----------------------------------------------------------------------------

void soundlib_init(void) {
	DDRB |= (1 << PB4); // Set the port as output.
	// Configure counter/timer1 for fast PWM on PB4
	/*
	// NOTE: Looks like this mode does not work well for our purpose. It causes PB1 to be "1" all the time.
	// TODO: Remove this after the other mode works.
	GTCCR |= 1 << COM1B1 | 1 << COM1B0;	// Comparator B Mode Select: Set the OC1B output line.
	TCCR1 |= 1 << COM1A1 | 1 << COM1A0;	// Comparator A Output Mode: Set the OC1A output line.
	*/
	GTCCR |= 1 << COM1B1;    // Setup the COM1B1/COM1B0 bits
	GTCCR &= ~(1 << COM1B0); // (these 2 lines cold be optimized into 1)
	TCCR1 &= ~(1 << COM1A1 | 1 << COM1A0);	// Comparator A Output Mode: Set the OC1A output line.
}

// Init the system scheduler with the library task.
// This is necessary to be called if any of the asynchronous mode functions are used.
void soundlib_scheduler() {
	scheduler_usertask(soundlib_scheduler_task, 1);
	// Note: The second argument could be used to specify the tempo.
}

// Starts playing a tone.
// 11 bits: [-----AAA|BBBBBBBB] - AAA=prescale, BBBBBBBB=pitch
// Note: it plays until "stop" is executed.
void soundlib_tone_play(uint16_t tone) {
	tone &= 0x07ff; // Mask the tone part of the data: lower 3+8=11 bits.
	uint8_t sound_prescale = (tone >> 8) + 2; // Cut the prescale part of the note - the higher 3 "AAA" bits.
	TCCR1 = (TCCR1 & 0b11110000) | ((sound_prescale) & 0b00001111);
	uint8_t sound_pitch = tone & 0xff; // Mask the pitch part of the note - the lower 8 "BBBBBBBB" bits.
	OCR1C = sound_pitch;
	uint8_t sound_volume = sound_pitch >> (8 - (soundlib_melody_volume & 7));	// 1...7 (1=lowest)
	OCR1B = sound_volume;
	GTCCR |= (1 << PWM1B);	// Pulse Width Modulator B Enable
}

// Stops playing the tone.
void soundlib_tone_stop(void) {
	GTCCR &= ~(1 << PWM1B);	// Pulse Width Modulator B Disable
}

// 3+1=4 bits: [-AAAB---|--------] - AAA=length, B=dotted
uint8_t soundlib_note_len(uint16_t melody_note) {
	uint8_t len = (melody_note >> 11) & 0x0f; // Get the length part of the note.
	if (!len) len = NOTE_04TH >> 11; // Check if there is a note length info. Set the default.
	uint8_t loops = (1 << (len >> 1)); // Calculate the number of loops.
	if (len & 1) loops += (loops >> 1); // Check if it is a dotted note. Add half length.
	return loops;
}

// NOTE: Synchronous mode function.
void soundlib_melody_play_sync(soundlib_melody_data_t *melody_data, int size, uint8_t volume) {
	soundlib_melody_volume = volume;
	for (int i = 0; i < size; i++) {
		uint16_t melody_note = pgm_read_word(&melody_data[i]); // Read one note from the buffer.
		uint8_t loops = soundlib_note_len(melody_note); // Calculate the number of loops.
		soundlib_tone_play(melody_note); // Start playing the tone.
		while (loops--) _delay_ms(50); // The same as ... for (int j = 0; j < loops; j++) _delay_ms(50);
		soundlib_tone_stop(); // Stop playing the tone.
		_delay_ms(5);
	}
	soundlib_tone_stop();
}

// NOTE: Asynchronous mode function.
void soundlib_melody_resume(soundlib_melody_data_t *melody_data, int size, uint8_t volume, int index) {
	soundlib_melody_volume = volume;
	soundlib_melody_data_size = size;
	soundlib_melody_data_index = index;
	soundlib_melody_data_p = melody_data; // That should be last as it will trigger the start of playing.
}

// NOTE: Asynchronous mode function.
void soundlib_melody_play(soundlib_melody_data_t *melody_data, int size, uint8_t volume) {
	soundlib_melody_resume(melody_data, size, volume, 0); // Start playing from position 0 (zero) in the byffer.
}

// NOTE: Asynchronous mode function.
void soundlib_melody_stop() {
	soundlib_tone_stop(); // Stops playing the tone.
	soundlib_melody_data_p = 0; // Clear the pointer to the melody buffer. That stops the playing.
}

// NOTE: Asynchronous mode function.
int soundlib_melody_pause() {
	soundlib_melody_stop();
	return soundlib_melody_data_index;
}

// Task to be executed by the system scheduler.
// NOTE: Asynchronous mode function.
void soundlib_scheduler_task(scheduler_status_p scheduler) {
	static uint8_t loops;
	if (soundlib_melody_data_p) {
		if (loops == 0) {
			if (soundlib_melody_data_index == soundlib_melody_data_size) soundlib_melody_data_index = 0; // Restart
			uint16_t melody_note = pgm_read_word(&soundlib_melody_data_p[soundlib_melody_data_index]); // Read one note from the buffer.
			loops = soundlib_note_len(melody_note) << 1; // Calculate the number of loops.
			soundlib_tone_play(melody_note);
			soundlib_melody_data_index++;
		} else {
			if (loops == 1) soundlib_tone_stop(); // The last tick - stop the playing, a silence between the notes.
			loops--;
		}
	}
}

// ============================================================================
