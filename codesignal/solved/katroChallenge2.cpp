#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> katroChallenge2(vector<vector<int>> board, int row, int col, bool isClockwise) {
	int d = (isClockwise ? 1 : -1) * (row % 2 ? -1 : 1);
	int y = row, x = col;
	int v = board[y][x];
	board[y][x] = 0;
	while (v--) {
		x += d;
		if ( x < 0 || x > 3 ) {
			y += y % 2 ? -1 : 1; 
			x  = x < 0 ? 0 : 3;
			d *= -1; 
		}
		board[y][x]++;
	}
	return board;
}

int main() {
	vector<vector<int>> board {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};
	katroChallenge2(board, 3, 2, false);
	return 0;
}
