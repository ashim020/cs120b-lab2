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
    DDRC = 0xFF; PORTC = 0x00; 	// Configure port B's 8 pins as outputs, initialize to 0s
    				// Initialize output on PORTB to 0x00
    /* Insert your solution below */
    unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char cntavail = 0x00;
    while (1) {
	cntavail = ((PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) + ((PINA & 0x02) >> 1) + (PINA & 0x01);
	tmpC = 4 - cntavail;
	if (tmpC == 0x00) {
	    tmpC = (tmpC | 0x80);
	}
	PORTC = tmpC;
    }	
    return 0;
}
