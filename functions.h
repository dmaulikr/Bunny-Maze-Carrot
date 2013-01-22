#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <time.h> 
#include <conio.h> 
using namespace std; 
#include <windows.h> 

#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

enum Colors { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite }; 

//prints charcters on the screen screen with a given color 
void coutc(int color, char* output) { 
	HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute( handle, color); 
	cout<< output; 
	SetConsoleTextAttribute( handle, color); 
} 

//prints number on the screen with a given color 
void coutc(int color, int output) { 
	HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute( handle, color); 
	cout<< output; 
	SetConsoleTextAttribute( handle, color); 
} 

//move cursor to location(x, y) 
void gotoxy ( short x, short y ) { 
	COORD coord = {x, y}; 
	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord ); 
}

#endif