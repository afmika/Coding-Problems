/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false


*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if ( matrix.size() == 0 ) return false;
	
	
	int nrows = matrix.size();
	int ncols = matrix[0].size();
	
	if ( nrows == 1 ) {
		for (int i = 0; i < ncols; i++) {
			if ( matrix[0][i] == target ) return true;
		}
		return false;
	}
		
	int row = 0;
	while ( row < nrows ) {
		if ( target <= matrix[row][ncols - 1] ) {
			if ( target == matrix[row][ncols - 1] )
				return true;
			else
				break;
		}
		row++;
	}
	if ( row == nrows ) return false;
	int inf = max(row - 1, 0);
	int sup = min(row + 1, nrows - 1 );
	// cout << inf << " " << sup << endl;
	for (int j = inf; j <= sup; j++ ) {
		for (int i = 0; i < ncols; i++ ) {
			if ( matrix[j][i] == target ) return true;
		}
	}
	return false;
}

/*
[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
50

[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
10

[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
34
*/
int main() {
	vector<vector<int>> m {
		{1},{3}
	};
	
	cout << "Val " << searchMatrix(m, 2) << endl;
	
	return 0;
}
