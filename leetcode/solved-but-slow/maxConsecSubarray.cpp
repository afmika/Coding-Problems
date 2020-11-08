#include <bits/stdc++.h>

using namespace std;

// vector<deque<int>> solution;
vector<int> solution;
unordered_map<int, int> dp;

// void dfs (vector<int>& nums, deque<int> current, int index) {
void dfs (vector<int>& nums, int current, int index) {
	int l = nums.size();
	
	if ( dp.find(index) != dp.end() ) {
		solution.push_back(current + dp[index]);
		cout << "ato \n";
		return;
	}
	if ( index + 1 >= l ) {
		dp[index] = 
		solution.push_back(current);
		return;
	}
	
	for (int i = index + 1; i < l; i++) {
		if ( nums[index] < nums[i] ) {
			// current.push_back(nums[i]);
			// dfs(nums, current, i);
			dfs(nums, current + 1, i);
			// current.pop_back();
		} 
	}
}

int maxSub(vector<int>& nums) {
	int l = nums.size();
	for (int i = l - 1; i >= 0; i--) {
		// deque<int> current;
		// current.push_back(nums[i]);
		// dfs(nums, current, i);
		dfs(nums, 1, i);
	}
	int best = 0;
	for (auto s : solution) {
		// best = max(best, (int) s.size());
		best = max(best, s);
		//for (int n : s) cout << n << " ";
		// cout << "\n";
	}
	int count = 0;
	for (auto s : solution)
		count += (best == s ? 1 : 0);
		// count += (best == (int) s.size() ? 1 : 0);
	return count;
}

int main() {
	vector<int> input {1, 3, 5, 4,  7, 1, 3, 5, 4,  7, 7, 1, 3, 5, 4,  7,7, 1, 3, 5, 4,  7,1, 2, 3,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7,1, 3, 5, 4,  7};
	// vector<int> input {9, 6, 6, 1, 11, 4, 1, 2, 6, 9, 4, 2, 6, 0, 0, 3, 2, 6, 2, 8, 0, 3, 10, 3, 2, 10, 6, 0, 3, 6, 3, 4, 0, 1, 6, 6, 4, 4, 1, 9, 6, 9, 4, 7, 10, 0, 2, 9, 6, 6, 5, 5, 9, 3, 11, 7, 0, 5, 3, 3, 5, 9, 11, 8, 9, 8, 10, 7, 7, 11, 10, 4, 9, 4, 0, 3, 8, 8, 0, 4, 5, 11, 7, 4, 0, 11, 10, 4, 4, 11, 9, 0, 7, 10, 8, 8, 9, 9, 2, 11, 8, 0, 4, 4, 1, 6, 10, 1, 5, 5, 11, 0, 2, 8, 1, 6, 3, 7, 5, 3, 11, 8, 3, 4, 3, 0, 4, 9, 9, 1, 3, 1, 0, 6, 9, 6, 6, 6, 9, 11, 0, 0, 1, 1, 7, 5, 11, 1, 8, 1, 7, 2, 9, 0, 8, 1, 3, 0, 10, 5, 8, 7, 0, 2, 2, 10, 7, 4, 7, 3, 6, 2, 7, 8, 4, 11, 11, 0, 10, 8, 6, 0, 8, 11, 4, 1, 4, 8, 2, 4, 3, 10, 11, 6, 8, 4, 5, 0, 8, 8, 1, 4, 2, 8, 5, 2, 0, 1, 5, 5, 11, 9, 0, 5, 5, 7, 5, 5, 1, 5, 3, 3, 2, 2, 5, 4, 2, 10, 7, 2, 6, 7, 0, 6, 11, 2, 11, 10, 1, 9, 10, 11, 11, 4, 2, 7, 5, 4, 11, 8, 2, 6, 10, 1, 2, 6, 10, 5, 6, 1, 6, 0, 5, 5, 2, 0, 11, 3, 6, 11, 5, 9, 1, 2, 5, 5, 7, 11, 8, 2, 6, 0, 2, 9, 10, 10, 5, 3, 6, 11, 8, 0, 11, 7, 10, 8, 6, 10, 6, 4, 8, 11, 6, 0, 4, 10, 6, 4, 7, 8, 0, 5, 4, 7, 3, 11, 3, 0, 0, 9, 3, 1, 6, 6, 9, 11, 5, 2, 3, 5, 2, 10, 4, 10, 1, 4, 8, 1, 11, 2, 7, 10, 8, 3, 2, 11, 10, 3, 6, 9, 2, 9, 7, 7, 8, 5, 3, 7, 2, 8, 1, 9, 1, 2, 6, 2, 3, 11, 9, 4, 1, 5, 4, 11, 2, 4, 0, 5, 5, 4, 6, 7, 4, 3, 5, 5, 3, 7, 3, 9, 3, 9, 9, 0, 0, 5, 9, 1, 3, 3, 8, 7, 5, 3, 1, 9, 10, 5, 2, 1, 11, 0, 9, 1, 2, 6, 1, 3, 3, 3, 1, 8, 1, 10, 8, 5, 0, 4, 3, 7, 9, 7, 5, 11, 0, 3, 9, 5, 10, 7, 9, 5, 10, 6, 0, 7, 10, 3, 9, 10, 0, 7, 5, 9, 11, 4, 1, 9, 4, 0, 3, 2, 8, 4, 8, 4, 2, 8, 2, 2, 6, 0, 9, 10, 10, 8, 10, 8, 8, 5, 7, 8, 9, 8, 5, 11, 7, 4, 0, 5, 3, 9, 7, 7, 3, 7, 8, 11, 3, 6};
	cout << "Input size " << input.size() << endl;
	cout << "Best " << maxSub(input);
	return 0;
}
