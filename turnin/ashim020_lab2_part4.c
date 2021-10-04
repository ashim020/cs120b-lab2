/*	Author: Andrew Shim
 * 	Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #0
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; 	// Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF;	// Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; 	// Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00;	// Configure port D's 8 pins as outputs

    /* Insert your solution below */
    unsigned char tmpA = 0x00;		// Temporary variable to hold the value of A
    unsigned char tmpB = 0x00;		// Temporary variable to hold the value of B
    unsigned char tmpC = 0x00;		// Temporary variable to hold the value of C
    unsigned char tmpD0 = 0x00;		// Temporary variable to hold the value of D0
    unsigned char tmpD1 = 0x00;		// Temporary variable to hold the value of D1
    unsigned short weight = 0x00;	// Temporary variable to hold the weight
    unsigned char finalD = 0x00;	// Temporary variable to hold the final value of D
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	weight = tmpA + tmpB + tmpC;
	if (weight > 0x8C) {
	    tmpD0 = 0x01;
	} else {
	    tmpD0 = 0x00;
	}
	if (((tmpA - tmpC) > 0x50) || ((tmpC - tmpA) > 0x50)) {
	    tmpD1 = 0x02;
	} else {
	    tmpD1 = 0x00;
	}
	finalD = (weight & 0x00FC) | tmpD1 | tmpD0;
	PORTD = finalD;
    }
    return 0;
}
