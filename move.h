/*
 * move.h
 *
 *	Methods for the basic IO of the mouse, to include:
 *		Motor output
 *		Sensor inputs
 *		Movement
 *
 *  Created on: Feb 22, 2014
 *      Author: Hamza El-Saawy
 *
 */

#ifndef MOVE_H_
#define MOVE_H_

// SFR_16BIT is `extern volatile unsigned in address`
//  or basically a 16 bit register

/*
 * How to move the motors?
 * Certain time period? Voltage=step? Magic?
 * Do we return a successful/not successful value from the move and turn methods
 */

void move(SFR_16BIT left_motor, SFR_16BIT right_motor, char direction) {

}

void turn(SFR_16BIT left_motor, SFR_16BIT right_motor, char direction) {

}

// WHAT ELSE IS NEEDED?

#endif /* MOVE_H_ */
