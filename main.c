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
#define SENSOR_1 (BIT1)
#define SENSOR_2 (BIT2) // how many sensors will there be?
						//  also, what ports support ADC?
#define MOTOR_1 (BIT3)
#define MOTOR_2 (BIT3)

// Ease of access stuff
#define SENSORS (SENSOR_1 | SENSOR_2)  //ADD MORE SENSORS HERE
#define MOTORS  (MOTOR_1 | MOTOR_2)

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


    // Turn on output mode for the motors
    P1DIR = MOTORS; 	// zero out all other values and allow output on motor ports
    P1OUT = 0;			// reset output values

    // Set up pins for sensor input
    P1REN = SENSORS;	// allow for pull-up/down resistors
    				//  P1OUT=0, so sensor inputs have pull down
    P1IFG = 0;		// reset all the interrupt flags
    P1IES = SENSORS;	// set interrupt on rising edge.  WE ALSO NEED TO WORK OUT HOW TO SIGNAL A WAL
    P1IE  = SENSORS;	// enable interrupts on the sensor ports

    __bis_SR(GIE);	// enable general interrupts

    init_map;

	// More stuff here please...

	return 0;
}

/*
 * ISR for sensors
 */
#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void) {

	//DO WE NEED TO ACCOUNT FOR SENSORE BOUNCING????
	switch (P1IFG & SENSORS){
		case SENSOR_1:
			// wall on the right?
			wall_detected(RIGHT);
			break;
		case SENSOR_2:
			// wall on the left?
			wall_detected(LEFT);
			break;
		default:
			// WOULD THIS BE BOTH SIDES?
			// SHOULD WE DISABLE MASKABLE INTERRUPTS DURING THIS ISR?
			break;
	}
}
