/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


 * */
#include <bits/stdc++.h>
using namespace std;
vector<int> cloneVec( vector<int> v ) {
	vector<int> r;
	for (int n : v) r.push_back( n );
	return r;
}    
bool DFS (set<vector<int>>& solutions, vector<int> current, vector<int> nums, vector<int> pass) {
	if ( current.size() == nums.size() ) {
		return true;
	}
	for (int i = 0; i < (int) nums.size(); i++ ) {
		if ( pass[i] == 0) {
			pass[i] = 1;
			vector<int> temp = cloneVec(current);
			temp.push_back( nums[i] );
			if ( DFS(solutions, temp, nums, pass) ) {
				solutions.insert( temp );
			}
			pass[i] = 0;
		}
	}
	return false;
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<int> pass(nums.size(), 0);
	set<vector<int>> solutions;
	vector<int> current;

	DFS (solutions, current, nums, pass);
	vector<vector<int>> sol;
	for (auto v : solutions) sol.push_back(v);
	return sol;     
}

int main() {
	vector<int> t{1, 1, 2};
	vector<vector<int>> res = permuteUnique(t);
	for (auto s : res) {
		for (int i : s) cout << i << " ";
		cout << endl;
	}
	return 0;
}

