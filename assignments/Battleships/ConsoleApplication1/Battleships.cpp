#include "Battleships.h"

int main()
{
	srand(static_cast <unsigned int>(time(NULL)));
	char board[rows][columns], playerBoard[rows][columns];
	int sizeShip, ships;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = '.';
			playerBoard[i][j] = '.';
		}
	}

	cout << "BATTLESHIP!" << endl;
	do {
		cout << "How many battleships do you want? You can't have more than 3 or less than 1: " << endl;
		cin >> ships;
	} while (ships < 1 || ships > 3);

	for (int i = 1; i <= ships; i++)
	{
		sizeShip = rand() % 3 + 1;
		GenerateShips(board, sizeShip);
	}

	int bombs = 25, rowGuess, colGuess;
	bool victory = false;
	if (ships != 1) {
		cout << "\nHere is the game board. There are " << ships << " enemy battleships hidden here. \n";
	}
	else {
		cout << "\nHere is the game board. There is " << ships << " enemy battleships hidden here. \n";
	}
	cout << "Input \"row\" and \"column\" to decide where to place your bomb. ";
	cout << "For example, type \"1 10\" (row 1, column 10), to place a bomb in the top right corner. ";
	cout << "You have 25 bombs. Good luck!" << endl;

	for (int n = 1; n <= bombs && !victory; n++)
	{
		PrintBoard(playerBoard);
		cout << "bombs #" << n << ", row and column: ";
		cin >> rowGuess;
		cin >> colGuess;

		if (board[rowGuess - 1][colGuess - 1] == 'S') {
			cout << "Hit!" << endl;
			board[rowGuess - 1][colGuess - 1] = '*';
			playerBoard[rowGuess - 1][colGuess - 1] = '*';
		}
		else if (board[rowGuess - 1][colGuess - 1] == '.') {
			cout << "Missed!" << endl;
			board[rowGuess - 1][colGuess - 1] = 'o';
			playerBoard[rowGuess - 1][colGuess - 1] = 'o';
		}
		victory = true;
		CheckBoard(board, victory);
	}
	cout << "Final board: " << endl;
	PrintBoard(board);
	cout << "A \".\" is the sea. ";
	cout << "\"*\" is a hit of an enemy ship. ";
	cout << "A \"S\" is a surviving enemy ship. ";
	cout << "A \"o\" is a missed bomb. " << endl;

	if (victory) {
		cout << "Congratulations! You hit all your enemy battleships!" << endl;
	}
	else {
		cout << "Sorry, you lost." << endl;
	}
	return 0;
}

void PrintBoard(char board[][columns])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <columns; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	return;
}

void GenerateShips(char board[][columns], int size)
{
	int iStart, jStart, ort;
Randomize:
	do {
		iStart = rand() % rows;
		jStart = rand() % columns;
		ort = rand() % 2;
	} while (board[iStart][jStart] == 'S');
	if (ort == 0) {
		while (jStart + size >= columns) {
			jStart = rand() % columns;
		}
		for (int j = jStart; j < jStart + size; j++)
		{
			if (board[iStart][j] == 'S') {
				goto Randomize;
			}
		}
		for (int j = jStart; j < jStart + size; j++)
		{
			board[iStart][j] = 'S';
		}
	}

	if (ort == 1) {
		while (iStart + size >= rows)
		{
			iStart = rand() % rows;
		}
		for (int i = iStart; i < iStart + size; i++) {
				
			if (board[i][jStart] == 'S') {
				goto Randomize;
			}
		}

		for (int i = iStart; i < iStart + size; i++) {

			board[i][jStart] = 'S';
		}
	}
		
	return;
}

void CheckBoard(char board[][columns], bool& victory)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (board[i][j] == 'S') {
				victory = false;
			}
		}
	}
}
