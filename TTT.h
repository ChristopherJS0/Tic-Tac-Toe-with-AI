#pragma once
#include <vector>
using namespace std;

struct TicTacToe {
	TicTacToe();

	void Insert(int Row, int Col, char Player); // TESTED

	void PrintBoard();	// TESTED

	char TerminalState(); // TESTED
	char DiagonalWin(); // TESTED
	char HorizWin(); // TESTED
	char VerticalWin();	// TESTED
	bool TieGame(); // TESTED

	vector<vector<char>> TTTBoard;

private:
	bool GameOver;
};