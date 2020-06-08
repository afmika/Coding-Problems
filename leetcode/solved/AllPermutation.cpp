
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
vector<int> cloneVec( vector<int> v ) {
	vector<int> r;
	for (int n : v) r.push_back( n );
	return r;
}    
bool DFS (vector<vector<int>>& solutions, vector<int> current, vector<int> nums, map<int, bool> m) {
	if ( current.size() == nums.size() ) {
		return true;
	}

	for (int c : nums) {
		if ( m[c] == false) {
			m[c] = true;
			vector<int> temp = cloneVec(current);
			temp.push_back( c );
			if ( DFS(solutions, temp, nums, m) ) {
				solutions.push_back( temp );
			}
			m[c] = false;
		}
	}
	return false;
}
vector<vector<int>> permute(vector<int>& nums) {
	map<int, bool> m;
	for (int c : nums) m[c] = false;

	vector<vector<int>> solutions;
	vector<int> current;

	DFS (solutions, current, nums, m);

	return solutions;       
}

int main() {
	vector<int> t{1,2,3};
	vector<vector<int>> res = permute(t);
	for (auto s : res) {
		for (int i : s) cout << i << " ";
		cout << endl;
	}
	return 0;
}
