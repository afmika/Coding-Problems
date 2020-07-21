#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define board vec<vec<char>>

#define DEBUG 0

namespace Game {
	
	char c_empty = '.';
	char c_queen = 'x';		
	
	bool isValid (board b, int r, int c) {
		return r >= 0 && r < b.size() && c >= 0 && c < b[0].size();
	}
	
	bool remove(board& b, int r, int c) {
		if ( b[r][c] == c_empty )
			return false;
		b[r][c] = c_empty;
		return true;
	}

	board clone(board& b) {
		board res(b.size());
		for (size_t i = 0; i < b.size(); i++) {
			res[i] = *( new vec<char>(b[i].size()) );
			for (size_t j = 0; j < b[i].size(); j++) {
				res[i][j] = b[i][j];
			}
		}
		return res;
	}
	
	bool put(board& b, int r, int c) {
		if ( !isValid(b, r, c) )
			return false;
		
		if ( b[r][c] != c_empty )
			return false;
		
		for (size_t i = 0; i < b.size(); i++) {
			for (size_t j = 0; j < b[i].size(); j++) {
				if ( b[i][j] != c_empty ) {
					int dy = abs(i - r),
						dx = abs(j - c);
					// horizontal / vertical
					// i == r || j == c
					if (dx == 0 || dy == 0 ) {
						#if DEBUG
							printf("%i,%i VS %i,%i SAME DXDY\n", i, j, r, c);
						#endif
						return false;
					}
					
					// square
					if ( dx <= 1 && dy <= 1 ){
						#if DEBUG
							printf("%i,%i VS %i,%i SQUARE\n", i, j, r, c);
						#endif
						return false;
					}
						
					// diag
					if ( dy/dx == 1 ){
						#if DEBUG
							printf("%i,%i VS %i,%i DIAG\n", i, j, r, c);
						#endif
						return false;
					}
				}
			}
		}
		b[r][c] = c_queen;
		return true;
	}
};


void displaySolution(board solution) {
	cout << '\n';
	for (size_t i = 0; i < solution.size(); i++) {
		for (size_t j = 0; j < solution[i].size(); j++) {
			cout << solution[i][j]; 
			cout << ' ';
		}
		cout << '\n';
	}
}

board createMatrix(int dim) {
	board b(dim);
	for (int i = 0 ; i < dim; i++)
		b[i] = *(new vec<char>(dim, Game::c_empty));
	return b;
}

void DFS ( vec<board>& solutions, board b, int nqueen) {
	for (size_t i = 0; i < b.size(); i++) {
		for (size_t j = 0; j < b[i].size(); j++) {
			if ( Game::put(b, i, j) ) {
				int cur_nqueen = nqueen - 1;
				if ( cur_nqueen <= 0 ) {
					solutions.push_back( Game::clone(b) );	
				} else {
					DFS (solutions, b, cur_nqueen);
				}
				Game::remove(b, i, j);
			}
		}
	}
}

vec<board> queen(int nqueen) {
	vec<board> solutions;
	board b = createMatrix(nqueen);
	DFS ( solutions, b, nqueen);
	return solutions;
}



int main() {
	vec<board> solutions = queen(4);
	for (board solution : solutions) {
		displaySolution(solution);
	}
	cout << solutions.size() << " Solutions"<< endl;

	return 0;
}
