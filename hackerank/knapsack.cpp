#include <bits/stdc++.h>

using namespace std;
// https://www.hackerrank.com/challenges/unbounded-knapsack/problem?h_r=profile
int solve (int k, vector<int> arr) {
    // must use a new dp after each test case
    unordered_map<int, int> dp;
    
    // this is relatively easier than the coin change problem
    for (int x : arr) {
        for (int i = x; i < (k + 1); i++) {
            // at[i] := max(solve(i), x + solve(i - x))
            dp[i] = max(
                dp[i], x + dp[i - x]
            );
        }
    }
    return dp[k];
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i = 0;
        cin >> n >> k;
        vector<int> arr (n);
        while (i < n)
            cin >> arr[i++];
        cout << solve (k, arr) << "\n";
    }
    return 0;
}