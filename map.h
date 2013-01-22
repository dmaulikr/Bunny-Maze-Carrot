#ifndef MAP_H
#define MAP_H 

/*
A possition in the map variable is true if a block exists on that spot and false if it is pathable (if no block exists on that spot)
ie. if map[2][14] is false then no block is on coordinate (2,14).
*/

const static int MAP_WIDTH = 16;
const static int MAP_HEIGHT = 16;
const static int INFINITY = (MAP_WIDTH * MAP_HEIGHT) + 1;
const static int MAP_X_OFFSET = 1; //start 1 unit away from the left edge
const static int MAP_Y_OFFSET = 3; //start 3 units away from the top edge
const static char BLOCK_CHAR = char(2); //this is the character that is drawn to represent a block
const static char BUNNY_CHAR = '+';
const static char CARROT_CHAR = '-';


struct Map {

	bool map[MAP_WIDTH][MAP_HEIGHT];
	int start[2]; //x and y coord of the bunny's start location
	int end[2]; //x and y coord of the carrot
};

//Structure for added complexity. This is a band-aid solution for being able to queue coordinates
struct Node {
	int x;
	int y;
};

#endif