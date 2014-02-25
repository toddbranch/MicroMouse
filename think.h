/*
 * think.h
 *
 * Methods that control the flood-fill algorithm:
 *		Decides if a sensor interrupt means a wall
 *		What to do if there is a wall
 *		Updating the `map`
 *
 */

#ifndef THINK_H_
#define THINK_H_

// Use these to describe where a wall (potentially) is, and the next move to make
#define RIGHT 0
#define FRONT 1
#define LEFT  2
#define BACK  3

// NOTE: 2d arrays aer accessed via [row][col]
//			which is the same as [y_loc][x_loc]. PLEASE BE CAREFUL
char map[16][16];

// current x and y location in the maze
char x_loc;
char y_loc;

void init_map();
void wall_detected(char side);
void moved();
char next_move();

#endif /* THINK_H_ */
