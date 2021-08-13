#include <bits/stdc++.h>

using namespace std;
struct Solution {
    int diff;
    int j;
    int j_;
};

int main() {
    int T = 205487, F = 2000, E = 10000; 
    // let's compute j, j' such that min |j - j'|
    // in other words we want j and j' to be equal idealy
	// Formally speaking we want to solve this
	//  [ argmin_j, j' |j - j'|
    // <  such that jE + j'F <= T
	//  [ For all E, F > 0; j >= j' >= 0
    int nax = T / E;
    Solution sol;
    sol.diff = INT_MAX;
    for (int j = nax; j >= 1; j--) {
        int leftF = T - j * E;
        int j_ = leftF / F;
        int diff = abs(j - j_); 
        printf("j = %i, j' = %i, |j - j'| = %i\n", j, j_, diff);
        if (diff < sol.diff && j >= j_) {
            sol.diff = diff;
            sol.j = j; sol.j_ = j_;
        }
    }
    printf("Optimal solution : dist(i, j) = %i, j = %i, j' = %i", sol.diff, sol.j, sol.j_);
    return 0;
}
