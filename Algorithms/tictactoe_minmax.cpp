/**
 * @author afmika
 * CLI TicTacToe with a MiniMax based AI
 */

#include <bits/stdc++.h>

using namespace std;

#define vvi vector<vector<int>>

const int _GAME_NOT_ENDED = 25;
const int computer = 1;
const int human = -1;

map<int, char> m {
	{ 1, 'X'},
	{-1, 'O'},
	{ 0, ' '}
};

void display(vvi& board) {
	cout << "-----------\n";
	for (int i = 0; i < 3; i++ ) {
		for (int j = 0; j < 3; j++ ) {
			int v = board[i][j];
			string t = to_string(v);
			if ( j > 0 ) cout << " |";
			cout << " "<< m[board[i][j]];
		}
		cout << "\n---+---+---\n";
	} 
	cout << "-----------\n";
}

int gameEnd(vvi& board) {
	int h = 0, v = 0, 
		l = 0, r = 0;
	int containsEmptyCells = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			h += board[i][j];
			v += board[j][i];	
			if ( board[i][j] == 0 )
				containsEmptyCells = true;
		}
		l += board[i][i];
		r += board[i][2-i];
		vector<int> values = {h, v, r, l};
		for (int value : values) {
			if ( abs(value) == 3 ) {
				return value / 3;
			}
		}	
		v = 0; h = 0;
	}
	if ( containsEmptyCells ) 
		return _GAME_NOT_ENDED;
	return 0;
}	

int minmax(vvi& board, int depth, bool isMax) {

	int game_state = gameEnd(board);

	if ( abs(game_state) != _GAME_NOT_ENDED ) {
		int score = 1000 - depth;
		return game_state * score;
	}
	
	int score = isMax ? INT_MIN : INT_MAX;
	for (int i = 0; i < 3; i++ ) {
		for (int j = 0; j < 3; j++ ) {
			if ( board[i][j] == 0 ) {
				if ( isMax ) {
					board[i][j] = computer; // maximizes the human's score
					score = max(score, minmax(board, depth + 1, false));
				} else {
					board[i][j] = human; // minimizes the computer's score
					score = min(score, minmax(board, depth + 1, true));
				}
				board[i][j] = 0;
			}
		}
	} 
	return score;
}

pair<int, int> play(vvi& board) {
	pair<int, int> pos;
	int currentScore = INT_MIN;
	for (int i = 0; i < 3; i++ ) {
		for (int j = 0; j < 3; j++ ) {
			if ( board[i][j] == 0 ) {
				board[i][j] = computer;
				int computedScore = minmax(board, 1, false); // min
				board[i][j] = 0;
				if ( currentScore < computedScore ) { // max (root)
					 currentScore = computedScore;
					 pos = {i, j};
				}
			}
		}
	}
	return pos;
}



int main() {
	cout << "# CLI - TicTacToe with an AI --- afmika 2020 #" << "\n";
	vvi board = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	
	int winner = _GAME_NOT_ENDED;
	while ( true ) {
		cout << "Input y x >>";
		int py, px;
		cin >> py;
		cin >> px;
		if ( py < 0 || px < 0 || px >= 3 || py >= 3) {
			cout << "Error : 0 <= y, x <= 2" << "\n";
			continue;
		}
		
		if ( board[py][px] != 0) {
			cout << "Spot not empty" << "\n";
			continue;
		}
		
		board[py][px] = human;		
		display( board );
		
		pair<int, int> bestMove = play(board);
		board[bestMove.first][bestMove.second] = computer;
		display( board );

		winner = gameEnd(board);			
		if ( winner != _GAME_NOT_ENDED ) {
			cout << " RESULT: ";
			if ( winner == 0 ) {
				cout << "TIE" << endl;
			} else {
				cout << "Winner " << m[winner] << endl;
			}
			break;
		}
	}
	return 0;
}
