/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */
#include <bits/stdc++.h>
using namespace std;
int minimum_jump = INT_MAX;
bool DFS (int cur_pos, vector<int> nums, int jump_count) {
	if ( cur_pos >= nums.size()  ) return false;
	if ( cur_pos == nums.size() - 1 ) return true;
	for (int njump = 1; njump <= nums[cur_pos]; njump++) {
		if ( DFS(cur_pos + njump, nums, jump_count + 1) ) {
			minimum_jump = min(minimum_jump, jump_count + 1);
		}
	}
	return false;
}
int jump(vector<int>& nums) {
	DFS(0, nums, 0);
	return minimum_jump == INT_MAX ? 0 : minimum_jump;
}

int main() {
	vector<int> t{2,3,1,1,4};
	cout << jump(t);
	return 0;
}

