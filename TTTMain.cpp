//Christoher Salinas-Sanchez
#include "TTT.h"
#include <iostream>
using namespace std;

//	Struct to store Row, Column AND Score of TTT Board.
struct Triple {
	int Row, Column, Score;
};

// Declare first so MAX can use this function.
Triple MIN(TicTacToe Board, pair<int, int> LastPlay, int Alpha, int Beta);

int Score(TicTacToe& Board) {
	// Function to return score, the AI will play X.
	if (Board.TerminalState() == 'X') { return 1; }
	else if (Board.TerminalState() == 'O') { return -1; }
	else { return 0; }
}

vector<Triple> EmptySpots(TicTacToe& Board) {
	// Function to collect all of a states child states.
	vector<Triple> OpenSpots;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Board.TTTBoard[i][j] == ' ') { OpenSpots.push_back({i,j,999}); } // 999 will be the sentinel for a no value score.
		}
	}
	return OpenSpots;
}

Triple MAX(TicTacToe Board, pair<int, int> LastPlay, int Alpha, int Beta) {
	// Function to return the MAX pair to play.

	//	Checks if the current state is terminal, then returns a state (pair) with the valid score.
	Board.Insert(LastPlay.first, LastPlay.second, 'O');
	if (Board.TerminalState() != '-') {
		return { LastPlay.first, LastPlay.second, Score(Board) };}

	//	Initiate starting maximizer for this MAX Node (-100) because it's a bad maximizer, so it's easy to change.
	//	ValidPlay is the struct that will be returned, contains Row, Column, Score.
	//	ChildStates are next states of current state, EmptySpots() returns a vector of next plays using board.
	int Value = -100;
	Triple ValidPlay = { LastPlay.first, LastPlay.second, 999 }; // 999 as score is a sentinel to NOT use this score.
	vector<Triple>ChildStates = EmptySpots(Board);

	for (auto& nextState : ChildStates) {

		pair<int, int> NextPlay = make_pair(nextState.Row, nextState.Column);
		Triple nextStateChild = MIN(Board, NextPlay, Alpha, Beta);

		if (nextStateChild.Score != 999 && nextStateChild.Score > Value){
			Value = nextStateChild.Score;
			ValidPlay.Column = nextState.Column; ValidPlay.Row = nextState.Row; ValidPlay.Score = Value;
		}

		if (Alpha < nextStateChild.Score) { Alpha = nextStateChild.Score; }

		//	Pruning because Minimizer parent will never go to this maximizer node.
		if (Beta <= Alpha) {
			// cout << "MAX Prune-> Pruning the children of: " << endl;
			// Board.PrintBoard();
			break; 
		}
	}

	return ValidPlay; 
}

Triple MIN(TicTacToe Board, pair<int, int> LastPlay, int Alpha, int Beta) {

	// Inserting the last made play to evaluate. First = Row, Second = Column.
	Board.Insert(LastPlay.first, LastPlay.second, 'X');

	//	Checks if the current state is terminal, then returns a state (pair) with the valid score.
	if (Board.TerminalState() != '-') {
		return { LastPlay.first, LastPlay.second, Score(Board) };
	}
	
	//	Initiate starting minimizer for this MIN Node (100) because it's a bad minimizer, so it's easy to change.
	//	ValidPlay is the struct that will be returned, contains Row, Column, Score.
	//	ChildStates are next states of current state, EmptySpots() returns a vector of next plays using board.
	int Value = 100;
	Triple ValidPlay = { LastPlay.first, LastPlay.second, 999 }; // 999 as score is a sentinel to NOT use this score.
	vector<Triple>ChildStates = EmptySpots(Board);

	for (auto& nextState : ChildStates) {

		pair<int, int> NextPlay = make_pair(nextState.Row, nextState.Column);
		Triple nextStateChild = MAX(Board, NextPlay, Alpha, Beta);

		if (nextStateChild.Score != 999 && nextStateChild.Score < Value) {
			Value = nextStateChild.Score;
			ValidPlay.Column = nextState.Column; ValidPlay.Row = nextState.Row; ValidPlay.Score = Value;
		}

		if (Beta > nextStateChild.Score) { Beta = nextStateChild.Score; }

		//	Pruning because Maximizer parent will never go to this minimizer node.
		if (Beta <= Alpha) {
			// cout << "MIN Prune -> Pruning the children of: " << endl;
			// Board.PrintBoard();
			break;
		}
	}

	return ValidPlay;
}

int main() {
	TicTacToe Game1;
	Game1.PrintBoard();

	// Active game, the loop checks if there are empty spots to use.
	while (Game1.TerminalState() == '-') {

		int Row, Col;
		cout << "Player O, enter row: ";
		cin >> Row; cout << endl;
		cout << "Player O, enter column: ";
		cin >> Col; cout << endl;

		Game1.Insert(Row, Col, 'O');
		Game1.PrintBoard();
		if (Game1.TerminalState() != '-') { break; }

		// AI will make the X plays, 
		Triple AIplayer = MAX(Game1, make_pair(Row, Col), -100, 100);
		Game1.Insert(AIplayer.Row, AIplayer.Column, 'X');
		Game1.PrintBoard();
	}

	//	Printing a winner of the tic-tac-toe game!
	char Winner = Game1.TerminalState();
	if (Winner == ' ') { cout << "No winner, it's a tie!"; }
	else {	cout << Winner << " has won this game!";}

	return 0;
}