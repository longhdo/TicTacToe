# TicTacToe Game

A basic C++ program that will allow 2 people to play a TicTacToe board game.

It has a class called Board that represents a tic-tac-toe board. It should have a 3x3 array as a data member, which will store the locations of the players' moves. It should have a default constructor that initializes the 3x3 array to being empty. It should have a method called makeMove that takes the x and y coordinates of the move (see the example below) and which player's turn it is as parameters. If that location is unoccupied, makeMove should record the move and return true. If that location is already occupied, makeMove should just return false. There should be a method called gameState that takes no parameters and returns one of the four following values: X_WON, O_WON, DRAW, or UNFINISHED. There should also be a method called print, which just prints out the current board to the screen.

It has a class called TicTacToe that allows two people to play a game. This class will have a field for a Board object and a field to keep track of which player's turn it is. It should have a constructor that takes a char parameter that specifies whether 'x' or 'o' should have the first move. It should have a method called play that starts the game. The play method should keep looping, asking the correct player for their move and sending it to the board (with makeMove) until someone has won or it's a draw (as indicated by gameState), and then declare what the outcome was.

It has a main method (in TicTacToe.cpp) that asks the user which player should go first, creates a new TicTacToe object and starts the game.

Thus, it also has simple input validation: if someone tries to take an occupied square, tell the person that square is already occupied and ask for a different move.
