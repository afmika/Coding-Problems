#include <bits/stdc++.h>
using namespace std;

int dp[10000];
int infinity = 10e6;
int perfectSquare(int n) {
    if ( n <= 0 ) {
        if ( n < 0 ) return infinity;
        return 0;  
    }
    int res = infinity;
    for (int i = 1; i < n; i++ ) {
        int sq = i * i;
        if ( sq == n )
            return 1;
        if ( sq > n ) break;
        else if (dp[n - sq] > 0 ) {
			// +1 means a new count
            res = min(res, dp[n - sq] + 1);
        } else {
			// +1 means a new count
            res = min(res, perfectSquare(n - sq) + 1);
        }
    }
    dp[n] = res;
    return res;
}
int main() {
    cout << perfectSquare(679);
    return 0;
}
