/*
 *  main.c
 *
 *	Someone should comment this project
 *
 *  Created on: Feb 22, 2014
 *      Author: Hamza El-Saawy
 *
 */

#include <msp430.h>
#include "move.h"
#include "think.h"

// HERE BE LOCATIONS OF THE MOTORS AND SENSORES
// for now, sensor 1 is on the right, and sensor 2 is on the left.  beware of directionality
#define SENSOR1 (BIT1)
#define SENSOR2 (BIT2) 	// how many sensors will there be?
						//  also, what ports support ADC?
#define MOTOR1 (BIT3)
#define MOTOR2 (BIT3)

// Ease of access stuff
#define INPUTS   (SENSOR1 | SENSOR2)
#define OUTPUTS  (MOTOR1 | MOTOR2)

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


    // Turn on output mode for the motors
    P1DIR = OUTPUTS; 	// zero out all other values and allow output on motor ports
    P1OUT = 0;			// reset output values

    // Set up pins for sensor input
    P1REN = INPUTS;	// allow for pulup/down resistors
    				//  P1OUT=0, so sensor inputs have pull down
    P1IFG = 0;		// reset all the interrupt flags
    P1IES = INPUTS;	// set interrupt on rising edge.  WE ALSO NEED TO WORK OUT HOW TO SIGNAL A WAL
    P1IE  = INPUTS;	// enable interrupts on the sensor ports

    __bis_SR(GIE);	// enable general interrupts

	// More stuff here please...

	return 0;
}

/*
 * Interupts primaily by
 */
#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void) {

	//DO WE NEED TO ACCOUNT FOR SENSORE BOUNCING????
	if (P1IFG & SENSOR1) {
		// sensor 1 detected something...
		wall_detected(RIGHT);
	} else if (P1IFG & SENSOR2) {
		// sensor 2 detected something...
		wall_detected(LEFT);
	} else {
		// false alarm?

	}
}
