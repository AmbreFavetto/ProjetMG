#include <iostream>
#include <windows.h>
#include <string.h>

#include "utils/headers/grid.h"
#include "utils/grid.cpp"

#include "utils/headers/verify.h"
#include "utils/verify.cpp"

#include "utils/headers/posChosen.h"
#include "utils/posChosen.cpp"

using namespace std;

//the "mrp" is to avoid conflicts with others var names

int main() {
    string mrp_grid[3][3]; //define the tic tac toe grid (3 raw & 3 columns)

    string mrp_player1 = "O";
    string mrp_player2 = "X";
    string mrp_player = mrp_player1;
    string mrp_pos = "";

    for (int i(0); i < 3; i++) {
        for (int j(0); j < 3; j++)
        {
            mrp_grid[i][j] = " ";       //fill the tictactoe grid with empty spaces
        }
    }

    while (true) {
		if (mrp_player == mrp_player1) {
			cout << "Player 1 - O" << endl; 
		} else if (mrp_player == mrp_player2) {
			cout << "Player 2 - X" << endl;
		}
		Display(mrp_grid);


		cout << "Select a position (ex : a1, c2...) : ";
		cin >> mrp_pos;
		int mrp_pos1 = posChosen(mrp_pos)[0];    //the func posChosen return an array (ex: [0,2] for the position a3)
		int mrp_pos2 = posChosen(mrp_pos)[1];

		if (mrp_pos1 == 9) { //check if the pos is on the board
			system("cls"); //clear the console
			cout << "The position isn't valid !" << endl; 
			continue;
		} else if (mrp_grid[mrp_pos1][mrp_pos2] != " ") {
			system("cls");
			cout << "This position is already taken !" << endl; //check if the pos is empty
		} else {
			 ChangeGrid(mrp_player, mrp_grid, mrp_pos1, mrp_pos2);  

			if (Verify(mrp_grid) == true) { //check if somebody has won
				break;
			}

			if (CheckFullGrid(mrp_grid) == true) {  //check if the grid is full
				system("cls");
				cout << "The grid is full, nobody has won !" << endl;
				Display(mrp_grid);
                system("pause");
				return 0;
			}

			if (mrp_player == mrp_player1) {
				mrp_player = mrp_player2;
			} else {
				mrp_player = mrp_player1;
			}
			system("cls");
		}
	}

	if (mrp_player == "O") {
		system("cls");
		cout << "Player1 has won !" << endl;
		Display(mrp_grid);
	} else {
		cout << "Player2 has won !" << endl;
	}

    system("pause");
    return 0;
}
