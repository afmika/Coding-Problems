/*
 * https://codeforces.com/contest/821/problem/A
 * */
#include <bits/stdc++.h>

using namespace std;

bool form(int x, vector<int> temp, int idx) {
	if ( x <= 0 ) {
		if ( x == 0 ) return true;
		return false;
	} 
	int possible = false;
	for (int i = idx; i < (int) temp.size(); i++) {
		int c = temp[i];
		possible = possible || form(x - c, temp, idx + 1);
	}
	return possible;
}

bool isPerfect(vector<vector<int>> grid) {
	int n = grid.size();
	for (int yp = 0; yp < n; yp++) {
		for (int xp = 0; xp < n; xp++) {
			
			if ( grid[yp][xp] == 1 )
				continue;
			
			vector<int> row;
			vector<int> col;
			for (int c = 0; c < n; c++ ) {
				if ( c != yp )
					row.push_back(grid[c][xp]);
				if ( c != xp)
					col.push_back(grid[yp][c]);
			}

			int can = form(grid[yp][xp], row, 0)
					||form(grid[yp][xp], col, 0);
			
			if (!can)
				return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> grid;
	int m = n;
	while ( n-- ) {
		vector<int> row;
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			row.push_back(temp);
		}
		grid.push_back(row);
	}
	
	cout << (isPerfect(grid) ? "Yes" : "No");
	return 0;
}
