#include <iostream>
#include <string.h>
#include "headers/verify.h"

using namespace std;

bool VerifyRaws(string grid[3][3])
{
    int player1 = 0;
    int player2 = 0;

    for (int i(0); i<3; i++) { //check raws
		for (int j(0); j<3; j++) {
			if (grid[i][j] == "O") {
				player1++;
            } else if (grid[i][j] == "X") {
				player2++;
            }
		}

		if (player1 == 3 || player2 == 3) {
			return true;
		}
        player1 = 0;
        player2 = 0;
    }
    return false;
}

bool VerifyColumns(string grid[3][3])
{
    int player1 = 0;
    int player2 = 0;

    for (int i(0); i < 3; i++)
    { 
        for (int j(0); j < 3; j++)
        {
            if (grid[j][i] == "O") {
                player1++;
            } else if (grid[j][i] == "X") {
                player2++;
            }
        }
        if (player1 == 3 || player2 == 3)
        {
            return true;
        }
        player1 = 0;
        player2 = 0;
    }
    return false;
}

bool VerifyDiagonals(string grid[3][3])
{
    int player1 = 0;
    int player2 = 0;

    for (int i = 0; i<3; i++) { //check the first diagonal
		if (grid[i][i] == "O") {
			player1++;
		} else if (grid[i][i] == "X") { //pos : 0-0; 1-1; 2-2 (1st diagonal)
			player2++;
		}

		if (player1 == 3 || player2 == 3) {
			return true;
		}
	}

	int i = 0;
	int j = 2;
    player1 = 0;
    player2 = 0;

    while (i < 3) {   //check the second diagonal
		if (grid[i][j] == "O") {
			player1++;
		} else if (grid[i][j] == "X") {
			player2++;
        }

		i++;    //pos : 0-2, 1-1, 2-0 (2nd diagonal)
		j--;
		if (player1 == 3 || player2 == 3) {
			return true;
		}
	}
	return false;
}


bool Verify(string grid[3][3])  //this check if somebody has won or not
{
    if (VerifyColumns(grid) == true || VerifyRaws(grid) == true || VerifyDiagonals(grid) == true) {
        return true;
    }	
	return false;
}

bool CheckFullGrid(string grid[3][3])  //check if the grid is full
{
    int check = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (grid[i][j] != " ") {
				check++;
			}
		}
	}
	if (check == 9) {
		return true;
	}
	return false;
}