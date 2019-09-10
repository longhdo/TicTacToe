/*********************************************************************************
Author: Long Do
Date: 8/8/2017
Description: This is a class that allows two people to play a game of
			tic tac toe.
*********************************************************************************/



#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"


class TicTacToe
{

private:
	Board game;
	char playerTurn;

public:

	// A constructor that takes a char parameter that specifies
	// whether 'x' or 'o' should have the first move.
	TicTacToe(char turn);

	// A method that starts the game.
	void play();
};

#endif