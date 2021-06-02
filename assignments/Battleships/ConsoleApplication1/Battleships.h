#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int rows = 10;
const int columns = 10;
void PrintBoard(char board[][columns]);
void GenerateShips(char board[][columns], int size);
void CheckBoard(char board[][columns], bool& victory);