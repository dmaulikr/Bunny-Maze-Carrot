#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#include "map.h"
#include "drawing.h"
#include "functions.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

//Originally for debugging, but I left it in for fun
int counttimes = 0;
void PrintCount() {
	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 6);
	cout << "Iterations: " << ++counttimes;
};

bool Exists(vector<Node> Vec, Node node) {
	for (unsigned int i = 0; i < Vec.size(); i++) {
		if ((Vec[i].x == node.x) && (Vec[i].y == node.y)) //couldn't figure out how to compare the actual objects.
			return true;
	}
	return false;
};

int DijkstrasShortestPath(Map map) {
	//Mostly Dijkstra's shortest path algorithm, but not quite.
	vector<Node> Q;
	Node tempNode;
	Node neighbourNode;
	int weight[MAP_WIDTH][MAP_HEIGHT];
	bool found[MAP_WIDTH][MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			found[i][j] = false;
			weight[i][j] = INFINITY;
		}
	}
	//initial stuff
	weight[map.start[0]][map.start[1]] = 0;
	found[map.start[0]][map.start[1]] = true;
	tempNode.x = map.start[0];
	tempNode.y = map.start[1];
	Q.push_back(tempNode);


	while (!Q.empty()) {
		tempNode = Q.front(); //take a node off the queue
		Q.erase(Q.begin());

		//if we're at the end, exit the loop
		if ((tempNode.x == map.end[0]) && (tempNode.y == map.end[1])) {
			break;
		}

		//check the node to the right
		neighbourNode = tempNode;
		neighbourNode.x++;
		if ((neighbourNode.x < MAP_WIDTH) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet and it's not already in the queue
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the left
		neighbourNode = tempNode;
		neighbourNode.x--;
		if ((neighbourNode.x >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the below
		neighbourNode = tempNode;
		neighbourNode.y++;
		if ((neighbourNode.y < MAP_HEIGHT) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the above
		neighbourNode = tempNode;
		neighbourNode.y--;
		if ((neighbourNode.y >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}

	}
	if (found[map.end[0]][map.end[1]])
		return weight[map.end[0]][map.end[1]];
	return -1;
};

int DijkstrasShortestPathAndDisplay(Map map, int delay) {
	//Mostly Dijkstra's shortest path algorithm, but not quite.
	vector<Node> Q;
	Node tempNode;
	Node neighbourNode;
	int weight[MAP_WIDTH][MAP_HEIGHT];
	bool found[MAP_WIDTH][MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			found[i][j] = false;
			weight[i][j] = INFINITY;
		}
	}
	//initial stuff
	weight[map.start[0]][map.start[1]] = 0;
	found[map.start[0]][map.start[1]] = true;
	tempNode.x = map.start[0];
	tempNode.y = map.start[1];
	Q.push_back(tempNode);


	while (!Q.empty()) {
		tempNode = Q.front(); //take a node off the queue
		Q.erase(Q.begin());

		//draw bunny and wait.
		drawBunny(tempNode.x, tempNode.y);
		Sleep(delay);

		gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 7);
		cout << "Currently on: (" << tempNode.x << ", " << tempNode.y << ")   ";

		//if we're at the end, exit the loop
		if ((tempNode.x == map.end[0]) && (tempNode.y == map.end[1])) {
			break;
		}

		//check the node to the right
		neighbourNode = tempNode;
		neighbourNode.x++;
		if ((neighbourNode.x < MAP_WIDTH) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet and it's not already in the queue
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the left
		neighbourNode = tempNode;
		neighbourNode.x--;
		if ((neighbourNode.x >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the below
		neighbourNode = tempNode;
		neighbourNode.y++;
		if ((neighbourNode.y < MAP_HEIGHT) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the above
		neighbourNode = tempNode;
		neighbourNode.y--;
		if ((neighbourNode.y >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}

	}
	if (found[map.end[0]][map.end[1]])
		return weight[map.end[0]][map.end[1]];
	return -1;
};

int DijkstrasShortestPathAndDisplayPath(Map map, int delay) {
	//Mostly Dijkstra's shortest path algorithm, but not quite.
	vector<Node> Q;
	Node tempNode;
	Node neighbourNode;
	int weight[MAP_WIDTH][MAP_HEIGHT];
	bool found[MAP_WIDTH][MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			found[i][j] = false;
			weight[i][j] = INFINITY;
		}
	}
	//initial stuff
	weight[map.start[0]][map.start[1]] = 0;
	found[map.start[0]][map.start[1]] = true;
	tempNode.x = map.start[0];
	tempNode.y = map.start[1];
	Q.push_back(tempNode);


	while (!Q.empty()) {
		tempNode = Q.front(); //take a node off the queue
		Q.erase(Q.begin());

		//if we're at the end, exit the loop
		if ((tempNode.x == map.end[0]) && (tempNode.y == map.end[1])) {
			break;
		}

		//check the node to the right
		neighbourNode = tempNode;
		neighbourNode.x++;
		if ((neighbourNode.x < MAP_WIDTH) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet and it's not already in the queue
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the left
		neighbourNode = tempNode;
		neighbourNode.x--;
		if ((neighbourNode.x >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the below
		neighbourNode = tempNode;
		neighbourNode.y++;
		if ((neighbourNode.y < MAP_HEIGHT) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the above
		neighbourNode = tempNode;
		neighbourNode.y--;
		if ((neighbourNode.y >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!found[neighbourNode.x][neighbourNode.y]) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			//we calculate the distance for our neighbour
			weight[neighbourNode.x][neighbourNode.y] = min(weight[tempNode.x][tempNode.y] + 1, weight[neighbourNode.x][neighbourNode.y]); //the new weight or it's current weight, whichever is less
			found[neighbourNode.x][neighbourNode.y] = true;
			Q.push_back(neighbourNode); //add it to the queue
		}

	}

	//display the shortest path. We'll be starting from the end and going backwards
	drawMazeWithBoarder(map); //draw blank map
	Q.clear(); 
	vector<Node> stack; //to draw the points in the correct order we should use a stack. O well.
	tempNode.x = map.end[0];
	tempNode.y = map.end[1];
	Q.push_back(tempNode);
	int least;

	while (!((tempNode.x == map.start[0]) && (tempNode.y == map.start[1]))) { //while we haven't reached the start
		//get the lowest distance from the nodes around us
		least = INFINITY;
		if (tempNode.x+1 < MAP_WIDTH)
			least = min(least, weight[tempNode.x+1][tempNode.y]);
		if (tempNode.x-1 >= 0)
			least = min(least, weight[tempNode.x-1][tempNode.y]);
		if (tempNode.y+1 < MAP_HEIGHT)
			least = min(least, weight[tempNode.x][tempNode.y+1]);
		if (tempNode.y-1 >= 0)
			least = min(least, weight[tempNode.x][tempNode.y-1]);
		
		if ((tempNode.x+1 < MAP_WIDTH) && (weight[tempNode.x+1][tempNode.y] == least)) {
			neighbourNode = tempNode;
			neighbourNode.x++;
			if (!Exists(Q, neighbourNode))
				Q.push_back(neighbourNode); //add it to the queue
		}else if ((tempNode.x-1 >= 0) && (weight[tempNode.x-1][tempNode.y] == least)) {
			neighbourNode = tempNode;
			neighbourNode.x--;
			if (!Exists(Q, neighbourNode))
				Q.push_back(neighbourNode); //add it to the queue
		}else if ((tempNode.y+1 < MAP_HEIGHT) && (weight[tempNode.x][tempNode.y+1] == least)) {
			neighbourNode = tempNode;
			neighbourNode.y++;
			if (!Exists(Q, neighbourNode))
				Q.push_back(neighbourNode); //add it to the queue
		}else if ((tempNode.y-1 >= 0) && (weight[tempNode.x][tempNode.y-1] == least)) {
			neighbourNode = tempNode;
			neighbourNode.y--;
			if (!Exists(Q, neighbourNode))
				Q.push_back(neighbourNode); //add it to the queue
		}
		//push our current node into the stack
		if (!Exists(stack, tempNode))
			stack.push_back(tempNode);

		//get the next node
		Q.erase(Q.begin());
		tempNode = Q.front();
	}

	//print the path
	drawBunny(map);
	drawCarrot(map);
	while (!stack.empty()) {
		tempNode = stack.back(); //it's supposted to be a stack, so take the last element first
		stack.erase(stack.end()-1);
		//draw bunny and wait.
		drawBunny(tempNode.x, tempNode.y);
		Sleep(delay);
	}


	if (found[map.end[0]][map.end[1]])
		return weight[map.end[0]][map.end[1]];
	return -1;
};

int BreadthFirstTraversal(Map map) {
	//NOTE: this function doesn't actually calculate the shortest path
	vector<Node> Q;
	vector<Node> visited;
	Node tempNode;
	Node neighbourNode;
	bool done = false;

	//enqueue the starting node
	tempNode.x = map.start[0];
	tempNode.y = map.start[1];
	Q.push_back(tempNode);

	while (!Q.empty()) {
		tempNode = Q.front(); //take a node off the queue
		Q.erase(Q.begin());
		visited.push_back(tempNode); //mark this node as visited

		//draw bunny and wait.
		drawBunny(tempNode.x, tempNode.y);
		Sleep(10);

		gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 8);
		cout << "Currently on: (" << tempNode.x << ", " << tempNode.y << ")   ";

		//if we're at the end, stop the algorithm
		if ((tempNode.x == map.end[0]) && (tempNode.y == map.end[1])) {
			break;
			done = true;
		}


		//check the node to the right
		neighbourNode = tempNode;
		neighbourNode.x++;
		if ((neighbourNode.x < MAP_WIDTH) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!Exists(visited, neighbourNode)) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet and it's not already in the queue
			PrintCount();
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the left
		neighbourNode = tempNode;
		neighbourNode.x--;
		if ((neighbourNode.x >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!Exists(visited, neighbourNode)) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the below
		neighbourNode = tempNode;
		neighbourNode.y++;
		if ((neighbourNode.y < MAP_HEIGHT) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!Exists(visited, neighbourNode)) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			Q.push_back(neighbourNode); //add it to the queue
		}
		//check the node to the above
		neighbourNode = tempNode;
		neighbourNode.y--;
		if ((neighbourNode.y >= 0) && (!map.map[neighbourNode.x][neighbourNode.y]) && (!Exists(visited, neighbourNode)) && (!Exists(Q, neighbourNode))) { //if the node is within the bounds of the map and it is not a block and we haven't visited it yet
			PrintCount();
			Q.push_back(neighbourNode); //add it to the queue
		}

	}

	return -1;
};

int DepthFirstShortestPathAndDisplay(Map map, int x, int y, vector<Node> tail, int delay) {
	Node node;
	node.x = x;
	node.y = y;
	tail.push_back(node);

	gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 9);
	cout << "Currently checking: (" << x << ", " << y << ")   ";

	//base case
	if ((map.end[0] == x) && (map.end[1] == y))
		return 0;
	else {
		int result = INFINITY;

		//draw bunny and wait.
		drawBunny(x, y);
		Sleep(delay);

		Node neighbourNode = node;

		//up
		neighbourNode = node;
		if ((y-1 >= 0) && (!map.map[x][y-1])) { //if the node to the left is within the bounds of the map and it is not a block
			neighbourNode.y--; //then set neighbourNode to be that node, and check if we should add it to the tail
			if (!Exists(tail, neighbourNode)) {
				PrintCount();
				result = DepthFirstShortestPathAndDisplay(map, x, y-1, tail, delay);
				if (result < INFINITY) {
					return result + 1;
				}
			}
		}
		//right
		neighbourNode = node;
		if ((x+1 < MAP_WIDTH) && (!map.map[x+1][y])) { //if the node to the right is within the bounds of the map and it is not a block
			neighbourNode.x++; //then set neighbourNode to be that node, and check if we should add it to the tail
			if (!Exists(tail, neighbourNode)) {
				PrintCount();
				result = DepthFirstShortestPathAndDisplay(map, x+1, y, tail, delay);
				if (result < INFINITY) {
					return result + 1;
				}
			}
		}
		//left
		neighbourNode = node;
		if ((x-1 >= 0) && (!map.map[x-1][y])) { //if the node to the left is within the bounds of the map and it is not a block
			neighbourNode.x--; //then set neighbourNode to be that node, and check if we should add it to the tail
			if (!Exists(tail, neighbourNode)) {
				PrintCount();
				result = DepthFirstShortestPathAndDisplay(map, x-1, y, tail, delay);
				if (result < INFINITY) {
					return result + 1;
				}
			}
		}
		//down
		neighbourNode = node;
		if ((y+1 < MAP_HEIGHT) && (!map.map[x][y+1])) { //if the node to the left is within the bounds of the map and it is not a block
			neighbourNode.y++; //then set neighbourNode to be that node, and check if we should add it to the tail
			if (!Exists(tail, neighbourNode)) {
				PrintCount();
				result = DepthFirstShortestPathAndDisplay(map, x, y+1, tail, delay);
				if (result < INFINITY) {
					return result + 1;
				}
			}
		}

		return INFINITY;
	}
};

int DepthFirstShortestPathAndDisplay(Map map) {
	vector<Node> tail;
	return DepthFirstShortestPathAndDisplay(map, map.start[0], map.start[1], tail, 400);
};

int DepthFirstShortestPathAndDisplay(Map map, int delay) {
	vector<Node> tail;
	return DepthFirstShortestPathAndDisplay(map, map.start[0], map.start[1], tail, delay);
};

Map calcBlockRemovedShortest(Map &map) {
	//we're gonna remove 1 unique block from the map each time and calculate the shortest path again for that new map.
	Map tempMap = *(new Map);
	int tempSteps;

	//this will store the shortest number of steps and the associated map
	Map shortestMap = map;
	int shortestSteps = DijkstrasShortestPath(map);

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (map.map[i][j]) { //Only run this if a block exists at this coordinate
				tempMap = map; //make a copy of the map
				tempMap.map[i][j] = false; //remove the block
				gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 10);
				cout << "Checking block: (" << i << ", " << j << ")   ";
				tempSteps = DijkstrasShortestPath(tempMap);
				if (tempSteps < shortestSteps) { //check if this new map has a shorter distance
					shortestMap = tempMap;
					shortestSteps = tempSteps;
					gotoxy(MAP_X_OFFSET +  MAP_WIDTH + 5, MAP_Y_OFFSET + 11);
					cout << "Shortest path so far: " << shortestSteps << " by removing block: (" << i << "," << j << ")";
				}
			}
		}
	}
	//we're done! return the shortest map.
	return shortestMap;
};



#endif