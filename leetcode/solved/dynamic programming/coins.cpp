#include <bits/stdc++.h>

using namespace std;

int infinity = 10e6;
int dp[10000];
int solve(vector<int> coins, int x) {
    if ( x <= 0 ) {
        if ( x < 0 ) return infinity;
        return 0;
    }
    int res = infinity;
    for (int c : coins) {
        // +1 means a new count
        if ( dp[x - c] != 0 ) {
            res = min(res, dp[x - c] + 1);
        } else {
            res = min(res, solve(coins, x - c) + 1);
        }
    }
    dp[x] = res;
    return res;
}
int main(int argc, char* argv[]) {
    vector<int> coins {1, 3, 4};
    int x = 10;
    for (int x = 0; x <= 10; x++ ) {
        cout << solve(coins, x) << "\n";
    }
    return 0;
}
