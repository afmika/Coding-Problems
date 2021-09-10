#include <bits/stdc++.h>

using namespace std;
int main () {
	string s;
	getline(cin, s);
	vector<int> nums;
	// 1, 2 and 3 only (single digits)
	for (char c : s) {
	    if (c == '+') continue;
	    nums.push_back ((int) (c - '0'));
	}
	sort(nums.begin(), nums.end());
	for (int i = 0, n = nums.size(); i < n; i++) {
	    cout << nums[i];
	    cout << (i + 1 == n ? "" : "+");
	}
	return 0;
}