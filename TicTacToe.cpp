/********************************************************************************
Author: Long Do
Date: 8/8/2017
Description: The definition file for TicTacToe class functions.
********************************************************************************/

#include "TicTacToe.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// A constructor that takes a char parameter that specifies whether
// player 'X' or 'O' should have the first move.
TicTacToe::TicTacToe(char turn)
{
	if (turn == 'X' || turn == 'O')
	{
		playerTurn = turn;
	}
	else
	{
		cout << endl;
		cout << "Please enter either X or O." << endl;
	}
}

// A method that starts the game. This method should keep looping,
// asking the correct player for their move and sending it to the board
// (with makeMove) until someone has won or it's a draw
// (as indicated by gameState), and then declare what the outcome was.
void TicTacToe::play()
{
	int x;
	int y;
	bool move;
	Player player;
	State current = UNFINISHED;

	game.print();

	while (playerTurn == 'X' || playerTurn == 'O')
	{
		if (playerTurn == 'X')
		{
			player = Player_X;

			cout << endl;
			cout << "\nThis is your turn, player X." << endl;
			cout << "\nPlease enter the coordinates of your move:" << endl;
			cin >> x >> y;

			while (x < 0 || x > 2 || y < 0 || y > 2)
			{
				cout << "\nYour coordinates are invalid." << endl;
				cout << "\nPlease enter your coordinates again." << endl;
				cin >> x >> y;
			}

			move = game.makeMove(x, y, player);

			while (move == false)
			{
				cout << "\nThat location is already occupied." << endl;
				cout << "\nPlease enter the coordinates of your move again:" << endl;
				cin >> x >> y;

				move = game.makeMove(x, y, player);
			}
			
			game.print();
			current = game.gameState();
			if (current == X_WON)
			{
				cout << "\nCongratulations, Player X is the winner." << endl;
				break;
			}
			else if (current == O_WON)
			{
				cout << "\nCongratulations, Player O is the winner." << endl;
				break;
			}
			else if (current == DRAW)
			{
				cout << "\nThis game is a draw." << endl;
				break;
			}

			playerTurn = 'O';
		}

		if (playerTurn == 'O')
		{
			player = Player_O;

			cout << endl;
			cout << "\nThis is your turn, player O." << endl;
			cout << "\nPlease enter the coordinates of your move:" << endl;
			cin >> x >> y;

			while (x < 0 || x > 2 || y < 0 || y > 2)
			{
				cout << "\nYour coordinates are invalid." << endl;
				cout << "\nPlease enter your coordinates again." << endl;
				cin >> x >> y;
			}
			
			move = game.makeMove(x, y, player);

			while (move == false)
			{
				cout << "\nThat location is already occupied." << endl;
				cout << "\nPlease enter the coordinates of your move again:" << endl;
				cin >> x >> y;

				move = game.makeMove(x, y, player);
			}
			
			game.print();
			current = game.gameState();
			if (current == X_WON)
			{
				cout << "\nCongratulations, Player X is the winner." << endl;
				break;
			}
			else if (current == O_WON)
			{
				cout << "\nCongratulations, Player O is the winner." << endl;
				break;
			}
			else if (current == DRAW)
			{
				cout << "\nThis game is a draw." << endl;
				break;
			}
			
			playerTurn = 'X';
		}
	}
}


// Testing the game
int main()
{
	char choice;

	cout << "\nWelcome to the grand OSU TicTacToe game." << endl;
	cout << "Which player will go first (you can pick either X or O)?" << endl;
	cin >> choice;

	while (choice != 'X' && choice != 'O')
	{
		cout << "Which player will go first (you can pick either X or O)?" << endl;
		cin >> choice;
	}

	TicTacToe game(choice);

	game.play();

	return 0;
}