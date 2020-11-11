#include <iostream>
#include <string.h>
#include "headers/grid.h"

using namespace std;

void Display(string grid[3][3]) {
    string s("abc");
	cout << "  1 2 3" << endl;
	for(int i(0); i<3; i++) {
        cout << s[i] << " " << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << " " << endl;
    }
	cout << endl;
}

void ChangeGrid(string player, string grid[3][3], int pos1, int pos2) {
	grid[pos1][pos2] = player;
}