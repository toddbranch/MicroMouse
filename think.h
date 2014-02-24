/*
 * think.h
 *
 * Methods that control the flood-fill algorithm:
 *		Decides if a sensor interrupt means a wall
 *		What to do if there is a wall
 *		Updating the `map`
 *
 *  Created on: Feb 24, 2014
 *      Author: Hamza El-Saawy
 */

#ifndef THINK_H_
#define THINK_H_

// Use these to describe where a wall (potentially) is, and the next move to make
#define RIGHT 0
#define FRONT 1
#define LEFT  2
#define BACK  3

// QUESTION:  most PC compilers replace `char` with `int` during operation, since they are 32-/64-bit, and working with `int`s is easier for them
//  	the MSP430 has a 16 bit CPU (I think). Does it honor the declaration of char, and save clock cycles and memory?

char map[16][16];

// current x and y location in the maze
char x_loc;
char y_loc;

void wall_detected(char side) {
	// DECIDE IF THE SIGNAL DETECTED CONSTITUTES A WALL OR NOT
	if (true) {
		// CHANGE THE map TO REFLECT THE EXISTANCE OF A WALL
	}

	think();
}

// updates the location after a valid move has been completed
void moved() {

}

// Returns the direction for next move
char next_move() {
	// do stuff. how will this work?
}

#endif /* THINK_H_ */
