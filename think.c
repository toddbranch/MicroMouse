#include "think.h"

// QUESTION:  most PC compilers replace `char` with `int` during operation, since they are 32-/64-bit, and working with `int`s is easier for them
//  	the MSP430 has a 16 bit CPU (I think). Does it honor the declaration of char, and save clock cycles and memory?

// set up the map with all the values
void init_map() {
	char value;
	for (char x = 0; x < 8; x++) {
		for (char y = 0; y < 8; y++) {
			// symmetrically iterate through the map
			value = 14 - (x + y);
			map[y][x]= value;
			map[15-y][x]= value;
			map[y][15-x]= value;
			map[15-y][15-x]= value;
		}
	}
	x_loc = 0;
	y_loc = 0;
}

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
