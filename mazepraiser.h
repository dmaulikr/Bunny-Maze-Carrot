#include <string>
#include <iostream>
#include <fstream> //file stream
using namespace std;
#include "map.h"

#ifndef MAZEPRAISER_H
#define MAZEPRAISER_H


//NOTE: constants are in the "map.h" file
const static char FILE_BLOCK_CHAR = 'x'; //this is the char in the text file that represents a block

bool loadMaze(const char *filename, Map &map) {
	ifstream infile;
	infile.open(filename);
	if (infile.fail()) { 
		cout << "failed to open " << filename << ". Aborting...\n";
        return false;
        }

	string temp;
	int line = 0;
    while (!(infile.eof())) {
		if (line >= MAP_HEIGHT) {
			cout << "Map height is greater than the expected height of " << MAP_HEIGHT << ". Aboring...\n";
			infile.close();
			return false;
		}
		infile >> temp; //get one line
		if (temp.length() != MAP_WIDTH) {
			cout << "Map width on line " << line << " is invalid. Aborting...\n";
			infile.close();
			return false;
		} else {
			for (int i = 0; i < MAP_WIDTH; i++) {
				map.map[i][line] = (temp[i] == FILE_BLOCK_CHAR);
			}
		}
		line++;
	}
	return true;
};

/*
NOTE
----
Below is code from the OOP final project. This is only here as a reference.




bool read_files() {

ifstream infile;
char filename[MAX_LENGTH_OF_COURSE_CODE+5]; //used in the third part of read_files(). the +4 is for the '.txt' that will be added to the end
//I realise that this is not a string but it is used as a string later so that '.txt' can be easily added

//read 'students.txt'
    cout << "opening students.txt for input...";
    infile.open("students.txt");
    //checks the file stream
    if (infile.fail()) { 
        cout << "Failed!\n";
        system("pause");
        return false;
        } else
        cout << "Success\n";
        
    while (!(infile.eof())) {
          if (students_used > MAX_STUDENTS)
             break;
          //good idea to add some more error checking, do that later
          infile >> student[students_used].ID;
                 if (student[students_used].ID != 0)
                    students_used++;
          //works well because if index 0-2 are used then students_used = 3
    }
    infile.close();
    infile.clear();
    cout << "finished reading 'students.txt'\n";
};
*/

#endif