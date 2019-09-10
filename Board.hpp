/********************************************************************************
Author: Long Do
Date: 8/8/2017
Description: This is a class that represents a tic-tac-toe board.
*********************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

// Set up enumerated data type called "State" for the
// current game state
enum State { X_WON = 3, O_WON, DRAW, UNFINISHED };

// Set up enumerated data type call "Player" for the
// two players
enum Player {Player_X = 0, Player_O};


class Board
{

private:

	// Create a 3x3 array as a data member
	// which will be used to store the
	// locations of the players' moves
	int locations[3][3];

public:

	// The default constructor that initializes
	// the 3x3 array to being empty
	Board();

	// A method that takes the x and y coordinates of the move
	// and which player's turn it is as parameters
	bool makeMove(int x, int y, Player player);

	// A method that takes no parameters and
	// returns the current state of the game
	State gameState();

	// A method which just prints out
	// the current board to the screen
	void print();
};

#endif