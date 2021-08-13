#include <bits/stdc++.h>

using namespace std;
struct Solution {
    int diff;
    int j;
    int j_;
};

void solveSimpleCase () {
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
        // printf("j = %i, j' = %i, |j - j'| = %i\n", j, j_, diff);
        if (diff < sol.diff && j >= j_) {
            sol.diff = diff;
            sol.j = j; sol.j_ = j_;
        }
    }
    printf("\nOptimal solution : dist(i, j) = %i, j = %i, j' = %i", sol.diff, sol.j, sol.j_);
}


void solveComplicatedCase (vector<int> work_date) {
    int T = 300000, F = 2000, E = 10000; 
	// let f a function defined as 
    // let's compute j, j' such that min d = (T - (jE + j'F)) with d >= 0
	// Formally speaking we want to solve this
	//  [ argmin_j, j' (T - (jE + j'F)) AND min |j - j'|
    // <  such that jE + j'F <= T, where j' is computed given the work_date constraint
	//  [ For all E, F > 0; j >= j' >= 0
    int nax = T / E;
    Solution sol;
    sol.diff = INT_MAX;
    for (int j = nax; j >= 1; j--) {
        int j_ = 0;
        // in this case we need to check the exact amount of work date for those ideal-j days
		// with min(s, j) we can be sure that j >= j_
        for (int pos = 1, s = work_date.size(); pos <= min(s, j); pos++)
            j_ += work_date [pos - 1] == 0 ? 1 : 0; // 0 if work_date 

        int diff = T - (j*E + j_*F);
        // argmin_j, j' (T - (jE + j'F)) 
        if (diff <= sol.diff && diff >= 0) {
            if (diff == sol.diff) {
                // will probably never happen but whatever := min |j - j'|
                if (abs(sol.j - sol.j_) > abs(j - j_))
                    continue;
            }
            sol.diff = diff;
            sol.j = j; sol.j_ = j_;
        }
    }
    printf("\nV2 Optimal solution : deltaTotal = %i, j = %i, j' = %i", sol.diff, sol.j, sol.j_);
}

int main() {
    solveSimpleCase ();
    // normally we want to 
    solveComplicatedCase (vector<int> {
        // for T = 200 000
        // we should have 
        // j = 7 + 7 + 3 which cost 170 000 
        // j' = 5 + 5 + 1 which cost 22 000
        // Left = 200 000 - 192 000 = 8 000
        0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 1, 1,
        0, 0, 1, 0, 0, 1, 1
    });
    return 0;
}
