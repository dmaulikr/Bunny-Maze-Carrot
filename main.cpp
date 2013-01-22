/**************************************************
** Algorithms and Data Structures Assignment 4
** By: Sergio Martins. 100372139
** This program calculates the shortest path from a start location (the bunny) to an end location (the carrot).
**
** Note: a lot of the code contained within this project isn't used. 
** This is because I created just about every search algorithm before I finally got one that found the shortest path
** While the code may not be used, it is still a great example of those algorithms
***************************************************/
#include <iostream>
#include <windows.h>
using namespace std;
#include "mazepraiser.h"
#include "drawing.h"
#include "functions.h"
#include "map.h"
#include "algorithms.h"


int main() {
	//definitions
	Map map = *(new Map); //I do it this way so you work with the actual object instead of a pointer
	
	cout << "Hungry Bunny Emulator";
	system("title Hungry Bunny Emulator");
	
	if (!(loadMaze("maze.txt", map))) {
		//the function will display an error message
		system("pause");
		return -1;
	}
	//constant bunny and carrot start locations
	map.start[0] = map.start[1] = 0;
	map.end[0] = map.end[1] = 15;

	drawLegend(map);
	drawMazeWithBoarder(map);
	drawBunny(map); //the algorithms draw the bunny anyways
	drawCarrot(map);

	//build antisipation
	Sleep(1300);

	//int result = BreadthFirstShortestPath(map);
	//int result = DepthFirstShortestPathAndDisplay(map, 50);

	gotoxy(0, MAP_HEIGHT + 5);
	cout << "Calculating shortest path... ";
	Sleep(200);
	int result = DijkstrasShortestPathAndDisplay(map, 35);
	gotoxy(0, MAP_HEIGHT + 6);
	cout << "Steps: " << result << endl;
	cout << "Showing path...";
	DijkstrasShortestPathAndDisplayPath(map, 200);

	gotoxy(0, MAP_HEIGHT + 8);
	cout << "Calculating shortest path with 1 block removed... ";
	Map blockMap = calcBlockRemovedShortest(map);
	result = DijkstrasShortestPath(blockMap);
	gotoxy(0, MAP_HEIGHT + 9);
	cout << "Steps with a block removed: " << result << endl;
	cout << "Showing path..." << endl;
	DijkstrasShortestPathAndDisplayPath(blockMap, 170);
	gotoxy(0, MAP_HEIGHT + 11);
	system("pause");
	return 0;
}