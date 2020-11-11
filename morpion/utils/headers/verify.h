#ifndef VERIFY_H
#define VERIFY_H

#include <string.h>

bool VerifyRaws(std::string grid[3][3]);
bool VerifyColumns(std::string grid[3][3]);
bool VerifyDiagonals(std::string grid[3][3]);   //these verify is somebody has won
bool Verify(std::string grid[3][3]);

bool CheckFullGrid(std::string grid[3][3]); //this check if the grid is full

#endif