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
	if ( cur_pos >= (int) nums.size()  ) return false;
	if ( cur_pos == (int) nums.size() - 1 ) return true;
	for (int njump = 1; njump <= nums[cur_pos]; njump++) {
		int new_jump_count = jump_count + 1;
		if ( new_jump_count < minimum_jump ) {
			if ( DFS(cur_pos + njump, nums, new_jump_count) ) {
				minimum_jump = new_jump_count;
			}   
		}
	}
	return false;
}
int jump(vector<int>& nums) {
	DFS(0, nums, 0);
	return minimum_jump == INT_MAX ? 0 : minimum_jump;
}

int main() {
	vector<int> t{8,2,4,4,4,9,5,2,5,8,8,0,8,6,7,5,1,9,9,3,5,0,7,5};
	cout << jump(t);
	return 0;
}

