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
    DDRB = 0xFF; PORTB = 0x00; 	// Configure port B's 8 pins as outputs, initialize to 0s
    				// Initialize output on PORTB to 0x00
    /* Insert your solution below */
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    while (1) {
	// 1) Read input
	tmpA = PINA & 0x03;
        // 2) Perform computation
	if (tmpA == 0x01) {
	    tmpB = (tmpB & 0xFE) | 0x01;
        } else {
            tmpB = (tmpB & 0xFE);
        }
	PORTB = tmpB;
    }	
    return 0;
}
