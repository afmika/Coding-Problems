#include <bits/stdc++.h>

using namespace std;

inline int iSqrt (int n) { return (int) sqrt((double) n); }

int solve (int target) {
    set<vector<int>> result;
    for (int a = 1; a < target; a++) {
        for (int b = 1; b <= (target - a); b++) {
            int c2 = a*a + b*b;
            int c = iSqrt (c2);
            if (c > (target - a)) break;
            if (c*c == c2 && (a + b + c) == target) {
                vector<int> vec = {a, b, c};
                sort(vec.begin(), vec.end());
                result.insert(vec);
            }
        }
    }
    // for (auto &v :result) {
    //     printf("%d^2 + %d^2 = %d^2\n", v[0], v[1], v[2]);
    // }
    return result.size();
}


int main() {
    int nax = 1, soFar = 0;
    // s = argmax solve(p)
    int p = 1;
    while (p < 1000) {
        int res = solve(p);
        if (soFar < res) {
            nax = p;
            soFar = res;
        }
        ++p;
    }
    cout << "solution p = " <<  nax; // << " total " << soFar;
    return 0;
}