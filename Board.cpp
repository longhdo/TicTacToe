/******************************************************************************
Author: Long Do
Date: 8/8/2017
Description: This is the definition file for the Board class functions.
******************************************************************************/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// The default constructor that initializes the 3x3 array to being empty.
Board::Board()
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			locations[x][y] = 0;
}

// A method that takes the x and y coordinates of the move
// and which player's turn it is as parameters. If that location
// is unoccupied, makeMove should record the move and return true.
// If that location is already occupied, makeMove should just return false.
bool Board::makeMove(int x, int y, Player player)
{
	bool validMove;

	// Player_X (first player) makes a move
	if (player == Player_X)
	{
		if (locations[x][y] == 0)
		{
			validMove = true;
			locations[x][y] = 1;
		}
		else
		{
			validMove = false;
		}
	}

	// Player_O (second player) makes a move
	else if (player == Player_O)
	{
		if (locations[x][y] == 0)
			{
				validMove = true;
				locations[x][y] = 2;
			}
		else
			{
				validMove = false;
			}
	}

	return validMove;
}

// A method that takes no parameters and returns one of the
// four following values: X_WON, O_WON, DRAW, or UNFINISHED.
State Board::gameState()
{
	State current = DRAW;
	bool empty;

	// Check whether any empty location exists
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			// An Empty location exists
			if (locations[x][y] == 0)
			{
				current = UNFINISHED;
			}
			else
			{
				empty = false;
			}

	// When the board has no empty location
	if (empty == false)
	{
		// Player X wins horizontally
		if ((locations[0][0] == 1 && locations[0][1] == 1 && locations[0][2] == 1) ||
			(locations[1][0] == 1 && locations[1][1] == 1 && locations[1][2] == 1) ||
			(locations[2][0] == 1 && locations[2][1] == 1 && locations[2][2] == 1))
		{
			current = X_WON;
		}
		// Player O wins horizontally
		else if ((locations[0][0] == 2 && locations[0][1] == 2 && locations[0][2] == 2) ||
				 (locations[1][0] == 2 && locations[1][1] == 2 && locations[1][2] == 2) ||
				 (locations[2][0] == 2 && locations[2][1] == 2 && locations[2][2] == 2))
		{
			current = O_WON;
		}
		// Player X wins vertically
		else if ((locations[0][0] == 1 && locations[1][0] == 1 && locations[2][0] == 1) ||
				 (locations[0][1] == 1 && locations[1][1] == 1 && locations[2][1] == 1) ||
				 (locations[0][2] == 1 && locations[1][2] == 1 && locations[2][2] == 1))
		{
			current = X_WON;
		}
		// Player O wins vertically
		else if ((locations[0][0] == 2 && locations[1][0] == 2 && locations[2][0] == 2) ||
				 (locations[0][1] == 2 && locations[1][1] == 2 && locations[2][1] == 2) ||
				 (locations[0][2] == 2 && locations[1][2] == 2 && locations[2][2] == 2))
		{
			current = O_WON;
		}
		// Player X wins diagonally
		else if ((locations[0][0] == 1 && locations[1][1] == 1 && locations[2][2] == 1) ||
				 (locations[0][2] == 1 && locations[1][1] == 1 && locations[2][0] == 1))
		{
			current = X_WON;
		}
		// Player O wins diagonally
		else if ((locations[0][0] == 2 && locations[1][1] == 2 && locations[2][2] == 2) ||
				 (locations[0][2] == 2 && locations[1][1] == 2 && locations[2][0] == 2))
		{
			current = O_WON;
		}
		// No winner - draw
		/*****************
		else
		{
			current = DRAW;
			return current;
		}
		******************/
	}

	return current;
}

// A method which just prints out the current board to the screen.
void Board::print()
{
	cout << endl;

	cout << "   " << "0 " << "1 " << "2" << endl;

	// First row
	cout << "0  ";
	for (int x = 0, y = 0; y < 3; y++)
	{
		if (locations[x][y] == 1)
		{
			cout << "X ";
		}
		else if (locations[x][y] == 2)
		{
			cout << "O ";
		}
		else
		{
			cout << ". ";
		}
	}

	cout << endl;

	// Second row
	cout << "1  ";
	for (int x = 1, y = 0; y < 3; y++)
	{
		if (locations[x][y] == 1)
		{
			cout << "X ";
		}
		else if (locations[x][y] == 2)
		{
			cout << "O ";
		}
		else
		{
			cout << ". ";
		}
	}

	cout << endl;

	// Third row
	cout << "2  ";
	for (int x = 2, y = 0; y < 3; y++)
	{
		if (locations[x][y] == 1)
		{
			cout << "X ";
		}
		else if (locations[x][y] == 2)
		{
			cout << "O ";
		}
		else
		{
			cout << ". ";
		}
	}
}