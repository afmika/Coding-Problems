#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> dp;
int xorNacci (int n, int a, int b) {
	if (dp.find(n) == dp.end()) {
		return dp[n];
	}
	dp[n] = xorNacci(n - 1, a, b) + xorNacci(n - 2, a, b);
	return dp[n];
}
int main () {
	dp[1] = a;
	dp[1] = b;
	return 0;
}