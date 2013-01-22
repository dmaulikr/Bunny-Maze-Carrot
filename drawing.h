#include <iostream>
using namespace std;
#include "map.h"
#include "functions.h"

#ifndef MAZEDRAWER_H
#define MAZEDRAWER_H 

void drawLine(Map &map, int line) {
	for (int i = 0; i < MAP_WIDTH; i++)
		if (map.map[i][line] == true)
			cout << BLOCK_CHAR;
		else
			cout << " ";
};

/* UNUSED
void drawMaze(Map &map) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		drawLine(map, i);
		cout << endl;
	}
};
*/

void drawMazeWithBoarder(Map &map) {

	//darw top boarder
	gotoxy(MAP_X_OFFSET, MAP_Y_OFFSET);
	for (int i = 0; i < MAP_WIDTH + 2; i++)
		cout << BLOCK_CHAR;

	//draw left & right boarders
	for (int i = 0; i < MAP_HEIGHT; i++) {
		gotoxy(MAP_X_OFFSET, MAP_Y_OFFSET + i + 1);
		cout << BLOCK_CHAR;
		gotoxy(MAP_X_OFFSET + MAP_WIDTH + 1, MAP_Y_OFFSET + i + 1);
		cout << BLOCK_CHAR;
	}


	//draw bottom boarder
	gotoxy(MAP_X_OFFSET, MAP_Y_OFFSET + MAP_HEIGHT + 1);
	for (int i = 0; i < MAP_WIDTH + 2; i++)
		cout << BLOCK_CHAR;

	//draw the map line-by-line with the x and y offsets
	for (int i = 0; i < MAP_HEIGHT; i++) {
		gotoxy(MAP_X_OFFSET + 1, MAP_Y_OFFSET + i + 1);
		drawLine(map, i);
	}

	gotoxy(MAP_X_OFFSET, MAP_Y_OFFSET + MAP_HEIGHT + 2);
};

void drawBunny(Map &map) {
	gotoxy(map.start[0] +  MAP_X_OFFSET + 1, map.start[1] + MAP_Y_OFFSET + 1); //+1 to compensate for the boarder
	cout << BUNNY_CHAR;
};

void drawBunny(int x, int y) {
	gotoxy(x +  MAP_X_OFFSET + 1, y + MAP_Y_OFFSET + 1); //+1 to compensate for the boarder
	cout << BUNNY_CHAR;
};

void drawCarrot(Map &map) {
	gotoxy(map.end[0] + MAP_X_OFFSET + 1, map.end[1] + MAP_Y_OFFSET + 1);
	cout << CARROT_CHAR;
};

void eraseBunny(Map &map) {
	gotoxy(map.start[0] +  MAP_X_OFFSET + 1, map.start[1] + MAP_Y_OFFSET + 1); //+1 to compensate for the boarder
	cout << " ";
};

void eraseCarrot(Map &map) {
	gotoxy(map.end[0] + MAP_X_OFFSET + 1, map.end[1] + MAP_Y_OFFSET + 1);
	cout << " ";
};

void drawLegend(Map &map) {
	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 0);
	cout << " Legend";
	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 1);
	cout << "--------";
	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 2);
	cout << BUNNY_CHAR << " Bunny";
	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 3);
	cout << CARROT_CHAR << " Carrot";
}

#endif