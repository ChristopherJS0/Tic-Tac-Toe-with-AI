#include "TTT.h"
#include <vector>
#include <iostream>
using namespace std;

TicTacToe::TicTacToe() {
	// Initialize an empty board using spaces.
	//	Board Rows go from top to bottom. 
	//	Board Columns go from left to right.
	GameOver = false;
	for (int i = 0; i < 3; i++) {
		vector<char>Row;
		for (int j = 0; j < 3; j++) {
			Row.push_back(' ');
		}
		TTTBoard.push_back(Row);
	}
}

void TicTacToe::PrintBoard() {
	//Print board for an update!
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2) { cout << TTTBoard[i][j]; break; }
			cout << TTTBoard[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;
}

void TicTacToe::Insert(int Row, int Col, char Player)
{
	if (Row < 3 && Row > -1 && Col < 3 && Col > -1) {
		if (TTTBoard[Row][Col] == ' ') { TTTBoard[Row][Col] = Player; }
	}
}

char TicTacToe::TerminalState()
{
	// Function that looks for any possible terminal conditions.
	//	Goes through Vertical, Horizontal, then Diagonal test.
	char Winner = VerticalWin();
	if (Winner != ' ') { GameOver = true; return Winner; }

	Winner = HorizWin();
	if (Winner != ' ') { GameOver = true; return Winner; }

	Winner = DiagonalWin();
	if (Winner != ' ') { GameOver = true; return Winner; }

	if (TieGame()) { GameOver = true; return ' '; }

	return '-'; //	'-' returns if Board still has available spaces to play!

}

char TicTacToe::DiagonalWin()
{
	// Function to detect a Diagonal Win. - TESTED!
	
	//	Immediately rule out no diagonal win by returning
	//	if a corner has no Y or X.
	if (TTTBoard[0][0] == ' ' && TTTBoard[0][2] == ' ') {
		return ' ';
	}

	//	Initiate Match to leave a double for loop if initiated
	//	player char doesn't match all diagaonal spots. (Left Top -> Right Bottom)
	bool Match = true;
	char Player = TTTBoard[0][0];
	for (int i = 1; i < 3; i++) {
		if (Player != TTTBoard[i][i]) { Match = false; break; }
	}
	if (Match) { return Player; }

	//	Match set to true for other diagonal win check.
	//	Same conditions. (Right Top -> Left Bottom)
	//	Added else, to if (Match), if no diagonal wins.

	Match = true;
	Player = TTTBoard[0][2];
	int j = 1; // Column index, doesn't increase with i.
	for (int i = 1; i < 3; i++) {
		if (Player != TTTBoard[i][j]) { Match = false; break; }
		j--;
	}

	if (Match) { return Player; }
	else {
		return ' ';
	}

}

char TicTacToe::VerticalWin()
{
	// Function detects if there is a vertical win!

	//	Automatically return nothing if a necessary vertical element isn't X or Y.
	if (TTTBoard[0][0] == ' ' && TTTBoard[0][1] == ' ' && TTTBoard[0][2] == ' ') {
		return ' ';
	}

	//	Player will be the first element of each column. Used to match the column's rows elements.
	//	Match will be true if each of the column's rows elements match with Player. Otherwise, will be false if one elem of column doesn't match.
	//	Loop makes Match = true, to check another column except on 2 because it has no more columns to check.
	char Player;
	bool Match = true;
	for (int Col = 0; Col < 3; Col++) {
		Player = TTTBoard[0][Col];
		if (Player != ' ') { //	Makes sure that emptys aren't being matched.

			for (int Row = 1; Row < 3; Row++) {
				if (Player != TTTBoard[Row][Col]) { Match = false; break; }
			}
			// If matched through entire column, then win!
			if (Match) { return Player; }

			// Set match to true again unless at last column!
			if (Col != 2) { Match = true; }
		}
	}
	return ' ';
}

char TicTacToe::HorizWin()
{
	// Function to detect horizontal wins.
	
	//	Automatically return nothing if a necessary horizontal spot is empty.
	if (TTTBoard[0][0] == ' ' && TTTBoard[1][0] == ' ' && TTTBoard[2][0] == ' ') {
		return ' ';
	}

	//	Player will be the first element in a row that compares to element on same row.
	//	Match is true if each column element of a row is matched with Player, changes to false if one column element of a row is different.
	//	Loop makes Match = true, to check another row except on 2 because it has no more rows to check.
	char Player;
	bool Match = true;
	for (int i = 0; i < 3; i++) {
		Player = TTTBoard[i][0];
		if (Player != ' ') {

			for (int j = 1; j < 3; j++) {
				if (Player != TTTBoard[i][j]) { Match = false; break; }
			}		
			// If matched through entire row, then win!
			if (Match) { return Player; }

			// Set match to true again unless at last row!
			if (i != 2) { Match = true; } 
		}
	}
	return ' '; // Loop exits only if no rows match!
}

bool TicTacToe::TieGame() {
	// Function that decides if the game has all slots filled and no winner possible.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (TTTBoard[i][j] == ' ') { return false; }
		}
	}

	//	Loops are only exited if there is a valid element in every cell.
	//	therefore, the board is filled and no moves available.
	return true;
}
